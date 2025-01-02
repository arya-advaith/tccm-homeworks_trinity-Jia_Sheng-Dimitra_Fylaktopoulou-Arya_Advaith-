void compute_acc(
	size_t Natoms,
	double** coord,
	double* mass,
	double** distance,
	double** acceleration,
	double epsilon,
	double sigma) {


         printf("This function calculate the acceleration.\n");	

	for (int atom = 0; atom < Natoms; atom++) {             // i 

		for (int comp = 0; comp < 3; comp++) {        // acceleration comp x, y,  and z

			double sigma_ovr6 = 0;
			double sigma_ovr12 = 0;
			double ur = 0;
			double sum = 0;

			for (int anoth_atom = 0; anoth_atom < Natoms; anoth_atom++) {
				if (atom != anoth_atom) {                                   // non diagonal atom value     // j

					sigma_ovr6 = pow(sigma / distance[atom][anoth_atom], 6);
					sigma_ovr12 = pow(sigma / distance[atom][anoth_atom], 12);

					//printf("The distance value is: %f\n", distance[atom][anoth_atom]);


					ur = 24 * (epsilon / distance[atom][anoth_atom]) * (sigma_ovr6 - 2 * sigma_ovr12);
					//printf("The ur value is: %f\n",ur);

					sum += ur * ((coord[atom][comp] - coord[anoth_atom][comp]) / distance[atom][anoth_atom]);
					//printf("The sum value is: %f\n", sum);
				
					
				}
			}
			acceleration[atom][comp] = (- sum / mass[atom]);

			//printf("[%d][%d]", atom, comp);
			//printf("newloop acceleration is: %f\n\n", acceleration[atom][comp]);
		}

		
	}


	// check value
	for (int i = 0; i < Natoms; i++) {   // change i, j  to number of Natoms    // i = atom number i                                         // j = x(j0) , y(j1) ,z(j2) component
		for (int j = 0; j < 3; j++) {
			printf("[%d][%d]", i, j);
			printf("The acceleration is: %f\n", acceleration[i][j]);
		}

	}

}
