//Header Files
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <cctype>
using namespace std;
//Class Declaration
class user
{
public:
	//Class Data Members
	string fname, mname, lname;
	double cnic[13];
	int age;
	char email[50];
	string username;
	string password;
	int phnumber[11];
	user() // Constructor
	{
		cout << "Enter Full Name: ";
		cin >> fname >> mname >> lname;
		cout << "Enter Age: ";
		cin >> age;
		if (age < 18)
		{
			cout << "You are not eligible to drive " << endl;
			exit(0);
		}
		cout << "Enter CNIC: ";
		for (int i = 0; i < 13; i++)
		{
			cnic[i] = _getche();
			if (i == 4 || i == 11)
			{
				cout << "-";
			}
		}
		cout << endl;
	reenteremail: //  For Goto Function
		cout << "Enter Email: ";
		int at = 0, dot = 0;
		for (int i = 0; i < 23; i++)
		{
			email[i] = _getche();
			if (email[i] == '@')
			{
				at++;
			}
			else if (email[i] == '.')
			{
				dot++;
			}
		}
	end:
		if (at == 0 || dot == 0)
		{
			cout << "Invalid Email" << endl;
			goto reenteremail;
		}
		cout << endl;
		cout << "Enter Phone Number: ";
		for (int i = 0; i < 11; i++)
		{
			phnumber[i] = _getche();
			if (i == 3)
			{
				cout << "-";
			}
		}
		cout << endl;
		cout << "Enter Username: ";
		cin >> username;
		cout << "Enter Password: ";
		cin >> password;
	}
};

class paymentdetails
{
private:
	long double accountnum[16];
	int CVC[3];
	int Expiryday[4];
public:
	int collection;
	paymentdetails(user&) //Aggregation Relationship with User Class
	{
		collection = 0;
		cout << "Enter Credit Card Number: ";
		for (int i = 0; i < 16; i++)
		{
			accountnum[i] = _getche();
			
			if (i == 3 || i == 7 || i == 11)
			{
				cout << " ";
			}
		}
		cout << endl;
		cout << "Enter CVC Number: ";
		for (int i = 0; i < 3; i++)
		{
			CVC[i] = _getche();
		}
		cout << endl;
		cout << "Enter Expiry Date: ";
		for (int i = 0; i < 4; i++)
		{
			Expiryday[i] = _getche();
			if (i == 1)
			{
				cout << "/";
			}
		}
		cout << endl;
		collection++;
	}
};
class vehicle //Abstract Class
{
public:
	//Virtual Functions
	void virtual print() = 0;
	void virtual inputhours()
	{

	}
	void virtual reciept()
	{

	}
};
//Inheritance
class car : public vehicle //Inherited Class
{
private:
	string make;  //Make of Car
	string model; //Model of Car
	string color;  //Colour of Car
	int	year; //Year of Release
	int mileage;  //Mileage of Car
	string type;  //Class of Car
	string nplate; //Number Plate
	float rate; //Rate Per Hour
	int hours; //Number of Hours
	float* tptr; //Pointer for saving value of total cost
	
	friend ostream& operator << (ostream& os, const car& n); //Friend Function
public:
	float total; //Variable for saving value of total cost
	car()
	{

	}
	//Parameterized Constructor
	car(string make, string model, string color, int year, int mileage, float rate, string type, string nplate) : make(make), model(model), color(color), year(year), mileage(mileage), type(type), nplate(nplate), rate(rate)
	{
	}
	//Member Functions
	void print()
	{
		cout << "Make: " << make << endl;
		cout << "Model: " << model << endl;
	}
	void reciept(user &u) //Value passed through reference
	{
		cout << "**************************RECIEPT******************************* " << endl;
		cout << "Your Reciept Number is : " << rand() % 1022881 + 1272788 << endl;
		cout << "************************RECIEVER DETAILS************************" << endl;
		cout << "Reciever Name: " << u.fname << " " << u.mname << " " << u.lname << endl;
		cout << "*************************CAR DETAILS****************************" << endl;
		cout << "Model: " << model << endl;
		cout << "Make: " << make << endl;
		cout << "Year: " << year << endl;
		cout << "Rate: " << rate << endl;
		cout << "Hours: " << hours << endl;
		cout << "Type: " << type << endl;
		cout << "Number Plate: " << nplate << endl;
		total = hours * rate;
		tptr = &total; //Use of pointers
		cout << "Your Total is Rs. " << *tptr << endl;
	}
	void inputhours()
	{
		cout << "Please Enter Total Number Of Hours The Vehicle Will Be Used = ";
		cin >> hours;
	}
};
ostream& operator << (ostream& os, const car& n) //Operator Overloading
{
	cout << endl;
	cout << "Make: " << n.make << endl;
	cout << "Model: " << n.model << endl;
	cout << "Color: " << n.color << endl;
	cout << "Year: " << n.year << endl;
	cout << "Mileage: " << n.mileage << endl;
	cout << "Type: " << n.type << endl;
	cout << "Number Plate: " << n.nplate << endl;
	return os;
}
//Multilevel Inheritance
class Economy : public car
{
public:
	float rate;
	int hours;
	Economy()
	{
		cout << "Invalid";
	}
	Economy(string make, string model, string color, int year, int mileage, float rate, string type, string nplate) : car(make, model, color, year, mileage, rate, type, nplate) //Constructor Overloading
	{

	}
	~Economy() //Destructor
	{

	}
};

class EconomyPlus : public car
{
public:
	float rate;
	int hours;
	EconomyPlus()
	{
		cout << "Invalid";
	}
	EconomyPlus(string make, string model, string color, int year, int mileage, float rate, string type, string nplate) : car(make, model, color, year, mileage, rate, type, nplate)
	{


	}
	~EconomyPlus()
	{

	}
};

class Business : public car
{
public:
	float rate;
	int hours;
	Business()
	{
		cout << "Invalid";
	}
	Business(string make, string model, string color, int year, int mileage, float rate, string type, string nplate) : car(make, model, color, year, mileage, rate, type, nplate)
	{

	}
	~Business()
	{

	}
};

//Functions
void bonvoyage()
{
	cout << endl;
	cout << "Please collect your keys from the counter" << endl;
	cout << endl;
	cout << "We wish you Bon Voyage" << endl;
}

void paymentmethod(user& user1,car &v1) //Function intakes parameter as an object of Class User
{
pay3:
	cout << "Please choose your preffered payment method: 1. Cash   2. Credit" << endl;
	int choice4;
	cout << "Enter Choice: ";
	cin >> choice4;
	if (choice4 == 2)
	{
		paymentdetails userpayment(user1);

		if (userpayment.collection == 1)
		{
			cout << "Checking Details ";
			for (int i = 6; i > 1; i--)
			{
				cout << i - 1 << "..";
				Sleep(1000);
			}
			cout << endl;
			cout << "********************************TRANSACTION DETAILS***********************************" << endl;
			cout << endl;
			cout << "Reciept ID: " << rand() % 1022881 + 1272788 << endl;
			cout << endl;
			cout << "Transaction Date & Time: " << __DATE__ << " " << __TIME__ << endl;
			cout << endl;
			cout << endl;
			cout << "Transaction Successful." << endl;
			cout << endl;
			cout <<"Rs. "<< v1.total <<" has been credited from your account." << endl;
		}
	}
	else if (choice4 == 1)
	{
		cout << "Please Pay Cash On The Counter" << endl;
	}
	else
	{
		cout << "Invalid Option" << endl;
		goto pay3;
	}
}

//Main Body
int main()
{	//Using arrays as data structure
	Economy ECars[3] = { {"Suzuki","Mehran","White",2002,16,500,"Economy","LEX-554"},{"Daihatsu","Coure","Grey",2005,23,600,"Economy","LEX-555"},{"Hyundai","Santro","White",2008,26,800,"Economy","LEX-556"} };
	EconomyPlus PCars[3] = { {"Honda","City","White",2012,35,1000,"Economy Plus","KEE-854"},{"Toyota","Corola","Grey",2015,36,1200,"Economy Plus","MNZ-984"},{"Honda","Civic","White",2015,35,1500,"Economy Plus","NEX-456"} };
	Business BCars[3] = { {"Honda","Vezel","White",2018,35,2500,"Business","LEE-854"},{"Toyota","Prado","Grey",2019,36,3000,"Business","MNS-985"},{"Audi","A7","White",2020,35,3500,"Business","LOL-695"} };
	cout << "********************Welcome to ADMWQ Car Rental Service********************" << endl;
	cout << "***********************Please Register To Rent A Car***********************" << endl;
	user user1;
	cout << "**************************REGISTRATION COMPLETED**************************" << endl;
	cout << endl;
inv:
	cout << "*************************Please Login To Continue*************************" << endl;
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "Trying To Login.";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	cout << endl;
	if (username == user1.username && password == user1.password)
	{
		cout << "***************************Login Succesful*****************************" << endl;
	}
	else
	{
		cout << "Invalid Username or Password" << endl;
		goto inv;
	}
	cout << "****************************Welcome " << user1.mname << " " << user1.lname << "****************************" << endl;
invalid:
	cout << "Please choose your preffered class: " << endl;
	cout << "1. Economy Class" << "      " << "2. Economy Plus Class" << "       " << "3. Business Class" << endl;
	cout << "Enter Choice: ";
	int choice;
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Invalid Choice. Please Try Again" << endl;
		goto invalid;
	}
	else if (choice == 1)
	{
		cout << "Displaying Cars Available In Economy Class" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << ". " << endl;
			ECars[i].print();
			cout << endl;
		}
		cout << "Enter Choice: ";
		int choice2;
		cin >> choice2;
		if (choice2 > 3 || choice2 < 1)
		{
			cout << "Invalid Choice. Please Try Again" << endl;
			goto invalid;
		}
		cout << endl;
		cout << setw(65) << "Printing Details.";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		cout << endl;
		cout << ECars[choice2 - 1];
	inv2:
		cout << "Would you like to confirm? (Y/N)" << endl;
		char choice3;
		cin >> choice3;
		switch (choice3)
		{
		case 'Y':
		{
			ECars[choice2 - 1].inputhours();
			cout << endl;
			cout << setw(65) << "Printing Reciept.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			cout << endl;
			ECars[choice2 - 1].reciept(user1);
			paymentmethod(user1,ECars[choice2 - 1]);
			bonvoyage();
			break;
		}
		case 'N':
		{
			cout << "Exiting.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			exit(0);
			break;
		}
		default:
		{
			cout << "Invalid Option. Please Try Again" << endl;
			goto inv2;
		}
		}
	}
	else if (choice == 2)
	{
		cout << "Displaying Cars Available In Economy Plus Class" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << ". " << endl;
			PCars[i].print();
			cout << endl;
		}
		cout << "Enter Choice: ";
		int choice2;
		cin >> choice2;
		if (choice2 > 3 || choice2 < 1)
		{
			cout << "Invalid Choice. Please Try Again" << endl;
			goto invalid;
		}
		cout << endl;
		cout << setw(65) << "Printing Details.";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		cout << endl;
		cout << PCars[choice2 - 1];
	inv3:
		cout << "Would you like to confirm? (Y/N)" << endl;
		char choice3;
		cin >> choice3;
		switch (choice3)
		{
		case 'Y':
		{
			PCars[choice2 - 1].inputhours();
			cout << endl;
			cout << setw(65) << "Printing Reciept.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			cout << endl;
			PCars[choice2 - 1].reciept(user1);
			paymentmethod(user1, PCars[choice2 - 1]);
			bonvoyage();
			break;
		}
		case 'N':
		{
			cout << "Exiting.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			exit(0);
			break;
		}
		default:
		{
			cout << "Invalid Option. Please Try Again" << endl;
			goto inv3;
		}
		}

	}
	else if (choice == 3)
	{
		cout << "Displaying Cars Available In Business Class" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << ". " << endl;
			BCars[i].print();
			cout << endl;
		}
		cout << "Enter Choice: ";
		int choice2;
		cin >> choice2;
		if (choice2 > 3 || choice2 < 1)
		{
			cout << "Invalid Choice. Please Try Again" << endl;
			goto invalid;
		}
		cout << endl;
		cout << setw(65) << "Printing Details.";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		cout << endl;
		cout << BCars[choice2 - 1];
	inv4:
		cout << "Would you like to confirm? (Y/N)" << endl;
		char choice3;
		cin >> choice3;
		switch (choice3)
		{
		case 'Y':
		{
			BCars[choice2 - 1].inputhours();
			cout << endl;
			cout << setw(65) << "Printing Reciept.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			cout << endl;
			BCars[choice2 - 1].reciept(user1);
			paymentmethod(user1, BCars[choice2 - 1]);
			bonvoyage();
			break;
		}
		case 'N':
		{
			cout << "Exiting.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			exit(0);
			break;
		}
		default:
		{
			cout << "Invalid Option. Please Try Again" << endl;
			goto inv4;
		}
		}
	}
}
