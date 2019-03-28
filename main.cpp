#include <fstream>
#include <iostream>
#include <time.h>
#include "Truss.hpp"

using namespace std;

const string FILEIN = "", 
			 FILEOUT = "";

int main(){
    ifstream fin(FILEIN);
    ofstream fout(FILEOUT);
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

	clock_t tStart = clock();
    truss.optimize();
    truss.output(fout);
	truss.output(cout);
	printf("Time: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	system("pause");
	return 0;
}