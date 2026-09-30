#include<stdio.h>
// rat in maze
#define N 4
// char name[];
int findingpath(int maze[N][N],int x,int y,char path[],int index){
    if(x==N-1&&y==N-1){
        path[index]='\0';
        printf("%s\n,path");
    }
    if(x>=N||y>==N||maze[x][y]==0){
        return 0;
    }
    if(findingpath(maze,x+1,path,index+1))
    {
        return 1;
    }
        path[index]='R';
int main(){
    {1,0,0,0},
    {1,1,0,1},
    {0,1,0,0},
}

}