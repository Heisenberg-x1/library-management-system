#include <stdio.h>
#include <string.h>

struct Book
{
    char title[25];
    char author[25];
    char category[25];
    int pages;
    int price;
};
int getChoice();
int addBook(int choice, struct Book books[], int bookCount);
int getBookInfo(struct Book books[]);
int displayAllBooks(struct Book books[], int bookCount);

int main()
{
    struct Book books[100];
    int bookCount = 0;
    int choice;
    choice = getChoice();

    while (choice != 5)
    {
        if (choice == 1)
        {
            bookCount = addBook(choice, books, bookCount);
            choice = getChoice();
        }
        else if (choice == 2)
        {
            getBookInfo(books);
            choice = getChoice();
        }else if (choice == 4){
            displayAllBooks(books, bookCount);
            choice = getChoice();
        }
    }
    printf("Thank you for using our library management system. Have a great day and happy reading! Goodbye!");

    return 0;
}

int getChoice()
{
    printf("----- Main menu -----");
    printf("\n\n");

    char input[25];
    int choice;

    while (1) {
        printf("1. Add a book. \n");
        printf("2. Display book information. \n");
        printf("3. Check the books available for a particular Category.\n");
        printf("4. Display all books. \n");
        printf("5. Exit \n\n");
        printf("Choose an option: ");
        fgets(input, 25, stdin);

        if (sscanf(input, "%d", &choice) == 1) break;

        printf("Invalid choice. Please try again.\n");
    }

    return choice;
}

int addBook(int choice, struct Book books[], int bookCount)
{
    char title[25];
    char author[25];
    char Category[25];
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
    printf("Category: ");
    fgets(Category, 25, stdin);
    printf("Pages: ");
    scanf(" %d", &pages);
    printf("Price: ");
    scanf(" %d", &price);

    // new book
    struct Book newBook;
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
    strcpy(newBook.category, Category);
    newBook.pages = pages;
    newBook.price = price;
    books[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully!");
    printf("\n\n");

    return bookCount;
}

int getBookInfo(struct Book books[])
{
    printf("----- Book information -----");
    printf("\n");
    char title[25];
    printf("Provide the title of the book: ");
    fgets(title, 25, stdin);
    title[strlen(title) - 1] = '\0';
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Pages: %d\n", books[i].pages);
            printf("Price: %d\n", books[i].price);
            printf("\n\n");
            return 0;
        }
    }
    printf("Book not found. Please check the title and try again.");
    return 0;
}

int displayAllBooks(struct Book books[], int bookCount)
{
    printf("----- All books -----");
    printf("\n");
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title[0] != '\0')
        {
            printf("Title: %s\n", books[i].title);
        }
    }
    printf("\n\n");
    return 0;
}