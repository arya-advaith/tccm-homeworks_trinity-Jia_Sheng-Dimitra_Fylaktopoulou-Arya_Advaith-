#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fileopening.c"

int main() {
    FILE* input_file = fopen("inp.txt", "r"); //important command to open the file as a reader "r"
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
   
size_t N=read_Natoms(input_file);
float** coord = malloc_2d(N, 3);
float* mass = malloc(5 * N * sizeof(float));
coord,mass=read_molecule(input_file,  N,coord, mass);
fclose(input_file); // important command to close the file
float** distance = malloc_2d(N,N);
distance=compute_distance(N,coord);
free_2d(coord);
free(mass);
free_2d(distance);
return 0;
}
