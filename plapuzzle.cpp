#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
	BLANK = 0,
	WALL  = 1,
};

#define SIZE 8


/**************************************************************************/
typedef struct Piece {
	int shapes;
	char map[10][18];
}Piece;

/**************************************************************************/
Piece piece_z = {
	1,
	{
		{1,1},
		{0,1},
		{0,1,1}
	}
};

/**************************************************************************/
class Ban {
public:
	char map[18][18];
	
	Ban(){
		memset( &map[0][0], WALL, sizeof(map) );
		
		for( int y=4; y<4+SIZE; y++ ){
			for( int x=4; x<4+SIZE; x++ ){
				map[y][x]=BLANK;
			}
		}
		
	}
	
	void print(){
		for( int y=4; y<4+SIZE; y++ ){
			for( int x=4; x<4+SIZE; x++ ){
				if( map[y][x]==BLANK ){
					printf(". ");
				}else{
					printf("%c ", map[y][x]+'a');
				}
			}
			puts("");
		}
	}
	
	void put(Piece a){
		
	}
};

/**************************************************************************/
int main()
{
	Ban b;
	
	b.put(4,4,piece_z);
	
	
    printf("hello.\n");
}

