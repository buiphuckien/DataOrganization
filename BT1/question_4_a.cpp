#include <stdio.h>

double raisedTo20(double x){
	double y = x*x;
	y = y*y; // y = x^4
	double z = y*y;
	z = z*z; // z = x^16
	return y*z;
}

int main(){
	for(int i = -5; i<5; i++)
		printf("%f  ", raisedTo20(i));
	return 0;
}
