#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fileopening.c"
#include "LennardJones.c"
#include "2TotalEnergy.c"
#include "acceleration.c"

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
printf("Time-Step please:\t");
double deltaT;
scanf("%lf",&deltaT);
double** acceleration = malloc_2d(N,3);
double** velocity = malloc_2d(N,3);
double** acc_prev = malloc_2d(N,3);
double** coord_iter = malloc_2d(N,3);
double** vel_iter = malloc_2d(N,3);
double** x = malloc_2d(N,3);
coord_iter=coord;
double** delT = malloc_2d(N,3);
for (int i=0;i<N;i++){
	for (int j=0;j<N;j++){
	delT[i][j]=deltaT;
	}
}

for (int i=0;i<1000;i++){
//printf("The T value is: %f \n", T_value);

vel_iter = velocity;
x=coord_iter;

printf("Iteration number:  %d\n",i+1);
**coord_iter = **coord_iter + **(vel_iter*delT) + **(acceleration) * 0.5 * **(delT*delT);

printf("\nNew coordinates is:\n");
for (int i=0;i<N;i++){
printf("%lf %lf %lf\n",coord_iter[i][0],coord_iter[i][1],coord_iter[i][2]);
}
printf("\n");

//if (x == coord_iter){
//break;}


double** distance=compute_distance(N,coord);
double pot_energy = V(epsilon, sigma, N, distance);
double T_value = T(N, velocity, mass);
double total=E(T_value, pot_energy);
compute_acc(N, coord, mass, distance, acceleration, epsilon, sigma);
**vel_iter = **vel_iter + (0.5)*(**acceleration+**acc_prev)*(**delT);
acc_prev = acceleration;

for (int i=0;i<N;i++){
printf("%lf %lf %lf\n",vel_iter[i][0],vel_iter[i][1],vel_iter[i][2]);
}
printf("\n");

free_2d(distance);
}

free_2d(coord);
free(mass);
free_2d(velocity);
return 0;
}
