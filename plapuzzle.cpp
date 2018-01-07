#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
	BLANK = 0,
	WALL  = 99,
};

#define SIZE 8


/**************************************************************************/
typedef struct XY_ {
	int x;
	int y;
} XY;
/**************************************************************************/
typedef struct Shape_ {
	XY  dot[6];
} Shape;
/**************************************************************************/
typedef struct Piece_ {
	int shapes;
	Shape shape[8];
}Piece;

/**************************************************************************/
Piece piece_z = {
	4,

	{
		// ■■
		//   ■
		//   ■■
		{{{0,0},{1,0},{1,1},{1,2},{2,2},{99,99}}},

		
		//     ■
		// ■■■
		// ■

		{{{0,0},{0,1},{-1,1},{-2,1},{-2,2},{99,99}}},

		// ■
		// ■■■
		//     ■
		{{{0,0},{0,1},{1,1},{2,1},{2,2},{99,99}}},

		//   ■■
		//   ■
		// ■■
		{{{0,0},{1,0},{0,1},{0,2},{-1,2},{99,99}}},
	
	}
};

/**************************************************************************/
class Ban {
public:
	char map[18][18];
	
	Ban(){
		memset( &map[0][0], WALL, sizeof(map) );
		
		for( int y=1; y<1+SIZE; y++ ){
			for( int x=1; x<1+SIZE; x++ ){
				map[x][y]=BLANK;
			}
		}
		
	}
	
	
	void print(){
		for( int y=1; y<1+SIZE; y++ ){
			for( int x=1; x<1+SIZE; x++ ){
				if( map[x][y]==BLANK ){
					printf(". ");
				}else{
					printf("%c ", map[x][y]+'a');
				}
			}
			puts("");
		}
	}
	
	void put(int x, int y, Shape s){
		//printf("putting test\n");
		for( int i=0; i<5; i++ ){
			if( map[x+s.dot[i].x][y+s.dot[i].y] != BLANK ){
				printf("i=%d, x=%d, y=%d, map=%d\n", i, x,y,map[x+s.dot[i].x][y+s.dot[i].y] );
				printf("%d %d\n", s.dot[i].x, s.dot[i].y );
				exit(1);
			}
			
			map[x+s.dot[i].x][y+s.dot[i].y] = 2;
		}
	}
};

/**************************************************************************/
int main()
{
	Ban b;
	
	
	Piece ps[12]={piece_z};

	b.put(1,1,piece_z.shape[0]);
	
	int used_map[12] = {0};
	for( int p=0; p<12; p++ ){
		
	}
	
	b.print();
	
}

