double** Verlet(
	size_t Natoms,
	double** coord,
	double** velocity,
	double** acceleration_previous,
	double** acceleration_current) {

	//printf("\n-------------start function Verlet-----------------\n");

	//double epsilon = 0.0661;
	//double sigma = 0.3345;

	// fixed parameters
	double time_step = 0.2;


	/*double new_coord[3][3];
	double new_velocity[3][3];
	double new_acceleration_previous[3][3];
	double new_acceleration_current[3][3];*/


	for (int i = 0; i < Natoms; i++) {    // i is the atom number 1, atom 2, atom 3
		for (int j = 0; j < 3; j++){      // j is the coordinate x, coordy , coord z

			// Position update
			/*printf("coordinate:%f\n", coord[i][j]);
			printf("velocity:%f\n", velocity[i][j]);
			printf("acceleration_current:%f\n", acceleration_current[i][j]);
			printf("acceleration_previous:%f\n", acceleration_previous[i][j]);*/

			coord[i][j] = coord[i][j] + (velocity[i][j] * time_step) + (acceleration_previous[i][j] * (pow(time_step, 2) / 2));
			

			// Velocity update
			velocity[i][j] = velocity[i][j] + 0.5 * (acceleration_previous[i][j] + acceleration_current[i][j]) * time_step;
		}
	}

	// print to see array
	for (int i = 0; i < Natoms; i++) {   // change i, j  to number of Natoms    // i = atom number i                                         // j = x(j0) , y(j1) ,z(j2) component
		for (int j = 0; j < 3; j++) {
			//printf("[%d][%d]", i, j);
			//printf("new position coordinate is: %f\n", coord[i][j]);
		}

	}

	// Print the new velocities of the atoms
	for (int i = 0; i < Natoms; i++) {   // change i, j  to number of Natoms    // i = atom number i                                         // j = x(j0) , y(j1) ,z(j2) component
		for (int j = 0; j < 3; j++) {
			//printf("[%d][%d]", i, j);
			//printf("new velocity is: %f\n\n", velocity[i][j]);
		}

	}




	//printf("\n-------------end function Verlet-----------------\n");
	// Return updated arrays for position, velocity and acceleration
	return coord, velocity, acceleration_previous, acceleration_current;

}
