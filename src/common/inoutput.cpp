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
	ifstream CrystalInputFile;

   CrystalInputFile.open(ifilename.c_str(),ios::in);

   if (!(CrystalInputFile.good())) {
      cout << "Error: File " << ifilename << "could not be opened...\n";
      return false;
   }

	DiscardComments(CrystalInputFile);
	int periodicity = GetPeriodicity(CrystalInputFile);
	if(periodicity > -1){
		atomicnumbers = GetAtomicNumbers(CrystalInputFile,periodicity);
		DiscardRepeatedElements(atomicnumbers);
	}else{
		cout << " Periodicity dont recognize " << endl ;
		cout << " Must be: MOLECULAR" << endl;
		cout << "          POLYMER" << endl;
		cout << "          SLAB" << endl;
		cout << "          CRYSTAL" << endl;
		open_without_problems = false;
	}

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
	}
	if (periodicity == 1 || periodicity == 2){
		for(int i=0;i<4;i++){
			getline(ifil,line); // skip lines
		}
	}
	if (periodicity == 3){
		for(int i=0;i<5;i++){
			getline(ifil,line); // skip lines
		}
	}
	ifil >> Natoms; 
	atomicnumbers.resize(Natoms,0);
	for(int i=0;i<Natoms;i++){
		ifil >> atomicnumbers[i];
		getline(ifil,line);
		if(ifil.fail()){
			atomicnumbers[i] = -1;
			open_without_problems = false;
			cout << " Insufficient atoms in the list " << endl;
		}
	}
	return atomicnumbers;
}
/***************************************************************************************/ 
void InOutput::DiscardRepeatedElements(vector<int> & atomicnumbers){

	int i=0,j=0;
	while(i < atomicnumbers.size()){
		j = i+1;
		while(j < atomicnumbers.size()){
			if(atomicnumbers[i] == atomicnumbers[j]){
				atomicnumbers.erase(atomicnumbers.begin()+j);
				j -= 1;
			}
			j++;
		}
		i++;
	}
}
/***************************************************************************************/ 
#endif // _INOUTPUT_CPP_

