# Project 3: Molecular Dynamics Simulation

## Project Description
The project simulates molecular dynamics using classical mechanics. The program calculates the total energy of a system atoms based on their atomic coordinates, masses and veocities. It includes calculations for kinetic energy, potential energy (via Lennard Jones potential), and total energy of the system. The simulation can be used to study the behavior of atoms and their interactions in molecular dynamics systems.


To compile this code using a gnu C/C++ compiler, and create an executable called 'MD.exe' in the Linux environment, type

`make`

Then, to run the program, type

`./MD.exe`



## Directory Structure
### 'project1/'
This directory contains files for project 1 not related to our project (project 3).

### 'project2/'
This directory contains files for project 2 nor related to our project.

### 'project3/'
Contains the core code for the simulation, including the files below.


## File Descriptions

'**inp.txt'** Input data file with atomic coordinates (x, y, z) and their atomic mass.

**'fileopening.c'**: The file is responsible for handling the input file that contains atomic data, including the number of atoms, their 3D coordinates (x,y,z) and their respective masses. The file contains functions that efficiently parse the input file, allocate necessary memory, and compute pairwise distances between atoms.


**'LennardJones.c'**: Implements the Lennard-Jones potential calculation for atomic interactions. The VLJ function computes the potential energy between two atoms bases on their distance, while the V function calculates the potential energy of the system by summing up pairwise interactions.

**'totalenergy.c'**: Is responsible for calculating the total energy of a molecular system. The total energy is the sum of the kinetic energy (T) and the potential energy (V) of the system. Specifically, the file contains the functios to compute the kinetic energy based on the velocities and masses of the atoms, and a function to compute the total energy by adding the kinetic and potential energy.

**'acceleration.c'**: Computes the acceleration of each atom using the Lennard-Jones potential. It iterates over all atom pairs to calculate forces and updates the acceleration components for each atom based on Newton's second law. The function uses the input parameter for atomic positions, masses and internuclear distances.

**distance.c'**: Acts as the main program for the molecular dynamics simulation. It integrates various components of the simulaton, including reading atomic data, computing distances, updating positions and velocities using the Verlet algorithm, and calculating the total energy of the system. It uses input files for initialization.

### 'testcompile3/'
## Files

**'LennardJones.c'**,
**'TotalEnergy.c'**,
**'Verlet.c'**,
**'a.out'**,
**'acceleration.c'**,
**'distancecalc.c'**,
**fileopening.c'**,
**'inp.txt'**,
**'output.xyz'**: contains the results of the simulation runs,
**'output1.xyz'**: same, 
**writefile.c**: is designed to write atom data (such as coordinates and energy values) to an .xyz file format. Specifically, it appends data to a file called output.xyz,
**'a.out'**: compiled executable for testing

### 'testcompile/'
Contains modified code for testing.  The directory includes the files below.
**'LennardJones.c'**,
TotalEnergy.c,
a.out2 days ago,
acceleration.c,
distancecal.c,
fileopening.c,
inp.txt

### 'LICENSE' 
This license allows you to copy, modify, and restribute the file under the same terms, ensuring it remains free and open-source. 

### 'README.md'
A description of the project and its structure.

### 'test.txt', 'test2.txt'
Test files.


The Molecular dynamics for the 3 Argon atoms viewed in Jmol are as follow:

Initial Coordinates
![image alt](https://github.com/arya-advaith/tccm-homeworks_trinity-Jia_Sheng-Dimitra_Fylaktopoulou-Arya_Advaith-/blob/79d3fdd45f7aed3cc443565b6fd20f7f22c5266c/MD_initial.png)

Final coordinates
![image alt](https://github.com/arya-advaith/tccm-homeworks_trinity-Jia_Sheng-Dimitra_Fylaktopoulou-Arya_Advaith-/blob/79d3fdd45f7aed3cc443565b6fd20f7f22c5266c/MD_final.png)







