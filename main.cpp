
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
    int joint1Num, joint2Num;
    for (int i = 0; i < numMembers; i++){
        Truss::Member * member = new Member();
        fin >> member->id >> joint1Num >> joint2Num;
        member->joint1 = &joints[joint1Num];
        member->joint2 = &joints[joint2Num];
        joints[joint1Num]->connections.push_back(member);
        joints[joint2Num]->connections.push_back(member);
    }

    truss.optimize();
    truss.output(fout);

}
