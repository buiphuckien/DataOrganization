#include <stdio.h>
#include <stdlib.h>
char* digitsToString(int x)
{
	char* p;
	p = (char*)malloc(3);
	int y = x%10;
	x = x/10;
	*p = '0' + x;
	*(p+1) = '0' + y;
	*(p+2) = '\0';
	return p;
}

int main()
{
	char* p1 = digitsToString(7);
	char* p2 = digitsToString(90);
	printf("%s\t%s\n", p1, p2);
	return 0;
}
