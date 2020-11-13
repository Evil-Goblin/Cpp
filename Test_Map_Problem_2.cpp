#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string max(string a, string b)
{

	if(a.length() > b.length()) return a;

	else return b;

}

string min(string a, string b)
{

	if(a.length() < b.length()) return a;

	else return b;

}


bool solution(vector<string> phone_book) {
    
    bool answer = true;

	sort(phone_book.begin(),phone_book.end());

	std::vector<string> :: iterator vi;

	for(vi = phone_book.begin(); vi != phone_book.end()-1; vi++){
		if(strncmp((*vi).c_str(),(*(vi+1)).c_str(),strlen(min(*vi,*(vi+1)).c_str())) == 0){
			answer = false;
			return answer;
		}
	}


    return answer;
}


int main(int argc, char const *argv[])
{
	std::vector<string> phone_book = {"119", "97674223", "1195524421"};

	cout << solution(phone_book) << endl;

	// string str1 = phone_book[0];
	// string str2 = phone_book[1];
	// std::vector<string> :: iterator vi = phone_book.begin();

	// cout << strlen(min(*vi,*(vi+1)).c_str()) << endl;

	// cout << *vi <<endl;

	// cout << *(vi+1) << endl;



	// cout << strncmp(str1.c_str(),str2.c_str(),3) << endl;

	return 0;
}