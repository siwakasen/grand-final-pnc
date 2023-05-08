#include "header.h"
int main(int argc, char *argv[]) {
	DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT];
	string map[WIDTH_SEAT][LENGTH_SEAT];
	// init(obj_map[0].bangku);
	// init(obj_map[1].bangku);

	CursorPosition c;
	c.y=2;
	c.x=1;
	char menu;

	do{
		/*
		wasd
		enter
		
		cur c y=5,x=8
		{
			curs a = c;
			
			map. bangku[a.y][a.x] = bangku;
		}
		*/
	}while(menu!=27);
	return 0;
}
