#include <math.h>
#include <stddef.h>
#include <stdio.h>
// Lennard-Jones potential function

float VLJ(float epsilon, float sigma, float r) {
	if (r == 0.0) {
		return 0.0; //Avoid division by zero
	}
	float sigma_over_r = sigma / r;
	float sigma1 = pow(sigma_over_r, 6);
	float sigma2 = pow(sigma_over_r, 12);
	return 4 * epsilon * ( sigma1 - sigma2);
}
// Total potential energy function
float V(float epsilon, float sigma, size_t N, float** distances) {
   float total_energy = 0.0;

   // Loop over each pair of atoms i and j, where j > i
   for (size_t i = 0; i < N; i++) {
       for (size_t j = i + 1; j < N; j++) {
           float rij = distances[i][j]; //Distance between atom i and j
           total_energy += VLJ(epsilon, sigma, rij);
       }
   }
   printf("\nTotal potential energy: %f\n", total_energy);
   return total_energy;
}

