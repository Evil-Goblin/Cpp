#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> board) {

	std::vector<int> cursur = {0,0};
	map<int, vector<int>> indexmap;
    int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			indexmap[board[i][j]] = {i,j};
		}
	}

	for (int i = 1; i < n*n+1; ++i)
	{
		std::vector<int> posi = indexmap[i];
		int Hroute1 = abs(posi[0]-cursur[0]);
		int Hroute2 = n-Hroute1;

		int Wroute1 = abs(posi[1]-cursur[1]);
		int Wroute2 = n-Wroute1;

		int routelen = min(Hroute1,Hroute2)+min(Wroute2,Wroute1)+1;
		answer += routelen;
		cursur = posi;
	}

    return answer;
}

int main(int argc, char const *argv[])
{
	int n = 4;
	vector<vector<int>> board {{11, 9, 8, 12},
							{2, 15, 4, 14},
							{1, 10, 16, 3},
							{13, 7, 5, 6}};

	cout << solution(n,board) << endl;
	return 0;
}