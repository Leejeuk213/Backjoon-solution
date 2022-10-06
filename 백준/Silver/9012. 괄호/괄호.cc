#include<stack>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char gwal[51];
    stack<char>a;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",gwal);
        stack<char>a;
        if(gwal[strlen(gwal)-1]=='(')
        {
            printf("NO\n");
            continue;
        }
        else
        {
            for(int j=0;j<strlen(gwal);j++)
            {
                if(gwal[j]=='(')
                {
                    a.push(gwal[j]);
                }
                else
                {
                    if(a.size()==0)
                    {
                        printf("NO\n");
                        break;
                    }
                    else
                    {
                        a.pop();
                    }
                }
                if(j==strlen(gwal)-1&&a.size()!=0)
                {
                    printf("NO\n");
                    break;
                }
                else if(j==strlen(gwal)-1&&a.size()==0)
                {
                    printf("YES\n");
                    break;
                }
            }
        }

    }
    return 0;
}