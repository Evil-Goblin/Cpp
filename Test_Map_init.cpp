#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int val = 0;
	vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa", "josipa"};
	vector<string> completion ={"josipa", "filipa", "marina", "nikola", "vinko"};
	std::vector<string> :: iterator vi;
	std::map<string, int> m;
	std::map<string, int> :: iterator mi;
	pair<map<string, int>::iterator, bool> pr;


	for( vi = participant.begin(); vi != participant.end(); vi++){
		pr = m.insert(make_pair(*vi,1));
		if ( pr.second == false ){
			m[*vi]++;
		}
	}

	for ( mi = m.begin(); mi != m.end(); mi++){
		cout << mi->first << "  |||||||||  " << mi->second << endl;
	}


	/* code */
	return 0;
}