# basis4crystal
basis4crystal is a program that translate the
information contained in the basis set for atoms in Gaussian 
format to atom basis sets in Crystal format.

## Features
Version 1.0 (12/12/2018)

* The program is written in C++, for compilation you must have GCC, CLang 
  or other suitable compilator on your computer.
* The program requires an input file with information in Gaussian format
  basis set for one or many atoms. The input file can be taken directly 
  from the Basis Set Exchange page [EMSL](https://bse.pnl.gov/bse/portal), 
  specifiying the data in GAUSSIAN94 format and copying the result in a 
  file with any kind of extension.
* The program will read the input file and translate the basis set 
  information into a Crystal basis set format. The result will be shown 
  on screen; using the flag -s the information will be saved in a file 
  with _basis_crystal.dat append to the file name. 
* The occupation numbers (the fourth column in the second line for the 
  Crystal basis format) which is set to 0.0, should be written by hand.

## Compilation 
 
1. In the terminal, in the desired direcction in your computer, 
   copy the remote repository from:
   [basis4crystal](https://github.com/Karemhl/basis4crystal).
2. To compile the files type in
   > make install
3. Now the executable:`basis4crystal` is ready to be used.

Note: In case of problems of compilation, enought information on 
screen will be given to fix it and make a successful compilation.

## Running basis4crystal

- Unix/Linux/MacOS

1. Go to your local repository where ´translatebasis4crystal´ is.
2. In the terminal, type in
    >./basis4crystal
   and then type in the name of the file (or the direction and 
   name of the file).
3. The Crystal format will be shown on screen and will be saved
   in the file with extension crysb.

## About the Crystal basis format

The program will give the Crystal format basis set and/or the 
output file that contains the information to be used in Crystal program 
[CRYSTAL](http://www.crystal.unito.it). Therefore this basis 
set format can be used to write the input files where the basis 
set for atoms is desired to be explicit specified. 
Remember that this version doesn't put the occupation numbers, 
so they must be written by hand for every atom.

For more information:
 - luis.alfredo.nu@gmail.com 
 - hlk@uaem.mx 

