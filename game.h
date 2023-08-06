#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//��ʼ�����ӵ�Ϊ�ո�
void def_point(char board[3][3],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            board[i][j]=' ';
        }
    }
}

//��ʾ����
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
    printf("��� o ���� x");
    printf("\n");
    printf("\n");
}

//�������
void player_select(char board[3][3])
{
    int x,y;
    do
    {
        display_board(board,3,3);
        printf("���Ӹ�ʽΪ�� �� �� ��");
        printf("\n");
        printf("\n");
        printf("������>>> ");
        scanf("%d %d",&x,&y);
        x--;
        y--;
        //�жϳ�������⣬��������
        if(x<0||x>2||y<0||y>2){
            printf("\n");
            printf("�������������");
            printf("\n");
            printf("\n");
            system("pause");
        }
        
        //�ж��Ƿ������
        if(x>=0&&x<=2&&y>=0&&y<=2){
            if(board[x][y]=='o'||board[x][y]=='x'){//�ж��Ƿ��ظ�����
            printf("\n");
            printf("\n");
            printf("��λ�������ӣ�������ѡ��");
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
    printf("�������>>>\n");
    printf("\n");
    display_board(board,3,3);

}

//��������

void computer_select(char board[3][3])
{
    srand((unsigned int)time(NULL));//�趨��������
    while(1){
        int x,y;
        x = rand()%3;
        y = rand()%3;
        if(board[x][y]==' '){//�ж��Ƿ��ظ�����
            board[x][y] = 'x';
            break;
            }
    }
    printf("\n");
    printf("��������>>>\n");
    printf("\n");
}

//�ж�ʤ��

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

//��Ϸ����
void game(){

    char board[3][3] = {0};
    int answer=0;
    int times=0;
    system("cls");
    def_point(board,3,3);
    while(1){
        printf("\n");
        //�������
        player_select(board);
        //���Ӵ�������
        times++;
        answer = value(board,3);
        //ͨ������ֵ��������
        if(answer == 5){
            printf("\n");
            printf("\n");
            printf("��һ�ʤ\n");
            break;
        }
        //ƽ�����
        if (times == 5)
        {
            printf("\n");
            printf("\n");
            printf("��Ϸ����\n");
            printf("\n");
            printf("ƽ��\n");
            printf("\n");
            system("pause");
            break;
        }
        //��������
        computer_select(board);
        //ͨ������ֵ��������
        answer = value(board,3);
        if(answer == 10){
            printf("\n");
            printf("\n");
            printf("���Ի�ʤ\n");
            break;
        }
    }
    printf("\n");
    printf("\n");
    printf("���ز˵�\n");
    printf("\n");
    printf("\n");
    system("pause");
}