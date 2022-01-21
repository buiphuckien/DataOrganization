#include <stdio.h>

void printThreeDigits(int x)
{
	if(x >= 100)
		{
			printf("%d", x);
		}
		else if(x >=10 && x < 100)
		{
			printf("0%d", x);
		}
		else
		{
			printf("00%d", x);
		}
}
int outPutIntegerWithComma(int x)
{
	int a[10];
	int count = 0;
	while(x != 0)
	{
		a[count] = x%1000;
		count++;
		x = x/1000;
	}
	printf("%d, ", a[count-1]);
	for(int i = count-2; i>0; i--)
	{
		printThreeDigits(a[i]);
		printf(", ");
	
	}
	printThreeDigits(a[0]);	
}

int main()
{
	outPutIntegerWithComma(100000003);
	return 0;
}
