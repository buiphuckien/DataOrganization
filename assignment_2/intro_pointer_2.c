#include <stdio.h>

int main(){
	char s[] = "hello";
	printf("Chuoi ban dau: %s\n", s);
	
	char *p = s; //p = &s[0]
	*p = 'H'; //s[0] = "H"
	printf("Chuoi sau khi sua: %s\n", s);
	printf("Ki tu dau cua chuoi: %c\n", *s);
	
	p = &s[1];  //
	*p = 'i'; //s[1] = "i"
	*(&s[2]) = '\0'; //Ky tu cuoi cua chuoi
	printf("What's this?: %s\n", s);
	return 0;
}
