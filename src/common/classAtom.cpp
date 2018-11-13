/************************************************************
*   Class Atom - Methods                                    *
*   September 2018                                          * 
************************************************************/
//---------------------------------------------------------//
#ifndef _CLASSATOM_CPP_
#define _CLASSATOM_CPP_
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//---------------------------------------------------------//
#include "classAtom.h"
//---------------------------------------------------------//
//---------------------------------------------------------//
// Definition (and explanation) of the Methods
//---------------------------------------------------------//
//---------------------------------------------------------//
// Function ReadAtomGaussString takes as an argument a
// string in Gauss format and extract from it all the
// information needed assigning each value to its
// corresponding private member.
//---------------------------------------------------------//
// Definition
//---------------------------------------------------------//
void Atom::ReadAtomGaussString(std::string &gauss_string){

  int charge_;
  std::string atomic_symbol_;
  std::vector<std::string> orbital_type_;
  std::vector<int> num_gauss_;
  std::vector<std::vector<double>> alpha_exp_;
  std::vector<std::vector<double>> coefs_num_;
  std::vector<std::vector<double>> coefs_sp_num_;
  std::string symbol;
  int charge;
//---------------------------------------------------------//      
   std::istringstream gauss_format(gauss_string);
   gauss_format.ignore(4,'\n');
//---------------------------------------------------------//
   gauss_format.seekg(0, gauss_format.cur) >> symbol;
   atomic_symbol_=symbol;
//---------------------------------------------------------//
   gauss_format.seekg(1, gauss_format.cur) >> charge;
   charge_=charge;
//---------------------------------------------------------//
   std::string lines;
   std::getline(gauss_format, lines);
//---------------------------------------------------------//
   while (std::getline(gauss_format, lines)){
    double expAlpha_actual, coeff_actual, coeff_sp_actual;
    std::string orb_t_actual;
    int gauss_n_actual;
    std::istringstream line1(lines);
//---------------------------------------------------------//
    line1 >> orb_t_actual >> gauss_n_actual;
    orbital_type_.push_back(orb_t_actual);
    num_gauss_.push_back(gauss_n_actual);
//---------------------------------------------------------//
     std::vector<double> alpha_actual_shell;
    std::vector<double> coefs_actual_shell;
    std::vector<double> coefs_sp_actual_shell;
    for(int i = 0; i < gauss_n_actual; i++){
       std::string num_lines;
       std::getline(gauss_format,num_lines);
       std::istringstream numbers(num_lines);
       numbers >> expAlpha_actual >> coeff_actual >> coeff_sp_actual;
       alpha_actual_shell.push_back(expAlpha_actual);
       coefs_actual_shell.push_back(coeff_actual);
       coefs_sp_actual_shell.push_back(coeff_sp_actual);
     }
     alpha_exp_.push_back(alpha_actual_shell);
     coefs_num_.push_back(coefs_actual_shell);
     coefs_sp_num_.push_back(coefs_sp_actual_shell);
   }
   
   // Erase the last elements of the vectors (****) 
   orbital_type_.erase(orbital_type_.end() - 1);
   alpha_exp_.erase(alpha_exp_.end() - 1);
   coefs_num_.erase(coefs_num_.end() - 1);
   coefs_sp_num_.erase(coefs_sp_num_.end() - 1);
}

//---------------------------------------------------------//
//---------------------------------------------------------//
// Function NameToAtomicNumber take as an argument  a string
// "atomic_symbol_" and return an int value assigned to
// "atomic_number_".
//---------------------------------------------------------//
// Definition
//---------------------------------------------------------//
int Atom::NameToAtomicNumber(std::string atom_name){
long atomicN[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
               15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
               27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 
               39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
               51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 
               63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 
               75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 
               87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 
               99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
              109, 110, 111, 112, 113, 114, 115, 116, 117, 118};

      if(atom_name == "H"){ return atomicN[0]; }
      else if(atom_name == "He"){ return atomicN[1]; }
      else if(atom_name == "Li"){ return atomicN[2]; }
      else if(atom_name == "Be"){ return atomicN[3]; }
      else if(atom_name == "B"){ return atomicN[4]; }
      else if(atom_name == "C"){ return atomicN[5]; }
      else if(atom_name == "N"){ return atomicN[6]; }
      else if(atom_name == "O"){ return atomicN[7]; }
      else if(atom_name == "F"){ return atomicN[8]; }
      else if(atom_name == "Ne"){ return atomicN[9]; }
      else if(atom_name == "Na"){ return atomicN[10]; }
      else if(atom_name == "Mg"){ return atomicN[11]; }
      else if(atom_name == "Al"){ return atomicN[12]; }
      else if(atom_name == "Si"){ return atomicN[13]; }
      else if(atom_name == "P"){ return atomicN[14]; }
      else if(atom_name == "S"){ return atomicN[15]; }
      else if(atom_name == "Cl"){ return atomicN[16]; }
      else if(atom_name == "Ar"){ return atomicN[17]; }
      else if(atom_name == "K"){ return atomicN[18]; }
      else if(atom_name == "Ca"){ return atomicN[19]; }
      else if(atom_name == "Sc"){ return atomicN[20]; }
      else if(atom_name == "Ti"){ return atomicN[21]; }
      else if(atom_name == "V"){ return atomicN[22]; }
      else if(atom_name == "Cr"){ return atomicN[23]; }
      else if(atom_name == "Mn"){ return atomicN[24]; }
      else if(atom_name == "Fe"){ return atomicN[25]; }
      else if(atom_name == "Co"){ return atomicN[26]; }
      else if(atom_name == "Ni"){ return atomicN[27]; }
      else if(atom_name == "Cu"){ return atomicN[28]; }
      else if(atom_name == "Zn"){ return atomicN[29]; }
      else if(atom_name == "Ga"){ return atomicN[30]; }
      else if(atom_name == "Ge"){ return atomicN[31]; }
      else if(atom_name == "As"){ return atomicN[32]; }
      else if(atom_name == "Se"){ return atomicN[33]; }
      else if(atom_name == "Br"){ return atomicN[34]; }
      else if(atom_name == "Kr"){ return atomicN[35]; }
      else if(atom_name == "Rb"){ return atomicN[36]; }
      else if(atom_name == "Sr"){ return atomicN[37]; }
      else if(atom_name == "Y"){ return atomicN[38]; }
      else if(atom_name == "Zr"){ return atomicN[39]; }
      else if(atom_name == "Nb"){ return atomicN[40]; }
      else if(atom_name == "Mo"){ return atomicN[41]; }
      else if(atom_name == "Tc"){ return atomicN[42]; }
      else if(atom_name == "Ru"){ return atomicN[43]; }
      else if(atom_name == "Rh"){ return atomicN[44]; }
      else if(atom_name == "Pd"){ return atomicN[45]; }
      else if(atom_name == "Ag"){ return atomicN[46]; }
      else if(atom_name == "Cd"){ return atomicN[47]; }
      else if(atom_name == "In"){ return atomicN[48]; }
      else if(atom_name == "Sn"){ return atomicN[49]; }
      else if(atom_name == "Sb"){ return atomicN[50]; }
      else if(atom_name == "Te"){ return atomicN[51]; }
      else if(atom_name == "I"){ return atomicN[52]; }
      else if(atom_name == "Xe"){ return atomicN[53]; }
      else if(atom_name == "Cs"){ return atomicN[54]; }
      else if(atom_name == "Ba"){ return atomicN[55]; }
      else if(atom_name == "La"){ return atomicN[56]; }
      else if(atom_name == "Ce"){ return atomicN[57]; }
      else if(atom_name == "Pr"){ return atomicN[58]; }
      else if(atom_name == "Nd"){ return atomicN[59]; }
      else if(atom_name == "Pm"){ return atomicN[60]; }
      else if(atom_name == "Sm"){ return atomicN[61]; }
      else if(atom_name == "Eu"){ return atomicN[62]; }
      else if(atom_name == "Gd"){ return atomicN[63]; }
      else if(atom_name == "Tb"){ return atomicN[64]; }
      else if(atom_name == "Dy"){ return atomicN[65]; }
      else if(atom_name == "Ho"){ return atomicN[66]; }
      else if(atom_name == "Er"){ return atomicN[67]; }
      else if(atom_name == "Tm"){ return atomicN[68]; }
      else if(atom_name == "Yb"){ return atomicN[69]; }
      else if(atom_name == "Lu"){ return atomicN[70]; }
      else if(atom_name == "Hf"){ return atomicN[71]; }
      else if(atom_name == "Ta"){ return atomicN[72]; }
      else if(atom_name == "W"){ return atomicN[73]; }
      else if(atom_name == "Re"){ return atomicN[74]; }
      else if(atom_name == "Os"){ return atomicN[75]; }
      else if(atom_name == "Ir"){ return atomicN[76]; }
      else if(atom_name == "Pt"){ return atomicN[77]; }
      else if(atom_name == "Au"){ return atomicN[78]; }
      else if(atom_name == "Hg"){ return atomicN[79]; }
      else if(atom_name == "Tl"){ return atomicN[80]; }
      else if(atom_name == "Pb"){ return atomicN[81]; }
      else if(atom_name == "Bi"){ return atomicN[82]; }
      else if(atom_name == "Po"){ return atomicN[83]; }
      else if(atom_name == "At"){ return atomicN[84]; }
      else if(atom_name == "Rn"){ return atomicN[85]; }
      else if(atom_name == "Fr"){ return atomicN[86]; }
      else if(atom_name == "Ra"){ return atomicN[87]; }
      else if(atom_name == "Ac"){ return atomicN[88]; }
      else if(atom_name == "Th"){ return atomicN[89]; }
      else if(atom_name == "Pa"){ return atomicN[90]; }
      else if(atom_name == "U"){ return atomicN[91]; }
      else if(atom_name == "Np"){ return atomicN[92]; }
      else if(atom_name == "Pu"){ return atomicN[93]; }
      else if(atom_name == "Am"){ return atomicN[94]; }
      else if(atom_name == "Cm"){ return atomicN[95]; }
      else if(atom_name == "Bk"){ return atomicN[96]; }
      else if(atom_name == "Cf"){ return atomicN[97]; }
      else if(atom_name == "Es"){ return atomicN[98]; }
      else if(atom_name == "Fm"){ return atomicN[99]; }
      else if(atom_name == "Md"){ return atomicN[100]; }
      else if(atom_name == "No"){ return atomicN[101]; }
      else if(atom_name == "Lr"){ return atomicN[102]; }
      else if(atom_name == "Rf"){ return atomicN[103]; }
      else if(atom_name == "Db"){ return atomicN[104]; }
      else if(atom_name == "Sg"){ return atomicN[105]; }
      else if(atom_name == "Bh"){ return atomicN[106]; }
      else if(atom_name == "Hs"){ return atomicN[107]; }
      else if(atom_name == "Mt"){ return atomicN[108]; }
      else if(atom_name == "Ds"){ return atomicN[109]; }
      else if(atom_name == "Rg"){ return atomicN[110]; }
      else if(atom_name == "Cn"){ return atomicN[111]; }
      else if(atom_name == "Nh"){ return atomicN[112]; }
      else if(atom_name == "Fl"){ return atomicN[113]; }
      else if(atom_name == "Mc"){ return atomicN[114]; }
      else if(atom_name == "Lv"){ return atomicN[115]; }
      else if(atom_name == "Ts"){ return atomicN[116]; }
      else if(atom_name == "Og"){ return atomicN[117]; }
      else{ return 0;}
}

//---------------------------------------------------------//
//---------------------------------------------------------//
// Function TypeOrbitalToNumber take as an argument a vector
// of string "orbital_type_" and return a vector of int
// values "num_orbital_type_". For every type of shell we
// assign a int value (all is in the vector array).
//---------------------------------------------------------//
// Definition
//---------------------------------------------------------//
int Atom::TypeOrbitalToNumber(std::string shellType){

     if (shellType == "S"){return 0;}
     else if (shellType == "SP"){return 1;}
     else if (shellType == "P"){return 2;}
     else if (shellType == "D"){return 3;}
     else if (shellType == "F"){return 4;}
     else if (shellType == "G"){return 5;}
}

//---------------------------------------------------------//
//---------------------------------------------------------//
// Function OccupationNumberAssign takes from the screen 
// the number of electros for each shell.
//---------------------------------------------------------//
// Definition
//---------------------------------------------------------//
void Atom::OccupationNumberAssign(){
    

}

//---------------------------------------------------------//
//---------------------------------------------------------//
// Fuction PrintAtomCrystString take all the information of
// a given atom (created by the default constructor) and 
// write all the info via X.member_name to give as a return 
// variable a string in Crystal format.
//---------------------------------------------------------//
// Definition
//---------------------------------------------------------//
std::string Atom::PrintAtomCrystString(){

}
//---------------------------------------------------------//
//---------------------------------------------------------//
#endif // _CLASSATOM_CPP_
  
