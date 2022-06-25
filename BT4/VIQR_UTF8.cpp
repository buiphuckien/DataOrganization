/*
BÀI TẬP 4
CHUYÊN ĐỀ TỔ CHỨC DỮ LIỆU
Sinh viên: Bùi Phúc Kiển
MSSV: 20880034
*/

#include <stdio.h>
void mode1(FILE *InFile, FILE *OutFile, unsigned char *buffer, unsigned char *obuffer)
{
    int n;
    while ((n = fread(buffer, 1, 1000, InFile)) > 0)
    {
        // Chuyển n byte trong buffer vào obuffer
        int i = 0, j = 0;
        while (i < n)
        {
            //Xử lý cho e^, e^', và e^.
            if (buffer[i] == 'e')
            {
                if (i < n - 1 && buffer[i + 1] == '^')
                {
                    if (i < n - 2 && buffer[i + 2] == '.') // e^.
                    {
                        // E1 BB 87
                        obuffer[j++] = 0xE1;
                        obuffer[j++] = 0xBB;
                        obuffer[j++] = 0x87;
                        i += 3;
                    }
                    else if (i < n - 2 && buffer[i + 2] == '\'') // e^'
                    {
                        // E1 BA BF
                        obuffer[j++] = 0xE1;
                        obuffer[j++] = 0xBA;
                        obuffer[j++] = 0xBF;
                        i += 3;
                    }
                    else // e^
                    {
                        obuffer[j++] = 0xC3;
                        obuffer[j++] = 0xAA;
                        i += 2;
                    }
                }
                else
                    obuffer[j++] = buffer[i++];
            }
            //Xử lý cho dd
            else if (buffer[i] == 'd')
            {
                obuffer[j++] = 0xC4;
                obuffer[j++] = 0x91;
                i += 2;
            }
            //Xử lý cho a^'
            else if (buffer[i] == 'a' && buffer[i + 1] == '^')
            {
                // E1 BA A5
                obuffer[j++] = 0xE1;
                obuffer[j++] = 0xBA;
                obuffer[j++] = 0xA5;
                i += 3;
            }
            //Xử lý cho o*'
            else if (buffer[i] == 'o' && buffer[i + 1] == '*')
            {
                // E1 BB 9B
                obuffer[j++] = 0xE1;
                obuffer[j++] = 0xBB;
                obuffer[j++] = 0x9B;
                i += 3;
            }
            //Xử lý cho '\'
            else if (buffer[i] == '\\')
            {
                i++;
            }
            //Xử lý cho u*
            else if (buffer[i] == 'u' && buffer[i + 1] == '*')
            {
                //	C6 B0
                obuffer[j++] = 0xC6;
                obuffer[j++] = 0xB0;
                i += 2;
            }
            //Các trường hợp bình thường
            else
                obuffer[j++] = buffer[i++];
        }
        //Viết các byte trong obuffer vào file xuất
        fwrite(obuffer, 1, j, OutFile);
    }
}
void mode2(FILE *InFile, FILE *OutFile, unsigned char *buffer, unsigned char *obuffer)
{
    int n;
    while ((n = fread(buffer, 1, 1000, InFile)) > 0)
    {
        // Xu ly xong n byte trong buffer vao obuffer
        int i = 0, j = 0;
        while (i < n)
        {
            //Xử lý cho 'ệ' -> e^.
            if (buffer[i] == 0xE1 && buffer[i + 1] == 0xBB && buffer[i + 2] == 0x87)
            {
                obuffer[j++] = 'e';
                obuffer[j++] = '^';
                obuffer[j++] = '.';
                i += 3;
            }
            //Xử lý cho 'đ'
            else if (buffer[i] == 0xC4 && buffer[i + 1] == 0x91)
            {
                obuffer[j++] = 'd';
                obuffer[j++] = 'd';
                i += 2;
            }
            //Xử lý cho 'ấ' -> a^.
            else if (buffer[i] == 0xE1 && buffer[i + 1] == 0xBA && buffer[i + 2] == 0xA5)
            {
                obuffer[j++] = 'a';
                obuffer[j++] = '^';
                obuffer[j++] = '\'';
                i += 3;
            }
            //Xử lý cho 'ư' -> u*
            else if (buffer[i] == 0xC6 && buffer[i + 1] == 0xB0)
            {
                obuffer[j++] = 'u';
                obuffer[j++] = '*';
                i += 2;
            }
            //Xử lý cho 'ớ' -> o*'
            else if (buffer[i] == 0xE1 && buffer[i + 1] == 0xBB && buffer[i + 2] == 0x9B)
            {
                obuffer[j++] = 'o';
                obuffer[j++] = '*';
                obuffer[j++] = '\'';
                i += 3;
            }
            //Xử lý cho 'ế' -> e^'
            else if (buffer[i] == 0xE1 && buffer[i + 1] == 0xBA && buffer[i + 2] == 0xBF)
            {
                obuffer[j++] = 'e';
                obuffer[j++] = '^';
                obuffer[j++] = '\'';
                i += 3;
            }
            //Xử lý cho 'ê' -> e^
            else if (buffer[i] == 0xC3 && buffer[i + 1] == 0xAA)
            {
                obuffer[j++] = 'e';
                obuffer[j++] = '^';
                i += 2;
            }
            //Thêm '\' vào trước dấu '.' hết câu
            else if (buffer[i] == '.' && (i = n - 1))
            {
                obuffer[j++] = '\\';
                obuffer[j++] = '.';
                i += 2;
            }
            //Các trường hợp còn lại
            else
                obuffer[j++] = buffer[i++];
        }
        //Viết vào file output
        fwrite(obuffer, 1, j, OutFile);
    }
}
int main(int argc, char *argv[])
{
    char *InputFile = argv[2];
    char *OutputFile = argv[3];
    unsigned char InputInBuff[1000];  // mang cac byte
    unsigned char OutputInBuff[4000]; // mang cac byte su ly
    FILE *f = fopen(InputFile, "rb");
    if (f == NULL)
        printf("Error opening input file");
    else
    {
        FILE *of = fopen(OutputFile, "wb");
        if (of == NULL)
            printf("Error opening output file");
        else
        {
            if (*argv[1] == '1')
                mode1(f, of, InputInBuff, OutputInBuff);

            else
                mode2(f, of, InputInBuff, OutputInBuff);
            fclose(of);
        }
        fclose(f);
        printf("Done\n");
    }
    return 0;
}