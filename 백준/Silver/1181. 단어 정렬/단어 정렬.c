#include <stdio.h>

#include <string.h>

char a[20001][51];

char sorteda[20001][51];

void merge(int left, int mid, int right)

{

    int iidx=left;

    int kidx=left;

    int jidx=mid+1;

    while(iidx<=mid&&jidx<=right)

    {

        if(strlen(a[iidx])>strlen(a[jidx]))

        {

            

            strcpy(sorteda[kidx++],a[jidx++]);

        }

        else if(strlen(a[iidx])==strlen(a[jidx]))

        {

            if(strcmp(a[iidx],a[jidx])<=0)

            {

                strcpy(sorteda[kidx++],a[iidx++]);      

            }

           else if(strcmp(a[iidx],a[jidx])>0)  

            {

            	strcpy(sorteda[kidx++],a[jidx++]);            	}  

        }  

        else if(strlen(a[iidx])<strlen(a[jidx]))

        {

            

            strcpy(sorteda[kidx++],a[iidx++]);

        }

                       

    }

    if(iidx>mid)

    {

        for(int i=jidx;i<=right;i++)

        {

            strcpy(sorteda[kidx++],a[i]); 

        }

    }

    else

    {

        for(int i=iidx;i<=mid;i++)

        {

            strcpy(sorteda[kidx++],a[i]); 

        }

    }

    for(int i=left;i<=right;i++)

    {

        strcpy(a[i],sorteda[i]); 

    }

}

void mergesort(int left,int right)

{

    int mid;

    if(left<right)

    {

        mid=(left+right)/2;

        mergesort(left,mid);

        mergesort(mid+1,right);

        merge(left,mid,right);

    }

    

}

int main() {

  int roop;

  scanf("%d",&roop);

  int cnt=0;

  for(int i=0;i<roop;i++)

    {

       scanf("%s",a[i]);

    }

    

mergesort(0,roop-1);

  for(int i=0; i<roop;i++)

    {

        if(strcmp(a[i],a[i+1])==0)

        {

            continue;

        }

            printf("%s\n",a[i]);

      

    }

    return 0;

}