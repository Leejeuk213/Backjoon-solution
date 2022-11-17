#include<stdio.h>
long long min(long long a, long long b)
{
	if (a > b)
	{
		return b;
	}
	else if(a<b){
		return a;
	}
	else
	{
		return a;
	}
}
long long color[1001][3];
long long d[1001][3];
int main(void)
{
	
	 color[0][0],color[0][1],color[0][2],d[0][0], d[0][1], d[0][2] = 0;
	int a;
	scanf("%d", &a);
	long long red=0;
	long long green=0;
	long long blue=0;
	for (int i = 1; i <= a; i++)
	{
		
		scanf("%lld %lld %lld", &red, &green, &blue);
		color[i][0] = red;
		color[i][1] = green;
		color[i][2] = blue;
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + color[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + color[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + color[i][2];
	}
	printf("%lld", min(min(d[a][0], d[a][1]), d[a][2]));
	
	return 0;
}