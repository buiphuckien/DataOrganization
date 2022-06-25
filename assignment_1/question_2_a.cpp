#include <stdio.h>

double myCubeRoot(double y)
{
	double mid, left, right;
	left = 0;
	if(y>1)
	{
		right = y;
	}
	else
	{
		right = 1;
	}

	do
	{
		mid = (left + right)/2;
		if(mid*mid*mid > y)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}	
	}
	while((right -left)/right>0.0000001);
	
	return mid;	
}

int main()
{
	for(int i = 1; i < 10; i++){
		double x = 0.1*i;
		double k = x*x*x;
		double m = myCubeRoot(k);
		printf("%f\t%f\n", k, m);
	}
	
	return 0;	
}
