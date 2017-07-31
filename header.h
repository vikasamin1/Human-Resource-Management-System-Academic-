#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<conio.h>
using namespace std;

/* GLOBAL VARIABLES AND ARRAY */
const string Month[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
static int elid;
static time_t now = time(0);
static char* dt = ctime(&now);
static tm *gmtm = gmtime(&now);

/* USER DEFINED MANIPULATORS */
ostream & PrintHeader(ostream & );	//Printing main Header in the project
ostream & LogOut(ostream & );		//Printing Logout Message

/* GLOBAL FUNCTIONS */
void LOGIN();				//Showing the Login Screen
void HR_SCREEN();			//Showing the HR Manager Login
void EMP_SCREEN();			//Showing the Normal Employe Login
void ADMN_SCREEN();			//Showing the Admin Who see the all login information

/* FORWARD DECLARATIONS OF CLASSES */
class Person;
class Profile;
class Attendance;
class Administrator;
class HRM;
class Employee;
class Leave_Management;
class Login;
class Salary;

/* DEFINITION OF CLASSES */
/* CLASS PERSON */
class Person{
protected:
	char fname[20];
	char mname[20];
	char lname[20];
	char dob[11];
	char doj[11];
	class Address{
	public:
		char HN[10];
		char soc[30];
		char local[20];
		char pincode[8];
	}A;
public:
	void get_personal_details();
	void show_personal_details();
};

/* CLASS PROFILE */
class Profile:public Person{
public:
	int empId;					// Employee Id for unique Identity
private:
	char Designation[30];
	double Basic_Salary;		//per month
	int eRole;					//Employee Role for 1. Admin, 2. HR, 3. Employee
public:		
	Profile()
	{
		empId = 100000;
	}
	//void create_profile();
	//void show_profile();
	friend istream & operator >>(istream & Temp, Profile & P)
	{
		P.empId += 1;
		cout << endl << setw(50) << "----- EMPLOYEE PROFILE -----";
		cout << endl << setw(38) << "Designation : ";
		Temp.getline(P.Designation,20);
		cout << endl << setw(33) << "Salary : ";
		Temp >> P.Basic_Salary;
		cout << endl << setw(49) << "-- SELECT EMPLOYEE ROLE --" << endl;
		cout << endl << setw(35) << "1. ADMIN";
		cout << endl << setw(32) << "2. HR";
		cout << endl << setw(38) << "3. EMPLOYEE";
		cout << endl << setw(46) << "Enter Employee Role: ";
		Temp >> P.eRole;
		return Temp;
	}
	friend ostream & operator <<(ostream & Temp, Profile & P)
	{
		Temp << endl << setw(47) << "- EMPLOYEE PROFILE -" << endl;
		Temp << endl << setw(28) << "#EMP ID : " << P.empId;
		Temp << setw(25) << "Designation : " << P.Designation << endl;
		Temp << setw(27) << "Salary : " << P.Basic_Salary << setw(19) << "Role: " << setw(10);
		if(P.eRole == 1) Temp << "ADMIN";
		else if(P.eRole == 2) Temp << "HR";
		else Temp << "EMPLOYEE";
		Temp << endl;
		return Temp;
	}
	int cmp_name(char name[])
	{
		if(strcmp(fname,name)==0)
			return 1;
		else
			return 0;
	}
	void create_Login();					// Creating Employee Login information
	void show_all_details();				// Used for making report of in HR screen
	void edit_employee(int n, int eid);		// Edit Employee informarion
	void view_emp();						// View employee all information
	friend class Salary;		//used for generatin salary slips at the next month start using hrm class
};

/* CLASS HRM */
class HRM{								//include functions for the HRM screen
public:
	void Add_employee();				//Creating New Employee
	void Show_employee();
	void remove_employee(int );			//Deleting employee Record
	void update_employee();				//Update Employee Information
	void show_All();					//Making Report of all employee informarion
	void search_employee(int );
	void search_employee(char []);
	//void operator<<(ostream & );		//Searching a Particular Employee
	void edit();
	void create_leave_balance(int );	//Create Leave Balance at time of Employee Creation
	void create_atdentry(int );			//Create Atdence Format for year at time of Employee Creation	
};

/* CLASS LOGIN */
class Login			//used at the time of login, create login , methods relared login
{
	int userid;
	char password[14];
	int role;
public:
	Login();									//Default Constructor
	Login(int Uid, char Epass[], int Erole);	//Parameterised Constructor
	void user_login(int user, char pass[]);		//Checkin Proper Authentication
	void header_login();						//Login Header
	void output();
	void del_Login(int eid);					//Remove Login DEtails
	void update_password();						//Update Password
	void update_login(int eid, int erole);		//Update whe role of employee Changed
};

/* CLASS ADMINISTRATOR */
class Administrator
{
public:
	void read_Login();
};

/* CLASS LOGIN */
class Employee{
public:
	void view_emp_info(int );
	void view_leave_status();	
};

/* CLASS LEAVE_MANAGEMENT */	// Methods related to the the leaves ans other leave functions
class Leave_Management{
private:
	int id;		//employee id
	int cl;		//casual leave
	int el;		//earned leave
	int ml;		//medical leave
	int sdd;	//start Date
	int smm;	//Start month
	int edd;	//End date
	int emm;	//End Month
	int status; // 1.Approve 2.Pending 3.Reject
public:
	Leave_Management();
	Leave_Management(int i,int c,int e, int m);		//Constructor for creating leave balance
	Leave_Management(int i, int c, int e, int m, int s, int sd , int sm, int ed, int em);	// Constructor for leave apply
	void format();
	void leaves_report();
	void view_leaves();
	//void apply_leave(int i);
	void leave_apply(int i);
	void deduct_leaves(int , int , int , int );
	void leave_balance_employee(int );
	void approve_leaves();
	void la_view();
	void la_format();
	void find_employee(int );
	void delete_balance(int );
};

/* CLASS ATTENDANCE */ 
class Attendance
{
	public:
		int empId;			// Getting the location of empId.
		char atd[12][31];	// Filling the attendance of employee.
	public:
		Attendance()
		{}
		Attendance(int eId) 
		{
			empId = eId;
			for(int i=0;i<12;i++)
			{
				int a = mnth(i);
				for(int j=0;j<a;j++)
				{
					atd[i][j] = 'N';
				}
			}
		}
		int mnth(int n);
		void view_atnd(int eId);
		void take_attendance(int eId);		//used for taking attendance
		void delete_atd(int eId);			//delete ateendance aentry
		void leave_entry(int eId,int sday, int month,int eday);		// Entries for leave
		int count_present_days(int eId);		// counting present dats
};

/* CLASS SALARY */ 
class Salary{
private:
	char name[30];
	int eid;
	int month;
	int year;
	int days_in_month;
	int present_days;
	int ab_days;
	float basic;
	float medical;
	float hra;
	float da;
	float pf;
	float tax;
	float total;
public:
	Salary();
	Salary(int ,float , int , char [], char []);
	void salary_slip(int , int);
	void ss_format();
	void salary_entry();
};

/* CLASS MyException */ 
class MyException{
private:
	int ExNo;
	string ExMessage;
public:
	MyException(int , string );
	void operator<<(ostream & );	
};