#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int roop;
        scanf("%d",&roop);
        vector <int> v1;
        long long ans=0;
        for(int j=0;j<roop;j++)
        {
            int num;
            scanf("%d",&num);
            v1.push_back(num);
        }
        int max=0;
        for(int j=v1.size()-1;j>=0;j--)
        {
            if(max<v1[j])
            {
                max=v1[j];
            }
            else
            {
                ans=ans+max-v1[j];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}