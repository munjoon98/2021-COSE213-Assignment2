#ifndef CALCULATOR_H
#define CALCULATOR_H

//
// Assignment 2 : Simple calculator using Stack
//
// COSE213 Spring 2021
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#include <iostream>
#include <cassert>
#include <math.h>
#include <string.h>
#include "stack.h"


Stack<double> opr; // stack for operands
Stack<char> opt;   // stack for operators


//
// Modify Eval() below to evaluate the given expression
//
double Eval(char* in)
{

	std::string s;
	double out = 0;

	char buf[1000]; // temp buffer
	char lastToken = '#';

	double operand;
	int i = 0, bi = 0;
	bool una = true;

	//opt.Push('#');

	while (in[i] != '\0')
	{
		char c = in[i];

		// Operators
		if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '(' || c == ')')
		{
			if (bi > 0)
			{
				buf[bi++] = '\0';
				//operand = atof(buf);
				bi = 0;
				std::string str1(buf);
				s += str1;
				s += ' ';

				// push operand
				//std::cout << "New operand : " << operand << std::endl;
				//opr.Push(operand);
			}

			// push operator
			//std::cout << "New operator : " << c << std::endl;
			if (c == '(') opt.Push(c);
			else if (c == ')') {
				while (opt.Top() != '(') {
					s += opt.Top();
					s += ' ';
					opt.Pop();
				}
				opt.Pop();
			}
			else if (c == '*' || c == '/') {
				while (!opt.IsEmpty() && (opt.Top() == '*' || opt.Top() == '/')) {
					s += opt.Top(); s += ' '; opt.Pop();
				}
				opt.Push(c);
			}
			else if (c == '+' || c == '-') {
				for (int k = i - 1; k >= 0; k--) {
					if (in[k] == ' ') continue;
					if (in[k] == '0' || in[k] == '1' ||
						in[k] == '2' || in[k] == '3' ||
						in[k] == '4' || in[k] == '5' ||
						in[k] == '6' || in[k] == '7' ||
						in[k] == '8' || in[k] == '9' || in[k] == ')') {
						una = false; break;
					}
					else {
						una = true; break;
					}
				}
				if (una == true) {
					buf[bi++] = c;
					i++;
					continue;
				}
				while (!(opt.IsEmpty() || opt.Top() == '(')) {
					s += opt.Top(); s += ' '; opt.Pop();
				}
				opt.Push(c);
			}

		}
		// Operands
		else if (c == '0' || c == '1' ||
			c == '2' || c == '3' ||
			c == '4' || c == '5' ||
			c == '6' || c == '7' ||
			c == '8' || c == '9' ||
			c == '.')
		{
			buf[bi++] = c;
		}
		else {}

		i++;
	}

	// push the very last operand if exists
	if (bi > 0)
	{
		buf[bi++] = '\0';
		//operand = atof(buf);
		bi = 0;
		std::string str2(buf);
		s += str2;
		s += ' ';
		// push operand
		//std::cout << "New operand : " << operand << std::endl;
		//opr.Push(operand);
	}
	while (!opt.IsEmpty()) {
		s += opt.Top();
		s += ' ';
		opt.Pop();
	}

	char buff[1000];
	int bii = 0;
	for (int j = 0; j < s.length(); j++) {
		char de = s[j];
		if (de == '0' || de == '1' ||
			de == '2' || de == '3' ||
			de == '4' || de == '5' ||
			de == '6' || de == '7' ||
			de == '8' || de == '9' ||
			de == '.')
		{
			buff[bii++] = de;
		}

		else if (de == '+' || de == '-' ||
			de == '*' || de == '/' ||
			de == '(' || de == ')' || de == ' ')
		{
			if (bii > 0)
			{
				buff[bii++] = '\0';
				operand = atof(buff);
				bii = 0;

				// push operand
				//std::cout << "New operand : " << operand << std::endl;
				opr.Push(operand);
			}
			if (de == ' ') continue;

			// push operator
			//std::cout << "New operator : " << c << std::endl;
			if (de == '-' && (s[j + 1] == '0' || s[j + 1] == '1' ||
				s[j + 1] == '2' || s[j + 1] == '3' ||
				s[j + 1] == '4' || s[j + 1] == '5' ||
				s[j + 1] == '6' || s[j + 1] == '7' ||
				s[j + 1] == '8' || s[j + 1] == '9')) {
				buff[bii++] = '-';
				continue;
			}

			double a1 = opr.Top(); opr.Pop();
			double a2 = opr.Top(); opr.Pop();
			double a3;
			if (de == '+') {
				a3 = a1 + a2;
				opr.Push(a3);
			}
			else if (de == '-') {
				a3 = a2 - a1;
				opr.Push(a3);
			}
			else if (de == '*') {
				a3 = a1 * a2;
				opr.Push(a3);
			}
			else if (de == '/') {
				a3 = a2 / a1;
				opr.Push(a3);
			}


		}

	}
	out = opr.Top();

	return out;
}

#endif
