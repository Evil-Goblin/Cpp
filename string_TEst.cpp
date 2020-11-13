#include <string>
#include <vector>
#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
	string penter = "1100";
	string pexit = "0011";
	string pescape = "1001";
	string data = "1101100100101111001111000000";

    string test = penter+pexit;

    cout << test << endl;
	return 0;
}