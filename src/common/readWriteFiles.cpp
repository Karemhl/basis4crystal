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
#include "readWriteFiles.h"
/***************************************************************************************/  

ReadWriteFiles::ReadWriteFiles(){
	atomData.clear();
}
/***************************************************************************************/ 
bool ReadWriteFiles::ReadFile(string infilename){
	
	ifstream GaussianBasisInputFile;
	GaussianBasisInputFile.open(infilename.c_str(),ios::in);

	if (!(GaussianBasisInputFile.good())) {
      cout << "Error: File " << infilename << "could not be opened...\n";
      return false;
   }

	DiscardComments(GaussianBasisInputFile);

	cout << GaussianBasisInputFile.rdbuf();

	GaussianBasisInputFile.close();
	return open_without_problems;
}
/***************************************************************************************/  
void ReadWriteFiles::DiscardComments(ifstream &ifil){
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
/***************************************************************************************/ 
#endif // _READWRITEFILES_CPP_

