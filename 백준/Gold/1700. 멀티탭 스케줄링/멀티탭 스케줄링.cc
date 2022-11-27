#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int n,k;
int a[101]={0,};
int ans=0;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
    {
        int num;
        scanf("%d",&num);
        a[i]=num;
        if(v.size()<n&&find(v.begin(),v.end(),a[i])==v.end())
        {
            v.push_back(num);
        }
    }
    for(int i=n;i<k;i++)
    {
        if(find(v.begin(),v.end(),a[i])==v.end())
        {
            vector<int>temp;
            temp.resize(v.size());
            copy(v.begin(),v.end(),temp.begin());
            int *index=0;
            int emb=0;
            for(int j=0;j<temp.size();j++)
            {
                if(index==0)
                {
                    index=find(a+i+1,a+k,temp[j]);
                    emb=temp[j];
                }
                else if(index<find(a+i+1,a+k,temp[j]))
                {
                    index=find(a+i+1,a+k,temp[j]);
                    emb=temp[j];
                }
            }
            v.erase(find(v.begin(),v.end(),emb));
            v.push_back(a[i]);
          /*  for(int j=0;j<v.size();j++)
            {
                printf("%d ",v[j]);
            }
            printf("\n");*/
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}