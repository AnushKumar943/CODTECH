#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;

    /* -------- CREATE & WRITE TO FILE -------- */
    fp = fopen("example.txt", "w");   // creates file if not exists
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(fp, "This is the first line in the file.\n");
    fprintf(fp, "File operations in C.\n");
    fclose(fp);
    printf("File created and data written successfully.\n");

    /* -------- READ FROM FILE -------- */
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nReading data from file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    /* -------- APPEND DATA TO FILE -------- */
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return 1;
    }

    fprintf(fp, "This line is appended to the file.\n");
    fclose(fp);
    printf("\nData appended successfully.\n");

    /* -------- READ AGAIN AFTER APPEND -------- */
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nFinal file content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
