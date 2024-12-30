#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double T(size_t Natoms,  // Natoms is just variable Natom
	double** velocity,   // "velocity" is the address of address of a variable
	double* mass) {      // "mass" is the address of another variable



	printf("\nThis is the function T to calculate total energy\n");
	printf("Natoms is: %ld\n", Natoms);




	double veloc_array_squared[3][3];// array to store each velocity^2

	for (int i = 0; i < Natoms; i++) {   // change i, j  to number of Natoms    // i = atom number i
		double velocity_sum = 0;                                           // j = x(j0) , y(j1) ,z(j2) component
		for (int j = 0; j < 3; j++) {
			//printf("[%d][%d]", i, j);
			//printf("velocity is: %f\n", velocity[i][j] );
			velocity_sum += velocity[i][j];

			veloc_array_squared[i][j] = velocity[i][j] * velocity[i][j];
		}
	}

	double v2_array[3];
	for (int i = 0; i < Natoms; i++) {   // i is number of atoms
		// 3 = x, y, z component
			v2_array[i] = veloc_array_squared[i][0] + veloc_array_squared[i][1] + veloc_array_squared[i][2];
	}

//	double mass_array[3];
//	for (int k = 0; k < Natoms; k++) {
//		printf("mass is: %f\n", mass[k]);
//		mass_array[k] = mass[k];
//	}


	double Tsum = 0;
	for (int i = 0; i < Natoms; i++) {
			Tsum += mass[i] * v2_array[i];
		}

//	printf("The Tsum value is : %f\n", Tsum);
	Tsum = Tsum * 0.5;
//	printf("The Tsum value is : %f\n", Tsum);

	//printf("//////////////done function////////////////////\n");
	return Tsum;
	
	}

	double E(double Tvalue, double Vvalue) {
	printf("\nThis function calculate the total energy of the system.\n"); //(change in every loop?)

		double Energy;
		Energy = Tvalue + Vvalue;

		printf("The total energy E is:%f\n",Energy);
		return Energy;
	}






//double main() {
//	double T_value;
//	int Natoms = 3;

	// Total kinetic energy T
	//for (int i = 0 ; i < n_atoms; i++) {


		//velocity
//	double velocity_value[][3] = {               // dummy velocity value, find a way to store here (initialize to 0 first)
//		{1.0,2.0,3.0} ,   // particle 1: {vx,vy,vz}    // change new velocity here by exp. velociy_value[0][1]= (new value)
//		{4.0,5.0,6.0},    // particle 2: {vx,vy,vz}    // at the end this will be all 0
//		{7.0,8.0,10.0}    // particle 3: {vx,vy,vz}
//	};  // # 3 atoms * 3 velocity direction
//
	    //https://youtu.be/-y8FUvRq_88
//		double** velocity1 = malloc(sizeof(double*) * 3); //allocate 3 pointer space
//		for (int i = 0; i < 3; i++) {
//			velocity1[i] = malloc(sizeof(double) * 3); // array of pointer box that point to a memory
//		}
//
//		// need to manually put value inside
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				velocity1[i][j] = velocity_value[i][j];
//			}
//
//		}
//
//		//mass
//		double mass[] = { 39.9481 , 39.9482 , 39.9483 };   // temporary put mass dummy value, try pass mass value into here
//		//double mass_value[] = { 39.9481 , 39.9482 , 39.9483 };
//		double* mass_address;
//
//
//
//		//call T function
//		T_value = T(Natoms, velocity1, mass);
//
//		//T = 0.5 * 1;
//
			//E = T + V;
			//printf("The total Energy is: ");
//		free(velocity1);
	//}

//	printf("The T value is: %f \n", T_value);
//
	// dummy V value
//	double V_value = 15.00;

	// call Total Energy function 1
//	E(T_value, V_value);



//}

