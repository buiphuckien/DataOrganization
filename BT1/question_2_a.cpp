#include <stdio.h>
#include <unistd.h>
double myCubeRoot(double y)
{
	double x, l, r;
	if(y > l)
		r = y;
	else
		r = l;
	l = 0;
	do
	{
		x = (l + r)/2;
		if(x*x*x > y)
		{
			r = x;
		}
		else
		{
			l = x;
		}	
	}
	while((r-l)/r>0.0000001);
	
	return x;	
}

int main()
{
	double m = myCubeRoot(8);
	printf("%f", m);
	return 0;	
}
