#include <stdio.h>

#define Max (1024 * 1024)
int main(int argc, char *argv[])
{
    argv[1] = "test.gif";
    FILE *fptr = fopen(argv[1], "rb");
    int i = 0;
    char data[Max];
    while (!feof(fptr))
    {
        data[i++] = fgetc(fptr);
    }
    fclose(fptr);
    data[0] = data[0] == 'G' ? 'S' : 'G';
    FILE *fptr1 = fopen(argv[1], "wb");
    for (int j = 0; j < i - 1; j++)
    {
        fputc(data[j], fptr1);
    }
    fclose(fptr1);
    return 0;
}