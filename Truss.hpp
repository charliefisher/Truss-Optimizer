
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
		};

		Truss(unsigned int numJoints);
		~Truss();
		Joint* getJoints();
		void solve();

	private:
		unsigned int numJoints;
		Joint* joints;
		Joint *pin, *normalJoint;

		// solves for moment above pin and net x and y force
		void solveGeneralSystem();
		void solveJoint(Joint* j);

		// should not be called
		Truss();
};
