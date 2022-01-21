#include <stdio.h>

int sign(double x){
	return (x>0) - (x<0);
}

int main(){
	for(int i = -5; i<5; i++)
		printf("%d\n", sign(i));
	return 0;
}
