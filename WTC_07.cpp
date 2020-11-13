#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n, bool horizontal) {
    vector<vector<int>> answer(n,vector<int>(n,0));
	int a = 0;
	int ud = 0;
    for (int i = 0; i < n; ++i)
    {
    	if (i!=0&&i%2==0)
    	{
    		a++;
    	}else if(i%2 == 1){
    		a = answer[0][i-1]+(2*i-1)*2+1;
    	}
    	int adv = a;
    	for (int j = 0; j <= i; ++j)
    	{
    		answer[j][i-j] =adv;
    		if(ud%2 == 0){
    			adv += 2;
    		}else{
    			adv -= 2;	
    		}
    	}
    	ud++;    	
    }
    if (n%2!=0)
    {
    	a = answer[n-1][0] + 2*(n-2)+1;
    }else{
    	a = answer[0][n-1]+1;
    }
    for (int i = 1; i < n; ++i)
    {
    	int adv = a;
    	int k = n-1;
    	for (int j = i; j < n; j++)
    	{
    		answer[j][k] = adv;
    		if(ud%2 == 0){
    			adv += 2;
    		}else{
    			adv -= 2;	
    		}
    		k--;
    		
    	}
    	if (ud%2!=0)
    	{
    		a++;
    	}else{
    		a += (2*(n-i-1)-1)*2+1;
    	}
    	ud++;
    }

    if (horizontal)
    {
    	int tmp;
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < i; ++j)
    		{
    			tmp = answer[i][j];
    			answer[i][j] = answer[j][i];
    			answer[j][i] = tmp;
    		}
    	}
    }

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cout << answer[i][j] << " ";
    	}
    	cout << endl;
    }




    return answer;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	bool horizontal = false;
	// int n = 4;
	// bool horizontal = true;
	vector<vector<int>> result = solution(n,horizontal);


	return 0;
}