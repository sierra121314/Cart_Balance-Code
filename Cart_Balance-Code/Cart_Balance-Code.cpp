// Cart_Balance-Code.cpp : Defines the entry point for the console application.
// Min-Max Evolutionary Controllers Physics Portion

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <fstream>

using namespace std;
// Establish boundaries
// Table boundaries
// gravity = 9.81; // m/s

// Initialize knowns
const int g = 9.81; // m/s^2

			  // Not sure where to put this
theta_dd = -Ry*cos(theta*PI / 180) + Rx*sin(theta*PI / 180);

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
			
	int Mc; // Mass of the Cart
	int y; // Y position of Cart - Irrelevant due to gravity
	int y_dot; // Velocity of y component of Cart - Irrelevant due to gravity
	int y_dd; // Y double dot - Y component of acceleration of Cart

			// Changing Variables
	int x; // X Position of Cart
	int x_dot; // Velocity of x component of Cart
	int x_dd; // Acceleration of x component of Cart



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

	int m; // Mass of Pendulum
	int L; // Length of the Pendulum
	int Px; // x coordinate of Pendulum;
	int Py; // y coordinate of Pendulum;

			// Changing variables
	double theta; // ever changing theta - main objective to keep theta around 90*
	double theta_dot; // ever changing velocity of theta.
	double theta_dd; // acceleration of theta.

};

// Within a loop - Balance the Pendulum on the cart in equilibrium
// Within another loop - The ball starts at the top but falls under the cart, finally falling into equilibrium


int main()
{

	// initialize theta_dot=0 and theta= little less that 90 degrees

	Pendulum pendulum;  // I have an object called pendulum of type pendulum
	pendulum.theta = 89.9;  //degrees //theta of this specific pendulum
	pendulum.theta_dd = 0; //rad/s^2 // theta double dot of this specific pendulum
	pendulum.m = 100; //kg  //mass of this specific pendulum
	pendulum.L = 10; //m

//loop in order to display the xy data
//processing loop

//open file
	ofstream fout;
	fout.open("filename.txt");
	for (int i = 0; i < 2000; i++) { // for i number of iterations 
		//calculate xy
		//use theta
		pendulum.Px = pendulum.L*cos(pendulum.theta);
		pendulum.Py = pendulum.L*sin(pendulum.theta);
		//output xy
		fout << pendulum.Px << "," << pendulum.Py << endl;
		//update theta and theta_dd
		pendulum.theta = asin((pendulum.theta_dd*pendulum.L) / g); // check if this works for defining theta
		pendulum.theta_dd = g*pendulum.theta / (pendulum.L); // define theta_dd with t variable
	}

	//close file
	fout.close();

	return 0;
}


