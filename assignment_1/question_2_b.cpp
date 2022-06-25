#include <stdio.h>
#include <math.h>

double myCubeRoot(double m)
{
	double x = 1;
	do{
		x = x - (x*x*x - m)/(3*x*x);
	}
	while(abs(x*x*x - m)>0.000000000001);
	return x;	
}

int main()
{
	for(int i = -10; i < 10; i++){
		double x = 0.1*i;
		double k = x*x*x;
		double r = myCubeRoot(k);
		printf("%f\t%f\n", k, r);
	}
	return 0;	
}
