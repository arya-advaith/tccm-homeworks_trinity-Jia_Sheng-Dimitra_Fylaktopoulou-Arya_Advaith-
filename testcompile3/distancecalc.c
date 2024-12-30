#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fileopening.c"
#include "LennardJones.c"
#include "TotalEnergy.c"
#include "acceleration.c"
#include "Verlet.c"
#include "writefile.c"


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




// =====================some messy necessary values (initialization) ==============================

//--------------------velocity----------------------------
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


//--------------------------- acceleration --------------------
double acceleration_previous[3][3] = {        // i{x y z}, j{x y z} k{x y z}     atom/acc_direction //later need initialize to 0  first
	{0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}

};

double** acceleration1 = malloc(sizeof(double*) * 3); //allocate 3 pointer space
for (int i = 0; i < 3; i++) {
	acceleration1[i] = malloc(sizeof(double) * 3); // array of pointer box that point to a memory
}

// need to manually put value inside
for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		acceleration1[i][j] = acceleration_previous[i][j];
	}

}

//---------------------------------------------------


double acceleration_current[3][3] = {        // i{x y z}, j{x y z} k{x y z}     atom/acc_direction //later need initialize to 0  first
	{0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}

};



double** acceleration2 = malloc(sizeof(double*) * 3); //allocate 3 pointer space
for (int i = 0; i < 3; i++) {
	acceleration2[i] = malloc(sizeof(double) * 3); // array of pointer box that point to a memory
}

// need to manually put value inside
for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		acceleration2[i][j] = acceleration_current[i][j];
	}

}




// =====================some messy necessary values ends ==============================



for (int n = 0; n < 1000; n++) {     // This is Verlet loop, 1000 steps 
printf("step:%d\n",n);

// ----------- 1 compute distance function --------------------
double** distance = compute_distance(N,coord);


// -------------2 compute LJ potential ----------------------
double total_energy = V(epsilon, sigma, N, distance);




// ------------------3 compute total energy (Kinetic) ------------------------------
double T_value = T(N, velocity1, mass);



// ------------------3 compute total energy (Total energy) ------------------------------
double Total_E_system = E(T_value, total_energy);  //total_energy = LJ potential



// -----------------4  Compute the acceleration -------------------------------------------
compute_acc(N, coord, mass, distance, acceleration2, epsilon, sigma);




// =========================5 Verlet part=============================================




	if (n < 1) {
		printf("This is the initial acceleration, accele_prev is same value");

	}
	else {
		printf("This is not initial acceleration, acceleration_prev take last acce value");
		acceleration1 = acceleration2;
	}

	// -----------------------function Verlet here ------------------------------------------------
	coord, velocity1, acceleration1, acceleration2 = Verlet(N, coord, velocity1, acceleration1, acceleration2);


// =========================Verlet part end =========================================



Writefile(N, T_value, total_energy, Total_E_system, coord);

}



free_2d(coord);
free(mass);
//free_2d(distance);

return 0;
}
