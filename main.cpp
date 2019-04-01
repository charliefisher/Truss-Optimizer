#include <fstream>
#include <iostream>
#include <time.h>
#include "Truss.hpp"

using namespace std;

const string FILEIN = "C:\\Users\\charl\\OneDrive\\Desktop\\truss\\1_symmetric_input", 
			 FILEOUT = "C:\\Users\\charl\\OneDrive\\Desktop\\truss\\1_symmetric_output";

int main(){
    ifstream fin(FILEIN+".txt");
    ofstream fout(FILEOUT+".txt");
	ofstream csvout(FILEOUT + ".csv");
	int numJoints = 0, numMembers = 0;
    fin >> numJoints >> numMembers;
    Truss truss(numJoints, numMembers);

    Truss::Joint * joints = truss.getJoints();
	Truss::Member * members = truss.getMembers();
    for (int i = 0; i < numJoints; i++){
        fin >> joints[i].x >> joints[i].y >> joints[i].fixedX >> joints[i].fixedY >> joints[i].externalX >> joints[i].externalY;
    }
    int joint1Num, joint2Num;
    for (int i = 0; i < numMembers; i++){
        fin >> members[i].id >> joint1Num >> joint2Num;
        members[i].joint1 = &joints[joint1Num];
        members[i].joint2 = &joints[joint2Num];
        joints[joint1Num].connections.push_back(i);
        joints[joint2Num].connections.push_back(i);
    }
	fin.close();
	cout << "Starting Optimization..." << endl;
	clock_t tStart = clock();
    truss.optimize();
	cout << "---Finished Optimization---" << endl << endl;
    truss.output(fout);
	truss.makeCSV(csvout);
	truss.output(cout);
	fout.close();
	csvout.close();
	cout << endl;
	printf("Time: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	fout.close();
	system("pause");
	return 0;
}