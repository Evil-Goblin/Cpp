#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int cw_100(int progress, int speed){
	int answer = (int)ceil((double)(100-progress)/speed);
	return answer;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;

	queue<int> cw;

	for (int i = 0; i < progresses.size(); ++i)
	{
		cw.push(cw_100(progresses[i],speeds[i]));
	}

	while(true){
		int cnt = 0;
		int first = cw.front();
		while(first>=cw.front()&&!cw.empty()){
			cnt++;
			cw.pop();
		}
		answer.push_back(cnt);
		if(cw.empty()){
			break;
		}
	}

    return answer;
}

int main(int argc, char const *argv[])
{
	vector<int> progresses = {93,30,55};
	vector<int> speeds = {1,30,5};

	vector<int> ans = solution(progresses,speeds);

	for(int i = 0 ; i < ans.size(); i++){
		cout << ans[i] << endl;
	}

	return 0;
}