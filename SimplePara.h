/*
#pragma once
#include "Parameter.h"
#include "Token.h"
#include <iostream>
#include <string>

using namespace std;

class SimplePara : public Parameter {
private:
	bool type = true; // True is ID, False is STRING
	string _parameter;

public:
	SimplePara(void) {};
	~SimplePara(void) {};

	bool setParameter(unsigned int& tracker, vector<Token> tokenList, bool& pass) {
		if (tokenList.at(tracker).getTokenCode() == 13) {
			type = true;
		}
		else {
			type = false;
		}
		_parameter = tokenList.at(tracker).getTokenValue();
		++tracker;
		return pass;
	}

	virtual string toString() {
		return _parameter;
	}

};
*/