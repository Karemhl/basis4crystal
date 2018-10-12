#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "readWriteFiles.h"

int main (int argc, char *argv[])
{
	cout << endl << "********************************************************" << endl;
	cout << " Testing for ReadWriteFiles Class " << endl;
	cout << "********************************************************" << endl << endl;

	string inputfilename="H-C-O-6311G.basisG";
	string outputfilename="H-C-O-6311G.basisCry";

	ReadWriteFiles readWriteFiles;

	bool all_fine = readWriteFiles.ReadFile(inputfilename);

	return EXIT_SUCCESS;
}


