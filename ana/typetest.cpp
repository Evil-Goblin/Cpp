#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int i = 1;
	char a = '1';
	// string str = "asdf";
	char buf[] = {"fesd"};
	char buff[20] = "fesd";

	if(!strcmp(buf,buff)){
		cout << "same" << endl;
	}

	cout << typeid(i).name() << endl;
	cout << typeid(a).name() << endl;
	// cout << typeid(str).name() << endl;
	
	cout << typeid(buf).name() << endl;

	cout << typeid(int).name() << endl;
	return 0;
}