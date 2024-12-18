#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double T(size_t Natoms,  // Natoms is just variable Natom
	double** velocity,   // "velocity" is the address of address of a variable
	double* mass) {      // "mass" is the address of another variable

	

	//printf("//////////////start function////////////////////\n");


	printf("\nThis is the function T to calculate total energy\n");
	printf("Natoms is: %ld\n", Natoms);



	//double veloc_array[3];// array to store each velocity sum
	double veloc_array_squared[3][3];// array to store each velocity^2 

	for (int i = 0; i < Natoms; i++) {   // change i, j  to number of Natoms    // i = atom number i
		double velocity_sum = 0;                                           // j = x(j0) , y(j1) ,z(j2) component
		for (int j = 0; j < 3; j++) {
			//printf("[%d][%d]", i, j);
			//printf("velocity is: %f\n", velocity[i][j] );
			velocity_sum += velocity[i][j];

			veloc_array_squared[i][j] = velocity[i][j] * velocity[i][j];
		}
		//veloc_array[i] = velocity_sum;
		//printf("velocity[%d] is: %f\n\n",i, velocity_sum);   // This is x + y + z velocity (useless) in atom i
		
		
	}

	//// print to see array
	//for (int i = 0; i < 3; i++) {
	//	printf("The velocity_array is %f\n",veloc_array[i]);
	//}

	//// print to see array
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		printf("The velocity_array_squared[%d][%d] is %f\n", i, j, veloc_array_squared[i][j]);
	//	}
	//}

	// Calculate the averged velocity squared
	double v2_array[3];
	for (int i = 0; i < Natoms; i++) {   // i is number of atoms
		// 3 = x, y, z component
			v2_array[i] = veloc_array_squared[i][0] + veloc_array_squared[i][1] + veloc_array_squared[i][2];
	}

	//// print to see array
	//for (int i = 0; i < 3; i++) {
	//		printf("The v2_array[%d] is %f\n", i, v2_array[i]);
	//}
	//
	//
	



	double mass_array[3];
	for (int k = 0; k < Natoms; k++) {
		printf("mass atom%d is: %f\n", k+1 ,mass[k]);
		mass_array[k] = mass[k];
	}






	//// print to see array
	//for (int i = 0; i < 3; i++) {
	//	printf("The mass_array is %f\n", mass_array[i]);
	//}
	
	



	double Tsum = 0;
	for (int i = 0; i < Natoms; i++) {
			Tsum += mass_array[i] * v2_array[i];
		}
	
	//printf("The Tsum value is : %f\n", Tsum);
	Tsum = Tsum * 0.5;
	printf("The Tsum value is : %f\n", Tsum);

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

//void compute_acc(
//	size_t Natoms,
//	double** coord,
//	double** mass,
//	double** distance,
//	double** acceleration
//) {
//
//	double epsilon = 0.0661;
//	double sigma = 0.3345;
//
//	double sigma_ovr6 = pow( sigma / distance ,6);
//	double sigma_ovr12 = pow( sigma / distance , 12);
//
//
//
//	double Ur;
//	Ur = 24;
//
//}



