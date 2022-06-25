#include <stdio.h>

double absoluteValue(double x){
	return x*((x>0)-(x<0));
}

int main(){
	double x;
	printf("Please enter a number: ");
	scanf("%lf", &x);
	double y = absoluteValue(x);
	printf("The absolute value of %f is  %f", x, y);
	return 0;
}
