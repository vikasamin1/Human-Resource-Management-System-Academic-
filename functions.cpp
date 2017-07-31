#include"header.h"
/* ----------------------------------------------------------------------------- */
/*	--------------------*	   GLOBAL FUNCTIONS	     *------------------------	 */
/* ----------------------------------------------------------------------------- */
void LOGIN()
{
	int user;
	char pass[15];
	while(true)
	{
		cout << PrintHeader;
		for(int i=0;i<10;i++)
			cout << endl;
		cout << setw(40) << "Username : ";
		cin >> user;
		cout << setw(40) << "Password : ";
		for(i=0;pass[i-1]!=13;i++)
		{
			pass[i] = getch();
			cout << "*";	
		}
		pass[i] = '\0';
		Login L;
		try{
			L.user_login(user,pass);
		}
		catch(MyException E1)
		{
			E1 << cout;
			getch();
		}
		system("cls");
	}
}
void ADMN_SCREEN()
{
	system("cls");
	Administrator A;
	Attendance T;
	T.take_attendance(elid);
	while(1)
	{
		system("cls");
		int n;
		cout << PrintHeader;
		for(int i=0;i<8;i++)
			cout << endl;
		cout.width(48);
		cout << "1. View Login Ids" << endl;
		cout.width(40);
		cout << "0. Logout" << endl << endl;
		cout.width(46);
		cout << "Select Option : ";
		cin >> n;
		switch(n)
		{
			case 1:
				A.read_Login();
				break;
			case 0:
				cout << LogOut;
				break;
			default:
				cout << endl << setw(48) << "Enter Proper Option" << endl;
		}
		getch();
		flushall();
	}
}
void EMP_SCREEN()
{
	system("cls");
	Leave_Management L;
	Attendance A;
	Profile P;
	Employee E;
	Salary S;
	A.take_attendance(elid);
	while(1)
	{
		cout << PrintHeader;
		for(int i=0;i<8;i++)
			cout << endl;
		cout << setw(50) << "1. View Personal Details" << endl;
		cout << setw(44) << "2. Apply for leave" << endl;
		cout << setw(48) << "3. View Leave Balances" << endl;
		cout << setw(59) << "4. Check Status of Leaves Applied" << endl;
		cout << setw(45) << "5. View Salary slip" << endl;
		cout << setw(35) << "0. Logout" << endl;
		cout << endl << setw(44) << "Select Option : ";
		int optn;
		cin >> optn;
		switch(optn)
		{
			case 1:
				E.view_emp_info(elid);
				break;
			case 2:
				L.leave_apply(elid);
				break;
			case 3:
				L.leave_balance_employee(elid);
				break;
			case 4:
				L.find_employee(elid);
				break;
			case 5:
				{
					try{
						system("cls");
						int temp;
						cout << setw(54) << "1. Salary Slip for last Month" << endl;
						cout << setw(60)<< "2. Salary Slip for Particular Month" << endl;
						cout << endl << setw(49) << "Choose Option : ";
						cin >> temp;
						if(temp==1)
						{
							S.salary_slip(elid, gmtm->tm_mon-1);
						}
						else
						{
							int a;
							cout << "Enter Month : ";
							cin >> a;
							S.salary_slip(elid, a-1);
						}
					}
					catch(MyException E1)
					{
						E1 << cout;
					}
				}
				break;
			case 0:
				cout << LogOut;
				break;
			default:
				cout.width(48);
				cout << endl << "Enter Proper Option..!" << endl;
		}
		getch();
		system("cls");
	}
}
void HR_SCREEN()
{
	system("cls");
	HRM H;
	Leave_Management L;
	Attendance A;
	//A.take_attendance(elid);
	while(1)
	{
		cout << PrintHeader;
		for(int i=0;i<8;i++)
			cout << endl;
		cout.width(55);
		cout << "1. Create New Employee Record" << endl;
		cout.width(51);
		cout << "2. Update Employee Record" << endl;
		cout.width(51);
		cout << "3. Delete Employee Record" << endl;
		cout.width(50);
		cout << "4. Show Employee Records" << endl;
		cout.width(51);
		cout << "5. Search Employee Record" << endl;
		cout.width(56);
		cout << "6. Approve from applied Leaves" << endl;
		cout.width(50);
		cout << "7. Generate Salary slips" << endl;
		cout.width(35);
		cout << "0. Logout" << endl;
		int n;
		cout << endl; cout.width(47);
		cout << "Select options : ";
		cin >> n;
		switch(n)
		{
			case 1:
				system("cls");
				H.Add_employee();
				break;
			case 2:
				system("cls");
				H.edit();
				break;
			case 3:
				system("cls");
				flushall();
				H.show_All();
				int id;
				cout << endl << setw(55) << "Enter employee id want to delete : ";
				cin >> id;
				H.remove_employee(id);
				H.show_All();
				break;
			case 4:
				system("cls");
				H.show_All();
				break;
			case 5:
				{
					system("cls");
					cout << "1. Searh By Employee Id" << endl;
					cout << "2. Searh By Employee Name" << endl;
					cout << "Select Search Option : " << endl;
					int i;
					cin >> i;
					if(i == 1)
					{	
						int id;
						cout << setw(55) << "Enter the Employee id for search : ";
						cin >> id;
						H.search_employee(id);
					}else if(i == 2) {
						char sname[30];
						cout << setw(55) << "Enter the Employee Name for search : ";
						cin >> sname;
						H.search_employee(sname);
					} else {
						cout << "Select Valid option!";
					}
				}
				break;
			case 6:
				system("cls");
				L.approve_leaves();
				break;
			case 7:
				{
					system("cls");
					Salary S;
					S.salary_entry();
				}
				break;
			case 0:
				cout << LogOut;
			default:
				cout.width(48);
				cout << "Select proper option!!!!";
		}
		flushall();
		getch();
		system("cls");
	}
}

/* ----------------------------------------------------------------------------- */
	/*	------------*	   FUNCTIONS OF PERSON CLASS   *------------------	 */
/* ----------------------------------------------------------------------------- */


void Person::get_personal_details()
{
	cout << endl << setw(35) << "First Name : ";
	cin >> fname;
	cout << setw(36) << "Second Name : ";
	cin >> mname;
	cout << setw(34) << "Last Name : ";
	cin >> lname;
	cout << setw(41) << "Do'B (dd/mm/yyyy): ";
	cin >> dob;
	cout << setw(41) << "Do'J (dd/mm/yyyy): ";
	cin >> doj;
	cout << endl << setw(39) << "---- ADDRESS ----";
	cout << endl << setw(27) << "HN : ";
	cin.getline(A.HN,10);
	cout << endl << setw(32) << "Society : ";
	cin.getline(A.soc,30);
	cout << endl << setw(33) << "Locality : ";
	cin.getline(A.local,20);
	cout << endl << setw(32) << "Pincode : ";
	cin.getline(A.pincode,8);
}
void Person::show_personal_details()
{
	cout << endl << setw(55) << "- EMPLOYEE PERSONAL DETAILS -" << endl;
	cout << endl << setw(30) << "Full Name : " << fname << " " << mname << " " << lname;
	cout << endl << setw(25) << "Do'B : " << dob;
	cout << endl << setw(25)  << "Do'J : " << doj << setw(30) << "-: ADDRESS :-" << endl;
	cout << endl << setw(50)  << "HN : " << A.HN;
	cout << endl << setw(55)  << "Society : " << A.soc;
	cout << endl << setw(56)  << "Locality : " << A.local;
	cout << endl << setw(55)  << "Pincode : " << A.pincode << endl;
}


/* ----------------------------------------------------------------------------- */
	/*--------------*	   FUNCTIONS FOR PROFILE CLASS   *-----------------*/
/* ----------------------------------------------------------------------------- */

void Profile::create_Login()
{	
	char pass[14] = "pass1234";
	ofstream file("Login_details.dat",ios::binary | ios::app);
	if(file.fail())
		cout << "Error occured while opening a file";
	Login create(empId, pass, eRole);
	file.write((char *)&create,sizeof(create));
	file.close();	
	cout << "Login is also created successfully\n with default password!";
}
void Profile::show_all_details()
{
	setfill(' ');
	cout << setw(8) << setiosflags(ios::left) << empId;
	cout << setw(10) <<fname << " " << setw(3) << mname << " " << setw(8) << lname;
	cout << setw(15) << Designation;
	cout << setw(12) << doj;
	cout << setw(10) << showpoint << Basic_Salary;
	cout << setw(10) << setiosflags(ios::left);
	if(eRole == 1)
		cout << "ADMIN";
	else if(eRole == 2)
		cout << "HR";
	else if(eRole == 3)
		cout << "EMPLOYEE";
	cout << endl;
}
void Profile::edit_employee(int n, int eid)
{
	
	fstream file("Employee_data.dat",ios::in | ios::out | ios::binary);
	bool found = false;
	while(!file.eof())
	{
		file.read((char *)this,sizeof(Profile));
		if(empId == eid)
		{
			found = true;
			if(n==1)
			{
					cout << setw(42) << "Enter First Name : ";
					cin >> fname;
					cout << setw(43) << "Enter Middle name : ";
					cin >> mname;
					cout << setw(41) << "Enter Last name : ";
					cin >> lname;
			}
			else if(n==2)
			{
					cout << setw(36) << "Enter DO'B : ";
					cin >> dob;
			}else if(n==3)
			{
			
					cout << setw(36) << "Enter DO'J : ";
					cin >> doj;
			}else if(n==4){
				
					cout << setw(38) << "Basic_Salary : ";
					cin >> Basic_Salary;
			}else if(n==5)
			{
					cout << setw(37) << "Designation : ";
					cin >> Designation;
			}else if(n==6){
					cout << endl << setw(37) << "1. ADMIN";
					cout << endl << setw(34) << "2. HR";
					cout << endl << setw(40) << "3. EMPLOYEE";
					cout << endl << setw(45) << "Enter Employee Role: ";
					cin >> eRole;
			}
			else{
					file.close();
					HR_SCREEN();
			}
			file.seekp(-sizeof(Profile),ios::cur);
			file.write((char *)this,sizeof(Profile));
			Login L;
			L.update_login(empId,eRole);
			break;
		}
	}
	if(found == false){
		cout << setw(35) << eid <<" ID NOT FOUND!";
	}
	getch();
	file.close();
	HR_SCREEN();
}
void Profile::view_emp()
{
	for(int i=0;i<10;i++)
		cout << endl;
	setfill(' ');
	cout << setw(15);
	for(i=0;i<50;i++)
		cout << '-';
	cout << endl << setw(51) << "YOUR PERSONAL INFORMATION" << endl;
	cout << setw(15);
	for(i=0;i<50;i++)
		cout << '-';
	cout << endl;
	cout << endl << setw(25) << "#EMPID :  " << empId << endl; 
	cout << endl << setw(28) << "Full Name :  " << fname << " " << mname << " " << lname << endl;
	cout << endl << setw(23) << "DO'B :  " << dob << endl;
	cout << endl << setw(23) << "DO'J :  " << doj << endl;
	cout << endl << setw(30) << "Designation :  "<< Designation << endl;
	cout << endl << setw(28) << "Basic Pay :  " << Basic_Salary << endl;
	cout << endl << setw(60) <<"-: ADDRESS :-" << endl;
	cout << endl << setw(48) << "House No :  " << A.HN << endl;
	cout << endl << setw(47) << "Society :  " << A.soc << endl;
	cout << endl << setw(47) << "Locality : " << A.local << endl;
	cout << endl << setw(47) << "Pincode :  " << A.pincode << endl;
}


/* ----------------------------------------------------------------------------- */
	/*--------------*	   FUNCTIONS FOR LOGIN CLASS   *-----------------*/
/* ----------------------------------------------------------------------------- */
Login::Login()
{
	userid = 0;
	password[0] = '\0';
	role = 0;
}
Login::Login(int Uid, char Epass[], int Erole)
{
	userid = Uid;
	strcpy(password,Epass);
	role = Erole;
}
void Login::update_login(int eid, int erole)		
{
	fstream file("Login_details.dat",ios::in | ios::out | ios::binary);
	while(!file.eof())
	{
		file.read((char *)this,sizeof(Login));
		if(file.eof())
			break;
		if(userid == eid)
		{
			role = erole;
			file.seekp(-sizeof(Login),ios::cur);
			file.write((char *)this,sizeof(Login));
			getch();
			break;
		}
	}
	file.close();
	cout << setw(30) << userid << " RECORD SUCCESSFULLY UPDATED!";
}
void Login::header_login()
{
	for(int i=0;i<7;i++)
		cout << endl;
	cout << setw(10);
	for(i=0;i<60;i++)
		cout << '-';
	cout << endl;
	cout << setw(17) << "#USERID";
	cout << setw(20) << "PASSWORD";
	cout << setw(10) << "ROLE" << endl;
	cout << setw(10);
	for(i=0;i<60;i++)
		cout << '-';
	cout << endl;
}
void Login::output()
{
	setw(10);
	setiosflags(ios::right);
	cout << setw(17) << userid <<  setw(20) << password << setw(10);
	if(role == 1)
		cout << "ADMIN";
	else if(role == 2)
		cout << "HR";
	else
		cout << "EMPLOYEE";
	cout << endl;
}	
void Login::del_Login(int eid)
{
	fstream ofile("Login_details.dat",ios::out | ios::binary);
	ofstream nfile("tLogin_details.dat",ios::binary);
	if(!nfile.is_open())
		cout << "Error Occured !";
	while(!ofile.eof())
	{
		ofile.read((char *)this, sizeof(Login));
		if(ofile.eof())
			break;
		if(userid != eid)
		{
			nfile.write((char *)this,sizeof(Login));
		}
	}
	ofile.close();
	nfile.close();
	if(remove("Login_details.dat") == 0)
	{
		if(rename("tLogin_details.dat","Login_details.dat") == 0)
		{
			cout << endl << setw(28) << eid << " Login Record has been Deleted!";
		}
	}
	getch();
}
void Login::update_password()
{
	int eid;
	flushall();
	fstream file("LoginDetails.dat",ios::in | ios::out | ios::binary);
	cout << "Enter EMP. ID for new password record.";
	cin >> eid;
	file.seekg(0, ios::beg);
	header_login();
	while(!file.eof())
	{		
		file.read((char *)this, sizeof(Login));
		output();
		if(userid == eid)
		{
			file.seekp(-sizeof(this), ios::cur);
			cout << "Enter new password : "; cin >> password;
			file.write((char *) this, sizeof(Login));
			break;
		}
		file.close();
	}
	/*file.close();
	while(!file.eof())
	{
		file.read((char *) this,sizeof(Login));
		output();
		if(userid == eid)
		{
			file.seekp(-sizeof(Login),ios::cur);
			cout << "Enter new password";
			cin >> password;
			file.write((char *) this,sizeof(Login));
			break;
		}
	}
	file.close();*/
}
void Login::user_login(int user, char pass[])
{
	bool found = false;
	ifstream file("Login_details.dat",ios::binary);
	while(!file.eof())
	{
		file.read((char *)this, sizeof(Login));
		if(file.eof())
			break;
		if(userid == user)
		{
			if(strcmp(pass, password) == 1)
			{
				elid = userid;
				found = true;
				cout << role;
				switch(role)
				{
					case 1:
						ADMN_SCREEN();
						break;
					case 2:
						HR_SCREEN();
						break;
					case 3:
						EMP_SCREEN();
						break;
				}
			}
		}
	}
	if(found == false)
	{
		MyException E1(404,"Incorrect Userid Or Password");
		throw E1;
	}
	getch();
	file.close();
}



/* ----------------------------------------------------------------------------- */
/*	--------------*		 ADMINISTRATOR CLASS FUNCTIONS	       *---------------- */
/* ----------------------------------------------------------------------------- */


void Administrator::read_Login()
{
	Login V;
	ifstream file("Login_details.dat",ios::out | ios::binary);
	file.seekg(0, ios::beg);
	V.header_login();
	while(!file.eof())
	{		
		file.read((char *)&V,sizeof(V));
		if(file.eof())
			break;
		V.output();
	}
	file.close();
	getch();
	ADMN_SCREEN();
}


/* ----------------------------------------------------------------------------- */
/*	--------------*		 EMPLOYEE CLASS FUNCTIONS	       *---------------- */
/* ----------------------------------------------------------------------------- */


void Employee::view_emp_info(int id)
{
	Profile P;
	ifstream file("Employee_data.dat",ios::binary);
	if(file.fail())
		cout << "Error in opening file";
	else
	{
		while(!file.eof())
		{
			file.read((char *)&P,sizeof(P));
			if(P.empId == id)
			{
				system("cls");
				P.view_emp();
				break;
			}
		}
	}
	file.close();
}


/* ----------------------------------------------------------------------------- */
/* ----------------- LEAVE MANAGEMENT CLASS FUNCTIONS -------------------------- */
/* ----------------------------------------------------------------------------- */

Leave_Management::Leave_Management()
{
	id = 0;		
	cl = 0;
	el = 0;
	ml = 0;
	sdd = 0;
	smm = 0;
	edd = 0;
	emm = 0;
	status = 0;
}
Leave_Management::Leave_Management(int i,int c,int e, int m) 
{
	id = i;		//Constructor for creating leave balance
	cl = c;
	el = e;
	ml = m;
}
Leave_Management::Leave_Management(int i, int c, int e, int m, int s, int sd , int sm, int ed, int em) 
{
	id = i;		// Constructor for leave apply
	cl = c;
	el = e;
	ml = m;
	sdd = sd;
	smm = sm;
	edd = ed;
	emm = em;
	status = s;
}
void Leave_Management::format()
{
	cout << setw(25);
	for(int i=0;i<30;i++)
		cout << '-';
	cout << endl;
	cout << setw(28) << "#ID" << setw(6) << setw(8) << " " << "CL" << setw(7) << "EL" << setw(7) << "ML" << endl;
	cout << setw(25);
	for( i=0;i<30;i++)
		cout << '-';
	cout << endl;
}
void Leave_Management::leaves_report()
{
	cout << setw(30) << id;
	cout << setw(8) << cl;
	cout << setw(7) << el;
	cout << setw(7) << ml << endl;
}
void Leave_Management::view_leaves()
{
	ifstream file("Leaves_Balance.dat",ios::binary);
	if(file.fail())
	{
		cout << "Error in opening a file!";
	} else {
		format();
		while(!file.eof())
		{
			file.read((char *) this,sizeof(Leave_Management));
			if(file.eof())
				break;
			leaves_report();
		}
	}
	file.close();
}
void Leave_Management::leave_balance_employee(int i)
{
	
	ifstream file("Leaves_Balance.dat",ios::binary);
	if(file.fail()){	
		cout << "Error in opening a file!";
	} else {
		while(!file.eof())
		{
			file.read((char *) this,sizeof(Leave_Management));
			if(id == i)
			{
				cout << setw(45) << "LEAVE BALANCE FOR " << id << endl;
				format();
				leaves_report();
				break;
			}
		}
		file.close();
	}
}
void Leave_Management::deduct_leaves(int eid, int c, int e, int m)
{
	fstream file("Leaves_Balance.dat",ios::in | ios::out | ios::binary);
	while(!file.eof())
	{
		file.read((char *) this,sizeof(Leave_Management));
		if(id == eid)
		{
			cl -= c;
			el -= e;
			ml -= m;
			file.seekp(-sizeof(Leave_Management), ios::cur);
			file.write((char *) this, sizeof(Leave_Management));
			break;
		}
	}
}
void Leave_Management::leave_apply(int i)
{
	ifstream file("Leaves_Balance.dat",ios::binary);
	ofstream file1("applied_leaves.dat",ios::binary | ios::app | ios::in | ios::out);
	if(file.fail() || file1.fail())
	{	
		cout << "Error in opening a file!";
	} else {
		while(!file.eof())
		{
			file.read((char *) this,sizeof(Leave_Management));
			if(id == i)
			{
				format();
				leaves_report();
				cout << "1. Casual Leave" << endl;
				cout << "2. Earned Leave" << endl;
				cout << "3. Medical Leave" << endl;
				cout << " . Exit";
				cout << "select option which leave to apply";
				int optn, day;
				cin >> optn;
				if(optn == 1){
					cout << "Enter days for Applying Casual Leaves : ";
					cin >> day;
					if(day > cl)
					{
						cout << "day should be less than balance leaves";
						getch();
						exit(0);
					}
					else
					{
						if(day > 1)
						{
							cout << "Start Date : ";
							cin >> sdd;
							cout << '-';
							cin >> smm;
							cout << "End Date : ";
							cin >> edd;
							cout << '-';
							cin >> emm;
						}
						else
						{
							cout << "Date : ";
							cin >> sdd;
							cout << '-';
							cin >> smm;
							edd = sdd;
							smm = emm;
						}
						cl = day;
						el = 0;
						ml = 0;
					}
				}else if(optn == 2){
					cout << "Enter days for Applying Earned Leave : ";
					cin >> day;
					if(day > el)
					{
						cout << "day should be less than balance leaves";
						exit(0);
					}
					else
					{
						if(day > 1)
						{
							cout << "Start Date : ";
							cin >> sdd;
							cout << '-';
							cin >> smm;
							cout << "End Date : ";
							cin >> edd;
							cout << '-';
							cin >> emm;
						}
						else
						{
							cout << "Date : ";
							cin >> sdd;
							cout << '-';
							cin >> smm;
							edd = sdd;
							smm = emm;
						}
						el = day;
						cl = 0;
						ml = 0;
					}
				}else if(optn == 3){
					cout << "Enter days for Applying Medical Leave : ";
					cin >> day;
					if(day > ml)
					{
						cout << "day should be less than balance leaves";
						exit(0);
					}
					else
					{
						if(day > 1)
						{
							cout << "Start Date : ";
							cin >> sdd;
							cout << '-';
							cin >> smm;
							cout << "End Date : ";
							cin >> edd;
							cout << '-';
							cin >> emm;
						}
						else
						{
							cout << "Date : ";
							cin >> sdd;
							cout << '-';
							cin >> smm;
							edd = sdd;
							smm = emm;
						}
						el = 0;
						cl = 0;
						ml = day;
					}
				}else{
					exit(0);
				}
				const int status = 2;
				Leave_Management L1(i,cl,ml,el,status,sdd,smm,edd,emm);
				file1.seekp(0,ios::end);
				file1.write((char *)&L1,sizeof(L1));
			}
		}
	}
	file.close();
	file1.close();
}


void Leave_Management::approve_leaves()
{
	ifstream file1("applied_Leaves.dat",ios::in | ios::out | ios::binary);
	la_format();
	if(file1.fail())
	{
		cout << endl << setw(60) << "There are no leaves applied for approval!";
		getch();
		HR_SCREEN();
	}
	while(!file1.eof())
	{
		file1.read((char *) this,sizeof(Leave_Management));
		if(file1.eof())
			break;
		la_view();
	}
	file1.close();
	flushall();
	fstream f2("applied_Leaves.dat",ios::in | ios::out | ios::binary);
	cout << endl << setw(45) << "ENTER EMPLOYEE ID : ";
	int i;
	cin >> i;
	while(!f2.eof())
	{
		f2.read((char *) this,sizeof(Leave_Management));
		if(id == i)
		{
			if(status != 1)
			{
				la_format();
				la_view();
				cout << endl << setw(30) << "SELECT OPTION : " << setw(15) << "1. Approve" << endl;
				cout << setw(44) << "3. Reject" << endl;
				cout << setw(44) << "0. Cancel" << endl;
				cout << setw(30) << "ENTER OPTION : ";
				cin >> status;
				f2.seekg(-sizeof(Leave_Management),ios::cur);
				f2.write((char *) this,sizeof(Leave_Management));
				cout << setw(50) << "ACTION COMITTED SUCCESSFULLY FOR "<< id << endl;
				if(status == 1){
					deduct_leaves(id,cl,el,ml);
				}
				break;
			}
			else
			{
				cout << setw(50) << "LEAVES ALREADY APPROVED FOR "<< id << endl;
				break;
			}
		}
	}
	f2.close();
}
void Leave_Management::la_format()
{
	cout << setw(15);
	for(int i=0;i<52;i++)
		cout << '-';
	cout << endl << setw(15) << "" << "#ID";
	cout << setw(3) << "" << setw(7) << "CL";
	cout << setw(6) << "ML";
	cout << setw(6) << "EL";
	cout << setw(15) << "Applied Date";
	cout << setw(10) << "Status" << endl;
	cout << setw(15);
	for( i=0;i<52;i++)
		cout << '-';
	cout << endl;
}
void Leave_Management::la_view()
{
	cout << setw(21) << id;
	cout << setw(6) << cl;
	cout << setw(6) << el;
	cout << setw(6) << ml;
	cout << setw(15) << "16/04/2016";
	cout.width(12);
	if(status == 1){
		cout << "APPROVED";
	} else if(status == 3){
		cout << "REJECTED";
	} else {
		cout << "PENDING";
	}
	cout << endl;
}
void Leave_Management::find_employee(int eid)
{
	ifstream file("applied_leaves.dat",ios::binary);
	la_format();
	while(!file.eof())
	{
		file.read((char *) this,sizeof(Leave_Management));
		if(id == eid)
		{
			la_view();
			getch();
			break;
		}
		else
		{
			if(file.eof())
			{
				cout << setw(50) << "There are no applied leaves";
				getch();
				break;
			}
		}
	}
	file.close();
}
void Leave_Management::delete_balance(int eid)
{
	ifstream bfile("Leaves_Balance.dat",ios::in | ios::out | ios::binary);
	ofstream tbfile("Leaves_Balance_Temp.dat",ios::in | ios::out | ios::binary | ios::trunc);
	while(!bfile.eof())
	{
		bfile.read((char *)this, sizeof(Leave_Management));
		if(bfile.eof())
			break;
		if(id != eid)
		{
			tbfile.write((char *)this, sizeof(Leave_Management));
		}
	}
	bfile.close();
	tbfile.close();
	if(remove("Leaves_Balance.dat")==0)
	{
		if(rename("Leaves_Balance_Temp.dat","Leaves_Balance.dat")==0)
		{
			cout << endl <<setw(23) << eid << " Leaves Balance Record has been Deleted !";
		}
	}
}


/* ----------------------------------------------------------------------------- */
/* ------------------------ SALARY CLASS FUNCTIONS ----------------------------- */
/* ----------------------------------------------------------------------------- */


void Salary::salary_entry()
{
	Profile P;
	ofstream sfile("Salary.dat",ios::binary | ios::app);
	if(sfile.fail())
		cout << "Error in opening a file!";
	else
	{
		ifstream file("Employee_data.dat", ios::binary);
		while(!file.eof())
		{
			file.read((char *)&P, sizeof(P));
			if(file.eof())
				break;
			else
			{
				int mon = (gmtm->tm_mon-1);
				cout << mon;
				Salary S(P.empId, P.Basic_Salary, mon, P.fname, P.lname);
				sfile.write((char *) &S,sizeof(S));
			}
		}
		file.close();
	}
	sfile.close();
}
void Salary::salary_slip(int id, int mon = gmtm->tm_mon-1)
{
	bool found = false;
	ifstream file("Salary.dat",ios::binary);
	if(file.fail())
	{
		cout << "An error Occured!";
		getch();
	}
	else
	{
		while(!file.eof())
		{
			file.read((char *) this,sizeof(Salary));
			if(file.eof())
				break;
			if(id == eid)
			{
				if(month == mon)
				{
					found = true;
					ss_format();
					getch();
					break;
				}
				break;
			}
		}
	}
	file.close();
	if(found == false)
	{
		MyException E1(401,"Till Salary Slip Not Generated....!");
		throw E1;
	}
}
void Salary::ss_format()
{
	cout << setw(8) << '-';
	for(int i=0;i<64;i++)
		cout << '-';
	cout << endl;
	cout << setw(55) << "SALARY SLIP FOR MONTH  " << Month[month] << "-2016" << endl;
	cout << setw(8) << '-';
	for(i=0;i<64;i++)
		cout << '-';
	cout << endl ;
	cout << setw(18) <<"Month : " << setw(5) << Month[month] << setw(35) << "Issue Date : " << "01-" << month+1 << '-' << year << endl;
	cout << setw(18) <<"Year  : " << setw(5) << year << setw(35) << "Days in Month : " << days_in_month << endl;
	cout << setw(8) << '-';
	for(i=0;i<64;i++)
		cout << '-';
	cout << endl;
	cout << setw(23) <<"Employee No :" << setw(8) << eid << setw(30) << "Presence :" << setw(4) << present_days << endl;
	cout << setw(25) <<	"Employee Name :" << setiosflags(ios::left) << setw(20) << name << resetiosflags(ios::left) << setw(15) << "Absence :" << setw(5) << ab_days << endl << endl;
	cout << setw(25) << "EARNINGS" << setw(38) << "DEDUCTIONS" << endl;
	cout << setw(8) << '=';
	for(i=0;i<64;i++)
		cout << '=';
	cout << endl;
	cout << setw(18) << setiosflags(ios::fixed) << setprecision(2) << showpoint << "Basic :" << setw(15) << basic << setw(21) <<"P.F. :"<< setw(14) << pf << endl;
	cout << setw(20) << "Medical :" << setw(13) << medical << setw(26) << "Prof. Tax :" << setw(9) << tax <<endl;
	cout << setw(19) << "H.R.A. :"<< setw(14) << hra << endl;
	cout << setw(17) << "D.A. :"<< setw(16) << da << endl;
	cout << setw(8) << '-';
	for(i=0;i<64;i++)
		cout << '-';
	cout << endl;
	float ta = basic + medical + hra + da;
	float td = pf + tax;
	cout << setw(18) << "TOTAL :" << setw(15) << ta << setw(35) << td << endl << endl;
	cout << setw(18) << '=';
	for(i=0;i<45;i++)
		cout << '=';
	cout << endl;
	cout << setw(18) << "|" << setw(24) << " Total Amount to pay:" << setw(15) << total << setw(6) <<"|"<< endl;
	cout << setw(18) << '=';
	for(i=0;i<45;i++)
		cout << '=';
	cout << endl;
}
Salary::Salary(){
	eid = 0;
	name[0] = NULL;
	month = 0;
	year = 0;
	days_in_month = 0;
	present_days = 0;
	ab_days = 0;
	basic = 0;
	medical = 0;
	hra = 0;
	da = 0;
	pf = 0;
	tax = 0;
	total = 0;
};
Salary::Salary(int id,float basic_pay , int mon, char fname[], char lname[])
{
	Attendance A;
	eid = id;
	strcat(fname, " ");
	strcat(fname, lname);
	strcpy(name, fname);
	month = mon;
	cout << month;
	year = 2016;
	days_in_month = A.mnth(month);
	present_days = A.count_present_days(id);
	if(present_days < days_in_month-4)
	{
		ab_days = days_in_month - present_days - 4;
		float temp = basic_pay/30;
		basic = present_days * temp;
	}
	else
	{
		ab_days = 0;
		basic = basic_pay;
	}
	medical = basic * 0.01;
	hra = basic * 0.1;
	da = basic * 0.05;
	pf = basic * 0.04;
	if(basic > 10000)
		tax = 100.0F;
	else
		tax = 0.0F;
	total = basic + medical + hra + da - (pf + tax);
}

/* ----------------------------------------------------------------------------- */
/* ----------------------- ATTENDENCE CLASS FUNCTIONS -------------------------- */
/* ----------------------------------------------------------------------------- */

int Attendance::mnth(int n)
{
	switch(n)
	{
		case 0:
			return 31;
		case 1:
			return 29;
		case 2:
			return 31;
		case 3:
			return 30;
		case 4:
			return 31;
		case 5:
			return 30;
		case 6:
			return 31;
		case 7:
			return 31;
		case 8:
			return 30;
		case 9:
			return 31;
		case 10:
			return 30;
		case 11:
			return 31;
	}
	return 0;
}
void Attendance::view_atnd(int eId)
{
	flushall();
	ifstream file("Attendance_2016.dat",ios::binary);
	while(!file.eof())
	{
		file.read((char *) this, sizeof(Attendance));
		if(file.eof())
			cout << "Not Found";
		if(empId == eId)
		{
			cout.width(5);cout << "  ";
			for(int i=1;i<=31;i++)
			{
					cout << setw(2) << i;
			}
			cout << endl;
			for(i=0;i<12;i++)
			{
				cout.width(3);cout << i << "  ";
				int a = mnth(i);
				for(int j=0;j<a;j++)
				{
						cout << setw(2) << atd[i][j];
				}
				cout << endl;
			}
			break;
		}
	}
	file.close();
}
void Attendance::take_attendance(int eId)
{
	fstream file("Attendance_2016.dat",ios::in | ios::out | ios::binary);
	while(!file.eof())
	{
		file.read((char *) this, sizeof(Attendance));
		if(empId == eId)
		{
			atd[gmtm->tm_mon][gmtm->tm_mday-1] = 'P';
			
			file.seekp(-sizeof(Attendance), ios::cur);
			file.write((char *) this, sizeof(Attendance));
			break;
		}
	}
	file.close();
}
void Attendance::delete_atd(int eId)
{
	ifstream file("Attendance_2016.dat",ios::binary);
	ofstream file1("Attendance_TEMP.dat",ios::binary);
	while(!file.eof())
	{
		file.read((char *) this, sizeof(Attendance));
		if(file.eof())
			break;
		if(empId != eId)
		{
			file1.write((char *) this, sizeof(Attendance));
		}
	}
	file.close();
	file1.close();
	if(remove("Attendance_2016.dat") == 0)
	{
		if(rename("Attendance_TEMP.dat","Attendance_2016.dat")==0)
		{
			cout << endl << setw(23) << eId << " Attendece entries Succsessfully Deleted!";
		}
	}
}

void Attendance::leave_entry(int eId,int sday, int month,int eday)
{
	fstream file("Attendance_2016.dat",ios::in | ios::out | ios::binary);
	while(!file.eof())
	{
		file.read((char *) this, sizeof(Attendance));
		if(empId == eId)
		{
			for(int i=sday;i<=eday;i++)
				atd[month-1][i-1] = 'L';
			file.seekp(-sizeof(Attendance), ios::cur);
			file.write((char *) this, sizeof(Attendance));
			break;
		}
	}
	file.close();
}
int Attendance::count_present_days(int eId)
{
	int c = 0;
	ifstream file("Attendance_2016.dat",ios::binary);
	while(!file.eof())
	{
		file.read((char *) this,sizeof(Attendance));
		if(file.eof())
			break;
		if(empId == eId)
		{
			for(int i=0; i <= 31;i++)
			{		
				if(atd[gmtm->tm_mon][i] == 'P' || atd[gmtm->tm_mon][i] == 'L')
					c++;
			}
		}
	}
	file.close();
	return c;
}



/* ----------------------------------------------------------------------------- */
/* ----------------------- CLASS MyException FUNCTIONS ------------------------- */
/* ----------------------------------------------------------------------------- */

MyException::MyException(int no, string msg)
{
	ExNo = no;
	ExMessage = msg;
}
void MyException::operator <<(ostream & Temp)
{
	system("cls");
	for(int i=0;i<12;i++)
		Temp << endl;
	Temp << setw(40) << "Error Number is : " << endl << setw(30) << ExNo << endl;
	Temp << setw(38) << "Error Message : " << endl << setw(36) << ExMessage << endl;
}