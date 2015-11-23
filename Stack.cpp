// Stack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TStack.h"
#include "Tparser.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char st[6] = { '2', '+', '5', '*', '2', '\0' };
	Tparser infin(st);
	double d;
	d = infin.FullCalc();
	cout << d<<'\n';
	return 0;
}

