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
   int AssignAtomicNumber(std::string);
   int AssignOrbitalTypeNumber(std::string);
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

// Definition of the functions of the class Atom

// This part need to be tested apart
void Atom::ReadAtomGaussString(std::string gauss_string){
    std::string line;
    
    std::getline (gauss_string, line);
    
    while(std::getline(gauss_string, line)){
    std::string tOrbitalActual;
    int nGaussActual;
    std::istringstream line1(line);
        line1 >> tOrbitalActual >> nGaussActual;
    tOrbital.push_back(tOrbitalActual);
    nGauss.push_back(nGaussActual);
      for(int i = 0; i<nGaussActual; i++){
        std::getline(inStream, line);
      }
    }
    
}













  
