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
	atomsStringData.clear();
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
      atomsStringData.push_back( GetAtomStringData(GaussianBasisInputFile));
   }

	GaussianBasisInputFile.close();
	return open_without_problems;
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
/***************************************************************************************/ 
#endif // _READWRITEFILES_CPP_

