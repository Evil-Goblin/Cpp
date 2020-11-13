#include <stdio.h>
#include <direct.h>
#include <errno.h>

struct Player
{
	int x = 3;
	int y = 8;
	int forward = 1;
	int energy = 20;
	int money = 0;	
};

int main(int argc, char const *argv[])
{

	struct Player player;
	FILE *fp;
	char a;

	char Path[] = { ".\\save" };

	int nResult = mkdir( Path );

	if( nResult == 0 )
	{
		printf( "Folder create\n" );
	}
	// else if( nResult == -1 )
	// {
	// 	perror( "Folder Fail\n" );
	// 	printf( "errorno : %d", errno );
	// }

	fp = fopen(".\\save\\test2.dat","w");
	if ( fp == NULL ) {
		printf("%s\n", "FAIL 1");
		return 0;
	}
	// for (int i = 0; i < 10; ++i)
	// {
	// 	fprintf(fp, "%d\n", i);
	// }
	fprintf(fp, "%d\n", player.x);
	fprintf(fp, "%d\n", player.y);
	fprintf(fp, "%d\n", player.forward);
	fprintf(fp, "%d\n", player.energy);
	fprintf(fp, "%d\n", player.money);

	fclose(fp);

	fp = fopen(".\\save\\save1.dat","r");
	if ( fp == NULL ) {
		printf("%s\n", "FAIL 2");
		return 0;
	}

	while(fscanf(fp, "%c", &a) != EOF){
		printf("%c", a);
	}

	fclose(fp);


	return 0;
}