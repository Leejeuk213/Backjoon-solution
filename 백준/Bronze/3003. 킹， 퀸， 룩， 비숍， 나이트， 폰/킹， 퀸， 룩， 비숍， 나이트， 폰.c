#include <stdio.h>
#include <string.h>

int main()
{

int peace[6] ;

scanf("%d %d %d %d %d %d",&peace[0],&peace[1],&peace[2],&peace[3],&peace[4],&peace[5]);
printf("%d %d %d %d %d %d",1-peace[0],1-peace[1],2-peace[2],2-peace[3],
2-peace[4],8-peace[5]);
return 0;
}