#include <stdio.h>

int main()
{
    char inputFile[] = "output.txt";
    char outputFile[] = "output2.txt";
    unsigned char buffer[1000]; // mang cac byte
    unsigned char obuffer[1000]; // mang cac byte
    FILE* f = fopen(inputFile, "rb");
    if(f == NULL)
        printf("Error opening input file");
    else
    {
        int n = fread(buffer, 1, 1, f);
        printf("%x\n", buffer);

        while (n)
        {
            printf("%d\n", n);
            n = fread(buffer, 1, 1, f);
            printf("%s\n", buffer);
        }
        
        fclose(f);
    }
    return 0;
}