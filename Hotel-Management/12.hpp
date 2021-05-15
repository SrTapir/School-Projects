#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "test.h"

using namespace std;
vector<string> tokenize_string(string str, char delimeter);

/////////////File Reading///////////
vector<string> read_from_file(string src, char delimeter) {
	ifstream file;
	file.open(src);

	vector<string> result;
	if (file.is_open()) {
		string output;
		while (getline(file, output)) {
      vector<string> temp = tokenize_string(output, delimeter);

			for (string s : temp) result.push_back(s);
		}
	}
	return result;
}

string find_first_line(string src, string search_value) {
	ifstream file;
	file.open(src);

	if (file.is_open()) {
		string output;
		while (getline(file, output)) {
			if (output.find(search_value) != string::npos) return output;
		}
	}

	return "Not Found";
}

vector<string> find_all_lines(string src, string search_value) {
	ifstream file;
	file.open(src);

	vector<string> result;

	if (file.is_open()) {
		string output;
		while (getline(file, output)) {
			if (output.find(search_value) != string::npos) result.push_back(output);
		}
	}

	return result;
}

int find_collumn_index(string src, string collumn_name, char delimeter) {
	ifstream file(src);

	if (file.is_open()) {
		string data = "";
		int index = 0;
		while (getline(file, data, delimeter) && data.find(collumn_name) == string::npos) {
			index++;
		}
		if (data.find(collumn_name) == string::npos) {
			cout << "Collumn Name does not match any value in the file" << endl;
			return -1;
		}
		return index;
	}

	else {
		cout << "File not found";
		return -1;
	}
}

//////////Edit String///////////
string remove_commas(string str) {
	int index = str.find(',');
	while (str.find(',') != string::npos) {
		str.replace(index, 1, " ");
		index = str.find(',');
	}

	return str;
}

vector<string> tokenize_string(string str, char delimeter) {
	vector<string> result;

	while (str.find(delimeter) != string::npos) {
		if (str[0] == ' ') str = str.substr(1, str.size() - 1);
		int index = str.find(delimeter);
		result.push_back(str.substr(0, index));
		str = str.substr(index + 1, str.size() - index - 1);
	}
  if (str.length() > 0 && str[0] != '\n') result.push_back(str);

	return result;
}

////////////////////////File Edit////////////////////
void write_to_database(string src, string data) {
	ofstream file;
	file.open(src, ios::ate);
	file << data;
	file.close();
}

void edit_all_lines(string src, string previous_value, string new_value) {
	ifstream file(src);

	vector<string> result;
	if (file.is_open()) {
		string output;
		while (getline(file, output)) {
			int index = output.find(previous_value);
			if (index != string::npos) result.push_back(output.replace(index, previous_value.size(), new_value));
			else result.push_back(output);
		}
	}
	file.close();

	ofstream out(src);

	for (string line : result)	out << line << "\n";
}

void edit_first_line(string src, string previous_value, string new_value) {
	ifstream file(src);

	vector<string> result;
	bool found = false;

	if (file.is_open()) {
		string output;
		while (getline(file, output)) {

			int index = output.find(previous_value);
			if (!found && index != string::npos) {
				result.push_back(output.replace(index, previous_value.size(), new_value));
				found = true;
			}
			else result.push_back(output);
		}
	}
	file.close();

	ofstream out(src);
	for (string line : result) out << line << "\n";
	out.close();
}

void edit_guest_info(string guest_name, string collumn_name, string new_value) {
	ifstream file("GuestInformation.txt");

	vector<string> result;

	if (file.is_open()) {
		string output;
    int index = find_collumn_index("GuestInformation.txt", collumn_name, ',');
		while (getline(file, output)) {
			if (output.find(guest_name) != string::npos) {
        vector<string> line = tokenize_string(output, ',');
        line[index] = new_value;
        string temp = "";
        for (string data : line) temp += data + ',';
        temp = temp.substr(0, temp.size() - 1);
        result.push_back(temp);
      }
			else result.push_back(output);
		}
	}
	file.close();

	ofstream out("GuestInformation.txt");
	int size = result.size();
	for (int i = 0; i < size; i++) {
    if (i < size - 1) out << result[i] << "\n";
    else out << result[i];
  }
	out.close();
}

void edit_room_info(int room_num, string previous_value, string new_value) {
	ifstream file("RoomInformation.txt");

	vector<string> result;

	if (file.is_open()) {
		string output;
		while (getline(file, output)) {
			int index = output.find(previous_value);
			if (output.find(to_string(room_num)) != string::npos && index != string::npos)
				result.push_back(output.replace(index, previous_value.size(), new_value));
			else result.push_back(output);
		}
	}
	file.close();

	ofstream out("RoomInformation.txt");
  int size = result.size();
	for (int i = 0; i < size; i++) {
    if (i < size - 1) out << result[i] << "\n";
    else out << result[i];
  }
	out.close();
}

////////Room Status Capability 1//////////////
void print_rooms(vector<string> nums, vector<string> types, vector<string> status, int size) {
	cout << "Room Number\t| Type\t\t\t| Status\n";

	for (int i = 0; i < size + 1; i++) {
		string temp = nums[i];
		temp.resize(11, ' ');
		cout << temp;
		temp = status[i];
		temp.resize(24, ' ');
		cout << "\t| " + temp;
		cout << "\t| " + types[i];
    cout << endl;
	}
	cout << endl;
}

void display_rooms_status() {
	vector<string> data = read_from_file("RoomInformation.txt", ',');

	int start = 4;
	int end = data.size();
	vector<string> nums, type, status;

	for (int i = start; i < end; i += start) {
		int index = (i / 4) - 1;
		nums.push_back(data[i]);
		type.push_back(data[i + 1]);
		status.push_back(data[i + 2]);
	}

	print_rooms(nums, type, status, (end - start) / 4);
}

void check_room_status(string data, int room_num) {
	if (data.find("Available") != string::npos) {
    stay(to_string(room_num));
	}
	else if (data.find("Unavailable/Occupied") != string::npos) {
    stay(to_string(room_num));
	}
	else if (data.find("Unavailable/Dirty") != string::npos) {
		cout << "The room is dirty. Do you still want to check in? (y/n)";
		char response;
		cin >> response;
		if (response == 'y') edit_room_info(room_num, "Unavailable/Dirty", "Unavailable/Occupied");
	}
	else if (data.find("Unavailable/Maintenance") != string::npos) {
		cout << "The room is dirty. Do you still want to check in? (y/n)";
		char response;
		cin >> response;
		if (response == 'y') edit_room_info(room_num, "Unavailable/Maintenance", "Unavailable/Occupied");
	}
}

int room_status_menu() {
	display_rooms_status();

	cout << "1. Select Room Number" << endl;
	cout << "2. Main Menu" << endl;
	int choice;
	cin >> choice;
	if (choice == 2) return 1;

	cout << "Enter a room number: ";
	int room_num;
	cin >> room_num;

	string data = find_first_line("RoomInformation.txt", to_string(room_num));
	if (data == "Not Found") {
		cout << "Room Not Found" << endl;
		return 1;
	}

	check_room_status(data, room_num);

	return 1;
}

////////Weekly Status Capability 2//////////////
/*vector<int> get_current_date() {
	SYSTEMTIME now;
	GetLocalTime(&now);

	vector<int> result = { now.wDay, now.wMonth, now.wYear };

	return result;
}*/

int days_in_between(vector<int> start_date, int month, int day) {
	if (month == start_date[1]) return abs(day - start_date[0]);
	int result = 0;
	if (start_date[1] == 2) result += abs(28 - start_date[0]);
	else if (start_date[1] == 4 || start_date[1] == 6 || start_date[1] == 9 || start_date[1] == 11) result += abs(30 - start_date[0]);
	else result += abs(31 - start_date[0]);
	start_date[1] += 1;
	start_date[0] = 0;
	if (start_date[1] == month) return result + day;
	return result + days_in_between(start_date, month, day);
}

int month_to_int(string month) {
	if (!month.compare("January")) return 1;
	else if (!month.compare("Febuary")) return 2;
	else if (!month.compare("March")) return 3;
	else if (!month.compare("April")) return 4;
	else if (!month.compare("May")) return 5;
	else if (!month.compare("June")) return 6;
	else if (!month.compare("July")) return 7;
	else if (!month.compare("August")) return 8;
	else if (!month.compare("September")) return 9;
	else if (!month.compare("October")) return 10;
	else if (!month.compare("November")) return 11;
	else if (!month.compare("December")) return 12;
	return 0;
}

bool date_in_range(string start_date, string end_date, string date) {
	int month = month_to_int(date.substr(0, date.find(' ')));
	int start_month = month_to_int(start_date.substr(0, start_date.find(' ')));
	int end_month = month_to_int(end_date.substr(0, end_date.find(' ')));

	if (month > start_month && month < end_month) return true;
	if (month != start_month && month != end_month) return false;

	int day = atoi(date.substr(date.find(' ') + 1, 2).c_str());
	int start_day = atoi(start_date.substr(start_date.find(' ') + 1, 2).c_str());
	int end_day = atoi(end_date.substr(end_date.find(' ') + 1, 2).c_str());

	if (month == start_month) return day >= start_day;
	if (month == end_month) return day <= end_day;

	return false;
}

string print_name(string name, int num_of_times) {
	if (name[0] == '\n') name = name.substr(1, name.size() - 1);
	string line = "";
	int len = name.length();
	for (int i = 0; i < num_of_times; i++) {
		line += name;
		if (len < 16) line += "\t";
		if (len < 8) line += "\t";
	}
	return line;
}

string print_date(string month, int day) {
	string result = "\t\t";

	int size = month.length();
	bool less = size < 5;

	for (int i = 0; i < 7; i++) {
		if (size == 5) less = day < 10;
		result += month + " " + to_string(day++);
		if (less) result += "\t";
		result += "\t";
	}

	return result;
}

string print_date(int month, int day) {
	string result = "\t\t";

	for (int i = 0; i < 7; i++) {
		if (month == 2) {
			if (day > 28) {
				month++;
				day = 1;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) {
				month++;
				day = 1;
			}
		}
		else if (day > 31) {
			month++;
			day = 1;
		}
		result += to_string(month) + "-" + to_string(day++);
		result += "\t\t";
	}

	return result;
}

string print_reservations(int num, string name, int start, int last) {
	string result = "";
	result += "\nRoom" + to_string(num);
	result += "\t" + print_name(name, last - start);
	return result;
}

string print_reservations(vector<int> nums, vector<string> names, vector<int> start, vector<int> last, int month, int day) {
	string result = "";
	result += print_date(month, day);

	result += "\nRoom " + to_string(nums[0]);
	result += "\t";
	result += print_name("", start[0]);
	result += print_name(names[0], 1 + last[0] - start[0]);
	int last_room = nums[0];
	int size = nums.size();

	for (int i = 1; i < size; i++) {
		if (last_room != nums[i]) {
			result += "\nRoom " + to_string(nums[i]);
			result += "\t";
			result += print_name("", start[i]);
		}
		else result += print_name("", start[i] - last[i - 1] - 1);
		last_room = nums[i];
		result += print_name(names[i], 1 + last[i] - start[i]);
	}

	result += "\n\n";

	return result;
}

void display_weekly_reservations() {
	vector<string> data = read_from_file("GuestInformation.txt", ',');
	vector<string> columns = tokenize_string(find_first_line("GuestInformation.txt", "Name"), ',');

	int size = data.size();
	int row_length = columns.size();
  int name_index = find_collumn_index("GuestInformation.txt", "First Name", ',');
	int checkIn = find_collumn_index("GuestInformation.txt", "Check In Date", ',');
	int checkOut = find_collumn_index("GuestInformation.txt", "Check Out Date", ',');
	int roomNumIndex = find_collumn_index("GuestInformation.txt", "Room#", ',');
	vector<int> nums, first, last;
	vector<string> names;

	for (int i = row_length; i < size; i+= row_length) {
		vector<string> start = tokenize_string(data[i + checkIn], '-');
		vector<string> end = tokenize_string(data[i + checkOut], '-');
    
		names.push_back(data[i + name_index] + " " + data[i + 1 + name_index]);
		nums.push_back(atoi(data[i + roomNumIndex].c_str()));
    if (start.size() > 1) {
    first.push_back(days_in_between({ 21, 4, 2021 }, atoi(start[0].c_str()), atoi(start[1].c_str())));
		int temp = days_in_between({ 21, 4, 2021 }, atoi(end[0].c_str()), atoi(end[1].c_str()));
		if (temp > 7) last.push_back(7);
		else last.push_back(temp);
    }
    else {
      first.push_back(0);
      last.push_back(7);
    }
	}
	cout << print_reservations(nums, names, first, last, 4, 21) << endl;
}

int check_availability(int room_num, vector<int> current_date) {
	vector<string> data = find_all_lines("GuestInformation.txt", to_string(room_num));

  int name_index = find_collumn_index("GuestInformation.txt", "First Name", ',');

	if (data.size() < 1 || (data.size() == 1 && tokenize_string(data[0], ',')[name_index] == "")) {
		cout << "Do you want to check in today? (y/n)";
		char choice;
		cin >> choice;

		if (choice == 'y') return stay(to_string(room_num));
		else return test_reservation();
	}

	string occupied_guest = "";


	for (string guest : data) {
		int check_in = find_collumn_index("GuestInformation.txt", "Check In Date", ',');
		int check_out = find_collumn_index("GuestInformation.txt", "Check Out Date", ',');
		vector<string> temp = tokenize_string(tokenize_string(guest, ',')[check_in], '-');
		vector<int> in_date = { atoi(temp[0].c_str()),atoi(temp[1].c_str()), atoi(temp[2].c_str()) };
		if (in_date[0] == current_date[0] && in_date[1] == current_date[1] && in_date[2] == current_date[2]) occupied_guest = guest;
		else if (in_date[2] < current_date[0] || (in_date[2] == current_date[2] && (in_date[0] < current_date[0] || (in_date[0] == current_date[0] && in_date[1] < current_date[0])))) {
			vector<string> temp = tokenize_string(tokenize_string(guest, ',')[check_out], '-');
			vector<int> out_date = { atoi(temp[0].c_str()),atoi(temp[1].c_str()), atoi(temp[2].c_str()) };
			if (out_date[2] > current_date[0] || (out_date[2] == current_date[2] && (out_date[0] > current_date[0] || (out_date[0] == current_date[0] && out_date[1] > current_date[0]))))
				occupied_guest = guest;
		}
	}

	if (occupied_guest != "") {
		return stay(to_string(room_num));
	}

	else {
		return test_reservation();
	}

}

int weekly_availability_menu() {
	display_weekly_reservations();

	cout << "1. Select Room Number" << endl;
	cout << "2. Main Menu" << endl;
	int choice;
	cin >> choice;
	if (choice == 2) return 1;

	cout << "Enter a room number: ";
	int room_num;
	cin >> room_num;

	return check_availability(room_num, {4, 21, 2021});
}