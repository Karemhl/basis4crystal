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
// Methods (declaration)
   void ReadAtomGaussString(std::string);
   std::string PrintAtomCrystString();
   int NameToAtomicNumber(std::string);
private:
// Variables 
   std::string atomic_symbol_;
   int atomic_number_;
   int charge_;
   int gauss_parameter_{0};
   std::vector<std::string> orbital_type_;
   std::vector<int> num_orbital_type_;
   std::vector<int> num_gauss_;
   double cryst_contrac_factor_{1.0};
   std::vector<std::vector<double>> alpha_exp_;
   std::vector<std::vector<double>> coefs_num_;
   std::vector<std::vector<double>> coefs_sp_num_;
   int num_shells_; 
   std::vector<double> occ_numbers_;
// Methods 
//   int NameToAtomicNumber(std::string);
   int TypeOrbitalToNumber(std::string);
   std::vector<double> OccupationNumberAssign(std::vector<std::string>, int);

};
//---------------------------------------------------------//
#endif // _ATOM_H_
