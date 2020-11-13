#include <string>
#include <vector>
#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
	string s = "1234";
	string op = "+";



	for (int i = 1; i < s.size(); ++i)
	{
		string sb1 = s.substr(0,i);
		string sb2 = s.substr(i,s.size()-i);

		cout << sb1 << " :: " << sb2 << endl;

	}


	return 0;
}