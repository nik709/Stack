#pragma once

#include "TStack.h"
#include <math.h>

using namespace std;

#define MaxLen 201

class Tparser
{
private:
	char inf[MaxLen];
	char post[MaxLen];
	Tstack <double> st_d;
	Tstack <char> st_c;
public:
	Tparser(char *s=NULL);
	int Priority(char ch);
	bool IsNumber(char ch);
	bool IsOper(char ch);
	double ExNumber(char *s, int &len);
	double FullCalc();
	void Operation(double a, double b, char ch)
	{
		switch (ch)
		{
			case '+': st_d.Push(a + b); break;
			case '-': st_d.Push(a - b); break;
			case '*': st_d.Push(a * b); break;
			case '/': st_d.Push(a / b); break;
			case '^': st_d.Push(pow(a,b)); break;
		}
	}
};



Tparser:: Tparser(char *s): st_d(100), st_c(100)
{
	if (s == NULL)
		inf[0] = '\0';
	else strcpy(inf, s);
}

int Tparser:: Priority(char ch)
{
	int n;
	switch (ch)
	{
		case '(': n = 0;
		case ')': n = 0; break;
		case '+': n = 1;
		case '-': n = 1; break;
		case '*': n = 2;
		case '/': n = 2; break;
		case '^': n = 3; break;
		default: n = -1;
	}
}

bool Tparser:: IsNumber(char ch)
{
	if (ch>='0' && ch<='9')
		return true;
	else return false;
}

bool Tparser:: IsOper(char ch)
{
	if ((ch='+') || (ch='-') || (ch='*') || (ch='/') || (ch='^'))
		return true;
	else return false;
}

double Tparser::ExNumber(char *s, int &len)
{
	int i=0;
	double tmp = atof(s);
	while (IsNumber(s[i]))
		i++;
	len = i;
	return tmp;
}

double Tparser::FullCalc()
{
	st_d.clear();
	st_c.clear();
	st_c.Push('=');
	int i=0;
	int len;
	while (inf[i] !='\0')
	{
		if (IsNumber(inf[i]))
		{
			double tmp = ExNumber(&inf[i], len);
			st_d.Push(tmp);
			i += len - 1;
		}
		else if (inf[i] == '(') 
			st_c.Push(inf[i]);
		else if (inf[i] == ')')
		{
			char tmpc=st_c.Pop();
			while (tmpc != '(')
			{
				double op2 = st_d.Pop();
				double op1 = st_d.Pop();
				Operation(op1, op2, tmpc);
				tmpc = st_c.Pop();
			}
		}
		else if (IsOper(inf[i]))
		{
			char tmpc=st_c.Pop();
			while (Priority(tmpc) >= Priority(inf[i]))
			{
				double op2 = st_d.Pop();
				double op1 = st_d.Pop();
				Operation(op1, op2, tmpc);
				tmpc = st_c.Pop();
			}
			st_c.Push(tmpc);
			st_c.Push(inf[i]);
		}
		i++;
	}			// } to main while
	char tmpc = st_c.Pop();
	while (tmpc != '=')
	{
		double op2 = st_d.Pop();
		double op1 = st_d.Pop();
		Operation(op1, op2, tmpc);
		tmpc = st_c.Pop();
	}
	return st_d.Pop();
}