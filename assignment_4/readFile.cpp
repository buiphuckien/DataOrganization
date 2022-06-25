#include <stdio.h>

int main(int argc,char* argv[])
{
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    unsigned char buffer[1000]; // mang cac byte
    unsigned char obuffer[4000]; // mang cac byte su ly
    if(*argv[1] == '1')
    { 
        FILE* f = fopen(inputFile, "rb");
        if(f == NULL)
            printf("Error opening input file");
        else
        {
        FILE* of = fopen(outputFile, "wb");
        if(of == NULL)
            printf("Error opening output file");
        else
        {
            int n;
            while((n = fread(buffer, 1, 1000, f)) > 0)
            {
                //Xu ly xong n byte trong buffer vao obuffer
                int i = 0, j = 0;
                while(i < n)
                {
                    if(buffer[i] == 'e')
                    {
                        if(i < n - 1 && buffer[i + 1] == '^')
                        {
                            if(i < n-2 && buffer[i + 2] == '.') //e^.
                            {
                                //E1 BB 87
                                obuffer[j++] = 0xE1;
                                obuffer[j++] = 0xBB;
                                obuffer[j++] = 0x87;
                                i += 3;
                            }
                            else if(i < n-2 && buffer[i + 2] == '\'') //e^'
                            {
                                //E1 BA BF
                                obuffer[j++] = 0xE1;
                                obuffer[j++] = 0xBA;
                                obuffer[j++] = 0xBF;
                                i += 3;
                            }
                            else //e^
                            {
                                obuffer[j++] = 0xC3;
                                obuffer[j++] = 0xAA;
                                i += 2;
                            } 
                        }
                        else
                            obuffer[j++] = buffer[i++];
                    }
                    else if(buffer[i] == 'd')
                    {
                        obuffer[j++] = 0xC4;
                        obuffer[j++] = 0x91;
                        i += 2;
                    }
                    else if(buffer[i] == 'a' && buffer[i + 1] == '^')
                    {
                        //E1 BA A5
                        obuffer[j++] = 0xE1;
                        obuffer[j++] = 0xBA;
                        obuffer[j++] = 0xA5;
                        i += 3;
                    }
                    else if(buffer[i] == 'o' && buffer[i + 1] == '*')
                    {
                        //E1 BB 9B
                        obuffer[j++] = 0xE1;
                        obuffer[j++] = 0xBB;
                        obuffer[j++] = 0x9B;
                        i += 3;
                    }
                    else if(buffer[i] == '\\') { i++; }
                    else if(buffer[i] == 'u' && buffer[i + 1] == '*')
                    {
                        //	C6 B0
                        obuffer[j++] = 0xC6;
                        obuffer[j++] = 0xB0;
                        i += 2;
                    }
                    else
                        obuffer[j++] = buffer[i++];
                }
                fwrite(obuffer, 1, j, of);
            }
            
            fclose(of);
        }
        fclose(f);
        printf("Done");
        }  
    }
    else
    {
        FILE* f = fopen(inputFile, "rb");
        if(f == NULL)
            printf("Error opening input file");
        else
        {
        FILE* of = fopen(outputFile, "wb");
        if(of == NULL)
            printf("Error opening output file");
        else
        {
            int n;
            while((n = fread(buffer, 1, 1000, f)) > 0)
            {
                //Xu ly xong n byte trong buffer vao obuffer
                int i = 0, j = 0;
                while(i < n)
                {
                    if(buffer[i] == 0xE1 && buffer[i + 1] == 0xBB && buffer[i + 2] == 0x87)
                    {
                        obuffer[j++] = 0x65;
                        obuffer[j++] = 0x5E;
                        obuffer[j++] = 0x2E;
                        i += 3;
                    }
                    else if(buffer[i] == 0xC4 && buffer[i + 1] == 0x91)
                    {
                        obuffer[j++] = 'd';
                        obuffer[j++] = 'd';
                        i += 2;
                    }
                    else if(buffer[i] == 0xE1 && buffer[i + 1] == 0xBA && buffer[i + 2] == 0xA5)
                    {
                        obuffer[j++] = 'a';
                        obuffer[j++] = '^';
                        obuffer[j++] = '\'';
                        i += 3;
                    }
                    else if(buffer[i] == 0xC6 && buffer[i + 1] == 0xB0)
                    {
                        obuffer[j++] = 'u';
                        obuffer[j++] = '*';
                        i += 2;
                    }
                    else if(buffer[i] == 0xE1 && buffer[i + 1] == 0xBB && buffer[i + 2] == 0x9B)
                    {
                        obuffer[j++] = 'o';
                        obuffer[j++] = '*';
                        obuffer[j++] = '\'';
                        i += 3;
                    }
                    else if(buffer[i] == 0xE1 && buffer[i + 1] == 0xBA && buffer[i + 2] == 0xBF)
                    {
                        obuffer[j++] = 'e';
                        obuffer[j++] = '^';
                        obuffer[j++] = '\'';
                        i += 3;
                    }
                    else if(buffer[i] == 0xC3 && buffer[i + 1] == 0xAA)
                    {
                        obuffer[j++] = 'e';
                        obuffer[j++] = '^';
                        i += 2;
                    }
                    else if(buffer[i] == '.' && (i = n-1))
                    {
                        obuffer[j++] = '\\';
                        obuffer[j++] = '.';
                        i += 2;
                    }
                    else
                    {
                        obuffer[j++] = buffer[i++];
                    }
                }
                fwrite(obuffer, 1, j, of);
            }
            
            fclose(of);
        }
        fclose(f);
        printf("Done");
    }
    }
    return 0;
}