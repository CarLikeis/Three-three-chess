#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//初始化落子点为空格
void def_point(char board[3][3],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            board[i][j]=' ';
        }
    }
}

//显示棋盘
void display_board(char board[3][3],int row,int col)
{
    int i,j;
    for ( i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++){
            printf(" %c ",board[i][j]);
            if(j<col-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<row-1){
            printf("---|---|---\n");
        }
    }
    printf("\n");
    printf("玩家 o 电脑 x");
    printf("\n");
    printf("\n");
}

//玩家落子
void player_select(char board[3][3])
{
    int x,y;
    do
    {
        display_board(board,3,3);
        printf("落子格式为“ 行 列 ”");
        printf("\n");
        printf("\n");
        printf("请落子>>> ");
        scanf("%d %d",&x,&y);
        x--;
        y--;
        //判断超出落点外，重新输入
        if(x<0||x>2||y<0||y>2){
            printf("\n");
            printf("输入错误，请重试");
            printf("\n");
            printf("\n");
            system("pause");
        }
        
        //判断是否在落点
        if(x>=0&&x<=2&&y>=0&&y<=2){
            if(board[x][y]=='o'||board[x][y]=='x'){//判断是否重复落子
            printf("\n");
            printf("\n");
            printf("该位置已落子，请重新选择");
            printf("\n");
            printf("\n");
            system("pause");
            continue;
            }
            board[x][y] = 'o';
            break;
        }
    } while (1);
    system("cls");
    printf("\n");
    printf("玩家落子>>>\n");
    printf("\n");
    display_board(board,3,3);

}

//电脑落子

void computer_select(char board[3][3])
{
    srand((unsigned int)time(NULL));//设定随机数起点
    while(1){
        int x,y;
        x = rand()%3;
        y = rand()%3;
        if(board[x][y]==' '){//判断是否重复落子
            board[x][y] = 'x';
            break;
            }
    }
    printf("\n");
    printf("电脑落子>>>\n");
    printf("\n");
}

//判断胜负

int value(char board[3][3],int n)
{
    int i,answer;
    for(i=0;i<n;i++){
            if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]=='o')
            {
                answer = 5;
            }
            if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]=='o')
            {
                answer = 5;
            }
            if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]=='x')
            {
                answer = 10;
            }
            if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]=='x')
            {
                answer = 10;
            }
    }
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]=='o')
    {
        answer = 5;
    }
    if (board[0][2]==board[1][1]&&board[2][0]==board[1][1]&&board[1][1]=='o')
    {
        answer = 5;
    }
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]=='x')
    {
        answer = 10;
    }
    if (board[0][2]==board[1][1]&&board[2][0]==board[1][1]&&board[1][1]=='x')
    {
        answer = 10;
    }
    
    return answer;
}

//游戏流程
void game(){

    char board[3][3] = {0};
    int answer=0;
    int times=0;
    system("cls");
    def_point(board,3,3);
    while(1){
        printf("\n");
        //玩家落子
        player_select(board);
        //落子次数增加
        times++;
        answer = value(board,3);
        //通过返回值结束进程
        if(answer == 5){
            printf("\n");
            printf("\n");
            printf("玩家获胜\n");
            break;
        }
        //平局情况
        if (times == 5)
        {
            printf("\n");
            printf("\n");
            printf("游戏结束\n");
            printf("\n");
            printf("平局\n");
            printf("\n");
            system("pause");
            break;
        }
        //电脑落子
        computer_select(board);
        //通过返回值结束进程
        answer = value(board,3);
        if(answer == 10){
            printf("\n");
            printf("\n");
            printf("电脑获胜\n");
            break;
        }
    }
    printf("\n");
    printf("\n");
    printf("返回菜单\n");
    printf("\n");
    printf("\n");
    system("pause");
}