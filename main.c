#include "header.h"
int main(int argc, char *argv[]) {
	srand(time(NULL));
	Teater t[2];
	string namaFilm[6]={"Spongebob SquarePants","Angry Birds","One Piece","Boboiboy","Kung Fu Panda 3","The Avengers"};
	int indexFilm=0;
	Index c,temp;
	int i;
	char move;
	string ukuran;
	string input,inputTeater;
	strcpy(ukuran, "large");
	bool hasData=false;
	int current = 0, tempCurrent; //current 0 = standard, current 1 = premiere
	setColor(white,black);
	hide_cur();

	c.y=0;c.x=0;
	initTeater(t,ukuran);
	initFilm(namaFilm,t,indexFilm);
	
	do{
		generateMap(&t[current].dMap);
		hasData=isHasData(t[current].dMap.p,c); //menentukan pd posisi cursor ada data/tidak
		generateCursPosition(c,t[current].dMap.map,hasData); //generate posisi cursor
		showTeater(t[current],ukuran);
		printf("\n\n\n    [Enter] Pesan/Lihat Detail");
		printf("\n    [P] Play Film");
		printf("\n    [F] Find Seat");
		move = getch();
		move = tolower(move);
		
		if(move == -32) move = getch();
		
		if(isValidMovement(move,c,t[current].jenisTeater,ukuran)) CursMovement(&c, move);
		
		if(move != 'w' && move != 'a' && move != 's' && move != 'd' && move != 13 &&
			move != 'p' && move != 'f') continue;  //jika inputan bukan dari key , continue..
		
		//movement ke map sebelah
		if(current==0 && c.x==COLUMN){
			generateMap(&t[current].dMap);
			showTeater(t[current],ukuran);
			do{
				if(strcmpi(ukuran,"large")==0){
					showPointerMap(t[current].jenisTeater,ROW+1);
				}else{
					showPointerMap(t[current].jenisTeater,ROWSMALL+1);
				}
				move=getch();
			}while(move!='a' && move!='d');

			if(move=='d'){
				clearMap();
				c.x=0;
				current=1;
			} 
			else if(move=='a') {
				clearMap();
				c.x=COLUMN-1;		
			}
			
		}else if(current==1 && c.x==-1){
			generateMap(&t[current].dMap);
			showTeater(t[current],ukuran);
			do{
				if(strcmpi(ukuran,"large")==0){
					showPointerMap(t[current].jenisTeater,ROW+1);
				}else{
					showPointerMap(t[current].jenisTeater,ROWSMALL+1);
				}
				move=getch();
			}while(move!='a' && move!='d');
			
			if(move=='a'){
				clearMap();
				c.x=COLUMN-1;
				current=0;
			}else if(move=='d') {
				clearMap();
				c.x=0;
			}
		}

		//logic generate map setelah play
		if((move =='p'|| move=='P') && strcmpi(ukuran,"large")==0 ){

			play(t[current].jenisTeater);
			strcpy(ukuran,"small");
			initTeater(t,ukuran);
			if(indexFilm!=4) indexFilm+=2;
			else if(indexFilm==4) indexFilm=0;
			initFilm(namaFilm,t,indexFilm);
			c.y=0;c.x=0;
			clearMap();
		}else if((move =='p'||move =='P')  && strcmpi(ukuran,"small")==0){
			
			play(t[current].jenisTeater);
			strcpy(ukuran,"large");
			initTeater(t,ukuran);
			if(indexFilm!=4) indexFilm+=2;
			else if(indexFilm==4) indexFilm=0;
			initFilm(namaFilm,t,indexFilm);
			c.y=0;c.x=0;
			clearMap();
		}else if(move==13){
			if(strcmp(t[current].dMap.map[c.y][c.x],"**")==0){
				//untuk input data
				show_cur();
				inputDataPemesan(t[current].dMap.p,c.y,c.x);
				hide_cur();
			}else{
				//untuk lihat data
				showDataPemesan(t[current].dMap.p,c.y,c.x); 
			}
		}else if(move=='f'){
			show_cur();
				tempCurrent=-1;
				gotoxy(3,46); printf("--=== Cari Seat ===--");
				gotoxy(4,46); printf("[1] Teater Standard");
				gotoxy(5,46); printf("[2] Teater Premiere");
				gotoxy(6,46); printf("Masukkan teater yang diinginkan : "); fflush(stdin); gets(inputTeater);
					if(strcmpi(inputTeater,"2")==0) tempCurrent=1; //goto premiere
					if(strcmpi(inputTeater,"1")==0) tempCurrent=0; //goto standard
					
				if(strcmpi(inputTeater,"2")==0 && current==0){ //standard to premiere
					gotoxy(7,46); printf("Masukkan Seat yang dicari : "); fflush(stdin); gets(input);
					temp=findSeat(t[tempCurrent].dMap.p,input,ukuran);
					if(temp.x==-1){
						gotoxy(8,46); printf("[!] Seat tidak ditemukan"); getch();
						gotoxy(8,46); printf("                        ");
					}else{
						current=1;
						c.y=temp.y;
						c.x=temp.x;
						gotoxy(8,46); printf("[~] Berhasil pindah ke seat [%s]",t[current].dMap.p[temp.y][temp.x].id); getch();
						gotoxy(8,46); printf("                                ");
						
						
						clearFindSeat(inputTeater,input);
							hide_cur();
						generateMap(&t[current].dMap);
						hasData=isHasData(t[current].dMap.p,c); 
						generateCursPosition(c,t[current].dMap.map,hasData);
						clearMap();
						showTeater(t[current],ukuran);
						printf("\n\n\n    [Enter] Pesan/Lihat Detail");
						printf("\n    [P] Play Film");
						printf("\n    [F] Find Seat");
			        	if(strcmp(t[current].dMap.map[c.y][c.x],"**")==0){
							//untuk input data
							show_cur();
							inputDataPemesan(t[current].dMap.p,c.y,c.x);
							hide_cur();
						}else{
							//untuk lihat data
							showDataPemesan(t[current].dMap.p,c.y,c.x); 
						}

					}
				}else if(strcmpi(inputTeater,"1")==0 && current==1){ //premiere to standard
					gotoxy(7,46); printf("Masukkan Seat yang dicari : "); fflush(stdin); gets(input);
					temp=findSeat(t[tempCurrent].dMap.p,input,ukuran);
					if(temp.x==-1){
						gotoxy(8,46); printf("[!] Seat tidak ditemukan"); getch();
						gotoxy(8,46); printf("                        ");
					}else{
						current=0;
						c.y=temp.y;
						c.x=temp.x;
						gotoxy(8,46); printf("[~] Berhasil pindah ke seat [%s]",t[current].dMap.p[temp.y][temp.x].id); getch();
						gotoxy(8,46); printf("                                ");
						
						
						clearFindSeat(inputTeater,input);
							hide_cur();
						generateMap(&t[current].dMap);
						hasData=isHasData(t[current].dMap.p,c); 
						generateCursPosition(c,t[current].dMap.map,hasData);
						clearMap();
						showTeater(t[current],ukuran);
						printf("\n\n\n    [Enter] Pesan/Lihat Detail");
						printf("\n    [P] Play Film");
						printf("\n    [F] Find Seat");
			        	if(strcmp(t[current].dMap.map[c.y][c.x],"**")==0){
							//untuk input data
							show_cur();
							inputDataPemesan(t[current].dMap.p,c.y,c.x);
							hide_cur();
						}else{
							//untuk lihat data
							showDataPemesan(t[current].dMap.p,c.y,c.x); 
						}

					}
				}else if(current==tempCurrent){
					gotoxy(7,46); printf("Masukkan Seat yang dicari : "); fflush(stdin); gets(input);
					temp=findSeat(t[current].dMap.p,input,ukuran);
					if(temp.x==-1){
						gotoxy(8,46); printf("[!] Seat tidak ditemukan"); getch();
						gotoxy(8,46); printf("                        ");
					}else{
						c.y=temp.y;
						c.x=temp.x;
						gotoxy(8,46); printf("[~] Berhasil pindah ke seat [%s]",t[current].dMap.p[temp.y][temp.x].id); getch();
						gotoxy(8,46); printf("                                ");
						
						
							clearFindSeat(inputTeater,input);
							hide_cur();
						generateMap(&t[current].dMap);
						hasData=isHasData(t[current].dMap.p,c); 
						generateCursPosition(c,t[current].dMap.map,hasData);
						clearMap();
						showTeater(t[current],ukuran);
						printf("\n\n\n    [Enter] Pesan/Lihat Detail");
						printf("\n    [P] Play Film");
						printf("\n    [F] Find Seat");
			        	if(strcmp(t[current].dMap.map[c.y][c.x],"**")==0){
							//untuk input data
							show_cur();
							inputDataPemesan(t[current].dMap.p,c.y,c.x);
							hide_cur();
						}else{
							//untuk lihat data
							showDataPemesan(t[current].dMap.p,c.y,c.x); 
						}
					}
				}else{
					gotoxy(7,46); printf("[!] Teater tidak ditemukan"); getch();
					gotoxy(7,46); printf("                          ");
				}
				clearFindSeat(inputTeater,input);
				hide_cur();
		}
	}while(move!=27);
	
	return 0;
}
