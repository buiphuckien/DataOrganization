#include <stdio.h>
#include <stdlib.h>

struct TIME
{
	int hh;
	int mm;
	int ss;
};

//
int totalSeconds(TIME t)
{
	return t.hh*3600 + t.mm*60 + t.ss;
}

void compareTime(TIME t1, TIME t2)
{
	int s1 = totalSeconds(t1);
	printf("%d\n", s1);
	int s2 = totalSeconds(t2);
	printf("%d\n", s2);
	int diff = s1 - s2;
	if(diff > 0)
	{
		printf("Thoi diem 1");
	}
	else if (diff == 0 )
	{
		printf("Thoi diem 2");
	}
	else
	{
		printf("Thoi diem 3");
	}
	printf("\nTong so giay troi qua giua hai thoi diem la %d %d.", diff, abs(diff));
}
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

TIME inputTime(){
	TIME t;
	char s[8];
	printf("Nhap thoi diem trong ngay theo dinh dang hh:mm:ss vi du 01:05:34 hoac 15:04:02 \t");
	scanf("%s", &s);
	int hh = (s[0] - '0')*10 + (s[1] - '0');
	int mm = (s[3] - '0')*10 + (s[4] - '0');
	int ss = (s[6] - '0')*10 + (s[7] - '0');
	while( !valid(hh, mm, ss))
	{
		printf("Thoi diem ban nhap chua hop le.\nCan nhap theo dinh dang hh:mm:ss vi du 01:05:34 hoac 15:04:02 \t");
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

int main()
{
	TIME t1 = inputTime();
	TIME t2 = inputTime();
	compareTime(t1, t2);
	return 0;
}
