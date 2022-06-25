#include <stdio.h>
struct TIME
{
	int hh;
	int mm;
	int ss;
};

const char* digitsToString(int x)
{
	char *p;
	int y = x%10;
	x = x/10;
	*p = '0' + x;
	*(p+1) = '0' + y;
	*(p+2) = '\0';
	return p;
}

int main()
{
	TIME t;
	t.hh = 10;
	const char* h = digitsToString(10);
	t.mm = 12;
	const char* m = digitsToString(12);
	t.ss = 13;
	const char* s = digitsToString(13);
	printf("%s", h);
	return 0;
}
