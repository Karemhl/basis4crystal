#ifndef _OPTSFLAG_H
#define _OPTSFLAG_H

#include <string>
using std::string;

class OptFlags{
	public:
		OptFlags();
				
		bool save_output_basis;

		void getOptions(int &argc, char** &argv);
		void printHelpMenu(int &argc, char** &argv); 

};


#endif //_OPTSFLAG_H
