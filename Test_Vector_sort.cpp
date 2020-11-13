#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
	std::vector<string> v = {"119", "97674223", "1195524421"};

	sort(v.begin(),v.end());

	std::vector<string> :: iterator vi;

	for(vi = v.begin(); vi != v.end(); vi++){
		cout << *vi << endl;
	}
	return 0;
}