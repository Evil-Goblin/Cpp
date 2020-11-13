#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer(prices.size());

	for (int i = 0; i < prices.size(); ++i)
	{
		for (int j = i+1; j < prices.size(); ++j)
		{
			if(prices[i]<=prices[j]){
				answer[i] += 1;
			}else{
				answer[i] += 1;
				break;
			}
		}
	}



    return answer;
}


int main(int argc, char const *argv[])
{
	vector<int> prices = {1,2,3,2,3};
	vector<int> answer = solution(prices);

	vector<int> :: iterator ansi;

	for(ansi = answer.begin(); ansi != answer.end(); ansi++){
		cout << *ansi << endl;
	}

	return 0;
}