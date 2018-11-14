#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "readwritefiles.h"

int main (int argc, char *argv[])
{
	cout << endl << "********************************************************" << endl;
	cout << " Testing for ReadWriteFiles Class " << endl;
	cout << "********************************************************" << endl;

	string inputfilename="H-C-N-O-631G.basisG";
	string outputfilename="H-C-O-6311G.basisCry";

	ReadWriteFiles readWriteFiles;

	bool all_fine = readWriteFiles.ReadFile(inputfilename);
   if (all_fine){
		
		vector<string> atom_string_Gaussian = readWriteFiles.atoms_string_data_;
      
		for(int i=0;i<atom_string_Gaussian.size();i++){
      	cout << "Atom "<<i<<endl<< atom_string_Gaussian[i]<<endl;
      }

		vector<string> atom_string_Crystal = atom_string_Gaussian;
		bool output_fine = readWriteFiles.PrintAndSaveOutput(atom_string_Gaussian,outputfilename);
   }

	return EXIT_SUCCESS;
}


