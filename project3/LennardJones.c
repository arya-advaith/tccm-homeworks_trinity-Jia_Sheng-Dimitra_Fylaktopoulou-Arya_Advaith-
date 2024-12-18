#include <math.h>
#include <stddef.h>
#include <stdio.h>

// Lennard-Jones potential function

double VLJ(double epsilon, double sigma, double r) {
	if (r == 0.0) {
		return 0.0; //Avoid division by zero
	}
	double sigma_over_r = sigma / r;
	double sigma1 = pow(sigma_over_r, 6);
	double sigma2 = pow(sigma_over_r, 12);
	return 4 * epsilon * ( sigma1 - sigma2);
}
// Total potential energy function
double V(double epsilon, double sigma, size_t Natoms, double** distances) {
   double total_energy = 0.0;

   // Loop over each pair of atoms i and j, where j > i
   for (size_t i = 0; i < Natoms; i++) {
       for (size_t j = i + 1; j < Natoms; j++) {
           double rij = distances[i][j]; //Distance between atom i and j
           total_energy += VLJ(epsilon, sigma, rij);
       }
   }
   return total_energy;
}

int main() {
	// Example parameters for the Lennard Jones potential
	double epsilon = 1.0; // depth of the potential well
        double sigma = 1.0; // the distance at which the potential is zero
	size_t Natoms = 3; // number of atoms
	
	// Example of the 2D array (distances between atoms
	double distances[3][3] = {
		{0.0, 1.5, 2.5},
		{1.5, 0.0, 1.0},
		{2.5, 1.0, 0.0}
	};

	// Convert the 2D array to a pointer-to-pointer format (double**)
	double* dist_ptrs[3] = {distances[0], distances[1], distances[2]};

	// Calculate the total potential energy 
	double total_energy = V(epsilon, sigma, Natoms, dist_ptrs);

	// Print the result
	printf("Total potential energy: %f\n", total_energy);

	return 0;
}
