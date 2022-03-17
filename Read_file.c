#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Ask_which_file(char file_name[256]);
void File_view(FILE *fp);

int main (void)
{
    FILE *fp;
    char target_file[256];

    Ask_which_file( target_file );
    //Check_file_extension( target_file );

    if ((fp = fopen(target_file, "r")) == NULL) {
        fprintf(stderr, "file open : error!\n");
        exit(1);
    }
    fprintf(stderr, "file open : successfully\n");
    File_view( fp );

    if (fclose(fp) != EOF){
        fprintf(stderr, "\nfile close : successfully\n");
    } else {
        fprintf(stderr, "\nfile close : failure!\n");
    };
    return 0;
}

void Ask_which_file(char file_name[256])
{
    fprintf(stderr, "Choose file >> ");
    fscanf(stdin, "%s", file_name);
    return;
}

void File_view(FILE *fp)
{
    int count = 0;
    char s[256];
    while (fgets(s, 256, fp) != NULL) {
        fprintf(stderr, "    %d\t|\t%s", count, s);
        count++;
    }

    return;
}