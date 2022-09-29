//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
int a[100001];
char check[210000][1];
int main()
{
    stack<int> stack;
    int roop;
    scanf("%d",&roop);
    for(int i=0;i<roop;i++)
    {
        int num;
        scanf("%d",&num);
        a[i]=num;
    }
    int j=0;
    int k=0;
    int cnt=1;
    for(int j=0;j<roop;j++)
    {
        while(cnt<=a[j])
        {
            stack.push(cnt);
            cnt++;
            check[k][0]='+';
            k++;
        }
        if(stack.top()==a[j])
        {
            stack.pop();
            check[k][0]='-';
            k++;
        }
        else
        {
            printf("NO");
            return 0;
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%c\n",check[i][0]);
    }
   
    return 0;
}