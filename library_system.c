

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char title[30];
} Book;

int main() {
    FILE *fp;
    Book myBook;

    printf("=== MINI LIBRARY SYSTEM ===\n");
    
    // 1. Get data from user
    printf("Enter Book ID: ");
    scanf("%d", &myBook.id);
    printf("Enter Book Title: ");
    scanf(" %29[^\n]", myBook.title);

    // 2. WRITE to file
    fp = fopen("library.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(fp, "%d - %s", myBook.id, myBook.title);
    fclose(fp);
    printf("\n[✓] Saved successfully to library.txt!\n\n");

    // 3. READ back from file
    fp = fopen("library.txt", "r");
    printf("Reading from file data:\n");
    printf("-----------------------\n");
    
    int savedId;
    char savedTitle[30];
    if (fscanf(fp, "%d - %[^\n]", &savedId, &savedTitle) != EOF) {
        printf("Stored Book ID: %d\n", savedId);
        printf("Stored Title: %s\n", savedTitle);
    }
    fclose(fp);

    return 0;
}
