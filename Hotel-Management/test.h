#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

int countLeapYears(int month, int year);

int getDifference(int m1, int d1, int y1, int m2, int d2, int y2);

void ReservationSceen();

void HousekeepingScreen();
int test_reservation();

int test_housekeeping();

int edit(int line,vector<string> gphone,vector<string>gaddress,vector<string>gemail,vector<string>gvlp);

int guest(string room);


int newcheckin(int line,vector<string> gfName,vector<string> glName,vector<string> grNum,vector<string> grtype,vector<string> grmdate,vector<string> gcid,vector<string> gcod,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp,vector<string> grr,vector<string> gtc,vector<string> gpay,vector<string> gbal);


int reservacheckin(int line,vector<string> grNum,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp);


int payment(int line,vector<string> gtc,vector<string> gpay,vector<string> gbal);


int checkin(int line,vector<string> gfName,vector<string> glName,vector<string> grNum,vector<string> grtype,vector<string> grmdate,vector<string> gcid,vector<string> gcod,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp,vector<string> grr,vector<string> gtc,vector<string> gpay,vector<string> gbal);

int checkout(int line,vector<string> gfName,vector<string> glName,vector<string> grNum,vector<string> grtype,vector<string> grmdate,vector<string> gcid,vector<string> gcod,vector<string> gphone,vector<string> gaddress,vector<string> gemail,vector<string> gid,vector<string> gvlp,vector<string> grr,vector<string> gtc,vector<string> gpay,vector<string> gbal);

int stay(string num);