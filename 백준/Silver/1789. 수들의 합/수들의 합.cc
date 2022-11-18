#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long sum_N=0;
    long long start=0;
    while(n>=sum_N)
    {
        start+=1;
        sum_N+=start;
        if( n < sum_N)
        {
        break;
        }
    }
printf("%d",start-1);
    return 0;
}