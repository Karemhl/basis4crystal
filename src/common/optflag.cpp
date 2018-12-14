#ifndef _OPTSFLAG_CPP
#define _OPTSFLAG_CPP

#include "optflag.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
#include <cstdlib>
using std::exit;
#include <string>
using std::string;
#include "screenutils.h"
/***************************************************************************************/  
OptFlags::OptFlags()	{
	save_output_basis = false;
};
/***************************************************************************************/ 
void OptFlags::getOptions(int &argc, char** &argv){
	ScreenUtils scrut;
	if (argc<2) {
      cout << endl;
      scrut.PrintScrStarLine();
      scrut.DisplayErrorMessage("Dont input file ");
      cout << "\t Example:" << argv[0] <<" basis_4_gaussian.dat  "<< endl;
      scrut.PrintScrStarLine();
      cout << endl;
		exit(1);
	}
	for (int i=1; i<argc; i++){
		if (argv[i][0] == '-'){
			switch (argv[i][1]){
				case 's':
					save_output_basis = true;
					break;
				case 'h':
					printHelpMenu(argc,argv);
					exit(0);
					break;
				default:
					cout << "\nCommand line error. Unknown switch: " << argv[i] << endl;
					cout << "\nTry: \n\t" << argv[0] << " -h\n" << endl << "to view the help menu.\n\n";
					exit(1);
			}
		}
	}
}
/***************************************************************************************/  
void OptFlags::printHelpMenu(int &argc, char** &argv){
   string progname=argv[0];
   size_t pos=progname.find("./");
   if (pos!=string::npos) {progname.erase(pos,2);}

	cout << endl;
   cout << "\nUsage:\n\n\t" << progname << " -flag ... -flag basis_4_gaussian.dat \n\n";
   cout << "This program translate the basis set of the gaussian format to crystal format, \n\t and options can be:\n\n"
        << "  -s        \tSave the out of basis for crystal" << endl;
   cout << "  -h        \tDisplays the help menu.\n"<< endl;
}




#endif //_OPTSFLAG_CPP
