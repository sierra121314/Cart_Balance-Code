// Cart_Balance-Code.cpp : Defines the entry point for the console application.
// Min-Max Evolutionary Controllers Physics Portion

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "vector"
#include <iostream>

using namespace std;
// Establish boundaries
// Table boundaries
// gravity = 9.81; // m/s

// Initialize knowns
const float g = 9.81f; // m/s^2
const int n = 1000; // iterations
static const double dt = 0.1; //time step



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

///////////////////////////////////
// Establish Pendulum boundaries //
///////////////////////////////////
class Pend_state {
public:
	// ball position - theta
	double theta; // ever changing theta - main objective to keep theta around 90*
	// ball position
	double Px; // x coordinate of Pendulum;
	double Py; // y coordinate of Pendulum;
};


class Pendulum {
public:

	// static variables
	const double m=50; // Mass of Pendulum
	const double L=10; // Length of the Pendulum
	
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
	void cycle();
};

void Pendulum::initialize()
{
	Pend_state initial;
	initial.theta = 45* M_PI / 180;
	initial.Px = L*cos(initial.theta);
	initial.Py = L*cos(initial.theta);
	// initialize theta_dot=0 and theta double dot= little less that 90 degrees
	theta_dot = 0; // rad/s // theta dot of this specific pendulum
	theta_dd = 0;

	pend.push_back(initial); //push_back pushes it to the back of the vector

}



void Pendulum::cycle() { 
	
	// variables
	Pend_state nextState;
	
	// use previous state + new conditions to "load" nextState (do all of the calculations)
		//nextState.Px = L*cos(theta);
		//nextState.Py = L*sin(theta);
	
	for (int i = 1; i < n; i++) {
		// does all necessary calculations, given an action (already set from set_action), to arrive at the next state at the next timestep.
		//torque to theta dd
		theta_dd = -g*cos(pend[i - 1].theta) / (m*L) + torq; //rad/s^2   // define theta_dd with t variable 
															 //thetat_dd to theta_dot
		theta_dot = theta_dot + theta_dd*dt;
		//theta_dot to theta
		nextState.theta = pend[i - 1].theta + theta_dot*dt;
		//theta to xy
		nextState.Px = L*cos(nextState.theta);
		nextState.Py = L*sin(nextState.theta);

		cout << nextState.theta << "," << nextState.Px << "," << nextState.Py << endl;
		
		pend.push_back(nextState);

	}
}

void Pendulum::set_action() { //receives "action vection", which in the first case will just consist of the torque at the joint

	//name vector
	// torq=t@0
	torq = 0;
}

Pend_state Pendulum::get_state(const int i) { 
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
	fout.open("positiondata2.csv");
	for (int i = 0; i < n; i++) { // for i number of iterations 
		//calculate xy
		//use theta
		//output xy
		fout << pend.get_state(i).Px << "," << pend.get_state(i).Py << "," << dt*i << "," << pend.get_state(i).theta << endl;
	}

	//close file
	fout.close();

	return 0;
}
