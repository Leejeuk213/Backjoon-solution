#include <stdio.h>
#include <stdlib.h>
    int main()
    {
        long n, k;   
        int cnt=0; 
        int cnt2=0; 
        scanf("%ld %ld", &n, &k);     
        for(long i=5;i<=n;i=i*5)
        {
            cnt=cnt+(n/i)-((n-k)/i)-(k/i);
        } 
        for(long i=2;i<=n;i=i*2)
        {
            cnt2=cnt2+(n/i)-((n-k)/i)-(k/i);
        }
        if(cnt<cnt2) 
        printf("%d",cnt); 
        else
        printf("%d",cnt2); 
        return 0;
    }