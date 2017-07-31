#include"header.h"
/* ----------------------------------------------------------------------------- */
	/*--------------*	   FUNCTIONS FOR HRM CLASS   *-----------------*/
/* ----------------------------------------------------------------------------- */

void HRM::search_employee(int eid)
{
	Profile P;
	ifstream file("Employee_data.dat",ios::binary);
	if(file.fail())
		cout << "Error occured";
	else
	{
		bool found = false;
		while(!file.eof())
		{
			file.read((char *)&P,sizeof(P));
			if(file.eof())
				break;
			if(P.empId == eid)
			{
				P.show_personal_details();
				cout << P;
				found = true;
			}
		}
		if(found == false)
			cout << endl << " RECORD NO :-: " << eid << " :-: IS NOT FOUND!!!" << endl;
	}
	file.close();
}
void HRM::search_employee(char name[])
{
	Profile P;
	ifstream file("Employee_data.dat",ios::binary);
	if(file.fail())
		cout << "Error occured";
	else
	{
		bool found = false;
		while(!file.eof())
		{
			file.read((char *)&P,sizeof(P));
			if(file.eof())
				break;
			int a = P.cmp_name(name);
			if(a == 1)
			{
				P.show_personal_details();
				cout << P;
				found = true;
			}
		}
		if(found == false)
			cout << endl << " RECORD NO :-: " << name << " :-: IS NOT FOUND!!!" << endl;
	}
	file.close();
}
void HRM::Add_employee()
{
	fstream file("Employee_data.dat",ios::in | ios::out | ios::binary | ios::app);
	Profile P;
	if(file.fail())
	{
		cout << "Error in opening a file!...";
		getch();
		HR_SCREEN();
	}
	else
	{
		for(int i=0;i<8;i++)
			cout << endl;
		cout << setw(15);
		for(i=0;i<50;i++)
			cout << '-';
		cout << endl << setw(45) << "CREATE EMPLOYEE" << endl << setw(15);
		for(i=0;i<50;i++)
			cout << '-';
		if(file.read((char *)&P,sizeof(P)))
		{
			file.seekg(-sizeof(P),ios::end);
			file.read((char *)&P,sizeof(P));
			P.get_personal_details();
//			P.create_profile();
			cin >> P;
			file.seekp(0,ios::end);
			file.write((char *)&P,sizeof(P));
		}
		else
		{
			P.get_personal_details();
//			P.create_profile();
			cin >> P;
			file.write((char *)&P,sizeof(P));
		}
		file.close();
		P.create_Login();
		create_atdentry(P.empId);
		create_leave_balance(P.empId);
	}
}
void HRM::Show_employee()
{
	Profile P;
	ifstream file("Employee_data.dat",ios::binary);
	if(file.fail())
		cout << "Error occured in opening a file!";
	else
	{
		while(!file.eof())
		{
			file.read((char *)&P,sizeof(P));
			if(file.eof())
				break;
			P.show_personal_details();
			cout << P;
		}
	}
	file.close();
}
void HRM::remove_employee(int eid)
{
	bool found = false;
	Profile P;
	Login L;
	Leave_Management LM;
	Attendance A;
	ifstream ofile("Employee_data.dat",ios::out | ios::binary);
	fstream nfile("nEmployee_data.dat",ios::in | ios::out | ios::binary | ios::trunc);
	while(!ofile.eof())
	{
		ofile.read((char *)&P,sizeof(P));
		if(ofile.eof())
			break;
		if(P.empId != eid)
		{
			nfile.write((char *)&P,sizeof(P));
		}
		else
		{
			found = true;
		}
	}
	ofile.close();
	nfile.close();
	if(found == true)
	{
		if(remove("Employee_data.dat") == 0)
		{
			if(rename("nEmployee_data.dat","Employee_data.dat")==0)
			{
				cout << setw(35) << eid <<" has been Deleted" << endl;
			}
		}
		L.del_Login(eid);
		LM.delete_balance(eid);
		A.delete_atd(eid);
	}
	else
	{
		cout << setw(35) << eid <<" NOT FOUND!" << endl;
	}
	getch();
	HR_SCREEN();
}
void HRM::show_All()
{
	system("cls");
	Profile P;
	ifstream file("Employee_data.dat",ios::binary);
	if(file.fail())
		cout << "Error occured";
	else
	{
		/*** Show format ***/
		for(int i=0;i<80;i++)
			cout << "-";
		cout<<endl;
		cout.setf(ios::right,ios::adjustfield);
		cout.width(50);
		cout << "ALL EMPLOYEE RECORDS" << endl;
		for(i=0;i<80;i++)
			cout << "-";
		cout<<endl;
		/*** Above Format ***/
		cout << setfill(' ') << setiosflags(ios::adjustfield);
		cout << setw(10) << "#EMP ID";
		cout << setw(16) << "FULL NAME";
		cout << setw(20) << "DESIGNATION";
		cout << setw(12) << "DO'J";
		cout << setw(10) << "SALARY";
		cout << setw(10) << "ROLE";
		cout << endl;
		for(i=0;i<80;i++)
			cout << "-";
		cout << endl;
		while(!file.eof())
		{
			file.read((char *)&P,sizeof(P));
			if(file.eof())
				break;
			P.show_all_details();;
		}
	}
	file.close();
}

void HRM::edit()
{
	Profile P;
	int id;
	system("cls");
	cout << setw(15);
	for(int i=0;i<8;i++)
		cout << endl;
	for(i=0;i<50;i++)
		cout << '-';
	cout << endl;
	cout << setw(55) <<"ENTER EMPLOYEE IF FOR SEARCH" << endl;
	cout << setw(15);
	for(i=0;i<50;i++)
		cout << '-';
	cout << endl;
	cout << setw(40) << "Enter employee id: ";
	cin >> id;
	while(1)
	{
		cout << setw(50) << "EDIT RECORD BY FIELD NAME" << endl;
		cout << setw(35) << "1 -> Name" << endl;
		cout << setw(35) << "2 -> DO'B" << endl;
		cout << setw(35) << "3 -> DO'J" << endl;
		cout << setw(37) << "3 -> Salary" << endl;
		cout << setw(42) << "5 -> Designation" << endl;
		cout << setw(43) << "6 -> Emloyee Role" << endl;
		cout << setw(40) << "0 -> MAIN MENU" << endl;
		cout << endl << setw(50) << "Select Option Value : ";
		int n;
		cin >> n;
		if(n == 0)
			HR_SCREEN();
		P.edit_employee(n,id);
	}
}
void HRM::create_atdentry(int id)
{
	Attendance A(id);
	ofstream file("Attendance_2016.dat",ios::app | ios::binary);
	file.write((char *)&A,sizeof(A));
	cout << A.empId << endl;
	for(int i=0;i<12;i++)
	{
		cout << i << "\t";
		for(int j=0;j<31;j++)
		{
			cout << A.atd[i][j];
		}
		cout << "\n";
	}
	file.close();
}
void HRM::create_leave_balance(int id)
{
	Profile P;
	int cl, ml, el;
	cl = ml = 12, el = 0;
	Leave_Management L(id,cl,el,ml);
	ofstream file("Leaves_Balance.dat",ios::binary | ios::app);
	if(file.fail())
	{
		cout << "Error in opening a file!";
	} else {
		file.write((char *) &L,sizeof(L));
	}
	file.close();
}