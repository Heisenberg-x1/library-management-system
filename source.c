#include <stdio.h>
#include <string.h>

int getChoice();
int addBook(int choice, struct Book books[], int bookCount);

struct Book
{
    char title[25];
    char author[25];
    int pages;
    int price;
};

int main()
{
    struct Book books[100];
    int bookCount = 0;
    int choice = getChoice();

    if (choice == 4)
    {
        printf("Thank you for using our library management system. Have a great day and happy reading! Goodbye!");
    }
    else
    {
        if (choice == 1)
        {
            addBook(choice, books, bookCount);
        }
    }
    return 0;
}

int getChoice()
{

    printf("------- Main menu ------");
    printf("\n\n");

    int choice;
    printf("1. Add books. \n");
    printf("2. Display book information. \n");
    printf("3. Add books.\n");
    printf("4. Exit \n\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    return choice;
}

int addBook(int choice, struct Book books[], int bookCount)
{
    char title[25];
    char author[25];
    int pages;
    int price;
    printf("----- Add book -----");
    printf("\n");

    printf("Provide the following details about the book.\n");
    printf("Title: ");
    fgets(title, 25, stdin);
    title[strlen(title) - 1] = '\0';
    printf("Author: ");
    fgets(author, 25, stdin);
    author[strlen(author) - 1] = '\0';
    printf("Pages: ");
    scanf(" %d", &pages);
    printf("Price: ");
    scanf(" %d", &price);

    // new book
    struct Book newBook;
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
    newBook.pages = pages;
    newBook.price = price;
    books[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully!");
    printf("\n\n");
    return 0;
}