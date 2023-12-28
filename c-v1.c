#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char book_name[20];
    char author_name[20];
    int stock_number;
};

void createBook(FILE *fp, struct student s[], int *count);
void listBooks(FILE *fp, struct student s[], int count);

int main() {
    int a, count = 0;
    FILE *fp;
    struct student s[100];

    printf("Welcome to Library Management System\n");

    do {
        printf("1. Create Book\n2. Books List\n3. Add another Book\n4. Exit\n");
        scanf("%d", &a);

        switch (a) {
            case 1:
                fp = fopen("bookstore.txt", "w");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                createBook(fp, s, &count);
                fclose(fp);
                break;

            case 2:
                fp = fopen("bookstore.txt", "r");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                listBooks(fp, s, count);
                fclose(fp);
                break;

            case 3:
                fp = fopen("bookstore.txt", "a+");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                createBook(fp, s, &count);
                fclose(fp);
                break;

            case 4:
                exit(0);
        }
    } while (a != 4);

    return 0;
}

void createBook(FILE *fp, struct student s[], int *count) {
    int ch = 1, i;

    printf("Enter BookName, AuthorName, and Stock number of the book\n");
    for (i = *count; ch == 1; i++) {
        scanf("%s %s %d", s[i].book_name, s[i].author_name, &s[i].stock_number);
        fprintf(fp, "%s \t%s\t %d\t", s[i].book_name, s[i].author_name, s[i].stock_number);
        (*count)++;
        printf("Press 1 to add another book or 0 to Main menu\n");
        scanf("%d", &ch);
    }
}

void listBooks(FILE *fp, struct student s[], int count) {
    int i;

    printf("BookName \tAuthorName \tStock Number \t\n\n");
    for (i = 0; i < count; i++) {
        fscanf(fp, "%s %s %d", s[i].book_name, s[i].author_name, &s[i].stock_number);
        printf("%s\t%s\t%d\t\n\n", s[i].book_name, s[i].author_name, s[i].stock_number);
    }
}
