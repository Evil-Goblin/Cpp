#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int money, vector<string> expected, vector<string> actual) {
    int bet = 100;
    for (int i = 0; i < expected.size(); ++i)
    {
    	if (expected[i] == actual[i])
    	{
    		money += bet;
    		bet = 100;
    	}else{
    		money -= bet;
    		bet *= 2;

    		if(money < bet){
    			bet = money;
    		}
    		if (money == 0)
    		{
    			return 0;
    		}
    	}
    }

    int answer = money;

    return answer;
}

int main(int argc, char const *argv[])
{
	int money = 1500;
	// std::vector<string> expected = {"H", "T", "H", "T", "H", "T", "H"};
	// std::vector<string> actual = {"T", "T", "H", "H", "T", "T", "H"};


	std::vector<string> expected = {"H", "H", "H", "T", "H"};
	std::vector<string> actual = {"T", "T", "T", "H", "T"};
	cout << solution(money,expected,actual) << endl;
	return 0;
}