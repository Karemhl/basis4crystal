/***************************************************************************************/ 
/*
 * 
 * Class for   
 * Methods
 *
 */
/***************************************************************************************/  
#ifndef _READWRITEFILES_H_
#define _READWRITEFILES_H_
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
/***************************************************************************************/ 
/***************************************************************************************/ 

class ReadWriteFiles{
	/***************************************************************************************/ 
	public:
		ReadWriteFiles();
	// Variables
		vector<string> atoms_string_data_;
	/***************************************************************************************/ 
	// Methods
		bool ReadFile(string);
		bool PrintAndSaveOutput(vector<string>,string,bool);

	/***************************************************************************************/
	/***************************************************************************************/ 
	private:
	// Variables
		bool open_without_problems_ = true;
	/***************************************************************************************/ 
	// Methods
      void DiscardInitialComments(ifstream &);
      bool FindAtom(ifstream &);
      string GetAtomStringData(ifstream &);

	/***************************************************************************************/ 
	/***************************************************************************************/ 
	protected:
};
#endif // _READWRITEFILES_H_
