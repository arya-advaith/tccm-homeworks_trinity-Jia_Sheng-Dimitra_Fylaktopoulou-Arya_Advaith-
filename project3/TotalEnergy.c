#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double T(size_t Natoms,  // Natoms is just variable Natom
	double** velocity,   // "velocity" is the address of address of a variable
	double* mass) {      // "mass" is the address of another variable

	printf("\nThis is the function T to calculate total energy\n");
	printf("Natoms is: %ld\n", Natoms);

 
        double Tsum = 0.0;
	for (int i = 0; i < Natoms; i++) {   // change i, j  to number of Natoms    // i = atom number i
		double v2 = 0.0; // Initialize v2 for this atom  
		// j = x(j0) , y(j1) ,z(j2) component
		for (int j = 0; j < 3; j++) { // Loop over x,y and z components
			v2 += velocity[i][j] * velocity[i][j];
		}
                Tsum += 0.5 * mass[i] * v2; // Add kinetic energy for this atom
	}
        

	printf("The total kinetic energy T is: %f\n", Tsum);
	return Tsum;
}	
// Function to compute the total energy 
double E(double Tvalue, double Vvalue) {
	printf("\nThis function calculate the total energy of the system.\n");

	double Energy = Tvalue + Vvalue;
	
	printf("The total energy is: %f\n", Energy);
	return Energy;


}
/*
// Main function for testing
int main() {
	size_t Natoms = 3;
	//Allocate memory for velocity array(3xNatoms)
	double** velocity = malloc(Natoms * sizeof(double*));
	for (size_t i =0; i < Natoms; i++) {
		velocity[i] = malloc(3 * sizeof(double));
	}

	// Initialize the velocity values (dummy values for testing)
        velocity[0][0] = 1.0; velocity[0][1] = 2.0; velocity[0][2] = 3.0;
        velocity[1][0] = 4.0; velocity[1][1] = 5.0; velocity[1][2] = 6.0;
        velocity[2][0] = 7.0; velocity[2][1] = 8.0; velocity[2][2] = 10.0;

	// Initialize mass values
	double mass[] = {39.9481, 39.9482, 39.9483};
	
	// Calculate kinetic energy 
	double Tvalue = T(Natoms, velocity, mass);

	// Dummy potential energy values
	double Vvalue = 15.00;

	//Calculate total energy
	double Evalue = E(Tvalue, Vvalue);

	//Free allocated memory
	for (size_t i=0; i < Natoms; i++) {
		free(velocity[i]); // Free each inner array
	        
	}
	free(velocity);
	return 0; // Free the outer pointer
}*/
