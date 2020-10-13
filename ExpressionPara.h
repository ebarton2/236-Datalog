/*
#pragma once
#include "Parameter.h"
#include "Token.h"
#include <iostream>
#include <string>

using namespace std;

class ExpressionPara : public Parameter {
private:
	string op;
	Parameter* leftParameter;
	Parameter* rightParameter;

	bool fillParameter(unsigned int& tracker, vector<Token> tokenList, bool& pass) {
		if ((tokenList.at(tracker).getTokenCode() != 3) // LEFT_PAREN
			|| (tokenList.at(tracker).getTokenCode() != 4) // RIGHT_PAREN
			|| (tokenList.at(tracker).getTokenCode() != 13) // ID
			|| (tokenList.at(tracker).getTokenCode() != 14)) // STRING
		{
			pass = false;
			return pass;
		}

		// FIRST CHECK -> ID STRING expression(LEFT_PAREN)
		if ((tokenList.at(tracker).getTokenCode() == 13)
			|| (tokenList.at(tracker).getTokenCode() == 14)) // Checks if current item is a string or ID
		{
			leftParameter = new SimplePara;
			if (!(leftParameter->setParameter(tracker, tokenList, pass))) { return pass; }
			// NOTE setParameter increments the tracker +1
		}
		else if (tokenList.at(tracker).getTokenCode() == 3) {
			++tracker;
			leftParameter = new ExpressionPara;
			//leftParameter->setParameter(tracker, tokenList, pass);
			if (!(leftParameter->setParameter(tracker, tokenList, pass))) {
				pass = false;
				return pass;
			}
		}

		// SECOND CHECK -> operators
		if ((tokenList.at(tracker).getTokenCode() == 7) // MULTIPLY
			|| (tokenList.at(tracker).getTokenCode() == 8)) // ADD
		{
			op = tokenList.at(tracker).getTokenValue();
			++tracker;
		}
		else {
			pass = false;
			return pass;
		}

		// THIRD CHECK -> ID STRING expression(LEFT_PAREN)
		if ((tokenList.at(tracker).getTokenCode() == 13)
			|| (tokenList.at(tracker).getTokenCode() == 14)) // Checks if current item is a string or ID
		{
			rightParameter = new SimplePara;
			if (!(rightParameter->setParameter(tracker, tokenList, pass))) { return pass; }
			// NOTE setParameter increments the tracker +1
		}
		else if (tokenList.at(tracker).getTokenCode() == 3) {
			++tracker;
			rightParameter = new ExpressionPara;
			if (!(rightParameter->setParameter(tracker, tokenList, pass))) {
				pass = false;
				return pass;
			}
		}

		// FINAL CHECK -> RIGHT_PAREN
		if (tokenList.at(tracker).getTokenCode() == 4) {
			++tracker;
			pass = true;
			return pass;
		}
		else {
			pass = false;
			return pass;
		}

		return pass;
	}


public:
	ExpressionPara(void) {};
	~ExpressionPara(void) { /*delete leftParameter; delete rightParameter; };

	bool setParameter(unsigned int& tracker, vector<Token> tokenList, bool& pass) {
		if (tokenList.at(tracker).getTokenCode() != 3) {
			pass = false;
			return pass;
		}
		else {
			++tracker;
			if (fillParameter(tracker, tokenList, pass) != true) { // MIGHT BE AN ERROR POINT
				pass = false;
				return pass;
			}
		}
		return pass;
	}



	virtual string toString() {
		string temp;
		temp += '(';
		temp += leftParameter->toString();
		temp += ' ';
		temp += op;
		temp += ' ';
		temp += rightParameter->toString();
		temp += ')';
		return temp;
	}

};
*/