// Cart_Balance-Code.cpp : Defines the entry point for the console application.
// Min-Max Evolutionary Controllers Physics Portion

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <fstream>
#include "vector"

using namespace std;
// Establish boundaries
// Table boundaries
// gravity = 9.81; // m/s

// Initialize knowns
const int g = 9.81; // m/s^2

			  // Not sure where to put this
//theta_dd = -Ry*cos(theta*PI / 180) + Rx*sin(theta*PI / 180);

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
class Pendulum {
public:

	const int m=50; // Mass of Pendulum
	const int L=10; // Length of the Pendulum
	double Px; // x coordinate of Pendulum;
	double Py; // y coordinate of Pendulum;

			// Changing variables
	double theta; // ever changing theta - main objective to keep theta around 90*
	double theta_dot; // ever changing velocity of theta.
	double theta_dd; // acceleration of theta.

};

// Within a loop - Balance the Pendulum on the cart in equilibrium
// Within another loop - The ball starts at the top but falls under the cart, finally falling into equilibrium

vector <double> get_state() { //gives the state of the pendulum at the given timestep
	
	Pendulum pendulum;

	pendulum.Py = pendulum.L*sin(pendulum.theta); 
	pendulum.Px = pendulum.L*cos(pendulum.theta);

	vector <double> Pstate;

	Pstate.push_back(pendulum.Px); //push_back pushes it to the back of the array
	Pstate.push_back(pendulum.Py);

	return Pstate;
}

void set_action(vector<double>) { //receives "action vection", which in the first case will just consist of the torque at the joint



}

void cycle() { // does all necessary calculations, given an action (already set from set_action), to arrive at the next state at the next timestep.



}





int main()
{
	// initialize cart weight
	//Cart cart; // Object call cart of type cart
	//cart.x = 0;

	// initialize theta_dot=0 and theta= little less that 90 degrees
	Pendulum pendulum;  // I have an object called pendulum of type pendulum
	pendulum.theta = 89.9*M_PI/180;  //degrees //theta of this specific pendulum
	pendulum.theta_dot = 0; // rad/s // theta dot of this specific pendulum
	pendulum.theta_dd = 0; //rad/s^2 // theta double dot of this specific pendulum
	
//loop in order to display the xy data
//processing loop

//open file
	ofstream fout;
	fout.open("filename.txt");
	for (int i = 0; i < 2000; i++) { // for i number of iterations 
		//calculate xy
		//use theta
		//pendulum.Px = cart.x+pendulum.L*cos(pendulum.theta);
		pendulum.Py = pendulum.L*sin(pendulum.theta); //THE STARTING POINT MAKES SENSE!!
		pendulum.Px = pendulum.L*cos(pendulum.theta); 
		//output xy
		fout << pendulum.Px << "," << pendulum.Py << "," << pendulum.theta << endl;

		//update theta_dd
		
		pendulum.theta_dd = -g*pendulum.L *cos(pendulum.theta)/(pendulum.m*(pendulum.L)^2) + tor; // define theta_dd with t variable 
		pendulum.theta_dot = g/pendulum.L*cos(pendulum.theta);
		pendulum.theta =  - g/pendulum.L * sin(pendulum.theta) ; // check if this works for defining theta //take this out
		
	}

	//close file
	fout.close();

	return 0;
}

vector<double> get_state()
{
	return vector<double>();
}
