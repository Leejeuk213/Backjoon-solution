#include<stdio.h>
#include<math.h>
int a,b;
int amin_arr[8];
int amax_arr[8];
int bmin_arr[8];
int bmax_arr[8];
int main()
{
    scanf("%d %d",&a,&b);
    int a_idx=0;
    int b_idx=0;
    int min_a=0;
    int max_a=0;
    int min_b=0;
    int max_b=0;
    while(a)
    {
        if(a%10==5)
        {
            amin_arr[a_idx]=5;
            amax_arr[a_idx]=6;
        }
        else if(a%10==6)
        {
            amin_arr[a_idx]=5;
            amax_arr[a_idx]=6;
        }
        else
        {
            amin_arr[a_idx]=a%10;
            amax_arr[a_idx]=a%10;
        }
        a=a/10;
        a_idx++;
    }
    while(b)
    {
        if(b%10==5)
        {
            bmin_arr[b_idx]=5;
            bmax_arr[b_idx]=6;
        }
        else if(b%10==6)
        {
            bmin_arr[b_idx]=5;
            bmax_arr[b_idx]=6;
        }
        else
        {
            bmin_arr[b_idx]=b%10;
            bmax_arr[b_idx]=b%10;
        }
        b=b/10;
        b_idx++;
    }
    for(int i=0;i<a_idx;i++)
    {
        min_a=min_a+(amin_arr[i]*round(pow(10,i)));
        max_a=max_a+(amax_arr[i]*round(pow(10,i)));
        //printf("%d %d\n",min_a,max_a);
    }
    for(int i=0;i<b_idx;i++)
    {
        min_b=min_b+(bmin_arr[i]*round(pow(10,i)));
        max_b=max_b+(bmax_arr[i]*round(pow(10,i)));
       // printf("%d %d\n",min_b,max_b);
    }
    printf("%d %d",min_a+min_b,max_a+max_b);
}