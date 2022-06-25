#include <stdio.h>

float raisedTo20(float x){
	float y = x*x;
	y = y*y; // y = x^4
	float z = y*y;
	z = z*z; // z = x^16
	return y*z; //(x^4)*(x^16) = x^20
}

int main(){
	float x;
	printf("Please enter a number: ");
	scanf("%f", &x);
	float y = raisedTo20(x);
	printf("\n%f raised to 20 is %f", x, y);
	return 0;
}

