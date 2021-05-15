#include <iostream>
#include <string>
#include "12.hpp"
#include "34.hpp"
#include "56.hpp"
#include "78.hpp"

using namespace std;

// main for testing purposes
int menu()
{
	int option;
	cout << "Enter the number coorelating with the option you wish to pick\n";
  cout <<	"1: Room Status\n";
	cout << "2: Weekly Availability\n";
	cout <<	"3: Reservations\n";
	cout << "4: Housekeeping\n";
  cout << "5: Guest Profile\n";
  cout << "6: Current Stay\n";
  cout <<	"7: Search For Guest\n";
	cout << "8: Daily Report\n";
	cin >> option;

  if (option == 1) {
    return room_status_menu();
  }
  else if (option == 2) {
    return weekly_availability_menu();
  }
	else if (option == 3){
    return test_reservation();
  }
	
	else if (option == 4){
    return test_housekeeping();
  }
  else if (option == 5){
    string num;
    cout<<"Enter Room Number"<<endl;
    cin>>num;
    return guest(num);
  }
	else if (option == 6){
    string num;
    cout<<"Enter Room Number"<<endl;
    cin>>num;
    return stay(num);
  }
  else if (option == 7){
    return searchForGuest();
  }
  else if (option == 8){
   return dailyReport();
  }
	return 0;
  
}