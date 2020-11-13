#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<long long> solution(string s, string op) {
    vector<long long> answer;

	for (int i = 1; i < s.size(); ++i)
	{
		string sb1 = s.substr(0,i);
		string sb2 = s.substr(i,s.size()-i);

		if(op == "+"){
			answer.push_back(stoi(sb1)+stoi(sb2));
		}else if(op == "*"){
			answer.push_back(stoi(sb1)*stoi(sb2));
		}else{
			answer.push_back(stoi(sb1)-stoi(sb2));
		}
	}

    return answer;
}

int main(int argc, char const *argv[])
{
	string s = "1234";
	string op = "+";

    vector<long long> answer = solution(s,op);

    for (int i = 0; i < answer.size(); ++i)
    {
    	cout << answer[i] << endl;
    }
	return 0;
}