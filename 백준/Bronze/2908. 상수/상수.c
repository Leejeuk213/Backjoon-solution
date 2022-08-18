#include <stdio.h>

int main()
{
int a;
int b;

scanf("%d %d",&a,&b);

int a_hun=a/100;
int a_ten=(a%100)/10;
int a_one=a%10;
int b_hun=b/100;
int b_ten=(b%100)/10;
int b_one=b%10;

if(a_one>b_one)
{
    printf("%d",a_one);
    printf("%d",a_ten);
    printf("%d",a_hun);
    return 0;  
}
else if(a_one<b_one)
{
    printf("%d",b_one);
    printf("%d",b_ten);
    printf("%d",b_hun);
    return 0; 
}

else if(a_one==b_one)
{
    if(a_ten>b_ten)
    {
        printf("%d",a_one);
        printf("%d",a_ten);
        printf("%d",a_hun);
        return 0;  
    }
    else if(a_ten<b_ten)
    {
        printf("%d",b_one);
        printf("%d",b_ten);
        printf("%d",b_hun);
        return 0; 
    }
    else if(a_ten==b_ten)
    {
        if(a_hun>b_hun)
        {
            printf("%d",a_one);
            printf("%d",a_ten);
            printf("%d",a_hun);
            return 0;  
        }
        else if(a_hun<b_hun)
        {
            printf("%d",b_one);
            printf("%d",b_ten);
            printf("%d",b_hun);
            return 0; 
        }
    }
}


return 0;
}