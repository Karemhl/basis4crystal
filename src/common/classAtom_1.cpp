// Class Atom
// September 2018
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Atom
{
public:

// Declaration of functions
   void ReadAtomGaussString(std::string);
   int NameToAtomicNumber(std::string);
   int TypeOrbitalToNumber(std::string);
   void PrintAtomCrystString();

private:

// Declaration of variables
   std::string atomic_symbol_;
   int atomic_number_;
   int gauss_paramter_{0};
   std::vector<std::string> orbital_type_;
   std::vector<int> num_orbital_type_;
   std::vector<int> num_gauss_;
   int cryst_contrac_factor_{1.0};
   std:::vector<std::vector<double>> alpha_exp_;
   std:::vector<std::vector<double>> coefs_num_;
   int num_shells_; 
   double occupation_number_;
}

// Definition (and explanation) of the functions of the class Atom

// Function ReadAtomGaussString takes as an argument a
// string in Gauss format and extract from it all the
// information needed assigning each value to its
// corresponding private member.
// Definition
void Atom::ReadAtomGaussString(std::string gauss_string){
    
}

// Function NameToAtomicNumber take as an argument  a string
// "atomic_symbol_" and return an int value assigned to
// "atomic_number_".
// Definition
int Atom::NameToAtomicNumber(std::vector<std::string>){

}

// Function TypeOrbitalToNumber take as an argument a vector
// of string "orbital_type_" and return a vector of int
// values "num_orbital_type_". For every type of shell we
// assign a int value (all is in the vector array).
// Definition
int Atom::TypeOrbitalToNumber(std::vector<std::string>){

}

// Fuction PrintAtomCrystString take all the information of
// a given atom (created by the default constructor) and write all 
// the info via X.member_name to give as a return variable a
// string in Crystal format.
// Definition
std::string Atom::PrintAtomCrystString(){

}




  
