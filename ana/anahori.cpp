#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wchar.h>
#include <locale.h>
#include <direct.h>
#include <string.h>

#define SHOP 101
#define WALL 100

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

struct Player
{
	int x = 3;
	int y = 8;
	int forward = UP;
	int energy = 20;
	int money = 0;	
};

char startscreen[][10] = { "New Game", "Load", "Quit"};
char gameMenu[][10] = { "Countinue", "Save", "Load", "Quit"};
char save[][10] = {
					"save1.dat",
					"save2.dat",
					"save3.dat",
					"save4.dat",
					"save5.dat"
				};
char saveList[][10] = {
	"No Data",
	"No Data",
	"No Data",
	"No Data",
	"No Data"
};

char eraser[10] = { "\0", };

char pathRoad[10] = { "\\" };


char (*loadList(char (*save)[10], char (*saveList)[10]))[10]
{
    _finddata_t fd;
    long handle;
    int result = 1;
    handle = _findfirst(".\\save\\*.*", &fd);
  	int list = 0;
    if (handle == -1)
    {
        return saveList;
    }
  
    while (result != -1)
    {
    	for (int i = list; i < 5; ++i)
    	{
    		if ( !strncmp( fd.name,save[i],5 )) {
    			// saveList[i] = save[i];
    			memcpy(saveList[i],eraser,10);
    			strncpy(saveList[i],save[i],5);
    		}
    		/* code */
    	}
        result = _findnext(handle, &fd);
    }
  
    _findclose(handle);

    return saveList;
}

int Menu(char (*data)[10], int size){
	int num = 1;
	while(1){
		system("cls");
		printf("\n\n\n");
		for (int i = 0; i < size; ++i)
		{
			if ( i+1 == num ) {
				printf("%10s%s\n", "V ",data[i]);
			} else {
				printf("%10s%s\n", " ",data[i]);
			}
		}
		char key = getch();

		if(kbhit()){
			key = getch();
			if ( key == 72 ) {
				if ( num != 1 ) {
					num--;
				}			
			} else if ( key == 80 ) {
				if (num != size+1 ) {
					num++;
				}
			}
		} else if ( key == 13 ) {
			return num;
		}
	}
}




void creatematrix(int (*matrix)[20]){
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if(i == 3 && (j == 5 || j == 6)){
				matrix[i][j] = SHOP;
			}else if( i == 4 && ( j < 9 || j > 11)){
				matrix[i][j] = WALL;
			}else if( i > 4 ){
				matrix[i][j] = (rand() % 99) + 1;
			}
		}
	}
}

void drawmatrix(int (*matrix)[20], struct Player *p){

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if ( i == p->x && j == p->y ) {
				switch(p->forward){
					case UP:
						wprintf(L"▲");
						break;
					case DOWN:
						wprintf(L"▼");
						break;
					case LEFT:
						wprintf(L"◀");
						break;
					case RIGHT:
						wprintf(L"▶");
						break;	
				}
			} else if ( matrix[i][j] == 0 )	{
				printf("  ");
			} else if ( matrix[i][j] == SHOP){
				// printf(mSHOP);
				wprintf(L"♨");
			} else if ( matrix[i][j] == WALL) {
				// printf(mWALL);
				wprintf(L"▩");
			} else if ( matrix[i][j] == 1 ){
				// printf(mROCK1);
				wprintf(L"①");
			} else if ( matrix[i][j] == 2 ){
				// printf(mROCK2);
				wprintf(L"②");
			} else if ( matrix[i][j] == 3 ){
				// printf(mROCK3);
				wprintf(L"③");
			} else if ( matrix[i][j] == 4 ){
				// printf(mROCK4);
				wprintf(L"④");
			} else if ( matrix[i][j] == 5 ){
				// printf(mROCK5);
				wprintf(L"⑤");
			}
		}
		printf("\n");
	}
	printf("%36s", "Energy : ");
	printf("%4d\n", p->energy);
	printf("%36s", "Money : ");
	printf("%4d\n", p->money);
}

void move(struct Player *p, int (*shape)[20]){
	char key = getch();
	if(kbhit()){
		key = getch();
		if ( key == 75 ) {
			// printf("\a");
			p->forward = LEFT;
			if ((shape[p->x][(p->y)-1] == 0) && (p->y > 0)) {
				p->y -= 1;
			}			
		} else if ( key == 72 ) {
			// printf("\a");
			p->forward = UP;
			if ((shape[(p->x)-1][p->y] == 0) && (p->x > 3)) {
				p->x -= 1;
			}
		} else if ( key == 80 ) {
			// printf("\a");
			p->forward = DOWN;
			if ((shape[(p->x)+1][p->y] == 0) && (p->x < 25)) {
				p->x += 1;
			}
		} else if ( key == 77 ) {
			// printf("\a");
			p->forward = RIGHT;
			if ((shape[p->x][(p->y)+1] == 0) && (p->y < 20)) {
				p->y += 1;
			}
		}
	} else if (key == 0x1B) {
		int select = Menu(gameMenu, 4);
		if ( select == 1 ) {
			return;
		} else if ( select == 4 ) {
			exit(0);
		} else if ( select == 2 ) {
			
			
			FILE *fp;
			char savePath[] = { ".\\save" };

			int nResult = mkdir( savePath );
			int saveNum = Menu(loadList(save,saveList),5);
			char realPath[20] = { "\0", };
			sprintf(realPath,"%s%s%s",savePath,pathRoad,save[saveNum-1]);
			fp = fopen(realPath,"w");
			// if ( fp == NULL ) {
			// 	return;
			// }
			// printf("asdfasdfas\n");
			fprintf(fp, "%d\n", p->x );
			fprintf(fp, "%d\n", p->y );
			fprintf(fp, "%d\n", p->forward );
			fprintf(fp, "%d\n", p->energy );
			fprintf(fp, "%d\n", p->money );
			// printf("after\n");
			for( int i = 5; i < 25; i++) {
				for( int j = 0; j < 20; j++) {
					fprintf( fp, "%d", shape[i][j]);
				}
				fprintf( fp , "\n");
			}
			fclose(fp);
		} else if ( select == 3 ) {
			int saveNum = Menu(loadList(save,saveList),5);
			FILE *fp;
			char savePath[] = { ".\\save\\" };
			char realPath[20] = { "\0", };
			sprintf(realPath,"%s%s",savePath,save[saveNum-1]);
			fp = fopen(realPath,"r");

		}
		
	} else if ( key == 32 ) {
		if ( p->forward == UP ) {
			if ( (shape[(p->x)-1][p->y] < 100) && (shape[(p->x)-1][p->y] != 0) ) {
				if ( p->energy >= shape[(p->x)-1][p->y] ){
					p->money += shape[(p->x)-1][p->y]*2;
					p->energy -= shape[(p->x)-1][p->y];
					shape[(p->x)-1][p->y]--;
				}				
			}
		} else if ( p->forward == DOWN ) {
			if ( (shape[(p->x)+1][p->y] < 100) && (shape[(p->x)+1][p->y] != 0) ) {
				if ( p->energy >= shape[(p->x)+1][p->y] ){
					p->money += shape[(p->x)+1][p->y]*2;
					p->energy -= shape[(p->x)+1][p->y];
					shape[(p->x)+1][p->y]--;
				}
					
			}
		} else if ( p->forward == LEFT ) {
			if ( (shape[p->x][(p->y)-1] < 100) && (shape[p->x][(p->y)-1] != 0) ) {
				if ( p->energy >= shape[p->x][(p->y)-1] ){
					p->money += shape[p->x][(p->y)-1]*2;
					p->energy -= shape[p->x][(p->y)-1];
					shape[p->x][(p->y)-1]--;
				}						
			} else if ( shape[p->x][(p->y)-1] == SHOP ){
				if ( p->money > 30 ) {
					p->money -= 30;
					p->energy = 20;
				}
			}
		} else if ( p->forward == RIGHT ) {
			if ( (shape[p->x][(p->y)+1] < 100) && (shape[p->x][(p->y)+1] != 0) ) {
				if ( p->energy >= shape[p->x][(p->y)+1] ){
					p->money += shape[p->x][(p->y)+1]*2;
					p->energy -= shape[p->x][(p->y)+1];
					shape[p->x][(p->y)+1]--;
				}						
			}
		}
	}
}

void makeshape(int (*shape)[20], int (*matrix)[20]){
	for (int i = 0; i < 25; ++i)
	{
		for ( int j = 0; j < 20; j++){
			// if ( matrix[i][j] < 101 && matrix[i][j] != 0 ) {
			// 	shape[i][j] = 1;
			// }

			if ( matrix[i][j] == 0 ){
				shape[i][j] = 0;
			} else if ( matrix[i][j] < 40 ) {
				shape[i][j] = 1;
			} else if ( matrix[i][j] < 70 ) {
				shape[i][j] = 2;
			} else if ( matrix[i][j] < 90 ) {
				shape[i][j] = 3;
			} else if ( matrix[i][j] < 95 ) {
				shape[i][j] = 4;
			} else if ( matrix[i][j] < 100 ) {
				shape[i][j] = 5;
			} else if ( matrix[i][j] == WALL ) {
				shape[i][j] = WALL;
			} else if ( matrix[i][j] == SHOP ) {
				shape[i][j] = SHOP;
			}
		}
	}
}

// void loadgame(){

// }



int main(int argc, char const *argv[])
{
	_wsetlocale( LC_ALL, L"korean" );

	int matrix[25][20] = { 0, };
	int shape[25][20] = {0, };

	struct Player player;

	// int selectMenu = Menu(startscreen, 3);

	// if ( selectMenu == 3 ) {
	// 	exit(0);
	// } else if ( selectMenu == 2 ) {
	// 	int saveNum = Menu(loadList(save,saveList),5);
	// 	FILE *fp;
	// 	char savePath[] = { ".\\save\\" };
	// 	char realPath[20] = { "\0", };
	// 	sprintf(realPath,"%s%s",savePath,save[saveNum-1]);
	// 	fp = fopen(realPath,"r");

	// 	int playerData;
	// 	// for(int i = 0; i < 5; i++) {
	// 	// }
	// 	fscanf( fp, "%d", &playerData);
	// 	player.x = playerData;
	// 	fscanf( fp, "%d", &playerData);
	// 	player.y = playerData;
	// 	fscanf( fp, "%d", &playerData);
	// 	player.forward = playerData;
	// 	fscanf( fp, "%d", &playerData);
	// 	player.energy = playerData;
	// 	fscanf( fp, "%d", &playerData);
	// 	player.money = playerData;
	// 	shape[3][5] = SHOP;
	// 	shape[3][6] = SHOP;
	// 	for ( int i = 0; i < 20; i++) {
	// 		if( i == 9 || i == 10 || i == 11 ) {
	// 			continue;
	// 		}
	// 		shape[4][i] = WALL;
	// 	}
	// 	for ( int i = 5; i < 25; i++) {
	// 		for ( int j = 0; j < 20; j++) {
	// 			char temp;
	// 			fscanf(fp,"%c",&temp);
	// 			shape[i][j] = (int)temp - 48;
	// 			//printf("%s\n", temp);
	// 		}
	// 	}
	// 	//exit(0);
	// } else if ( selectMenu == 1 ) {
	// 	creatematrix(matrix);
	// 	makeshape(shape,matrix);
	// }

	for (int i = 0; i < 10; ++i)
	{
		creatematrix(matrix);
		makeshape(shape,matrix);
		// system("cls");
		drawmatrix(shape,&player);
	}
	
	// while(1){
	// 	system("cls");
	// 	drawmatrix(shape,&player);
	// 	move(&player, shape);
	// }
	return 0;
}