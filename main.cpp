
#include <fstream>
#include <iostream>
#include "Truss.cpp"
using namespace std;

const string FILEIN = "", FILEOUT = "";


int main(){
    ifstream fin(FILEIN);
    ofstream fout(FILEOUT);
    fin >> int numJoints;
    Truss truss(numJoints);

    Truss::Joint * joints = getJoints();
    for (int i = 0; i < numJoints; i++){
        fin >> joints[i].x >> joints[i].y >> joints[i].fixedX >> joints[i].fixedY >> joints[i].externalX >> joints[i].externalY;
    }

    truss.solve();
    truss.output(fout);

    system("PAUSE");


}

Truss::output(ofstream & out){
    for(int i  = 0; i < numJoints; i++){
        out << "Joint " << i+1 << ":  ( " << joints[i].x << " , " << joints[i].y << " )";
    }
}

Truss::solveJoint(int index){

}

struct Members{
    Joint * joint1;
    Joint * joint2;
    length
};