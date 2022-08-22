#include <stdio.h>
#include <string.h>


int main()
{
int total;
scanf("%d",&total);
int roop;
scanf("%d",&roop);
int price;
int num;
for(int i=0;i<roop;i++)
{
    scanf("%d %d",&price,&num);
    total=total-(price*num);
}
if(total==0)
{
    printf("Yes");
    return 0;
}
else{
    printf("No");
}
return 0;
}