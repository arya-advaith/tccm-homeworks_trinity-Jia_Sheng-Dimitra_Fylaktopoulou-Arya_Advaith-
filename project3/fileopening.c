#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

size_t read_Natoms(FILE* input_file) { //it is the input name given by professor to read the input file
    char number[5];
    if (fgets(number, 5, input_file) == NULL) {
        printf("Error reading number of atoms.\n");
        return 0;
    }
    int N;
    sscanf(number, "%d", &N); // finds the number of atoms in the file
    printf("Number of Atoms = %d\n", N);
 return N;
}

double** malloc_2d(size_t m, size_t n){
 double** a = malloc(m*sizeof(double*));
 if (a == NULL){
  return NULL;
 }
 a[0] = malloc(n*m*sizeof(double));
 if (a[0] == NULL) {
  free(a);
  return NULL;
 }
 for (size_t i=1;i<m;i++){
	a[i] = a[i-1]+n;
 }
 return a; 
}


double**  read_molecule(FILE* input_file, size_t N, double** coord, double* mass) {

char cartesian[256]; // just a variable to read the rest of the input file. size cannot be less than 50 i guess.

for (size_t j = 0; j < N; j++) {
        if (fgets(cartesian, sizeof(cartesian), input_file) == NULL) {
            printf("Error reading coordinates and atomic number. Mostly there are more than 4 inputs in a line :/\n");
            return NULL;
        }
        if (sscanf(cartesian, "%lf %lf %lf %lf", &coord[j][0], &coord[j][1], &coord[j][2],&mass[j]) != 4) {                                                                                                   printf("Error parsing coordinates and atomic number. Mostly there are more spaces than required :/ we usually ask only for 1 space between the numbers please \n");
            return NULL;
        }
//        printf("%lf %lf %lf with atomic number as %lf\n", coord[j][0], coord[j][1], coord[j][2], mass[j]);
    }
return coord, mass;
}

double** compute_distance(size_t N, double** coord) {

double** distance = malloc_2d(N,N);
//printf("\n The distance matrix is given below:\n ");

for (int i=0;i<N;i++){
	for (int j=0;j<N;j++){
             distance[i][j] = (coord[i][0]-coord[j][0])*(coord[i][0]-coord[j][0]);
	     distance[i][j] = distance[i][j]+(coord[i][1]-coord[j][1])*(coord[i][1]-coord[j][1]);
	     distance[i][j] = distance[i][j]+(coord[i][2]-coord[j][2])*(coord[i][2]-coord[j][2]);
	     distance[i][j]=sqrt(distance[i][j]);
	}
// printf("%lf %lf %lf\n",distance[i][0],distance[i][1],distance[i][2]);
}
//printf("\n");
return distance;
}

void free_2d(double** a){
free(a[0]);
a[0]=NULL;
free(a);
}
