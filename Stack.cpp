// Stack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tparser.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char str[MaxLen];
	int comand;
	for (;;)
	{
		cout<<"1 - Vvod stroki\n";
		cout<<"2 - Full Calc\n";
		cout<<"3 - Int To Post\n";
		cout<<"4 - Calc Post\n";
		cout<<"\nVvedite comandu: ";
		cin>>comand;
		switch (comand)
		{
			case 1:
				{
					cout<<"Vvedite stroku: ";
					str[0]='\0';
					cin>>str;
					cout<<"\n";
					break;
				}
			case 2:
				{
					TParser parser(str);
					double d=parser.FullCalc();
					cout<<"Full Calc: "<<d<<"\n\n";
					break;
				}
			case 3:
				{
					TParser parser(str);
					parser.InfToPost();
					cout<<parser<<"\n";
					break;
				}
			case 4:
				{
					TParser parser(str);
					parser.InfToPost();
					double d = parser.CalcPost();
					cout<<"Calc Post: "<<d<<"\n\n";
					break;
				}
		}
	}
	return 0;
}

