#include <stdio.h>

void toHex(int n, char h[]){
	int l = sizeof(h)/sizeof(h[0]); //Lấy chiều dài của chuổi h
	int count = 0;					//dùng một biến đếm để đếm số ký tự cần thiết.
	char temp[l];					//Khai báo một chuỗi tạm có kích thước bằng kích thước của chuỗi h.
	while(n != 0){
		int x = n%16;						//Lấy số dư khi chia n cho 16
		if(x >= 10)							//Nếu x >= 10 thì gán 1 trong các kí tự a, b,
			temp[count] = 'a' + x - 10;		//c, d, e, f vào temp[count].
		else
			temp[count] = '0' + x;			//Nếu x < 10 thì gán 1 trong các kí tự 0, 1,... ,9 vào temp[count]
		n = n/16;							//Lấy phần nguyên của n/16 gán lại vào n.
		count++;					
	}
	for(int i = 0; i<count; i++){			//Gán các phần tử từ chuỗi tạm vào h theo thứ tự ngược lại.
		h[i] = temp[count-i-1];
	}
}
int main(){
	char h[100];
	toHex(129093884, h);
	printf("%s\n", h);
}
