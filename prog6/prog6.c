#include<stdio.h>
#include<stdlib.h>

#define rows 26
#define cols 26
struct circle{
    int radius;
    int centerX;
    int centerY;
};

void initializeBuffer(char buffer[rows][cols]);
int isCircle(int x, int y, struct circle c);
void drawCircle(char buffer[rows][cols], struct circle c);
void printCircle(char buffer[rows][cols]);

int main(){
    struct circle c;

    c.centerX = 13;
    c.centerY = 13;
    c.radius = 5;

    char buffer[rows][cols];
    initializeBuffer(buffer);
    drawCircle(buffer, c);
    printCircle(buffer);
    return 0;
}

void initializeBuffer(char buffer[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            buffer[i][j]=' ';
        }
    }
}

int isCircle(int x, int y, struct circle c){
    int dy=y-c.centerY;
    int dx=x-c.centerX;
    int point=(dy*dy) + (dx*dx);
    int r_squared=c.radius*c.radius;
    if(abs(r_squared - point) <= c.radius){
        return 1;
    }
    return 0;
}

void drawCircle(char buffer[rows][cols], struct circle c){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(isCircle(j, i, c)){
                buffer[i][j]='*';
            }
        }
    }
}

void printCircle(char buffer[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           printf("%c", buffer[i][j]);
        }
        printf("\n");
        }
}
