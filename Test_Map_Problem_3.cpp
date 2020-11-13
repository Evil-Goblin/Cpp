#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {

	int answer = 1;
	map<string, int> m;
	pair<map<string, int>::iterator, bool> pr;

	vector<vector<string>> :: iterator vi;
	
	map<string, int> :: iterator mi;

	for(vi = clothes.begin() ; vi != clothes.end() ; vi++){
		pr = m.insert(make_pair((*vi)[1],1));

		if ( pr.second == false ){
			m[(*vi)[1]]++;
		}
	}

	for(mi = m.begin();mi!=m.end();mi++){
		answer *= mi->second+1;
	}

    return answer-1;
}

int main(int argc, char const *argv[])
{
	
	vector<vector<string>> clothes = {{"yellow_hat","headgear"},
							{"blue_sunglasses","eyewear"},{"green_turban","headgear"}};
	
	
	cout << solution(clothes) << endl;
	return 0;
}