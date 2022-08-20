#include <stdio.h>

int main()
{

int num[8];
scanf("%d %d %d %d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],
&num[4],&num[5],&num[6],&num[7]);
int cnt=0;
for (int i=0;i<4;i++)
{
    int b=num[i]+num[7-i];
    
    if(b==9)
       {
        cnt++;
       }
}
int cnt2=0;
for (int j=0;j<7;j++)
{
    int check=num[j]-num[j+1];
if(check==1||check==-1)
{
    cnt2++;
}
}
 if(cnt==4&&cnt2==7)
 {
     if (num[0]<num[1])
        {
            printf("ascending");
            return 0;

        }
        else if (num[0]>num[1])
        {
             printf("descending");
            return 0;
        }
        else{
             printf("mixed");
    return 0;
        }
    }
else{
    printf("mixed");
    return 0;
}
 }