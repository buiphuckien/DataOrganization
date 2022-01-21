#include <stdio.h>

double absoluteValue(double x){
	return x*((x>0)-(x<0));
}

int main(){
	for(int i = -5; i<5; i++)
		printf("%f\t", absoluteValue(i));
	return 0;
}
