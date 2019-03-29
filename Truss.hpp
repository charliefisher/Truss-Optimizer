#include <cstdlib>
#include <ostream>
#include <vector>

#ifndef TRUSS_HPP_
#define TRUSS_HPP_
#endif

using namespace std;

class Truss {
	public:
		const double MAX_MEMBER_FORCE = 7.0000000000;
		const long double MIN_MOVEMENT_INCREMENT = 0.0000000000001;
		// assume that up and right are positive for position
		// assume that up and right are positive for forces
		struct Joint{
			Joint();
			double x, y;
			bool fixedX, fixedY;
			double externalX, externalY;
			double connectionLen;//sum of connections to this joint
			vector<int> connections;//vector of pointers to members
		};

		struct Member {
			Member();
			int id;
			Joint * joint1;
			Joint * joint2;
			double length;
		};

		Truss(int numJoints, int numMembers);
		~Truss();
		void output(ostream & out) const;
		Joint* getJoints();
		Member* getMembers();

		//main function to optimize the system. Calls other functions
		void optimize();

	private:
		int numJoints;
		int numMembers;
		Joint* joints;
		Joint *pin, *normalJoint;
		Member* members;
		vector<double> validForces;

		bool solveInternal();
		// solves for moment above pin and net x and y force
		void solveGeneralSystem();
		void initialSolve();

		//will update member lengths and move node if it is less costly, otherwise will leave everything unchanged
		double * checkIfBetterState(bool xDir, int jointNum, double increment);

		void revertLengths(int jointNum, double * oldLengths);

		// should not be called
		Truss();
};