#include <iostream>
#include <algorithm>
using namespace std;
int d[3]={0,};
int main() {
    int n ;
    scanf("%d",&n);
    int a=300;
    int b=60;
    int c=10;
    while(n)
    {
        if(n>=300)
        {
          n=n-300;
          d[0]++;
          continue;
        }
      if(n>=60)
        {
          n=n-60;
          d[1]++;
          continue;
        }
      if(n>=10)
        {
          n=n-10;
          d[2]++;
          continue;
        }
      if(n==0)
      {
        break;
      }
      if(n>0)
      {
        printf("-1");
        return 0;
      }
    }
    printf("%d ",d[0]);
    printf("%d ",d[1]);
    printf("%d ",d[2]);
    return 0;
}