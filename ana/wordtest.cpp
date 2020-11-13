#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	// cout << "☆  ▲" << endl;
	// cout << "■■■" << endl;

	// printf("☆  ▲\n");
	// printf("■■■\n");

	// printf("%c%c%c\n", 35,0xff,0xfe);
	// printf("%c%c%c\n", 0xB2,0xDB,0xF0);

	for (int i = 0; i < 128; ++i)
	{
		printf("%d : %c , %C\n", i, i, i);
	}
	return 0;
}