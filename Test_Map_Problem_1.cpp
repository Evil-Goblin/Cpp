#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {

	std::vector<string> :: iterator vi;
	std::map<string, int> m;

	pair<map<string, int>::iterator, bool> pr;

	for( vi = participant.begin(); vi != participant.end(); vi++){
		pr = m.insert(make_pair(*vi,1));

		if ( pr.second == false ){
			m[*vi]++;
		}
	}
	for( vi = completion.begin(); vi != completion.end(); vi++){
		if ( m[*vi] == 1 ){
			m.erase(*vi);
		} else {
			m[*vi]--;
		}

	}


    string answer = m.begin()->first;
    return answer;
}

int main(int argc, char const *argv[])
{

	vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa", "josipa"};
	vector<string> completion ={"josipa", "filipa", "marina", "nikola", "vinko"};

	cout << solution(participant,completion) << endl;

	/* code */
	return 0;
}