#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void) {
    FILE *fin, *fout;
    if ((fin = fopen("fin.txt", "r")) == NULL) {
        puts("Error opening input file");
        exit(1);
    }
    if ((fout = fopen("fout.txt", "w")) == NULL) {
        puts("Error opening output file");
        exit(1);
    }
    //1 Варіант
    /*char ch = getc(fin);
    while (ch != EOF) {
        putc(ch, fout);
        ch = getc(fin);
    }*/

    //2 варіант
    /*char temp[30];
    while (!feof(fin)) {
        fscanf(fin, "%s", temp);
        fprintf(fout, "%s ", temp);
    }*/

    //3 Варіант
    char temp[31];
    while (!feof(fin)) {
        fgets(temp, 30, fin);
        fputs(temp, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
