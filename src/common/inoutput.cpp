/***************************************************************************************/  
/* Class of InOutput       */
/***************************************************************************************/  
#ifndef _INOUTPUT_CPP_
#define _INOUTPUT_CPP_

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <vector>
using std::vector;
#include <string>
using std::string;
/***************************************************************************************/ 
#include "inoutput.h"
/***************************************************************************************/  

InOutput::InOutput(){ 
}
/***************************************************************************************/ 
bool InOutput::GetValuesFromInputFile(string ifilename,vector<int>& atomicnumbers){
	bool open_without_problems = true;
	ifstream CrystalInputFile;

   CrystalInputFile.open(ifilename.c_str(),ios::in);

   if (!(CrystalInputFile.good())) {
      cout << "Error: File " << ifilename << "could not be opened...\n";
      return false;
   }

	DiscardComments(CrystalInputFile);
	int periodicity = GetPeriodicity(CrystalInputFile);
	atomicnumbers = GetAtomicNumbers(CrystalInputFile,periodicity);

   CrystalInputFile.close();
	return open_without_problems;
}
/***************************************************************************************/ 
void InOutput::DiscardComments(ifstream &ifil){
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
      if (tl[0]!='#') {
         procnext=false;
         ifil.seekg(prevpos);
      }   
   }   
}
/***************************************************************************************/ 
int InOutput::GetPeriodicity(ifstream &ifil){
	string line;
	getline(ifil,line); // skip the first line
	getline(ifil,line); // get the second line 
	int periodicity = -1;
	if(line=="MOLECULE") periodicity = 0;
	if(line=="POLYMER")  periodicity = 1;
	if(line=="SLAB")     periodicity = 2;
	if(line=="CRYSTAL")  periodicity = 3;

	return periodicity;
}
/***************************************************************************************/ 
vector<int> InOutput::GetAtomicNumbers(ifstream &ifil,int periodicity){
	int Natoms = 0;
	vector<int> atomicnumbers;
	string line;
	ifil.seekg(0);
	if (periodicity == 0){
		for(int i=0;i<3;i++){
			getline(ifil,line); // skip lines
		}
		ifil >> Natoms; 
		atomicnumbers.resize(Natoms,0);
		for(int i=0;i<Natoms;i++){
			ifil >> atomicnumbers[i];
			getline(ifil,line);
		}
	}
	return atomicnumbers;
}
/***************************************************************************************/ 
#endif // _INOUTPUT_CPP_

