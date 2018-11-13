/************************************************************ 
*  Class Atom -Definition                                   *
*  September 2018                                           *
************************************************************/
//---------------------------------------------------------//
#ifndef _CLASSATOM_H_
#define _CLASSATOM_H_
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//---------------------------------------------------------//
class Atom{
public:
// Methods (definitions)
   void ReadAtomGausString(std::string);
   int NameToAtomicNumber(std::string);
   int TypeOrbitalToNumber(std::string);
   void OccupationNumberAssign();
   void PrintAtomCrystString();

private:
// Variables
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

};
//---------------------------------------------------------//
#endif // _ATOM_H_
