// Cart_Balance-Code.cpp : Defines the entry point for the console application.
// Min-Max Evolutionary Controllers Physics Portion

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "vector"

using namespace std;
// Establish boundaries
// Table boundaries
// gravity = 9.81; // m/s

// Initialize knowns
const int g = 9.81; // m/s^2
const int n = 1000 // iterations



////Struct has function 
//Class has public, private, function and inheritance

// Cart
// Establish cart boundaries
// cart movements - left and right
// Cart starting position
// cart position - x
// cart velocity - xdot 
// forces on the cart
// weight of cart
class Cart {
public:
			
	const int Mc=200; // Mass of the Cart
	const int y; // Y position of Cart - Irrelevant due to gravity
	const int y_dot; // Velocity of y component of Cart - Irrelevant due to gravity
	const int y_dd; // Y double dot - Y component of acceleration of Cart

			// Changing Variables
	double x; // X Position of Cart
	double x_dot; // Velocity of x component of Cart
	double x_dd; // Acceleration of x component of Cart

};


// Establish Pendulum boundaries
// weight of Pendulum
// ball position
// ball movements - rotational about pin
// ball position - theta
// ball velocity - thetadot
// forces on Pendulum
// Massless Pendulum
class Pend_state {
public:

	int theta; // ever changing theta - main objective to keep theta around 90*
	double Px; // x coordinate of Pendulum;
	double Py; // y coordinate of Pendulum;

};


class Pendulum {
public:

	// static variables
	const int m=50; // Mass of Pendulum
	const int L=10; // Length of the Pendulum
	
	// collection of states
	vector <Pend_state> pend;

	// Changing variables
	double theta_dot; // ever changing velocity of theta.
	double theta_dd; // acceleration of theta.
	double torq;
	double I;

	// public functions
	void initialize();
	Pend_state get_state(const int);
	void set_action();
	Pend_state cycle();
	double f(double theta, double omega, double time);

private:

};

void Pendulum::initialize()
{
	Pend_state initial;
	initial.theta = 180* M_PI / 180;
	initial.Px = -10;
	initial.Py = 0;
	
	for (int i = 0; i < n; ++i) {
		pend.push_back(initial); //push_back pushes it to the back of the vector
	}

}

double Pendulum::f(double theta, double omega, double time) {
	return -theta
}


// Within a loop - Balance the Pendulum on the cart in equilibrium
// Within another loop - The ball starts at the top but falls under the cart, finally falling into equilibrium

Pend_state Pendulum::cycle() { 
	
	// variables
	Pend_state nextState;
	double dt = 0.1; //time step

	// use previous state + new conditions to "load" nextState (do all of the calculations)
		//nextState.Px = L*cos(theta);
		//nextState.Py = L*sin(theta);
	
	// does all necessary calculations, given an action (already set from set_action), to arrive at the next state at the next timestep.
	//torque to theta dd
	theta_dd = -g*L *cos(theta) / m*pow(L, 2) + torq; //rad/s^2   // define theta_dd with t variable 
		//thetat_dd to theta_dot
		//theta_dot to theta
		//theta to xy

	// initialize theta_dot=0 and theta= little less that 90 degrees
	theta_dot = 0; // rad/s // theta dot of this specific pendulum
	theta_dd = 0;

	// overwrite vector with nextState
		//pend[++i]=nextState; // loop this for all of your steps

	/*
	vector <double> Pstate;


	Return Pstate;*/

	return (*this);
}

void Pendulum::set_action() { //receives "action vection", which in the first case will just consist of the torque at the joint

	//name vector
	// torq=t@0
	torq = 0


}

Pend_state Pendulum:get_state(const int i) { 
	//gives the state of the pendulum at the given timestep
	return pend[i];
}


int main()
{
	// variables
	Pendulum pend;

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
	ofstream fout;
	fout.clear();
	fout.open("filename.txt");
	for (int i = 0; i < n; i++) { // for i number of iterations 
		//calculate xy
		//use theta
		//output xy
		fout << pend[i].Px << "," << pend[i].Py << "," << pend[i].theta << endl;	
	}

	//close file
	fout.close();

	return 0;
}
