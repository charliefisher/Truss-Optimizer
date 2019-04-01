#include <fstream>
#include <iostream>
#include <time.h>
#include "Truss.hpp"
#include <cstdlib>
#include <string>

using namespace std;

const string FILEIN = "C:\\Users\\charl\\OneDrive\\Desktop\\truss\\1_11_joint_triangular_truss", 
			 FILEOUT = "C:\\Users\\charl\\OneDrive\\Desktop\\truss\\1_optimized_11_joint_triangular_truss";

int main(){
    ifstream fin(FILEIN+".txt");
	bool defaultFile = true;
	string filePath = "";
	while (!fin) {
		if (defaultFile)
			defaultFile = false;
		else {
			cout << "Failed to open " << filePath << endl;
		}
		cout << "Please input file path of input file (with file extension)" << endl;
		cin >> filePath;
		fin = ifstream(filePath);
	}
	ofstream fout, csvout;
	if (defaultFile) {
		fout = ofstream(FILEOUT + ".txt");
		csvout = ofstream(FILEOUT + ".csv");
	}
	else {
		fout = ofstream("Optimized_Truss.txt");
		csvout = ofstream("Optimized_Truss.csv");
	}
	
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