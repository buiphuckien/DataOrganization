#include <stdio.h>

//Dùng để in các phần tử ở giữa của mãng, phần tử có 2 chữ số thì thêm số 0 ở trước, phần tử có 1 chữ số thì thêm 00 ở trước.
void printThreeDigits(int x)
{
	if(x >= 100)
		{
			printf("%d", x);
		}
		else if(x >=10 && x < 100)
		{
			printf("0%d", x);
		}
		else
		{
			printf("00%d", x);
		}
}

// Xuất số nguyên với các dấu phẩy
void outPutIntegerWithComma(int x)
{
	int a[10];
	int count = 0;
	while(x != 0)
	{
		a[count] = x%1000;
		count++;
		x = x/1000;
	}
	//In phần tử đầu
	printf("%d, ", a[count-1]);

	//In các phần tử ở giữa
	for(int i = count-2; i>0; i--)
	{
		printThreeDigits(a[i]);
		printf(", ");
	
	}

	//In phần tử cuối
	printThreeDigits(a[0]);	
}

int main()
{
	int x;
	printf("Please enter an integer: ");
	scanf("%d", &x);
	outPutIntegerWithComma(x);
	return 0;
}
