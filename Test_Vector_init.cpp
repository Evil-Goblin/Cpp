#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;




int main(int argc, char const *argv[])
{
	vector<string> :: iterator vi;
	vector<string> v = {"marina", "josipa", "nikola", "vinko", "filipa"};
	
	for (vi = v.begin(); vi != v.end(); ++vi)
	{
		cout << *vi << endl;
	}
	/* code */
	return 0;
}