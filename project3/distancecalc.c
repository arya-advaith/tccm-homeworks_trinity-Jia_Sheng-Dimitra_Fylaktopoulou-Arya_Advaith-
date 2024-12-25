#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fileopening.c"
#include "LennardJones.c"
#include "2TotalEnergy.c"

int main() {
    FILE* input_file = fopen("inp.txt", "r"); //important command to open the file as a reader "r"
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
float epsilon = 0.0661; // depth of the potential well
float sigma = 0.3345; // the distance at which the potential is zero

size_t N=read_Natoms(input_file);

float** coord = malloc_2d(N, 3);
float* mass = malloc(5 * N * sizeof(float));
coord,mass=read_molecule(input_file,  N,coord, mass);

fclose(input_file); // important command to close the file

float** distance=compute_distance(N,coord);
float** velocity = malloc_2d(N,3);
float pot_energy = V(epsilon, sigma, N, distance);
float T_value = T(N, velocity, mass);
 printf("The T value is: %f \n", T_value);
E(T_value, pot_energy);
free_2d(coord);
free(mass);
free_2d(distance);
free(velocity);
return 0;
}
