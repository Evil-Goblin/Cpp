#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> grades, vector<int> weights, int threshold) {


    int answer = 0;

	std::map<string, int> gw;
	gw["A+"] = 10;
	gw["A0"] = 9;
	gw["B+"] = 8;
	gw["B0"] = 7;
	gw["C+"] = 6;
	gw["C0"] = 5;
	gw["D+"] = 4;
	gw["D0"] = 3;
	gw["F"] = 0;

	for ( int i = 0 ; i < grades.size(); i++) {
		answer += gw[grades[i]]*weights[i];
	}
    
    return answer-threshold;
}

int main(int argc, char const *argv[])
{

	std::vector<string> grades = {"A+","D+","F","C0"};
	std::vector<int> weights = {2,5,10,3};
	int threshold = 50;

	cout << solution(grades,weights,threshold) <<endl;
	/* code */
	return 0;
}