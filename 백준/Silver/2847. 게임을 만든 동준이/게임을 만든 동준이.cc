#include<stdio.h>
using namespace std;
int n;
int arr[101]={0,};
int ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        if(arr[i]<=arr[i-1])
        {
            int temp=arr[i-1];
            arr[i-1]=arr[i]-1;
            ans=ans+(temp-arr[i-1]);
        }
    }
    printf("%d",ans);
    return 0;
}