#include <stdio.h>

int main(){
	char a[11];
	*a = 'Y' - 1;
	printf("Dia chi a[0]: %x va gia tri a[0]: %c\n", &a, *a);
	*(a + 1) = 0x69; //Gan a[1] = 'i'
	printf("Dia chi a[1]: %x va gia tri a[1]: %c\n", &a[1], *(a+1));
	int *p = (int *)(a + 2); //p tro toi a[2], chua so nguyen a[2], a[3], a[4], a[5]
	*p = 1751326830; //Gan so nguyen nay vao cac o nho a[2], a[3], a[4], a[5]
	printf("Gia tri a[2], a[3], a[4], a[5]: %d\t %d\t %d\t %d\n", *(a+2), *(a+3), *(a+4), *(a+5));
	a[6] = 133; //ki tu a trong ascii mo rong
	p = (int *)&a[7]; //p tro toi dia chi a[7], ep thanh kieu int*
	*p = 0xA6F; //p=2671, gan vao cac o nho a[7], a[8], a[9], a[10]
	printf("Gia tri a[7], a[8], a[9], a[10]: %d\t %d\t %c\t %c\n", *(a+7), *(a+8), *(a+9), *(a+10));
	printf("%s", a);
	return 0;
}
