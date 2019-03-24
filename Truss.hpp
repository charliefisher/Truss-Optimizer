
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
			vector<*Member> connections;//linked list of members needed, called "members"
		};

		struct Member{
			Member();
			int id;
			Joint * joint1;
			Joint * joint2;
			double length, force;
		};

		Truss(unsigned int numJoints);
		~Truss();
		void output();
		Joint* getJoints();
		bool checkIfBetterState(bool xDir, double increment)
		void optimize();

	private:
		unsigned int numJoints;
		unsigned int numMembers;
		Joint* joints;
		Joint *pin, *normalJoint;

		// solves for moment above pin and net x and y force
		bool validSolve();
		bool solve();
		void solveGeneralSystem();
		void solveJoint(Joint* j);

		// should not be called
		Truss();
};
