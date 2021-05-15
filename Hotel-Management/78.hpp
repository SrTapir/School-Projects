
//Capability 7 & 8
//By: Abass zada

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//search for guest function
int searchForGuest()
{
	string input = " ";
	cout << "+-------------------------------------------------+" << endl;
	cout << "|****         Search For a guest By:          ****|" << endl;
	cout << "|FirstName   :                                    |" << endl;
	cout << "|LastName    :                                    |" << endl;
	cout << "|RoomNumber  :                                    |" << endl;
	cout << "|PhoneNumber :                                    |" << endl;
	cout << "|CheckIn     :                                    |" << endl;
	cout << "|CheckOut    :                                    |" << endl;
	cout << "+-------------------------------------------------+" << endl;
	cout << endl;
	cout << "Enter Information: ";
  cout<<endl;
	cin.get();
  getline(cin,input);
	for (string s : find_all_lines("list.txt", input))
		cout << remove_commas(s) << endl;
	

  return 1;
}


//Daily Report function
int dailyReport()
{
  
  string date = " ";
      //Daily report call function
	cout << "***Daily Report****" << endl;
	cout << "Enter Today's Date Month-Day-Year : ";
  cin.get();
	getline(cin, date);
	for (string d : find_all_lines("list.txt", date))
		cout << remove_commas(d) << endl;
      return 1;
}
