#include "header.h"

void CursMovement(Index *c, char move){ //generate curs movement
    if(move=='w'){
        c->y=c->y-1;
    }else if(move=='s'){
        c->y=c->y+1;
    }else if(move=='a'){
        c->x=c->x-1;
    }else if(move=='d'){
        c->x=c->x+1;
    }
}
bool isValidMovement(char move, Index c, string jenisMap, string ukuran){ //ck validitas movement cursor
    if(move=='w'){
        if((c.y-1)==-1) return false;       
    }else if(move=='s'){
        if(strcmpi(ukuran,"large")==0){
            if(c.y+1==ROW) return false;
            else return true;
        }else{
            if(c.y+1==ROWSMALL) return false;
            else return true;
        }
    }else if(move == 'a' && strcmpi(jenisMap,"standard")==0){
        if((c.x-1)==-1) return false;
        else return true;
    }else if(move == 'd' && strcmpi(jenisMap,"premiere")==0){
        if((c.x+1)==COLUMN) return false;
        else return true;
    }
}
bool isHasData(DataPemesan p[ROW][COLUMN], Index c){
    if(strlen(p[c.y][c.x].nama)!=0) return true;
    else return false;
}
