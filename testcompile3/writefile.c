double Writefile(size_t Natoms, 
	double KE ,
	double PE, 
	double TE, 
	double** coord) {

	

	/*
	* The formatting of the .xyz file format is as follows: 
	* <number of atoms>
      comment line
      <element> <X> <Y> <Z>
	* 
	* 
	* 3 
	* KE	PE	TE
	* Ar	0.0		0.0		0.0
	* Ar	0.0		0.0		0.5
	* Ar	0.1		0.2		-0.5
	* 
	* 3 (new)
	* KE	PE	    TE
	* Ar	0.0		0.0		0.0
	* Ar	0.0		0.0		0.5
	* Ar	0.1		0.2		-0.5
	
	*/

	FILE* fptr;
	fptr = fopen("output.xyz","a");

	// Natoms
	fprintf(fptr, "%d", Natoms);fputs("\n", fptr);
	// Comment: KE, PE, TE
	fprintf(fptr, "%lf", KE); fputs("\t", fptr);fprintf(fptr, "%lf", PE);fputs("\t", fptr);fprintf(fptr, "%lf", TE);fputs("\n", fptr);
	//fprintf(fptr, "%d", Natoms);fputs("\t", fptr);fprintf(fptr, "%d", Natoms);fputs("\t", fptr);fputs("\n", fptr);
	//atom1 x y z
	//atom2 x y z
	//atom3 x y z
	fprintf(fptr,"Ar");fputs("\t", fptr); fprintf(fptr, "%lf", coord[0][0]);fputs("\t", fptr);fprintf(fptr, "%lf", coord[0][1]);fputs("\t", fptr);fprintf(fptr, "%lf", coord[0][2]);fputs("\n", fptr);
	fprintf(fptr, "Ar");fputs("\t", fptr); fprintf(fptr, "%lf", coord[1][0]);fputs("\t", fptr);fprintf(fptr, "%lf", coord[1][1]);fputs("\t", fptr);fprintf(fptr, "%lf", coord[1][2]);fputs("\n", fptr);
	fprintf(fptr, "Ar");fputs("\t", fptr); fprintf(fptr, "%lf", coord[2][0]);fputs("\t", fptr);fprintf(fptr, "%lf", coord[2][1]);fputs("\t", fptr);fprintf(fptr, "%lf", coord[2][2]);fputs("\n", fptr);
    fputs("\n", fptr);  //New line


	fclose(fptr);

}