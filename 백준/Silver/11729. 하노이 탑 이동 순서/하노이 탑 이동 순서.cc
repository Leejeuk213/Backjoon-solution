#include<stdio.h>
#include<string.h>
#include<math.h>
int cnt = 0;
void hanoi(int n,int from, int by, int to)
{
    
    if (n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else
    {
        hanoi(n - 1, from, to, by);
        printf("%d %d\n", from, to);
        hanoi(n - 1, by, from, to);
    }
}
void counthanoi(int n, int from, int by, int to)
{
    cnt++;
    if (n == 1)
    {
        return;
    }
    else
    {
        counthanoi(n - 1, from, to, by);
        
        counthanoi(n - 1, by, from, to);
    }
}
int main(void)
{
    int a;
    scanf("%d", &a);
    counthanoi(a,1,2,3);
    printf("%d\n", cnt);
    hanoi(a, 1, 2, 3);
	return 0;
}