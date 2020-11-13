#include <stdio.h>
#include <string.h>

class MenuProto
{

private:
	char list[4][20] = {};
	int listnum = 0;
public:
	// MenuProto(char* (*data)[20]);
	void makelist(char* data);

	void print(int num);
	
};

// MenuProto::MenuProto(char (*data)[20]){
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		strcpy(list[i],data[i]);
// 	}
// }

void MenuProto::makelist(char* data){
	strcpy(list[listnum],data);
	listnum++;
}

void MenuProto::print(int num){
	for (int i = 0; i < 4; ++i)
	{
		if ( i+1 == num ) {
			printf("%10s%s\n", "V ",list[i]);
		} else {
			printf("%10s%s\n", " ",list[i]);
		}
	}
}


int main(int argc, char const *argv[])
{
	char data1[] = "countinue";
	char data2[] = "save";
	char data3[] = "quit";
	MenuProto menu;

	menu.makelist(data1);
	menu.makelist(data2);
	menu.makelist(data3);

	menu.print(1);
	return 0;
}