// Cart_Balance-Code.cpp : Defines the entry point for the console application.
// Min-Max Evolutionary Controllers Physics Portion

#include "stdafx.h"
#define _USE_MATH_DEFINES
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


int main()
{
	// initialize cart weight
	//Cart cart; // Object call cart of type cart
	

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
		pendulum.Px = pendulum.L*cos(pendulum.theta);
		pendulum.Py = pendulum.L*sin(pendulum.theta);
		//output xy
		fout << pendulum.Px << "," << pendulum.Py << endl;
		//update theta_dd
		
		pendulum.theta_dd = -g*pendulum.L / (sin(pendulum.theta)); // define theta_dd with t variable //THE STARTING POINT MAKES SENSE!!
		//pendulum.theta_dot =
		pendulum.theta = pendulum.theta - (-g*pendulum.L/pendulum.theta_dd)  ; // check if this works for defining theta //take this out

	}

	//close file
	fout.close();

	return 0;
}


