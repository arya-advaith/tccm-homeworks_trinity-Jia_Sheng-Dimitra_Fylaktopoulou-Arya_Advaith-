# Project 3: Molecular Dynamics Simulation

## Project Description
The project simulates molecular dynamics using classical mechanics. The program calculates the total energy of a system atoms based on their atomic coordinates, masses and veocities. It includes calculations for kinetic energy, potential energy (via Lennard Jones potential), and total energy of the system. The simulation can be used to study the behavior of atoms and their interactions in molecular dynamics systems.

## File Descriptions

'fileopening.c': The file is responsible for handling the input file that contains atomic data, including the number of atoms, their 3D coordinates (x,y,z) and their respective masses. The file contains functions that efficiently parse the input file, allocate necessary memory, and compute pairwise distances between atoms.

'LennardJones.c': Implements the Lennard-Jones potential calculation for atomic interactions. The VLJ function computes the potential energy between two atoms bases on their distance, while the V function calculates the potential energy of the system by summing up pairwise interactions.

'totalenergy.c': Is responsible for calculating the total energy of a molecular system. The total energy is the sum of the kinetic energy (T) and the potential energy (V) of the system. Specifically, the file contains the functios to compute the kinetic energy based on the velocities and masses of the atoms, and a function to compute the total energy by adding the kinetic and potential energy.

'acceleration.c' Computes the acceleration of each atom using the Lennard-Jones potential. It iterates over all atom pairs to calculate forces and updates the acceleration components for each atom based on Newton's second law. The function uses the input parameter for atomic positions, masses and internuclear distances.

'distance.c': Acts as the main program for the molecular dynamics simulation. It integrates various components of the simulaton, including reading atomic data, computing distances, updating positions and velocities using the Verlet algorithm, and calculating the total energy of the system. It uses input files for initialization.
