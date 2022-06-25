#include <stdio.h>

int sign(double x){
	return (x>0) - (x<0);
}

int main(){
	double x;
	printf("Please enter a number: ");
	scanf("%lf", &x);
	int y = sign(x);
	printf("\nsign(%f) =  %d", x, y);
	return 0;
}
