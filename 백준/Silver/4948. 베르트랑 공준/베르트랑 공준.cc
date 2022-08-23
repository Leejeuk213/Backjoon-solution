#include <stdio.h>
#include <math.h>

#define SIZE 300000

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
    int top;
    a[0]=1;
    a[1]=1;
    while(1)
    {
    scanf("%d",&top);
    int cnt=0;
    if(top==0)
    {
        break ;
    }
    for(i = top+1; i <= top*2; i++) 
        {
    
        if(a[i] == 0) cnt++;
        }
    printf("%d\n",cnt);
    }

    return 0;
}