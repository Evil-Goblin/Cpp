#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int cw_100(int progress, int speed){
	int answer = (int)ceil((double)(100-progress)/speed);


	return answer;
}

int main(int argc, char const *argv[])
{
	vector<int> progresses = {93,30,55};
	vector<int> speeds = {1,30,5};

	for (int i = 0; i < 3; ++i)
	{
		cout << cw_100(progresses[i],speeds[i]) << endl;
	}

	return 0;
}