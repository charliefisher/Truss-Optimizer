#include "Truss.hpp"

Truss::Joint::Joint() {
	x=y=0;
	fixedX=fixedY=false;
	externalX=externalY=0;
}

Truss::Truss(unsigned int numJoints) {
	this->numJoints = numJoints;
	this->joints = new Joint[this->numJoints];
	this->pin = &joints[0];
	this->normalJoint = &joints[1];
}

Truss::~Truss() {
	delete[] joints;
}

Truss::Joint* Truss::getJoints() {
	return this->joints;
}

void Truss::solve() {

}

void Truss::solveGeneralSystem() {
	// assumes normal reaction force is horizontally or vertically aligned
	double momentAtPin = 0; // counterclockwise is positive
	// calculate moments about every joint
	for (unsigned int i = 2; i < this->numJoints; i++) {
		// if the joint has an external x (i.e. has any external force
		if (joints[i].externalY != 0) {
			momentAtPin += joints[i].x*joints[i].externalY;
			// do not need to calculate moment generated by x forces since external forces are only in y direction
//			momentAtPin -= joints[i].y*joints[i].externalX;
		}
	}

	if (normalJoint->x == 0) { // the reactions are vertically aligned
		 normalJoint->externalX = momentAtPin/normalJoint->y;
		 pin->externalX = -normalJoint->externalX;

		 for (unsigned int i = 2; i < this->numJoints; i++) {
			 pin->externalY -= joints[i].externalY;
		 }
	}
	else { // the reactions forces are horizontally aligned
		normalJoint->externalY = -momentAtPin/normalJoint->x;
		pin->externalX=0;
		for (unsigned int i = 1; i < this->numJoints; i++) {
			pin->externalY -= joints[i].externalY;
		}
	}
}
void Truss::solveJoint(Joint* j) {

}

void Truss::output(ofstream & out){
	for(int i  = 0; i < numJoints; i++){
	out << "Joint " << i+1 << ":  ( " << joints[i].x << " , " << joints[i].y << " )";
	}
}





