#include <stdio.h>

int f(char *s){
	int n = 0;
	while(*s != '\0'){
		if('a' <= *s && *s <= 'f')
			n = n*16 + (*s - 'a' + 10);
		else
			n = n*16 + (*s - '0');
		s++;
	}
	return n;
}
int main(){
	printf("%d\n", f("7de"));
}
