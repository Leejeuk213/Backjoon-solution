#include <stdio.h>

int main()
{



    int num[5];
    scanf("%d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4]);

    int cnt=(num[0]*num[0])+(num[1]*num[1])+(num[2]*num[2])+(num[3]*num[3])+
    (num[4]*num[4]);
   

    printf("%d",cnt%10);
}