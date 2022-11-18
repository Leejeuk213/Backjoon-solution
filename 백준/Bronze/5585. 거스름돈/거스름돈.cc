#include <iostream>

int main() {
    int n ;
    scanf("%d",&n);
    int handler=1000-n;
    int ans=0;
    while(handler)
      {
        if(handler>=500)
        {
          handler=handler-500;
          ans++;
          continue;
        }
        if(handler>=100)
        {
          handler=handler-100;
          ans++;
          continue;
        }
        if(handler>=50)
        {
          handler=handler-50;
          ans++;
          continue;
        }
        if(handler>=10)
        {
          handler=handler-10;
          ans++;
          continue;
        }
        if(handler>=5)
        {
          handler=handler-5;
          ans++;
          continue;
        }
        if(handler>=1)
        {
          handler=handler-1;
          ans++;
          continue;
        }
      }
    printf("%d",ans);
    return 0;
}