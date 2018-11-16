// Test to check if all is working well with class_Atom

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "classAtom.h"

int main(){
// String for test 
std::string gauss_string("C 0\nS 2 1.00\n3047.5249000 0.0018347\n457.3695100 0.0140373\nSP 3 1.00\n7.8682724 -0.1193324 0.0689991\n1.8812885 -0.1608542 0.3164240\n0.5442493 1.1434564 0.7443083\nP 1 1.00\n0.1687144 1.0000000\nSP 1 1.00\n3.8682724 1.1193324 3.2689991");

// Default constructor
Atom A;
// Reading and assigning values to the object A
A.ReadAtomGaussString(gauss_string);

// Check if everything is going well
// A.PrintObjectVariables();

// Check on screen
// Print the Crystal Format of the object A
   std::cout << "Gauss format string: " << "\n"
             << gauss_string << "\n" << std::endl;

   std::cout << "Crystal format string: " << "\n" 
             << A.PrintAtomCrystString() << std::endl;
}
