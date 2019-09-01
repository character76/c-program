#include <stdio.h>
#include <cstdlib>
#include<string.h>
#include <conio.h>
#include<iostream>
#include <thread>
#include <ctime>
#define length 100
#define wide 40
#define speed 1

using namespace std;

//define ��������Ļ�ĳ��Ϳ�,�˴���ָ������֮��ĳ��ȣ�����ʵ�ʵĳ���Ϊ(1+wide+1)*length
int points[wide][length]={0};//�˴����ڴ�ӡ�м���Ļ����
int mines[wide][length]={0};//�˴����ڴ����������
int ball_direction;//��ķ���ְ˸�����
int ball_x=50;//initialize ball's x,y
int ball_y=19;
char character_move;

int main()
{//��ʼ������
    void add_ball_move();
    void add_screen_p_m(int point_x,int point_y);
    void print_head();
    void print_screen_middle();
    void set_screen_object();
    int init_x= length/2;
    int init_y=1;//��ʼ��������
    ball_direction=2;
    int m_sum = 0;//The sum of mines
    cout<<"please enter the sum of mines:_____(100>num>0)"<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin>>m_sum;
    srand(int(time(0)));

    while(m_sum--)
    {

    }

    while(1)//��Ϸ��ѭ����
    {
    add_screen_p_m(init_x,init_y);
    add_screen_p_m(init_x+1,init_y);
    add_screen_p_m(init_x-1,init_y);


    print_screen_middle();

    char bom;
    bom=getch();
    if(bom=='a')
    {
        init_x-=speed;
    }
    else if(bom=='d')
    {
        init_x+=speed;
    }
    else if(bom=='w')
    {
        init_y++;
    }
    else if(bom=='s')
    {
        init_y--;
    }

    set_screen_object();
    }
    //��ѭ��������

    return 0;
}
void print_head()
{
    char object[10] = "ball game";
    for(int i=0;i<=((length-9)/2);i++) printf(" ");
    printf("%s\n",object);
    return ;
}
void add_screen_p_m(int point_x,int point_y)
{
    points[wide-point_y][0]+=1;
    points[wide-point_y][point_x] = 1;
}
void add_screen_mines(int point_x,int point_y)
{
    mines[wide-point_y][0]+=1;
    mines[wide-point_y][point_x] = 1;
}
void print_screen_middle()
{
    for(int i=0;i<wide;i++)//ͳһ����ÿ�У���20��
    {
        if(points[i][0]==0)
        {
            printf("\n");//���ڿ���ֱ��\n��������֡��
            continue;
        }
        int a_times = 0;
        for(int p=0;p<=(length-1);p++)//ͳһ����ÿ�еĴ�ӡ����
        {
            if(points[i][p]==1)
            {
                cout<<"#";
                a_times++;
            }
            else if(p==(length-1))
            {
                cout<<" \n";
            }
            else
            {
                cout<<" ";
            };
            if(a_times==points[i][0])
            {
                cout<<"\n";
                break;
            }
        }
    }
}
void set_screen_object()//�������ˢ����Ļǰ���֮ǰ�Ĵ�ӡ����
{
    for(int i=0;i<=(wide-1);i++)
    {
        for(int p=0;p<=(length-1);p++)
        {
            points[i][p]=0;
        }
    }
    system("cls");
}

void add_ball_move()//����Ϊint�����Է��ؿ��н�Ŀ��
{
    if((ball_y+1>=38||points[wide-(ball_y+1)][ball_x]==1)&&(ball_direction==2||ball_direction==6))
    {
        ball_direction=6;//�Ϸ����ϰ���
    }
    else if((ball_y-1<=1||points[wide-(ball_y-1)][ball_x]==1)&&(ball_direction==2||ball_direction==6))
    {
        ball_direction=2;//�·����ϰ���
    };//δ�����
    if(ball_direction==1)
    {
        add_screen_p_m(ball_x--,ball_y++);
    }
    else if(ball_direction==2)
    {
        add_screen_p_m(ball_x,ball_y++);
    }
    else if(ball_direction==3)
    {
        add_screen_p_m(ball_x++,ball_y++);
    }
    else if(ball_direction==4)
    {
        add_screen_p_m(ball_x++,ball_y);
    }
    else if(ball_direction==5)
    {
        add_screen_p_m(ball_x++,ball_y--);
    }
    else if(ball_direction==6)
    {
        add_screen_p_m(ball_x,ball_y--);
    }
    else if(ball_direction==7)
    {
        add_screen_p_m(ball_x--,ball_y--);
    }
    else if(ball_direction==8)
    {
        add_screen_p_m(ball_x--,ball_y);
    }
}








