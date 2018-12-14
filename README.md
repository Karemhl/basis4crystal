# basis4crystal
basis4crystal is a program that translate the
information contained in the basis set for atoms in Gaussian 
format to atom basis sets in Crystal format.

## Features
Version 1.0 (12/12/2018)

* The program is written in C++, to compile it you must install GCC, CLang 
or other suitable compiler on your computer.
* The program requires an input file that contains information of
  basis set, for one or many atoms,in Gaussian format.
  The input file can be taken directly 
  from the Basis Set Exchange page [EMSL](https://bse.pnl.gov/bse/portal), 
  but requesting the data to be in GAUSSIAN94 format. The data can be copied into a 
  file of any extension.
* The program will read the input file and translate the basis set 
  information into a Crystal basis set format. The result will be shown 
  on screen, however using the flag -s the information will be saved into a file 
  with _basis_crystal.dat appended to the file name. 
* The occupation numbers (the fourth column in the second line for the 
  Crystal basis format) which is set to 0.0, should be written by hand.

## Install
 
1. In the terminal, at the adequate path in your computer, 
   copy this repository with:
   > git clone  https://github.com/Karemhl/basis4crystal.git
2. To compile the program go to src folder and type
   > make
3. To install the program type 
   > sudo make install
4. This generates the executable `basis4crystal`, which is ready to be used.

Note: If problems during the compilation arise, information will be
printed on screen. This should provide enough details to fix
the problems and to render a successful compilation.

## Running basis4crystal

- Unix/Linux/MacOS

1. Go to your local repository where ´translatebasis4crystal´ is.
2. In the terminal, type
   > basis4crystal basis_set_gaussian.dat
3. The basis information in Crystal format will be shown on screen and, if you choice, will be saved
   in the file with _basis_crystal.dat appended to the file name.

## About the Crystal basis format

The program will re-write basis set information to the Crystal format.
Optionally, this information will be saved into
an output file that contains the information ready to be used in the Crystal program 
[CRYSTAL](http://www.crystal.unito.it). 
This basis set format can be used to write the input files where the basis 
set for atoms is desired to be explicitly specified. 
Remember that this version doesn't provide the occupation numbers, 
but they must be written by hand for every atom.

For more information:
 - luis.alfredo.nu@gmail.com 
 - hlk@uaem.mx 

