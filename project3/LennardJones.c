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
double V(double epsilon, double sigma, size_t N, double** distances) {
   double total_energy = 0.0;

   // Loop over each pair of atoms i and j, where j > i
   for (size_t i = 0; i < N; i++) {
       for (size_t j = i + 1; j < N; j++) {
           double rij = distances[i][j]; //Distance between atom i and j
           total_energy += VLJ(epsilon, sigma, rij);
       }
   }
   printf("\nTotal potential energy: %f\n", total_energy);
   return total_energy;
}

