#include <stdio.h>

int main(){
    int a;
    a = 10;
    int* p;
    p = &a;
    *p = 20;

    printf("Gia tri cua a: %d\n", a);
    printf("Dia chi cua a: %x \t %x \n", &a, p);
    printf("Gia tri cua p: %x\n", p);
    printf("Gia tri noi p tro: d\n", *p);
    printf("Dia chi cua p: %x\n", &p);
    printf("What's this?: %x\n", &*p); //&*p = &a = p
    printf("What's this?: %x\n", *&p); //q = &p, *q = gia tri cua p = &a
    return 0;
}