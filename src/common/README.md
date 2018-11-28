# translatebasis
TransBasisGauss2Crystal is a program that translate the
information contained in the basis set for atoms in Gaussian 
format to atom basis sets in Crystal format.

## Features
Version 1.0 (11/30/2018)

* The program requires an input file with information in Gaussian format
  basis set for one or many atoms. The input file can be taken directly 
  from the Basis Set Exchange page [EMSL](https://bse.pnl.gov/bse/portal), 
  specifiying the data in GAUSSIAN94 format and copying the result in a 
  file with any kind of extension.
* The program will read the input file and translate the basis set 
  information into a Crystal basis set format. The result will be shown 
  on screen and will be saved in a file with the name of the input file 
  with the extension: crysb.
* The occupation numbers (the fourth column in the second line for the 
  Crystal basis format) which is set to 0.0, should be written by hand.

## Compilation 
 
1. In the terminal, in the desired direcction in your computer, 
   copy the remote repository from:
   [translatebasis](https://bitbucket.org/Frodox14/
                    translatebasis4crystal/src/master/src)
2. To compile the files type in
   > make
3. Now the executable:`traslatebasis.x` is ready to be used.

Note: In case of problems of compilation, enought information on 
screen will be given to fix it and make a successful compilation.

## Running translatebasis

- Unix/Linux/MacOS
1. Go to your local repository where ´translatebasis4crystal´ is.
2. In the terminal, type in
    >./traslatebasis.x 
   and then type in the name of the file (or the direction and 
   name of the file).
3. The Crystal format will be shown on screen and will be saved
   in the file with extension crysb.

## About the Crystal basis format

The program will give an output file with extension crysb that
contains the information of the basis set for an atom or a set 
of atoms in the format to be used in Crystal program 
[CRYSTAL](http://www.crystal.unito.it). Therefore this basis 
set format can be used to write the input files where the basis 
set for atoms is desired to be explicit specified. 
Remember that this version doesn't put the occupation numbers, 
so they must be written by hand for every atom.

For more information:
 - luis.alfredo.nu@gmail.com 
 - hlk@uaem.mx 
