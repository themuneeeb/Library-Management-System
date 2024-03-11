#include<iostream>   
#include<string>     
#include<fstream>    
#include<conio.h>    
#include<string.h>   
#include<stdio.h>    
#include<cstring>
#include <cstdlib>   
#include <windows.h> 


using namespace std;

int changeclr = 1;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //to get a handle at console
bool onetime = 1;
void rgb()
{
	SetConsoleTextAttribute(hStdOut, changeclr);
	changeclr += 1;
	if (changeclr > 15)
		changeclr = 1;
}
void welcome()
{
	char name[] = { "LIBRARY MANAGEMENT SYSTEM" };
	SetConsoleCursorPosition(hStdOut, { 0 , 7 });
	for (int i = 0; i < 25; i++)
	{
		Beep(400, 70);
		cout << "\t\t\t\t\t" << name[i] << "\n";
		rgb();
		Sleep(300);
	}
}
void instructions()
{
	ifstream inFile;
	inFile.open("Instruction.txt");
	char typer;
	while (!inFile.eof())
	{
		inFile.get(typer);

		if (!inFile.eof())
		{
			if (typer == 32)
				rgb();
			if (typer != 32)
				Beep(303, 100);
			cout << typer;
		}
	}
	cout << endl;
	inFile.close();
}
void hideCursor()
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1; // size = 1
	cci.bVisible = FALSE; // visibility false
	SetConsoleCursorInfo(hStdOut, &cci); // hide cursor
}


bool LOGIN();
void SORTING(void);
void SORTING_BY_ISBN(void);
void SORTING_BY_NAME(void);
void DISPLAY();
void ADD();
void SEARCH(void);
void SEARCH_BY_TITLE(void);
void SEARCH_BY_ISBN(void);
void DELETE_();
void DELETE_BY_TITLE(void);
void DELETE_BY_ISBN(void);
void LENDING();
void RETURNBOOK();

struct BOOK
{
	string BOOK_TITLE;
	int BOOK_ISBN = 0;
	string BOOK_AUTHOR;
	string BOOK_PUB_DATE;
};

BOOK BOOKS[10000];

struct BOOKISSUE
{
	string nameofperson;
	string nameofbook;
	string issuedate;
	string returndate;
	int fine = 0;
};

BOOKISSUE f1;

int n = 0;

int main()
{
	if (onetime) {
		welcome();
		cout << "PRESS ANY KEY TO CONTINUE........";
		_getch();
		cout << endl;
		system("cls");
		instructions();
		onetime = 0;
	}
	int CHOICE = 0;
	cout << "\t\tLOGIN PAGE\n\n";
	cout << "\tENTER 1 TO LOGIN TO YOUR ACCOUNT." << endl;
	cout << "\tENTER 2 TO EXIT THE LIBRARY." << endl;
	cout << "\n\t\tENTER YOUR CHOICE:\t";
	cin >> CHOICE;
	rgb();
	if (CHOICE == 1)
	{
		bool LOG = LOGIN();
		if (LOG == true)
		{
			do
			{
				system("cls");

				cout << " \t\tLIBRARY MANAGEMENT SYSTEM \n";
				cout << "\n\tPLEASE CHOOSE FROM THE OPTIONS GIVEN BELOW:\n\n";
				cout << "\t\tENTER 1 TO ADD A NEW BOOK\n\n";
				cout << "\t\tENTER 2 TO SEARCH FOR A BOOK\n\n";
				cout << "\t\tENTER 3 TO DELETE A BOOK\n\n";
				cout << "\t\tENTER 4 TO SORT BOOKS\n\n";
				cout << "\t\tENTER 5 TO DISPLAY TO ALL BOOKS IN THE LIBRARY\n\n";
				cout << "\t\tENTER 6 TO LEND BOOKS\n\n";
				cout << "\t\tENTER 7 TO RETURN BOOKS\n\n";
				cout << "\t\tENTER 8 TO EXIT THE LIBRARY\n\n";
				cout << "\n\tENTER THE OPTION YOU WANT TO CARRY OUT:\t";

				int OPTION = 0;
				cin >> OPTION;
				rgb();
				cout << "\n\n";

				if (OPTION == 1)
				{
					ADD();
				}

				else if (OPTION == 2)
				{
					SEARCH();
				}

				else if (OPTION == 3)
				{
					DELETE_();
				}

				else if (OPTION == 4)
				{
					SORTING();
				}

				else if (OPTION == 5)
				{
					DISPLAY();
				}

				else if (OPTION == 6)
				{
					LENDING();
				}

				else if (OPTION == 7)
				{
					RETURNBOOK();
				}

				else if (OPTION == 8)
				{
					exit(0);
				}

				else
				{
					cout << "\n\n \t\tINVALID OPTION.\n\n\t\tPRESS ANY KEY TO ENTER AGAIN.........";
				}

			} while (1);
			_getch();
			rgb();
		}
	}
	else if (CHOICE == 2)
	{
		cout << "\n\tTHANKS FOR COMING TO THE LIBRRY.\n\n";
	}
	else
	{
		cout << "\n\t\tINVALID CHOICE.\n\t\tPRESS ANY KEY TO ENTER AGAIN..........\n\n";
		_getch();
		rgb();
		system("cls");
		main();
	}
}

bool LOGIN()
{
	int count = 0;
	string USERID, USERPASSWORD, ALR_USERID, ALR_PASSWORD;
	system("cls");
	cout << "\t\tWELCOME TO THE LOGIN PAGE FOR OUR LIBRARY.";
	cout << "\n\n\tPLEASE ENTER YOUR LOGIN ID AND PASSWORD TO ACCESS THE LIBRARY.\n";
	cout << "\n\t\tENTER YOUR USERNAME:\t";
	cin >> USERID;
	rgb();
	cout << "\t\tENTER YOUR PASSWORD:\t";
	cin >> USERPASSWORD;
	rgb;

	ifstream INPUT("database.txt");
	while (INPUT >> ALR_USERID >> ALR_PASSWORD)
	{
		if (ALR_USERID == USERID && ALR_PASSWORD == USERPASSWORD)
		{
			count = 1;
			system("cls");
		}
	}
	INPUT.close();
	if (count == 1)
	{
		cout << "\n\tYOU HAVE SUCCESSFULLY LOGGED INTO YOUR ACCOUNT.\n";
		cout << "\n\t\tHELLO " << USERID;
		cout << "\n\t\tPRESS ANY KEY TO ACCESS THE MENU.";
		cin.get();
		cin.get();
		rgb();
		return true;
	}
	else
	{
		cout << "\n\tINVALID LOGIN CREDENTIALS.\n\tMAYBE CONSIDER YOURSELF REGISTERING UP?\n\n";
		char ch = '0';
		cout << "\t\tEnter (Y/N):\t";
		cin >> ch;
		rgb();
		if (ch == 'Y' || ch == 'y')
		{
			system("cls");
			string REG_USERID, REG_PASSWORD, ALR_REG_U, ALR_REG_P;
			cout << "\t\tWELCOME TO THE SIGN UP PAGE FOR OUR LIBRARY.";
			cout << "\n\n\tPLEASE ENTER THE REQUIRED CREDENTIALS TO GET REGISTERED FOR OUR LIBRARY.";
			cout << "\n\n\t\tENTER YOUR NEW USERNAME:\t";
			cin >> REG_USERID;
			rgb();
			cout << "\t\tENTER YOUR NEW PASSWORD:\t";
			cin >> REG_PASSWORD;
			rgb();

			ofstream REG("database.txt", ios::app);
			REG << REG_USERID << ' ' << REG_PASSWORD << endl;
			cout << "\n\tYOU HAVE SUCCESSFULLY REGISTERED.\n\n";
			main();
		}
		else if (ch == 'N' || ch == 'n')
		{
			cout << "\t\tTHANK YOU FOR USING LIBRARY SYSTEM";
			exit(0);
		}
		else
		{
			system("cls");
			cout << "\n\tINVALID INPUT.\n\tPLEASE ENTER AGAIN.\n\n";
			main();
		}
	}
}

void DISPLAY(void)
{
	system("cls");
	cout << "\n\t\tDISPLAY FUNCTION\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\n---------------------------------------------------------------------------------------------------------------------\n";
		cout << "\n\t\tBOOK\t" << i + 1;
		cout << "\n\n\tBOOK ISBN:\t" << BOOKS[i].BOOK_ISBN;
		cout << "\n\tBOOK TITLE:\t" << BOOKS[i].BOOK_TITLE;
		cout << "\n\tBOOK AUTHOR:\t" << BOOKS[i].BOOK_AUTHOR;
		cout << "\n\tBOOK PUBLISHING DATE:\t" << BOOKS[i].BOOK_PUB_DATE;
	}
	cout << "\n\n\t\tPRESS ANY KEY TO BACK GO TO MAIN MENU\n";
	_getch();
	rgb();
}

void ADD(void)
{
	system("cls");
	cout << "\n\t\tADD FUNCTION";
	cout << "\n\n\tENTER THE ISBN OF THE BOOK:\t";
	cin >> BOOKS[n].BOOK_ISBN;
	rgb();
	cin.ignore();

	cout << "\n\tENTER THE TITLE OF THE BOOK:\t";
	getline(cin, BOOKS[n].BOOK_TITLE);
	rgb();

	cout << "\n\tENTER THE NAME OF THE AUTHOR:\t";
	getline(cin, BOOKS[n].BOOK_AUTHOR);
	rgb();

	cout << "\n\tENTER THE PUBLISHING DATE:\t";
	getline(cin, BOOKS[n].BOOK_PUB_DATE);
	rgb();

	ofstream MyFile(BOOKS[n].BOOK_TITLE + ".txt");

	MyFile << BOOKS[n].BOOK_ISBN << endl << BOOKS[n].BOOK_TITLE << endl << BOOKS[n].BOOK_AUTHOR << endl << BOOKS[n].BOOK_PUB_DATE << endl;

	MyFile.close();

	fstream readbook(BOOKS[n].BOOK_TITLE + ".txt", ios::in);
	string str;

	getline(readbook, str);
	BOOKS[n].BOOK_ISBN = stoi(str);
	cout << "\n\n\tBOOK ISBN:\t" << BOOKS[n].BOOK_ISBN << endl;

	getline(readbook, str);
	BOOKS[n].BOOK_TITLE = str;
	cout << "\n\tBOOK TITLE:\t" << BOOKS[n].BOOK_TITLE << endl;

	getline(readbook, str);
	BOOKS[n].BOOK_AUTHOR = str;
	cout << "\n\tBOOK AUTHOR:\t" << BOOKS[n].BOOK_AUTHOR << endl;

	getline(readbook, str);
	BOOKS[n].BOOK_PUB_DATE = str;
	cout << "\n\tBOOK PUBLISHING DATE:\t" << BOOKS[n].BOOK_PUB_DATE << endl;

	readbook.close();

	n++;

}

void SORTING(void)
{

	int OPTION;
	cout << "\n\t\tSORT FUNCTION";
	cout << "\n\n\tENTER 1 TO SORT ACCORDING TO ISBN.";
	cout << "\n\tENTER 2 TO SORT ACCORDING TO TITLE OF BOOK.";

	cout << "\n\n\tPLEASE CHOOSE THE OPTION IN WHICH YOU WANT TO SORT:\t";
	cin >> OPTION;
	rgb();
	if (OPTION == 1)
	{
		SORTING_BY_ISBN();
	}
	else if (OPTION == 2)
	{
		SORTING_BY_NAME();
	}
	else
	{
		system("cls");
		cout << "\n\t\tIVALID OPTION\n\t\tPLEASE ENTER AGAIN\n";
		SORTING();
	}
}

void SORTING_BY_ISBN(void)
{
	int i, j;
	BOOK temp;
	system("cls");

	cout << "\n\t\tSORTING BY ISBN\n";

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (BOOKS[j].BOOK_ISBN > BOOKS[j + 1].BOOK_ISBN)
			{
				temp = BOOKS[j];
				BOOKS[j] = BOOKS[j + 1];
				BOOKS[j + 1] = temp;
			}
		}
	}

	DISPLAY();
}


void SORTING_BY_NAME(void)
{
	int i, j = 0;

	BOOK temp;

	system("cls");

	cout << "\n\t\tSORTING BY NAME\n";

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			const char* str = BOOKS[j].BOOK_TITLE.c_str();
			const char* str1 = BOOKS[j + 1].BOOK_TITLE.c_str();

			if (strcmp(str, str1) > 0)
			{
				temp = BOOKS[j];
				BOOKS[j] = BOOKS[j + 1];
				BOOKS[j + 1] = temp;
			}
		}
	}

	DISPLAY();
}

void SEARCH(void)
{
	system("cls");
	int OPTION = 0;
	cout << "\n\t\tSEARCH FUNCTION\n";
	cout << "\n\tENTER 1 TO SEARCH BY ISBN.";
	cout << "\n\tENTER 2 TO SEARCH BY TITLE OF BOOK.";

	cout << "\n\n\tPLEASE ENTER YOUR CHOICE:\t";
	cin >> OPTION;
	rgb();

	if (OPTION == 1)
	{
		SEARCH_BY_ISBN();
	}
	else if (OPTION == 2)
	{
		SEARCH_BY_TITLE();
	}
	else
	{
		cout << "\n\n\t\tINVALID OPTION\n\t\tPRESS ANY KEY TO ENTER AGAIN..........";
		_getch();
		rgb();
		SEARCH();
	}
}

void SEARCH_BY_TITLE(void)
{
	string TITLE;
	int loc, found = 0;
	system("cls");
	cout << "\n\t\tSEARCH BY TITLE OF BOOK\n";
	cout << "\n\t\tENTER THE TITLE OF THE BOOK YOU WANT TO SEARCH:\t";
	cin.ignore();
	getline(cin, TITLE);
	rgb();
	for (int i = 0; i < n; i++)
	{
		const char* str = BOOKS[i].BOOK_TITLE.c_str();
		const char* str1 = TITLE.c_str();

		if (strcmp(str, str1) == 0)
		{
			loc = i;
			found = 1;
			cout << "\n\t\tBOOK FOUND!!!!";
			cout << "\n\n---------------------------------------------------------------------------------------------------------------------\n";
			cout << "\n\n\tBOOK ISBN:\t" << BOOKS[loc].BOOK_ISBN;
			cout << "\n\tBOOK TITLE:\t" << BOOKS[loc].BOOK_TITLE;
			cout << "\n\tBOOK AUTHOR:\t" << BOOKS[loc].BOOK_AUTHOR;
			cout << "\n\tBOOK PUBLISHING DATE:\t" << BOOKS[loc].BOOK_PUB_DATE;

		}
	}
	if (found == 0)
	{
		cout << "\n\t\tBOOK NOT FOUND!!!." << endl;
	}
	cout << "\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU..........";
	_getch();
	rgb();
}

void SEARCH_BY_ISBN(void)
{
	int ISBN;
	int loc, found = 0;
	system("cls");
	cout << "\t\tSEARCH BY ISBN OF BOOK\n";
	cout << "\n\tENTER THE ISBN OF THE BOOK YOU WANT TO SEACRH:\t";
	cin >> ISBN;
	rgb();

	for (int i = 0; i < n; i++)
	{
		if (BOOKS[i].BOOK_ISBN == ISBN)
		{
			loc = i;
			found = 1;
			cout << "\n\t\tBOOK FOUND!!!";
			cout << "\n\n---------------------------------------------------------------------------------------------------------------------\n";
			cout << "\n\n\tBOOK ISBN:\t" << BOOKS[loc].BOOK_ISBN;
			cout << "\n\tBOOK TITLE:\t" << BOOKS[loc].BOOK_TITLE;
			cout << "\n\tBOOK AUTHOR:\t" << BOOKS[loc].BOOK_AUTHOR;
			cout << "\n\tBOOK PUBLISHING DATE:\t" << BOOKS[loc].BOOK_PUB_DATE;
		}
	}
	if (found == 0)
	{
		cout << "\n\t\tBOOK NOT FOUND!!!." << endl;
	}
	cout << "\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU..........";
	_getch();
}

void DELETE_(void)
{
	system("cls");
	int OPTION = 0;
	cout << "\n\t\tDELETE FUNCTION\n";
	cout << "\n\tENTER 1 TO DELETE BY ISBN.";
	cout << "\n\tENTER 2 TO DELETE BY TITLE OF BOOK.";

	cout << "\n\n\tPLEASE ENTER YOUR CHOICE:\t";
	cin >> OPTION;
	rgb();
	if (OPTION == 1)
	{
		DELETE_BY_ISBN();
	}
	else if (OPTION == 2)
	{
		DELETE_BY_TITLE();
	}
	else
	{
		cout << "\n\n\t\tINVALID OPTION\n\t\tPRESS ANY KEY TO ENTER AGAIN..........";
		_getch();
		rgb();
		DELETE_();

	}
}

void DELETE_BY_TITLE(void)
{
	string TITLE;
	int loc, found = 0;
	system("cls");
	cout << "\n\t\tDELETE BY TITLE OF BOOK\n";
	cout << "\n\tENTER THE TITLE OF THE BOOK YOU WANT TO DELETE:\t";
	cin.ignore();
	getline(cin, TITLE);
	rgb();

	for (int i = 0; i < n; i++)
	{
		const char* str = BOOKS[i].BOOK_TITLE.c_str();
		const char* str1 = TITLE.c_str();
		if (strcmp(str, str1) == 0)
		{
			loc = i;
			found = 1;
			for (i = loc; i < n - 1; i++)
			{
				BOOKS[i] = BOOKS[i + 1];
			}
			n--;
		}
	}
	if (found == 0)
		cout << "\n\t\tBOOK NOT FOUND";
	cout << "\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU........";
	_getch();
	rgb();
}

void DELETE_BY_ISBN(void)
{
	int ISBN;
	int loc, found = 0;
	system("cls");
	cout << "\n\t\tDELETING BY ISBN OF BOOK\n";
	cout << "\n\tENTER THE ISBN OF THE BOOK YOY WANT TO DELETE:\t";
	cin >> ISBN;
	rgb();

	for (int i = 0; i < n; i++)
	{
		if (BOOKS[i].BOOK_ISBN == ISBN)
		{
			loc = i;
			found = 1;
			for (i = loc; i < n - 1; i++)
			{
				BOOKS[i] = BOOKS[i + 1];
			}
			n--;
		}
	}
	if (found == 0)
		cout << "\n\t\tBOOK NOT FOUND";
	cout << "\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU........";
	_getch();
	rgb();
}

void LENDING()
{
	system("cls");

	ofstream lending;
	lending.open("lending.txt");

	cout << "\t\tLENDING FUNCTION";

	cout << "\n\n\tENTER YOUR NAME:\t";
	cin.ignore();
	getline(cin, f1.nameofperson);
	rgb();

	cout << "\n\tENTER THE TITLE OF BOOK:\t";
	getline(cin, f1.nameofbook);
	rgb();

	cout << "\n\tENTER THE ISSUE DATE OF BOOK:\t";
	getline(cin, f1.issuedate);
	rgb();

	cout << "\n\tENTER THE DATE OF RETURN OF THE BOOK:\t";
	getline(cin, f1.returndate);
	rgb();

	lending << f1.nameofperson << endl << f1.nameofbook << endl << f1.issuedate << endl << f1.returndate << endl;
	lending.close();

	ifstream LEND;
	LEND.open("lending.txt");

	string str;

	getline(LEND, str);
	f1.nameofperson = str;
	cout << "\n\n\tNAME OF PERSON:\t" << f1.nameofperson << endl;

	getline(LEND, str);
	f1.nameofbook = str;
	cout << "\n\tNAME OF BOOK:\t" << f1.nameofbook << endl;

	getline(LEND, str);
	f1.issuedate = str;
	cout << "\n\tISSUE DATE:\t" << f1.issuedate << endl;

	getline(LEND, str);
	f1.returndate = str;
	cout << "\n\tRETURN DATE:\t" << f1.returndate << endl;

	LEND.close();

	cout << "PRESS ANY KEY TO CONTINUE........";
	_getch();
}

void RETURNBOOK()
{
	system("cls");

	cout << "\t\tRETURN FUNCTION";

	int choicee, days;
	int fine = 200;
	double fineimposed;

	BOOKISSUE	f2;

	ofstream returnbook;
	returnbook.open("Returnbook.txt");

	cout << "\n\n\tENTER YOUR NAME:\t";
	cin.ignore();
	getline(cin, f2.nameofperson);
	rgb();

	cout << "\n\tENTER THE TITLE OF THE BOOK:\t";
	getline(cin, f2.nameofbook);
	rgb();

	cout << "\n\tENTER THE DATE OF RETURN:\t";
	getline(cin, f2.returndate);
	rgb();

	returnbook << f2.nameofperson << endl << f2.nameofbook << endl << f2.returndate << endl;
RETURN:
	cout << "\n\n\tARE YOU RETURNING THE BOOK LATE OR NOT ACCORDING TO THE ISSUE DATE?" << endl;
	cout << "\n\t\t1.YES\n\t\t2.NO" << endl;
	cin >> choicee;
	if (choicee == 1)
	{
		cout << "\n\tHOW MANY DAYS ARE YOU LATE IN RETURNING THE BOOK?" << endl;
		cin >> days;
		fineimposed = fine * days;
		cout << "\n\tYOU HAVE TO PAY THE FINE OF " << fineimposed << " DUE TO THE LATE RETURNING OF BOOK." << endl;
		f2.fine = fineimposed;
		returnbook << f2.fine << endl;
	}
	else if (choicee == 2)
	{
		cout << "\n\t\tTHANKS FOR LENDING THE BOOK FROM OUR LIBRARY. " << endl;
		fineimposed = 0;
	}
	else
	{
		cout << "\n\t\tINVALID OPTION. PLEASE CHOOSE CORRECT OPTION  " << endl;
		_getch();
		goto RETURN;

	}
	returnbook.close();

	ifstream returnbook2;
	returnbook2.open("lending.txt");

	string str;

	getline(returnbook2, str);
	f2.nameofperson = str;
	cout << "\n\n\tNAME OF PERSON:\t" << f2.nameofperson << endl;

	getline(returnbook2, str);
	f2.nameofbook = str;
	cout << "\n\tNAME OF BOOK:\t" << f2.nameofbook << endl;

	getline(returnbook2, str);
	f2.returndate = str;
	cout << "\n\tRETURN DATE:\t" << f2.returndate << endl;

	cout << "\n\tFINE IMPOSED:\t" << fineimposed << endl;

	returnbook2.close();

	cout << "PRESS ANY KEY TO CONTINUE...........";
	_getch();
	rgb();
}