#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[]) {
	//cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}

	int lineNum = 1;

	Lexer myLexer;
	string line;


	for (string tempLine; getline(in, tempLine);) {
		if (in.eof()) {
			line = line + tempLine;
		}
		else {
			line = line + tempLine + '\n';
			//line.push_back('\n');
		}
	}
	myLexer.getTokens(line, lineNum);
	myLexer.endOfFile();




	//myLexer.printTokens();
	//cout << "-------------------------" << endl;

	Parser myDatalogProgram(myLexer);
	if (myDatalogProgram.parse() == true) {
		cout << "Success!" << endl;
		myDatalogProgram.print();
	}

	return 0;
}