#include <stdio.h>

//Hàm swap dùng để đổi vị trí hai phần tử của mảng
void swap(int a[], int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
//Sắp xếp các phần tử của mảng sử dụng selectionSort
void selectionSort(int a[], int l){
	for(int i = 0; i<l; i++){
		for(int j = i; j<l; j++){
			if(a[j] < a[i]){
				swap(a, i, j);
			}
		}
	}
}
int main(){
	int n, k;
	printf("Ban muon nhap bao nhieu so nguyen?\n");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i <n; i++){
		printf("Nhap so nguyen thu %d\n", i+1);
		scanf("%d", a + i);
	}
	printf("Cac so nguyen ban da nhap la: \n");
	for(int i = 0; i < n; i++){
		printf("%d\t", *(a+i));	
	}
	selectionSort(a, n);
	printf("\nBan muon tim so nguyen lon thu may?\n");
	scanf("%d", &k);
	while( k>= n || k<=1) //Kiểm tra tính hợp lệ của k.
	{
		printf("\nSo ban nhap khong hop le?\n");
		printf("\nBan muon tim so nguyen lon thu may?\n");
		scanf("%d", &k);	
	}
	printf("So nguyen lon thu %d la %d?\n", k, a[k-1]);
	return 0;
}
