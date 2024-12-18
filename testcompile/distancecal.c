#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fileopening.c"
#include "LennardJones.c"
#include "TotalEnergy.c"

int main() {
    FILE* input_file = fopen("inp.txt", "r"); //important command to open the file as a reader "r"
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
double epsilon = 0.0661; // depth of the potential well
double sigma = 0.3345; // the distance at which the potential is zero

size_t N=read_Natoms(input_file);

double** coord = malloc_2d(N, 3);
double* mass = malloc(5 * N * sizeof(double));
coord,mass=read_molecule(input_file,  N,coord, mass);



fclose(input_file); // important command to close the file

double** distance=compute_distance(N,coord);


double total_energy = V(epsilon, sigma, N, distance);



		//velocity
	double velocity_value[][3] = {               // dummy velocity value, find a way to store here (initialize to 0 first)
		{0.0,0.0,0.0} ,   // particle 1: {vx,vy,vz}    // change new velocity here by exp. velociy_value[0][1]= (new value)
		{0.0,0.0,0.0},    // particle 2: {vx,vy,vz}    // at the end this will be all 0
		{0.0,0.0,0.0}    // particle 3: {vx,vy,vz}
	};  // # 3 atoms * 3 velocity direction

	//https://youtu.be/-y8FUvRq_88
	double** velocity1 = malloc(sizeof(double*) * 3); //allocate 3 pointer space
	for (int i = 0; i < 3; i++) {
		velocity1[i] = malloc(sizeof(double) * 3); // array of pointer box that point to a memory
	}

	// need to manually put value inside
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			velocity1[i][j] = velocity_value[i][j];
		}

	}



double T_value = T(N, velocity1, mass);

double Total_E_system = E(T_value, total_energy);


free_2d(coord);
free(mass);
free_2d(distance);

return 0;
}
