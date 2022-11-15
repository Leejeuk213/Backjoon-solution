#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a % 5 == 1 || a % 5 == 3)
	{
		printf("%d", (a / 5) + 1);
	}
	else if (a == 4 || a == 7)
	{
		printf("-1");
	}
	else if (a % 5 == 2 || a % 5 == 4)
	{
		printf("%d", (a / 5) + 2);
	}
	else if (a % 5 == 0)
	{
		printf("%d", a / 5);
	}
	

}