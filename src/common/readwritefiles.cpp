/***************************************************************************************/  
/* Class of ReadWriteFiles       */
/***************************************************************************************/  
#ifndef _READWRITEFILES_CPP_
#define _READWRITEFILES_CPP_

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <vector>
using std::vector;
#include <string>
using std::string;
/***************************************************************************************/ 
#include "readwritefiles.h"
/***************************************************************************************/  

ReadWriteFiles::ReadWriteFiles(){
	atoms_string_data_.clear();
}
/***************************************************************************************/ 
bool ReadWriteFiles::ReadFile(string infilename){
	
	ifstream GaussianBasisInputFile;
	GaussianBasisInputFile.open(infilename.c_str(),ios::in);

	if (!(GaussianBasisInputFile.good())) {
      cout << "Error: File " << infilename << "could not be opened...\n";
      return false;
   }

   
   while( FindAtom(GaussianBasisInputFile) ){
      atoms_string_data_.push_back( GetAtomStringData(GaussianBasisInputFile));
   }

	GaussianBasisInputFile.close();
	return open_without_problems_;
}
/***************************************************************************************/  
void ReadWriteFiles::DiscardInitialComments(ifstream &ifil){
   string tl; 
   int prevpos;
   bool procnext=true;
   while (procnext) {
      prevpos=ifil.tellg();
      getline(ifil,tl);
      while (tl.length()==0) {
         getline(ifil,tl);
         if (ifil.eof()) {return;}
      }   
      while((tl[0]==' ')||(tl[0]=='\t')){tl.erase(0,1);}
      if (tl[0]!='!') {
         procnext=false;
         ifil.seekg(prevpos);
      }   
   }   
}
/***************************************************************************************/ 
bool ReadWriteFiles::FindAtom(ifstream &ifil){
   string line;
   bool findatom = false;
   bool endchunk = false;
   int prevpos;
   while(!ifil.eof()){
      getline(ifil,line);
      if(line.substr(0,4) == "****"){
         if (endchunk){
            ifil.seekg(prevpos);
            return findatom=true;
         }
         endchunk = true; 
         prevpos = ifil.tellg();
      }
   }

   return findatom;
}
/***************************************************************************************/ 
string ReadWriteFiles::GetAtomStringData(ifstream &ifil){
   int prevpos;
   string atomdata;
   string line;
   getline(ifil,line);
   while(line.substr(0,4) != "****"){
      prevpos=ifil.tellg();
      atomdata += line + '\n';
      getline(ifil,line);
   }
   ifil.seekg(prevpos);

   return atomdata;
}
/***************************************************************************************/  
bool ReadWriteFiles::PrintAndSaveOutput(vector<string> output_crystal_, string CrystalBasisOutputFileName,bool save_output){
   
	cout << "Transale the Basis Set from Gaussan format to Crystal format" << endl;
	for (int i=0;i<output_crystal_.size();i++)
   	cout << output_crystal_[i];
   if (save_output){
      ofstream CrystalBasisOutputFile(CrystalBasisOutputFileName.c_str());

      if ( !CrystalBasisOutputFile.good() ) {
         cout << "Error while opening the file " << CrystalBasisOutputFileName << endl;
         cout << __FILE__ << ", line: " << __LINE__ << endl;
         CrystalBasisOutputFile.close();
         return false;
      }
      for (int i=0;i<output_crystal_.size();i++)
         CrystalBasisOutputFile << output_crystal_[i];

      CrystalBasisOutputFile.close();
   }

   return true;
}
/***************************************************************************************/ 
/***************************************************************************************/ 
#endif // _READWRITEFILES_CPP_

