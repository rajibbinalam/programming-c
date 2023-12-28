#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int age;
    int rollno;
};

void main() {
    int a, i, ch = 1, rec;
    FILE *fp;
    struct student s[100];
    int count = 0;

    printf("Welcome to Library Management System\n");
    do {
        printf("1. Create record\n2. List record\n3. Add another record\n4. Exit\n");
        scanf("%d", &a);

        switch (a) {
            case 1:
                ch = 1;
                fp = fopen("bookstore.txt", "w");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                printf("Enter BookName, age, and roll number of the student\n");
                for (i = 0; ch == 1; i++) {
                    scanf("%s %d %d", s[i].name, &s[i].age, &s[i].rollno);
                    fprintf(fp, "%s \t%d\t %d\t", s[i].name, s[i].age, s[i].rollno);
                    count++;
                    printf("Press 1 to add another record and 0 to exit\n");
                    scanf("%d", &ch);
                }
                fclose(fp);
                break;

            case 2:
                fp = fopen("bookstore.txt", "r");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                printf("Name \tAge \tRoll number \t\n\n");
                for (i = 0; i < count; i++) {
                    fscanf(fp, "%s %d %d", s[i].name, &s[i].age, &s[i].rollno);
                    printf("%s\t%d\t%d\t\n\n", s[i].name, s[i].age, s[i].rollno);
                }
                fclose(fp);
                break;

            case 3:
                fp = fopen("bookstore.txt", "a");
                if (fp == NULL) {
                    printf("Cannot open file\n");
                    exit(1);
                }
                ch = 1;
                for (i = count; ch == 1; i++) {
                    scanf("%s %d %d", s[i].name, &s[i].age, &s[i].rollno);
                    fprintf(fp, "%s\t%d\t %d\t", s[i].name, s[i].age, s[i].rollno);
                    printf("Press 1 to add another record and 0 to exit\n");
                    scanf("%d", &ch);
                    count++;
                }
                fclose(fp);
                break;

            case 4:
                exit(0);
        }
    } while (a != 4);
}
