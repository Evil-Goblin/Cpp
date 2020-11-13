#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

string solution(string penter, string pexit, string pescape, string data) {

	int len = penter.size();
    string answer = penter;

    for (int i = 0; i < data.size(); i=i+len)
    {
    	string sub = data.substr(i,len);
    	if(strcmp(penter.c_str(),sub.c_str())==0){
    		answer += pescape;
    	}else if(strcmp(pexit.c_str(),sub.c_str())==0){
    		answer += pescape;
    	}else if(strcmp(pescape.c_str(),sub.c_str())==0){
    		answer += pescape;
    	}
    	answer += sub;
    }
    answer += pexit;

    return answer;
}

int main(int argc, char const *argv[])
{
	string penter = "1100";
	string pexit = "0010";
	string pescape = "1001";
	string data = "1101100100101111001111000000";
	string result = "110011011001100110010010111100111001110000000010";

	cout << solution(penter,pexit,pescape,data) << endl;
	cout << result << endl;


	return 0;
}