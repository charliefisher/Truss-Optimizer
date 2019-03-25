
#ifndef TRUSS_HPP_
#define TRUSS_HPP_
#endif

class Truss {
	public:
		const unsigned int MAX_MEMBER_FORCE = 7;

		// assume that up and right are positive for position
		// assume that up and right are positive for forces
		struct Joint{
			Joint();
			double x, y;
			bool fixedX, fixedY;
			double externalX, externalY;
			double connectionLen;//sum of connections to this joint
			vector<*Member> connections;//vector of pointers to members
		};

		struct Member{
			Member();
			int id;
			Joint * joint1;
			Joint * joint2;
			double length;
		};

		Truss(unsigned int numJoints);
		~Truss();
		void output();
		Joint* getJoints();

		//main function to optimize the system. Calls other functions
		void optimize();

	private:
		unsigned int numJoints;
		unsigned int numMembers;
		Joint* joints;
		Joint *pin, *normalJoint;
		vector<double> validForces;


		bool validSolve();
		bool solveInternal();
		// solves for moment above pin and net x and y force
		void solveGeneralSystem();
		void initialSolve();

		//will update member lengths and move node if it is less costly, otherwise will leave everything unchanged
		double * checkIfBetterState(bool xDir, double increment)

		// should not be called
		Truss();
};
