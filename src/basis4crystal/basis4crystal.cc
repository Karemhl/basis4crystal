#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "optflag.h"
#include "readwritefiles.h"
#include "classAtom.h"

int main (int argc, char *argv[])
{

   OptFlags optflags; optflags.getOptions(argc,argv);

	string inputfilename=argv[argc-1];
	string outputfilename=inputfilename.substr(0, inputfilename.find(".", 0)) +"_crystal_basis.dat";

	ReadWriteFiles readWriteFiles;

	bool all_fine = readWriteFiles.ReadFile(inputfilename);
   if (all_fine){
		
		vector<string> atom_string_Gaussian = readWriteFiles.atoms_string_data_;
		vector<string> atom_string_Crystal(atom_string_Gaussian.size());
      vector<Atom> atoms(atom_string_Gaussian.size());
	
		for(int i=0;i<atom_string_Gaussian.size();i++){
			atoms[i].ReadAtomGaussString(atom_string_Gaussian[i]);
			atom_string_Crystal[i] = atoms[i].PrintAtomCrystString();
		}

		bool output_fine = readWriteFiles.PrintAndSaveOutput(atom_string_Crystal,outputfilename,optflags.save_output_basis);
   }

	return EXIT_SUCCESS;
}


