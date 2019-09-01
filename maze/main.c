#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int len;
    int wid;
    int begin_x,begin_y;
    int end_x,end_y;
    int** cells;
}Map;
    char file_n[]={"C:\Users\31324\Desktop\c program\maze\map.txt"};
int main()
{
    char ch;
    int m_len=0;
    int m_wid=0;
    int state=0;
    FILE* map;
    map=fopen(file_n,"r");
    fscanf(map,"%c",&ch);
    do
    {
        switch(ch)
        {
            case '\n':
            {
                m_len++;
                state=1;
                break;
            }
            case '\0':
            {
                if(state==0)
                {
                    m_wid++;
                    break;
                }
                if(state!=0)
                break;
            }
        }
    }
    while(ch!=EOF);//to identify the wid and the len of the map
    fclose(map);

}
Map* init_map(int len,int wid,Map* a,FILE* map)
{   
    a->cells=calloc(len,sizeof(int));
    for(int i=0;i<wid;i++)
    {
        a->cells[i]=calloc(wid,sizeof(int));
    }
    map=fopen(file_n,'r');
    char ch;
    int len_state=0;//these two used to store the 
    int wid_state=0;
    fscanf(map,"%c",&ch);
    do
    {
        switch(ch)
        {
            case '\n':
            {
                len_state++;
                break;
            }
            case '*':
            {
                a->cells[len_state][]   
            }
            case
        }
    }
    while(ch!=EOF);//to identify the wid and the len of the map
}