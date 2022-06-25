#include <stdio.h>
#include <stdlib.h>

struct TIME
{
	int hh;
	int mm;
	int ss;
};

//Hàm tính tổng số giây ở thời điểm t
int totalSeconds(TIME t)
{
	return t.hh*3600 + t.mm*60 + t.ss;
}

//Hàm đổi từ số nguyên sang string
char* digitsToString(int x)
{
	char *p;
	p = (char*)malloc(3);
	int y = x%10;
	x = x/10;
	*p = '0' + x;
	*(p + 1) = '0' + y;
	*(p + 2) = '\0';
	return p;
}

//Hàm đổi từ thời gian sang string
char* timeToString(TIME t)
{
	char *p;
	p = (char*)malloc(9);
	char *hh = digitsToString(t.hh);
	char *mm = digitsToString(t.mm);
	char *ss = digitsToString(t.ss);
	*p = *hh;
	*(p + 1) = *(hh + 1);
	*(p + 2) = ':';
	*(p + 3) = *mm;
	*(p + 4) = *(mm + 1);
	*(p + 5) = ':';
	*(p + 6) = *ss;
	*(p + 7) = *(ss + 1);
	*(p + 8) = '\0';
	return p;
}

//Hàm so sánh hai thời điểm, cho biết thời điểm trước nào trước và tổng số giây trôi qua.
void compareTime(TIME t1, TIME t2)
{
	int s1 = totalSeconds(t1);
	int s2 = totalSeconds(t2);
	int diff = s1 - s2;
	if(diff < 0)
	{
		printf("Thoi diem %s truoc thoi diem %s.", timeToString(t1), timeToString(t2));
	}
	else if (diff == 0)
	{
		printf("Thoi diem %s trung thoi diem %s.", timeToString(t1), timeToString(t2));	
	}
	else
	{
		printf("Thoi diem %s truoc thoi diem %s.", timeToString(t2), timeToString(t1));
	}
	printf("\nTong so giay troi qua giua hai thoi diem la %d.", abs(diff));
}

//Hàm kiểm tra thời gian hợp lệ 0 <= h <= 23,  0 <= m <= 59,  0 <= s <= 59. 
bool valid(int h, int m, int s)
{
	if(h<=23 && h>=0 && m<=59 && m>=0 && s<=59 && s>=0)
	{	
		return 1;
	}
	else
	{
		return 0;
	}
}

//Hàm cho phép người dùng nhập thời gian.
TIME inputTime(){
	TIME t;
	char s[8];
	printf("Nhap thoi diem trong ngay theo dinh dang hh:mm:ss vi du 01:05:34 hoac 15:04:02 \n");
	scanf("%s", &s);
	int hh = (s[0] - '0')*10 + (s[1] - '0');
	int mm = (s[3] - '0')*10 + (s[4] - '0');
	int ss = (s[6] - '0')*10 + (s[7] - '0');
	while( !valid(hh, mm, ss))
	{
		printf("Thoi diem ban nhap chua hop le.\nCan nhap theo dinh dang hh:mm:ss vi du 01:05:34 hoac 15:04:02 \n");
		scanf("%s", &s);
		hh = (s[0] - '0')*10 + (s[1] - '0');
		mm = (s[3] - '0')*10 + (s[4] - '0');
		ss = (s[6] - '0')*10 + (s[7] - '0');	
	}
	t.hh = hh;
	t.mm = mm;
	t.ss = ss;
	return t;
}

int main(){
	//Người dùng nhập hai thời điểm.
	TIME t1 = inputTime();
	TIME t2 = inputTime();

	//So sánh hai thời điểm.
	compareTime(t1, t2);

	return 0;
}
