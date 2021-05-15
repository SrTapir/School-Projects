#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string removeComments(const string& str, bool& comment)
{
	int n = str.length();
	string res;

	for(int i = 0; i < n; i++)
	{
		if(comment == true && str[i] == '*' && str[i+1] == ')')
		{
			comment = false;
			i++;
		}
		else if(comment)
    {
      continue;
    }
		else if(str[i] == '(' && str[i+1] == '*')
		{
			comment = true;
			i++;
		}
		else
    {
      res += str[i];
    }
	}

	return res;
}

bool bothSpaces(char lhs, char rhs)
{
  return (lhs == rhs) && (lhs == ' ');
}

void removeExtraSpaces(string &str)
{
  int count = 0;

  string::iterator new_end = unique(str.begin(), str.end(), bothSpaces);
  str.erase(new_end, str.end());

  size_t start = str.find_first_not_of(WHITESPACE);
  str.erase(0, start);
}

void insertSpace(string &str)
{
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] == '*' || str[i] == '+'
     || str[i] == '/' || str[i] == '-')
    {
      str.insert(i++, " ");
      str.insert(i+1, " ");
    }
  }
}



int main()
{
	ifstream inFile;
	ofstream outFile;
	string inFilename = "final.txt";
	string outFilename = "final2.txt";
	string str, tempStr;

	inFile.open(inFilename.c_str());

	if (inFile.fail()) {
		cout << "\nInvaild file\n";
		return 0;
	}

	outFile.open(outFilename.c_str());

	if (inFile.is_open())
	{
		bool comment = false;

		while (getline(inFile, tempStr))
		{
			str = removeComments(tempStr, comment);

			insertSpace(str);

			removeExtraSpaces(str);

			if (!str.empty())
				outFile << str << endl;
		}

		inFile.close();
	}

	outFile.close();

	return 0;
}
