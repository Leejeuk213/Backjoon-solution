#include <stdio.h>
#include <math.h>

#define SIZE 10001

int main(void)
{
    int a[SIZE] = { 0 };	// 0 ~ 200
    int i, j;

    for(i = 2; i <= sqrt(SIZE); i++) {	// 최대값의 제곱근까지 반복
        if(a[i] == 0) {		//i가 소수이면
            for(j = 2; i * j < SIZE; j++) {	// 자신을 제외한 i의 배수 제거
                a[i * j] = 1;
            }
        }
    }
    int roop;
    a[0]=1;
    a[1]=1;

    scanf("%d",&roop);
    
   for(int i=0;i<roop;i++)
   {
    int num;
    scanf("%d",&num);
    int halp=num/2;
    int cnt=0;
        for(int j=halp;j>=2;j--)
        {
            
            if(a[j]==0&&a[halp+cnt]==0&&j+halp+cnt==num)
            {
                printf("%d %d\n",j,halp+cnt);
                continue;
            }
            cnt++;
        }
     
    }
    return 0;
}