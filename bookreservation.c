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
void updateBook(FILE *fp, struct student s[], int count);

int main() {
    int a, count = 0;
    FILE *fp;
    struct student s[100];

    printf("Welcome to Library Management System\n");

    do {
        printf("1. Create Book\n2. Books List\n3. Add another Book\n4. Update Book\n5. Exit\n");
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
                fp = fopen("bookstore.txt", "r+");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                updateBook(fp, s, count);
                fclose(fp);
                break;

            case 5:
                exit(0);
        }
    } while (a != 5);

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

void updateBook(FILE *fp, struct student s[], int count) {
    char search_name[20];
    int i, found = 0;

    printf("Enter the BookName to update: ");
    scanf("%s", search_name);

    for (i = 0; i < count; i++) {
        fscanf(fp, "%s %s %d", s[i].book_name, s[i].author_name, &s[i].stock_number);

        if (strcmp(s[i].book_name, search_name) == 0) {
            found = 1;
            printf("Enter updated information for BookName %s: ", search_name);
            scanf("%s %s %d", s[i].book_name, s[i].author_name, &s[i].stock_number);
            fseek(fp, -strlen(s[i].book_name) - strlen(s[i].author_name) - 4, SEEK_CUR);
            fprintf(fp, "%s \t%s\t %d\t", s[i].book_name, s[i].author_name, s[i].stock_number);
            break;
        }
    }

    if (!found) {
        printf("Book with BookName %s not found\n", search_name);
    }
}
