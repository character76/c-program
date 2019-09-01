#include <stdio.h>
#include <stdlib.h>
#define OUTPUT_SUCCESS 1


//Graham Scan Algorithm
/*
there seems to be another methods using vector cross-product
but mainly what I using is slope to judge
*/
typedef struct {
    int x;
    int y;
    int state;
}Point;
//state used to transfer location message along function
    /*
    state=1 ->at the rightmost point
    state=2 ->not at the right most point ,continue
    state=65565 -> act as a stop sign in an point array
    */
int Up_nextp(Point* points,int now_point,int left);
int Down_nextp(Point* points,int now_point,int left);
Point* begin_point(Point* points,int len);
void print_ans(Point* points,int len);
float slope(Point a,Point b);

int main()
{
    int point_size=sizeof(Point);
    int compare_func(const void* a,const void* b);
    unsigned int point_num=20;
    Point* random_point(int num,int x_len,int y_len);
    int check_point(Point* a,int len);
    void print_points(Point* points,int len);

    Point* points=random_point(point_num,50,50);
    printf("data size of Point%d",point_size);
    print_points(points,point_num);
    qsort(points,point_num,sizeof(Point),compare_func);
    printf("after sort\n");
    print_points(points,point_num);
    points=begin_point(points,point_num);
    print_ans(points,point_num);
    return 0;
}

int check_point(Point* a,int len)
{
    for(int i=0;i<len;i++)
    {
        if(a[i].x>50000||a[i].y>50000)
        return -1;
    }
    return 1;
}

Point* random_point(int num,int x_len,int y_len)
{
    int data_len=sizeof(Point);
    
    Point* points=malloc(data_len*num+1);
    for(int i=0;i<num;i++)
    {
        points[i].x=rand()%x_len+1;
        points[i].y=rand()%y_len+1;
    }
    points[num].x=0;
    points[num].y=0;
    points[num].state=65565;
    return points;
};
/*
Provide a compare function to qsort
since the points has to be sorted so we just use qsort
About the order:
1,left point's x is alway higher than right point's x
2,if point's x is equal then we will compare y and the high y is on the left
*/
int compare_func(const void* a,const void* b)
{
    const Point* aa=(const Point*) a;
    const Point* bb=(const Point*) b;
    const Point A=*aa;
    const Point B=*bb;
    if(A.x>B.x)
    {
        return 1;
    }
    else if(A.x<B.x)
    {
        return -1;
    }
    else if(A.x==B.x)
    {
        if(A.y>B.y)
        {
            return 1;
        }
        else if(A.y<B.y)
        {
            return -1;
        }
        else if(A.y==B.y)
            return 0;
    }
    return 0;
}
void print_ans(Point* points,int len)
{
    int i=0;
    while(i<len)
    {
        printf("[%d,%d],\n",points[i].x,points[i].y);
        i++;
    }
    printf("\n");
};
void print_points(Point* points,int len)
{

    for(int i=0;i<len;i++)
    {
        printf("[%d,%d],\n",points[i].x,points[i].y);
    }
    printf("\n");
};
/*
To output point into file

*/
float slope(Point a,Point b)
{
    float delta_x=a.x-b.x;
    float delta_y=a.y-b.y;
    if(delta_x==0&&delta_y>0)
    {
        return 1;
    }
    else if(delta_x==0&&delta_y<0)
    {
        return -1;
    }
    return delta_y/delta_x;
}
int output_file(FILE* point_txt)
{
    return OUTPUT_SUCCESS;
}
/*
Before used,Points should be sorted
partly thinking we only need to consider y

so basically we put the points set into to part
we set the
*/
Point* begin_point(Point* points,int len)
{
    if(len==2)
    {
        return points;
    }
    int* hull_up_points=malloc(sizeof(int)*len+1);
    int* hull_down_points=malloc(sizeof(int)*len+1);
    Point* hull_points=malloc(sizeof(Point)*len);//used to merge two up/down point set
    hull_up_points[0]=0;
    int hull_up_state=0;
    int hull_up_count=1;//to count how many effective element hull_up_points have

    hull_down_points[0]=0;
    int hull_down_state=0;
    int hull_down_count=1;

    for(int i=0;i<len;i++)
    {

        if(hull_up_points[i]<=len-1&&i<=len-1)//haven't reach the rightmost point
        {
            hull_up_points[i+1]=Up_nextp(&points[i],hull_up_points[i],len-1);//left point shouldn't be like this
            hull_up_state=hull_up_points[i+1];
            
            hull_up_count++;
        }
        if(hull_up_points[i]<=len-1)
        {
            hull_down_points[i+1]=Down_nextp(&points[i],hull_down_points[i],len-1);
            hull_down_state=hull_down_points[i+1];
            hull_down_count++;
        }
        /*for(int i=1;i<(hull_up_count+hull_down_count);i+=2)
            {
                if(hull_down_points[i]>=len-1||hull_up_points[i]>=len-1)
                {
                    if(hull_down_points[i]==len-1)
                    free(hull_down_points);
                    if(hull_up_points[i]==len-1)
                    free(hull_up_points);
                    break;
                }
                else if(hull_up_points[i]>=hull_down_points[i])
                {
                    hull_points[i]=points[hull_down_points[i]];//flaut
                    hull_points[i+1]=points[hull_up_points[i]];
                }
                else if(hull_up_points[i]<hull_down_points[i])
                {
                    hull_points[i]=points[hull_up_points[i]];
                    hull_points[i+1]=points[hull_down_points[i]];
                } 
                
            } */
        if(hull_up_points[i]==len-1&&hull_up_points[i]==len-1)//both up&&down function reach the rightmost point
        {
            printf("element=%d",hull_up_count+hull_down_count);
            hull_points[0]=points[0];
            int i;//counter var
            for(i=1;i<hull_up_count;i++)
            {
                if(hull_up_points[i]>len-1)
                break;
                hull_points[i]=points[hull_up_points[i]];
                
            }
            i--;
            for(int j=i+1;j<(hull_up_count+hull_down_count);j++)
            {
                if(hull_up_points[j-i]>len-1)
                break;
                hull_points[j]=points[hull_down_points[j-i]];
            }
            break;

        }
    }
    printf("  counter num:%d,%d  \n",hull_up_count,hull_down_count);
    return hull_points;
}
int Up_nextp(Point* points,int now_point,int left)//before the rightmost point
{
    Point base_point = points[now_point];
    
    int max_index=now_point+1;//to store the highest slope point's index
    float s_last = slope(points[max_index],base_point);
  
    float s_now;
    if(now_point==left)
    {
        return left;
    }
    for(int i=2;i<=left;i++)
    {
        s_now=slope(points[i],base_point);
        if(s_now>=s_last&&i<=left)//should include equal
        {
            max_index=i;
            s_last=slope(base_point,points[max_index]);
            if(i==left)
            printf("got\n");
        }
        
        else if(i==left&&s_now<s_last)
        {
            break;//reached end
        }
        else
        {
            continue;
        }

    }
    printf("hull up points:[%d,%d] \n ",points[max_index].x,points[max_index].y);
    return max_index;
};
int Down_nextp(Point* points,int now_point,int left)
{
    Point base_point = points[now_point];
    int min_index=now_point+1;//to store the lowest slope point's index
    float s_last = slope(base_point,points[min_index]);
    float s_now;
    
    if(now_point==left)
    {
        return left;
    }
    for(int i=2;i<=left;i++)
    {
        s_now=slope(points[i],base_point);
        if(s_now<=s_last&&i<=left)//should include equal
        {
            min_index=i;
            s_last=slope(base_point,points[min_index]);
        }
     
        else if(i==left&&s_now>s_last)
        {
            break;//reached end
        }
        else
        {
            continue;
        }
    }
    printf("hull down points:(%d,%d) \n ",points[min_index].x,points[min_index].y);
    return min_index;
};
