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
        int n = fread(buffer, 1, 1000, f);
        for(int i = 0; i < n; i++)
        {
            printf("%x\n", buffer[i]);
        }
        FILE* of = fopen(outputFile, "wb");
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(buffer[i] == 0xE1)
            {
                obuffer[j++] = 0x65;
                obuffer[j++] = 0x5E;
                obuffer[j++] = 0x2E;
            }
        }
        fwrite(obuffer, 1, j, of);
        fclose(of);
        fclose(f);
    }
    return 0;
}