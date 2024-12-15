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
   
   read_Natoms(input_file);
   fclose(input_file); // important command to close the file
    
    return 0;
}
