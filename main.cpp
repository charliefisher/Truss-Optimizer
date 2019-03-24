
#include <fstream>
#include <iostream>
#include "Truss.cpp"
using namespace std;

const string FILEIN = "", FILEOUT = "";


int main(){
    ifstream fin(FILEIN);
    ofstream fout(FILEOUT);
    fin >> int numJoints >> int numMembers;
    Truss truss(numJoints, numMembers);

    Truss::Joint * joints = getJoints();
    for (int i = 0; i < numJoints; i++){
        fin >> joints[i].x >> joints[i].y >> joints[i].fixedX >> joints[i].fixedY >> joints[i].externalX >> joints[i].externalY;
    }

    truss.optimize();
    truss.output(fout);

}
