#include "Cart_Balance-Code.h"
#include "stdafx.h"


int main()
{
	// variables
	CB::Pendulum pend;

	// initialize pendulum
	pend.initialize();

	// calculate all of the states of the pendulum along the curve
	pend.cycle();

	// initialize cart weight
	//Cart cart; // Object call cart of type cart
	//cart.x = 0;

	//loop in order to display the xy data
	//processing loop

	//open file
	std::ofstream fout;
	fout.clear();
	fout.open("positiondata2.csv", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < n; i++) { // for i number of iterations 
								  //calculate xy
								  //use theta
								  //output xy
		fout << pend.give_state(i).Px << "," << pend.give_state(i).Py << "," << dt*i << "," \
			<< pend.give_state(i).theta << "," << pend.give_state(i).theta_dot << "," \
			<< pend.give_state(i).theta_dd << std::endl;
	}

	//close file
	fout.close();

	return 0;
}
