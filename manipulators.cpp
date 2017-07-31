#include"header.h"
/* ----------------------------------------------------------------------------- */
	/*	----------	*	   USER DEFINED MANIPULATORS	     *	----------	*/
/* ----------------------------------------------------------------------------- */
ostream & PrintHeader(ostream & TempOut)
{

	TempOut << endl << endl << setw(80) << setfill('-') << '-' << endl;
	TempOut << setw(80) << setfill('-') << '-' << endl;
	TempOut << setw(65) << setfill(' ') << "WELCOME TO HUMAN RESOURSE MANAGEMENT SYSTEM!" << endl;
	TempOut << setw(80) << setfill('-') << '-' << endl;
	TempOut << setw(80) << setfill('-') << '-' << endl << setfill(' ');
	return TempOut;
}
ostream & LogOut(ostream & TempOut)
{
	system("cls");
	for(int i = 0;i<=12;i++)
		TempOut << endl;
	TempOut << endl <<setw(15) << setfill(' ') << ' ' << setw(49) << setiosflags(ios::left) << setfill('-') << '-' << endl;
	TempOut << setw(15) << setfill(' ') << ' ' << setw(49) << setiosflags(ios::left) << setfill('-') << '-';
	cout << setw(20) << setfill(' ') << endl;
	cout << resetiosflags(ios::left) << setw(56) << "You are Succsessfully Logged Out.!";
	TempOut << endl << setw(15) << setfill(' ') << ' ' << setw(49) << setiosflags(ios::left) << setfill('-') << '-' << endl;
	TempOut << setw(15) << setfill(' ') << ' ' << setw(49) << setiosflags(ios::left) << setfill('-') << '-' << endl;
	exit(0);
	return TempOut;
}