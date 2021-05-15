#include <iostream>
#include "test.h"

using namespace std;
int listline;
//Editing function for edit gust info
int edit(int line,vector<string> grNum,vector<string> gphone,vector<string>gaddress,vector<string>gemail,vector<string>gvlp){
  int pick;
  cout<<"\n"<<endl;
  cout<<"------------------------------------------------------------------------------------------"<<endl;
  //pick the info need to edit
  cout<<"Pick the Info need to Edit:\n"<<endl;
  cout<<"1.Edit Phone\t2.Edit Address\t3.Edit Email\t4.Edit License"<<endl;
  cin>>pick;
  if(pick ==1){
	//stroe the new info to news and replace to the current one.
    string news;
    cout<<"Input the new Phone Number:"<<endl;
    cin.get();
    getline(cin,news);
    gphone[line]=news;
    edit_guest_info(grNum[line],"Phone#",gphone[line]);
    
  }
  else if(pick == 2){
    string news;
    cout<<"Input the new Address:"<<endl;
    cin.get();
    getline(cin,news);
    gaddress[line]=news;
    edit_guest_info(grNum[line],"Address",gaddress[line]);
  }
  else if(pick == 3){
    string news;
    cout<<"Input the new Email:"<<endl;
    cin.get();
    getline(cin,news);
    gemail[line]=news;
    edit_guest_info(grNum[line],"Email",gemail[line]);
  }
  else if(pick == 4){
    string news;
    cout<<"Input the new License:"<<endl;
    cin.get();
    getline(cin,news);
    gvlp[line]=news;
    edit_guest_info(grNum[line],"License Plate",gvlp[line]);
  }
  return 1;
}

//Guest page function, call it with num number , bring you to guest page
int guest(string room) {
	//set different vecter to store the file information 
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
//open file and store the data into vector.
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
	//check file open seccess. 
	else cout << "Unable open file" << endl;
	infile.close();
  int line;
  for (int i = 0; i<l;i++){
    if (room == grNum[i]){
      line = i;
    }

  }
  //print out the page, print out the infomation. 
  cout << "Guest profile\n\n";
  cout << "Room#  First Name\t Last Name \t\tPhone \t\t\tAddress \t\t\t\tE-mail\t\t\t ID Info\t Vehicle License"<<endl;
  cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
  cout<<grNum[line]<<"\t\t"<<gfName[line]<<"\t\t"<<glName[line]<<"\t"<<gphone[line]<<"\t  "<<gaddress[line]<<"\t"<<gemail[line]<<"\t "<<gid[line]<<" \t\t"<<gvlp[line]<<endl;
  cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n1.Menul\t2.Edit Profile"<<endl;
  int num;
  cin>>num;
  if(num==1){
    return 1;
  }
  else if(num==2){
    edit(line,grNum,gphone,gaddress,gemail,gvlp);
  }
  return 1;
}

//checkin function for walk in customer. 
int newcheckin(int line,vector<string> gfName,vector<string> glName,vector<string> grNum,vector<string> grtype,vector<string> grmdate,vector<string> gcid,vector<string> gcod,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp,vector<string> grr,vector<string> gtc,vector<string> gpay,vector<string> gbal){
	int  option2; 
	bool availability = true;	
	//check in date
	int cInMonth, cInDay, cInYear;
	//check out date
	int cOutMonth, cOutDay, cOutYear;
	string phone, add, email,id,vlp;
	string fName, lName, rNum, rtype, cid, cod, tc, pay, bal,rr;
	cout << "Enter First Name: ";
	cin >> fName;
	cout << "Enter Last Name: ";
	cin >> lName;

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
	cout << "Enter Checkout Year: ";
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
			int total = 100 * totalDays;
			cout << total << endl;
		}

		cout << "2. Double Queen: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $200, your total is $";
			int total = 200 * totalDays;
			cout << total << endl;
		}

		cout << "3. Double Queen with Kitchen: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $300, your total is $";
			int total = 300 * totalDays;
			cout << total << endl;
		}

		cout << "4. Suite: Available\n";
		if (availability == true)
		{
			cout << "Daily rate is $400, your total is $";
			int total = 400 * totalDays;
			cout << total << endl;
		}

	cout << "Please select one of the options 1, 2, 3, or 4: ";
	cin >> option2;

	gfName[line]=fName;
	glName[line]=lName;
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
	//input guest info
	cout<<"\nNow Input Guest Information:"<<endl;
	cout<<"Input the Guest Phone number :"<<endl;
	getline(cin,phone);
	gphone[line]=phone;
	cout<<"Input the Guest address :"<<endl;
	getline(cin,add);
	gaddress[line]=add;
	cout<<"Input the Guest E-mail"<<endl;
	getline(cin,email);
	gemail[line] = email;
	cout<<"Input the Guest ID# :"<<endl;
	getline(cin,id);
	gid[line]=id;
	cout<<"Input the Guest Vehicle License Plate: "<<endl;
	getline(cin,vlp);
	gvlp[line]=vlp;
  int roomnum = atoi(grNum[line].c_str());
  edit_room_info(roomnum, "Available", "Unavailable/Occupied");
	pay="0";
	grtype[line]=rtype;
	gcid[line]=cid;
	gcod[line] = cod;
	grr[line]=rr;
	gtc[line]=tc;
	gpay[line]=pay;
	gbal[line]=tc;
	grmdate[line]=cid;
	//store the change in to the file.
  edit_guest_info(grNum[line],"Guest First Name",gfName[line]);
  edit_guest_info(grNum[line],"Guest Last Name",glName[line]);
  edit_guest_info(grNum[line],"Room Type",grtype[line]);
  edit_guest_info(grNum[line],"Reservation Made Date",grmdate[line]);
  edit_guest_info(grNum[line],"Check In Date",gcid[line]);
  edit_guest_info(grNum[line],"Check Out Date",gcod[line]);
  edit_guest_info(grNum[line],"Phone#",gphone[line]);
  edit_guest_info(grNum[line],"Address",gaddress[line]);
  edit_guest_info(grNum[line],"Email",gemail[line]);
  edit_guest_info(grNum[line],"License Plate",gvlp[line]);
  edit_guest_info(grNum[line],"ID",gid[line]);
  edit_guest_info(grNum[line],"Room Rate",grr[line]);
  edit_guest_info(grNum[line],"Total Charge",gtc[line]);
  edit_guest_info(grNum[line],"Payments Made",gpay[line]);
  edit_guest_info(grNum[line],"Balance",gbal[line]);
  //edit_guest_info(grNum[line],"",[line]);//edit file formate
  return 0;

}

//check in page for customer with reservation
int reservacheckin(int line,vector<string> grNum,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp){
  string phone, add, email,id,vlp;
	cout<<"\n<<<<< Reservation Check In Page >>>>>"<<endl;
	cout<<"Input the Guest Phone number :"<<endl;
	getline(cin,phone);
	gphone[line]=phone;
  cin.ignore();
	cout<<"Input the Guest address :"<<endl;
	getline(cin,add);
	gaddress[line]=add;
  cin.ignore();
	cout<<"Input the Guest E-mail"<<endl;
	getline(cin,email);
	gemail[line] = email;
  cin.ignore();
	cout<<"Input the Guest ID# :"<<endl;
	getline(cin,id);
	gid[line]=id;
  cin.ignore();
	cout<<"Input the Guest Vehicle License Plate: "<<endl;
	getline(cin,vlp);
	gvlp[line]=vlp;
  cin.ignore();
  //store info to the file.
  edit_guest_info(grNum[line],"Phone#",gphone[line]);
  edit_guest_info(grNum[line],"Address",gaddress[line]);
  edit_guest_info(grNum[line],"Email",gemail[line]);
  edit_guest_info(grNum[line],"License Plate",gvlp[line]);
  edit_guest_info(grNum[line],"ID",gid[line]);
  int roomnum = atoi(grNum[line].c_str());
  edit_room_info(roomnum, "Available", "Unavailable/Occupied");
	cout<<"\n Guest Check In Complect\n"<<endl;
  return 1;
}

//payment function for guest.
int payment(int line,vector<string>grNum,vector<string> gtc,vector<string> gpay,vector<string> gbal){
    cout<<"\nGuest balance leave $"<<gbal[line]<<endl;
    cout<<"Input payment amount"<<endl;
    int amount;
    cin>>amount;
	//check amount still need to pay after this payment,
    int total = atoi(gtc[line].c_str());
	int pay = atoi(gpay[line].c_str());
	int balance = atoi(gbal[line].c_str());

	pay = pay+amount;
	balance = total-pay;
  	gpay[line]= to_string(pay);
	gbal[line]=to_string(balance);
  
  edit_guest_info(grNum[line],"Payments Made",gpay[line]);
  edit_guest_info(grNum[line],"Balance",gbal[line]);
  return 0;
}

//check in function
int checkin(int line,vector<string> gfName,vector<string> glName,vector<string> grNum,vector<string> grtype,vector<string> grmdate,vector<string> gcid,vector<string> gcod,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp,vector<string> grr,vector<string> gtc,vector<string> gpay,vector<string> gbal){
    cout<<"\n::::::Check In Page::::::"<<endl;
	//pick the type of check in.
    cout<<"1.New Guest Chink In \t 2.Reservation Check In"<<endl;
    int pick;
    cin>>pick;
    if(pick == 1){
        newcheckin(line,gfName,glName,grNum,grtype,grmdate,gcid,gcod,gphone,gaddress,gemail,gid,gvlp,grr,gtc,gpay,gbal);
    }
    else if(pick == 2){
        reservacheckin(line,grNum,gphone,gaddress,gemail,gid,gvlp);
    }
    return 1;
}

//check out function. 
int checkout(int line,vector<string> gfName,vector<string> glName,vector<string> grNum,vector<string> grtype,vector<string> grmdate,vector<string> gcid,vector<string> gcod,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp,vector<string> grr,vector<string> gtc,vector<string> gpay,vector<string> gbal){
	char out;
  int bal= atoi(gbal[line].c_str());
  //check current balance before compelct check out.
	cout<<"Check Guest Current Blance : $"<<bal<<endl;
	// if balance is 0, able to check out.
	if(bal==0){
		cout<<"Guest available to check out."<<endl;
		cout<<"Comfim to check out (Y/N):"<<endl;
		cin>>out;
		//comfim to check out , and update the room to emtry. 
		if(out == 'Y'|| out=='y'){
			gfName[line]="";
			glName[line]="";
			gcid[line]="";
			gcod[line]="";
			grmdate[line]="";
			gphone[line]="";
			gaddress[line]="";
			gid[line]="";
			gvlp[line]="";
			gemail[line]="";
			gtc[line]="";
			gpay[line]="";
			gbal[line]="";
      edit_guest_info(grNum[line],"Guest First Name",gfName[line]);
      edit_guest_info(grNum[line],"Guest Last Name",glName[line]);
      
      edit_guest_info(grNum[line],"Reservation Made Date",grmdate[line]);
      edit_guest_info(grNum[line],"Check In Date",gcid[line]);
      edit_guest_info(grNum[line],"Check Out Date",gcod[line]);
      edit_guest_info(grNum[line],"Phone#",gphone[line]);
      edit_guest_info(grNum[line],"Address",gaddress[line]);
      edit_guest_info(grNum[line],"Email",gemail[line]);
      edit_guest_info(grNum[line],"License Plate",gvlp[line]);
      edit_guest_info(grNum[line],"ID",gid[line]);
      edit_guest_info(grNum[line],"Room Rate",grr[line]);
      edit_guest_info(grNum[line],"Total Charge",gtc[line]);
      edit_guest_info(grNum[line],"Payments Made",gpay[line]);
      edit_guest_info(grNum[line],"Balance",gbal[line]);
      int roomnum = atoi(grNum[line].c_str());
      edit_room_info(roomnum, "Unavailable/Occupied", "Unavailable/Dirty");
		}
		else{
			return 1;
		}
	}
	//if balance not 0,. bring it to  the payment page to do the payment. 
	else{
		cout<<"Guest Still have Blance need to be pay."<<endl;
		cout<<"return to payment page now..."<<endl;
		payment(line,grNum,gtc,gpay,gbal);
	}
  return 1;
}

//guest currrent stay page
int stay(string num){
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

	fstream infile("GuestInformation.txt");
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
  listline = l;
  int line;
  for (int i = 0; i<l;i++){
    if (num == grNum[i]){
      line = i;
    }

  }
    cout<<"Current Room Stay\n"<<endl;
    
    cout<<"Room# \t\t Guest \t\tCheckIn \tCheckOut \tRoom  ($/Day)  Total  Pay-Made  Balance"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<grNum[line]<<" \t"<<gfName[line]<<" "<<glName[line]<<"\t"<<gcid[line]<<"\t"<<gcod[line]<<"\t"<<grtype[line]<<"\t"<<grr[line]<<"\t\t"<<gtc[line]<<"\t\t"<<gpay[line]<<"\t\t"<<gbal[line]<<endl;//display list of room
    cout<<"\n1.Menul\t2.Edit Guest\t3.Check In\t4.Payment\t5.Check Out"<<endl;
    int pick;
    cin>>pick;
    if(pick==1){
        return 1;
    }
    else if(pick==2){
        edit(line,grNum,gphone,gaddress,gemail,gvlp);
    }
    else if(pick==3){
        checkin(line,gfName,glName,grNum,grtype,grmdate,gcid,gcod,gphone,gaddress,gemail,gid,gvlp,grr,gtc,gpay,gbal);
    }
    else if(pick == 4){
        payment(line,grNum,gtc,gpay,gbal);
    }
    else if(pick == 5){
        checkout(line,gfName,glName,grNum,grtype,grmdate,gcid,gcod,gphone,gaddress,gemail,gid,gvlp,grr,gtc,gpay,gbal);
    }
  return 1;
}
