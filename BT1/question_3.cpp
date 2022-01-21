#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(65001);
	printf("\x42\xC3\xB9\x69\x20\x50\x68\xC3\xBA\x63\x20\x4B\x69\xE1\xBB\x83\x6E");
	return 0;
}
