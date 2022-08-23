#include <stdio.h>
#include <math.h>

#define SIZE 1000001

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
    int bottom;
    scanf("%d %d",&top,&bottom);
    a[0]=1;
    a[1]=1;
    for(i = top; i <= bottom; i++) {
        if(a[i] == 0) printf("%d\n", i);
    }

    return 0;
}