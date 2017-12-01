#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "inoutput.h"

int main (int argc, char *argv[])
{
	cout << endl << "********************************************************" << endl;
	cout << " Testing for InOutout Class " << endl;
	cout << "********************************************************" << endl << endl;

	InOutput inout;

	string filename = "filetest_metane.d12";
	vector<int>  atomicnumbers;

	bool all_fine = inout.GetValuesFromInputFile(filename,atomicnumbers);

	cout << "All is right ? " << (all_fine ? "Yes":"No") << endl;
	cout << "Number of atoms = " << atomicnumbers.size() << endl;
	for(unsigned int i=0;i<atomicnumbers.size();i++) 
		cout << "Atomic number = " << atomicnumbers[i] << endl;

	return EXIT_SUCCESS;
}


