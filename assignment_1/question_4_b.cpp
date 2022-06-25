#include <stdio.h>

double square(double x){
	return x*x;
}

double raisedTo4(double x){
	double y = square(x);
	return y*y;
}

double raisedTo8(double x){
	double y = raisedTo4(x);
	return y*y;
}

double raisedTo16(double x){
	double y = raisedTo8(x);
	return y*y;
}

double raisedTo32(double x){
	double y = raisedTo16(x);
	return y*y;
}

double raisedTo36(double x){
	double z = raisedTo4(x); //z = x^4
	double y = raisedTo8(z); //y = z^8 = (x^4)^8 = x^32
	return y*z;				 //(x^32)*(x^4) = x^36
}

double raisedTo64(double x){
	double y = raisedTo32(x);
	return y*y;
}

double evaluateThePolynomial(double x){
	double y = raisedTo32(x);  // y = x^32
	double z = y*y; 		   // z = y^2 = x^64
	double t = y*raisedTo4(x); // t = y*(x^4) = (x^32)*(x^4) = x^36
	double w = raisedTo8(x-1); // w = (x-1)^8
	double result = 4*z + 3*t + 2*w + 1;
	return result;
	
}

int main(){
	double x;
	printf("Please enter a number: ");
	scanf("%lf", &x);
	double y = evaluateThePolynomial(x);
	printf("\nThe value of the polynomial is %f",y);
	return 0;
}
