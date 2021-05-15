//Antonio de Lis
//cpsc 463 Capabilities 3 and 4

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "test.h"

using namespace std;

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int countLeapYears(int month, int year)
{
	if (month <= 2)
	{
		year--;
		return (year / 4) - (year / 100) + (year / 400);
	}	
  return 0;
}

int getDifference(int m1, int d1, int y1, int m2, int d2, int y2)
{
	long int n1 = y1 * 365 + d1;
	
	for (int i = 0; i < m1 - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(m1, y1);

	long int n2 = y2 * 365 + d2;
	for (int i = 0; i < m2 - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(m2, y2);

	return (n2 - n1);
}

void ReservationSceen()
{
	//check in date
	int cInMonth, cInDay, cInYear;
	//check out date
	int cOutMonth, cOutDay, cOutYear;

	//putting file stuff in vectors, why did i do this, idk, but its what i did in section 4 so keeping same format
	string fName, lName, rNum, rtype, rmdate, cid, cod, phone, address, email, id, vlp, rr, tc, pay, bal;
	vector<string> gfName;
	vector<string> glName;
	vector<string> grNum;
	vector<string> grtype;
	vector<string> grmdate;
	vector<string> gcid;
	vector<string> gcod;
	vector<string> gphone;
	vector<string> gaddress;
	vector<string> gemail;
	vector<string> gid;
	vector<string> gvlp;
	vector<string> grr;
	vector<string> gtc;
	vector<string> gpay;
	vector<string> gbal;
	int l = 0;

	ifstream infile("GuestInformation.txt");
	if (infile.is_open()) {
		string line;

		while (!infile.eof())
		{
      getline(infile, rNum, ',');
			grNum.push_back(rNum);
			getline(infile, fName, ',');
			gfName.push_back(fName);
			getline(infile, lName, ',');
			glName.push_back(lName);
			getline(infile, rtype, ',');
			grtype.push_back(rtype);
			getline(infile, rmdate, ',');
			grmdate.push_back(rmdate);
			getline(infile, cid, ',');
			gcid.push_back(cid);
			getline(infile, cod, ',');
			gcod.push_back(cod);
			getline(infile, phone, ',');
			gphone.push_back(phone);
			getline(infile, address, ',');
			gaddress.push_back(address);
			getline(infile, email, ',');
			gemail.push_back(email);
			getline(infile, id, ',');
			gid.push_back(id);
			getline(infile, vlp, ',');
			gvlp.push_back(vlp);
			getline(infile, rr, ',');
			grr.push_back(rr);
			getline(infile, tc, ',');
			gtc.push_back(tc);
			getline(infile, pay, ',');
			gpay.push_back(pay);
			getline(infile, bal, '\n');
			gbal.push_back(bal);
			l += 1;
		}
	}
	else cout << "Unable open file" << endl;
	infile.close();

  string lastrnum;
	cout << "Current Reservations: " << endl;
	for (int i = 1; i < l; i++)
	{
		cout << grNum[i] << ", " << gfName[i] << ", " << glName[i] << ", " << grtype[i] << "," << grmdate[i] << ", " << gcid[i] << ", " << gcod[i] << ", " << gtc[i] << "\n";
    if(i == l-1)
    {
      lastrnum = grNum[i];
      int ilrnum = stoi(lastrnum);
      ilrnum++;
      lastrnum = to_string(ilrnum);
    }
	}



	int option1, option2; 
	bool availability = true;
	cout << "1. Add Reservation\n2. Delete Reservation\n3. Select Room\n";
	cin >> option1;

	//get all the information to append it to the back of the vector
	if (option1 == 1)
	{
		cout << "Enter First Name: ";
		cin >> fName;
		cout << "Enter Last Name: ";
		cin >> lName;

    cout << "Enter the current date: (ex. 1-11-2011)" << endl;
    cin >> rmdate;
		//collect checkin date
		cout << "Enter Checkin month: ";
		cin >> cInMonth;
		cout << "Enter Checkin day: ";
		cin >> cInDay;
		cout << "Enter Checkin year: ";
		cin >> cInYear;

		cid = to_string(cInMonth) + "-" + to_string(cInDay) + "-" + to_string(cInYear);
		//cout << cid << endl;

		//collect checkout date
		cout << "Enter Checkout month: ";
		cin >> cOutMonth;
		cout << "Enter Checkout day: ";
		cin >> cOutDay;
		cout << "Enter Checkout year: ";
		cin >> cOutYear;
		
		cod = to_string(cOutMonth) + "-" + to_string(cOutDay) + "-" + to_string(cOutYear);
		//cout << cod << endl;

		int totalDays = getDifference(cInMonth, cInDay, cInYear, cOutMonth, cOutDay, cOutYear);
		int total = 0;

		cout << "Here are the Room Types and their availability:\n";
		//something to change when merging code
		cout << "1. King: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $100, your total is $";
			total = 100 * totalDays;
			cout << total << endl;
		}

		cout << "2. Double Queen: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $200, your total is $";
			total = 200 * totalDays;
			cout << total << endl;
		}

		cout << "3. Double Queen with Kitchen: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $300, your total is $";
			total = 300 * totalDays;
			cout << total << endl;
		}

		cout << "4. Suite: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $400, your total is $";
			total = 400 * totalDays;
			cout << total << endl;
		}

		cout << "Please select one of the options 1, 2, 3, or 4: ";
		cin >> option2;

		gfName.push_back(fName);
		glName.push_back(lName);
		grNum.push_back(lastrnum);
		if (option2 == 1)
		{
			rtype = "King";
			rr = "100";
			tc = to_string(totalDays * 100);
		}
		else if (option2 == 2)
		{
			rtype = "Double Queen";
			rr = "200";
			tc = to_string(totalDays * 200);
		}
		else if (option2 == 3)
		{
			rtype = "Double Queen with Kitchen";
			rr = "300";
			tc = to_string(totalDays * 300);
		}
		else if (option2 == 4)
		{
			rtype = "Suite";
			rr = "400";
			tc = to_string(totalDays * 400);
		}
		
		grtype.push_back(rtype);
    grmdate.push_back(rmdate);
		gcid.push_back(cid);
		gcod.push_back(cod);
		gphone.push_back("");
		gaddress.push_back("");
		gemail.push_back("");
		gid.push_back("");
		gvlp.push_back("");
		grr.push_back(rr);
		gtc.push_back(tc);
		gpay.push_back("0");
		gbal.push_back(tc);
		l += 1;

		ofstream outfile("GuestInformation.txt");
		for (int i = 0; i < l; i++)
		{
			outfile << grNum[i] << "," << gfName[i] << "," << glName[i] << "," <<  grtype[i] << "," <<grmdate[i] << "," << gcid[i] << "," << gcod[i] << "," << gphone[i] << "," << gaddress[i] << "," << gemail[i] << "," << gid[i] << "," << gvlp[i] << "," << grr[i] << "," << gtc[i] << "," << gpay[i] << "," << gbal[i];
      if (i<(l-1)){
        outfile<<"\n";
      }
      
		}


		outfile.close();


		cout << "Thanks for making the resevation.\n";
	}

	//pop the given like out of the vector
	if (option1 == 2)
	{
		cout << "Enter the First Name of the Reservatoin you wish to delete: " << endl;
		cin >> fName;
		string temp;
		for (int i = 0; i < l; i++)
		{
			temp = gfName[i];
			if (temp == fName)
			{
				swap(gfName[i], gfName.back());
				swap(glName[i], glName.back());
				swap(grNum[i], grNum.back());
				swap(grtype[i], grtype.back());
        swap(grmdate[i], grmdate.back());
				swap(gcid[i], gcid.back());
				swap(gcod[i], gcod.back());
				swap(gphone[i], gphone.back());
				swap(gaddress[i], gaddress.back());
				swap(gemail[i], gemail.back());
				swap(gid[i], gid.back());
				swap(gvlp[i], gvlp.back());
        swap(grr[i], grr.back());
				swap(gtc[i], gtc.back());
				swap(gpay[i], gpay.back());
				swap(gbal[i], gbal.back());
			}
		}
		//delete back
		l--;
		gfName.pop_back();
		glName.pop_back();
		grNum.pop_back();
		grtype.pop_back();
    grmdate.pop_back();
		gcid.pop_back();
		gcod.pop_back();
		gphone.pop_back();
		gaddress.pop_back();
		gemail.pop_back();
		gid.pop_back();
		gvlp.pop_back();
    grr.pop_back();
		gtc.pop_back();
		gpay.pop_back();
		gbal.pop_back();

		ofstream outfile("GuestInformation.txt");
		for (int i = 0; i < l; i++)
		{
			outfile << grNum[i] << "," << gfName[i] << "," << glName[i] << "," << grtype[i] << "," <<grmdate[i] << "," << gcid[i] << "," << gcod[i] << "," << gphone[i] << "," << gaddress[i] << "," << gemail[i] << "," << gid[i] << "," << gvlp[i] << "," << grr[i] << "," << gtc[i] << "," << gpay[i] << "," << gbal[i];
      if (i<(l-1)){
        outfile<<"\n";
      }
		}
		cout << "Reservation delete Success" << endl;
		outfile.close();
	}
	if (option1 == 3)
	{
		cout << "Enter the room number you want to select: " << endl;
		cin >> rNum;

		bool flag = true;
		string temp;
		while (flag)
		{
			for (int i = 0; i < l; i++)
			{
				temp = grNum[i];
				if (temp == rNum)
				{
					//cout << "B";
					flag = false;				
				}
			}
			if (flag == true)
			{
				cout << "\nRoom number entered is invalid, please enter a proper room number: ";
				cin >> rNum;
			}
		}
    int option1;
    cout << "Do You wish to check in with the reservation? (1 = Yes/ 2 = No)" << endl;
    cin >> option1;
    if(option1 == 1)
    {
      stay(rNum);
    }
	}
}

void HousekeepingScreen()
{
	string num, ava, siz, guest;
	vector<string> roomNum;
	vector<string> roomAva;
	vector<string> roomSiz;
	vector<string> roomGuest;
	int l = 0;

	ifstream infile("RoomInformation.txt");
	if (infile.is_open()) {
		string line;

		while (!infile.eof())
		{
			getline(infile, num, ',');
			roomNum.push_back(num);
			getline(infile, ava, ',');
			roomAva.push_back(ava);
			getline(infile, siz, ',');
			roomSiz.push_back(siz);
			getline(infile, guest, '\n');
			roomGuest.push_back(guest);
			l += 1;
		}
	}
	else cout << "Unable open file" << endl;
	infile.close();

	// print out list of unavailable rooms
	string temp;
	for (int i = 1; i < l; i++)
	{
		temp = roomAva[i];
		if (temp == "Unavailable/Occupied" || temp == "Unavailable/Dirty")
		{
			cout << roomNum[i] << " " << roomAva[i] << endl;
		}
	}

	// get user input for room
	string inputNum;
	cout << "\n\nEnter the room number you wish to select: ";
	cin >> inputNum;

	// check if user input matches a room
	bool flag = true;
	string temp2;
	int track;
	while (flag)
	{
		for (int i = 1; i < l; i++)
		{
			temp = roomAva[i];
			temp2 = roomNum[i];
			if (temp == "Unavailable/Occupied" || temp == "Unavailable/Dirty")
			{
				//cout << "A" << endl;
				//cout << temp2 << endl;
				//cout << inputNum << endl;
				if (temp2 == inputNum)
				{
					//cout << "B";
					flag = false;
					track = i;
					i = l;
				}
			}
		}
		if (flag == true)
		{
			cout << "\nRoom number entered is invalid, please enter a proper room number: ";
			cin >> inputNum;
		}
	}

	// give option to change room to unavailable/maintenace or go to room check
	int option;
	string status;
	cout << "1. Proceed to Room Check\n";
	cout <<"2. Change status to Unavailable/Maintenance" << endl;

	temp2 = roomAva[track];
	cin >> option;
	if (option == 2)
	{
		roomAva[track] = "Unavailable/Maintenance";
	}

	// room check list of options / if any left blank room stays dirty
	
	else if (option == 1)
	{
		bool clean = true;
		cout << "Enter Y for clean and N for not clean" << endl;
		cout << "Bathroom: ";
		cin >> status;
		if (status != "Y")
		{
			clean = false;
		}

		cout << "Towels: ";
		cin >> status;
		if (status != "Y")
		{
			clean = false;
		}

		cout << "Bed Sheets: ";
		cin >> status;
		if (status != "Y")
		{
			clean = false;
		}

		cout << "Vacuum: ";
		cin >> status;
		if (status != "Y")
		{
			clean = false;
		}

		cout << "Dusting: ";
		cin >> status;
		if (status != "Y")
		{
			clean = false;
		}

		cout << "Electronics: ";
		cin >> status;
		if (status != "Y")
		{
			clean = false;
		}

		if (clean == true)
		{
			temp = roomAva[track];
			if (temp == "Unavailable/Dirty")
			{
				roomAva[track] = "Available";
			}
		}

	}


	//print to file
	
	ofstream outfile("RoomInformation.txt");
	for (int i = 0; i < l; i++)
	{
		outfile << roomNum[i] << "," << roomAva[i] << "," << roomSiz[i] << "," << roomGuest[i];
    if (i<(l-1)){
      outfile<<"\n";
    }
	}


	outfile.close();
	

	/*
	for (int i = 0; i < l; i++)
	{
		cout << roomNum[i] << '\n' << roomAva[i] << '\n' << roomSiz[i] << '\n' << roomGuest[i] << endl;
	}
	*/
}
int test_reservation(){
  ReservationSceen();

  return 1;
}

int test_housekeeping(){
  HousekeepingScreen();

  return 1;
}