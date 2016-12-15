#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
using namespace std;

int main() {
	vector<string> first;
	vector<string> second;
	string inputName;
	cout << "Give a file name to open" << endl;
	cin >> inputName;
	string line;
	string prevline;
	ifstream ReadFile;
	ofstream myfile;
	ofstream myfiletemp;
	myfile.open("C:\\Users\\Spencer\\Desktop\\Temp\\SpamOrgOut.txt");
	myfiletemp.open("C:\\Users\\Spencer\\Desktop\\Temp\\SpamOrgTemp.txt");

	try
	{
		ReadFile.open("C:\\Users\\Spencer\\Desktop\\Temp\\SpamOrg.txt");
		while (ReadFile.good())
		{
			getline(ReadFile, line);
			first.push_back(line);
		}
	}
	catch(exception e)
	{
		cout << "that file does not exist" << endl;
	}
	bool noswitch = false;
	while (!noswitch)
	{
		noswitch = true;
		for (int i = 0; i < first.size(); i++)
		{
			if (i != first.size() - 1)
			{
				if (first.at(i) < first.at(i + 1))
				{
					string temp = first.at(i);
					first.at(i) = first.at(i + 1);
					first.at(i + 1) = temp;
					noswitch = false;
				}
			}
		}

	}


	for (int i = first.size(); i > 0; i--)
	{
		//myfiletemp << "THE SIZE IS " << first.size() << endl;
		myfiletemp << first.back() << "\n";
		first.pop_back();
	}
	for (int i = second.size(); i > 0; i--)
	{
		myfile << second.back() << "\n";
		second.pop_back();
	}
	myfile.close();
	ReadFile.close();
	myfiletemp.close();

}