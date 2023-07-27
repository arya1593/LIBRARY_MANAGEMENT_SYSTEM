#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
struct node
{
    char name[100];
    struct node *left;
    struct node *right;
};
struct node *head = NULL, *rear = NULL;
void insert()
{
    struct node *newnode, *temp;
    newnode = (struct node *)calloc(1, sizeof(struct node));
    printf("Please enter the name of the book : ");
    char book[100];
    scanf("%s", book);
    strcpy(newnode->name, book);
    // puts(newnode->name);
    if (head == NULL)
    {
        head = newnode;
        rear = head;
        head->left = NULL;
        head->right = NULL;
    }
    else
    {
        rear->right = newnode;
        newnode->right = NULL;
        newnode->left = rear;
        rear = newnode;
    }
}
void delete ()
{

    char kl[100];
    struct node *temp = NULL, *temp1 = NULL, *temp2 = NULL;

    temp = head;
    printf("Please enter the name of the book which you want to delete : ");
    scanf("%s", kl);

    if (strcmp(head->name, kl) == 0)
    {
        head = head->right;
        printf("The book deleted is : %s", temp->name);
        free(temp);
        return;
    }
    else if (strcmp(rear->name, kl) == 0)
    {
        temp = rear;
        rear = rear->left;
        rear->right = NULL;
        printf("The book deleted is : %s", temp->name);
        printf("\n");
        free(temp);
        return;
    }
    else
    {
        temp = head;
        temp = temp->right;

        while (temp->right != NULL)
        {
            if (strcmp(temp->name, kl) == 0)
            {
                temp1 = temp->left;
                temp2 = temp->right;

                temp1->right = temp2;
                temp2->left = temp1;

                printf("The deleted book is : %s", temp->name);
                printf("\n");
                free(temp);
                return;
            }
            temp = temp->right;
        }
        printf("Book not found!");
        return;
    }
}
struct node *search()
{
    int l = 1;
    struct node *temp;
    temp = head;
    char at[100];

    printf("Please enter the name of the book : ");
    scanf("%s", at);
    printf("\n");

    while (temp != NULL)
    {
        if (strcmp(temp->name, at) == 0)
        {
            printf("\nThe book entered by you is found at %d location\n", l);
            return temp;
            break;
        }
        else
        {
            l = l + 1;
            temp = temp->right;
        }
    }
}
void submit()
{
    struct node *newnode, *temp;
    temp = rear;
    newnode = (struct node *)calloc(1, sizeof(struct node));
    printf("Please enter the name of the book : ");
    scanf("%s", newnode->name);
    rear->right = newnode;
    rear = newnode;
    newnode->left = temp;
    printf("Your book has been successfully added.\n");
    temp = rear;
}
void display()
{
    struct node *temp;
    temp = head->right;
        printf("Your book list is as follows : \n");
        printf("\n");
        printf("%s\n", head->name);

        while (temp != NULL)
        {
            printf("%s\n", temp->name);
            temp = temp->right;
        }
    printf("\n");
}
void issue(int ad, int bd, int cd)
{
    char name[20];
    int a = ad, b = bd, c = cd;
    struct node *temp1 = NULL, *temp2 = NULL;
    struct node *temp = head;
    printf("Enter the name of the book you want to issue : ");
    scanf("%s", name);
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            break;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (strcmp(temp->name, name) == 0)
    {
        if (temp == head)
        {
            head = head->right;
            printf("%s Book is issued to you on : %d/%d/%d\n", temp->name, ad, bd, cd);
            if (bd == 12 && ad > 16)
            {
                ad = ad - 16;
                bd = 1;
                cd = cd + 1;
                printf("You have to submit %s book on or before : %d/%d/%d", temp->name, ad, bd, cd);
                free(temp);
            }
            else
            {
                if (bd == 1 || bd == 3 || bd == 5 || bd == 7 || bd == 8 || bd == 10 || bd == 12)
                {
                    if (ad > 16)
                    {
                        ad = ad - 16;
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                    }
                    else
                    {
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad + 15, bd, cd);
                    }
                }
                else
                {
                    if (ad >= 15)
                    {
                        bd = bd + 1;
                        ad = ad - 16;
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                    }
                    else
                    {
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad + 15, bd, cd);
                    }
                }
                free(temp);
            }
        }
        else if (temp == rear)
        {
            rear = rear->left;
            printf("Book : %s is issued to you on : %d/%d/%d\n", temp->name, ad, bd, cd);
            if (bd == 12 && ad > 16)
            {
                ad = ad - 16;
                bd = 1;
                cd = cd + 1;
                printf("You have to submit %s book on or before : %d/%d/%d", temp->name, ad, bd, cd);
                free(temp);
            }
            else
            {
                if (bd == 1 || bd == 3 || bd == 5 || bd == 7 || bd == 8 || bd == 10 || bd == 12)
                {
                    if (ad > 16)
                    {
                        ad = ad - 16;
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                    }
                    else
                    {
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad + 15, bd, cd);
                    }
                }
                else
                {
                    if (ad >= 15)
                    {
                        bd = bd + 1;
                        ad = ad - 16;
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                    }
                    else
                    {
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad + 15, bd, cd);
                    }
                }
                free(temp);
            }
        }
        else
        {
            temp1 = temp->left;
            temp2 = temp->right;
            temp1->right = temp2;
            temp2->left = temp1;
            printf("Book %s is issued to you on : %d/%d/%d\n", temp->name, ad, bd, cd);
            if (bd == 12 && ad > 16)
            {
                ad = ad - 16;
                bd = 1;
                cd = cd + 1;
                printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                free(temp);
            }
            else
            {
                if (bd == 1 || bd == 3 || bd == 5 || bd == 7 || bd == 8 || bd == 10 || bd == 12)
                {
                    if (ad > 16)
                    {
                        ad = ad - 16;
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                    }
                    else
                    {
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad + 15, bd, cd);
                    }
                }
                else
                {
                    if (ad >= 15)
                    {
                        bd = bd + 1;
                        ad = ad - 16;

                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad, bd, cd);
                    }
                    else
                    {
                        printf("You have to submit %s book on or before : %d/%d/%d\n", temp->name, ad + 15, bd, cd);
                    }
                }
                free(temp);
            }
        }
    }
    else
    {
        printf("Book not found.\n");
    }
}
int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    struct node *temp;
    int ad = tm.tm_mday;
    int bd = tm.tm_mon + 1;
    int cd = tm.tm_year + 1900;
    int i, j, k, re = 0, or = 0;
    char pass[20];
    char password[128], c;
    char repass[128], c1;
    char orpass[128] = "12345";
    char c2;
    int index2 = 0;
    int index1 = 0;
    int index = 0;

    printf("\n");
    printf("                                                    GREETINGS OF THE DAY!\n");
    printf("\n");
    printf("                                                    WELCOME TO LIBRARY");
    printf("\n");
    printf("\n");


    while (1)
    {
    first:
        printf("\nIf you are a student press : 1\nIf you are an admin of the library press : 2\nEnter 1 or 2 : ");
        scanf("%d", &i);
        printf("\n");
        switch (i)
        {
        case 1:
            printf("Press 1 : To search the book\nPress 2 : To display all books\nPress 3 : To issue a book\nPress 4 : To submit a book\n");
            scanf("%d", &j);
            printf("\n");
            switch (j)
            {
            case 1:
                temp = search();
                break;
            case 2:
                display();
                break;
            case 3:
                issue(ad, bd, cd);
                break;
            case 4:
                submit();
                break;
            default:
                printf("Please make the choice between 1 or 2\n");
                break;
            }
            break;
        case 2:
        second:
            printf("Enter your password : ");
            index = 0;
            while ((c = getch()) != 13)
            {
                if (index < 0)
                    index = 0;
                if (c == 8)
                {
                    putch('\b');
                    putch(NULL);
                    putch('\b');
                    index--;
                    continue;
                }
                password[index++] = c;
                putch('*');
            }
            password[index] = '\0';
            printf("\n");

            if (strcmp(password, orpass) != 0)
            {
                printf("You have entered wrong information\n");
                printf("Press 1 : To go the main menu\nPress 2 : To enter password again\nPress 3 : To change the password\n");
                scanf("%d", &re);
                switch (re)
                {
                case 1:
                    goto first;
                    break;
                case 2:
                    goto second;
                    break;
                case 3:
                third:
                    printf("Enter your current password : ");
                    index1 = 0;
                    while ((c1 = getch()) != 13)
                    {
                        if (index1 < 0)
                            index1 = 0;
                        if (c1 == 8)
                        {
                            putch('\b');
                            putch(NULL);
                            putch('\b');
                            index1--;
                            continue;
                        }
                        repass[index1++] = c1;
                        putch('*');
                    }
                    printf("\n");
                    repass[index1] = '\0';
                    if (strcmp(repass, orpass) == 0)
                    {
                        printf("Enter your new password : ");
                        index2 = 0;
                        while ((c2 = getch()) != 13)
                        {
                            if (index2 < 0)
                                index2 = 0;
                            if (c2 == 8)
                            {
                                putch('\b');
                                putch(NULL);
                                putch('\b');
                                index2--;
                                continue;
                            }
                            orpass[index2++] = c2;
                            putch('*');
                        }
                        orpass[index2] = '\0';
                        printf("\n");
                        printf("Your password has been changed successfully.\n");
                    }
                    else
                    {
                        printf("Press 1 : To go to the main menu\nPress 2 : To re-enter your passsword ");
                        scanf("%d", & or);
                        printf("\n");
                        switch (or)
                        {
                        case 1:
                            goto first;
                            break;
                        case 2:
                            goto third;
                            break;
                        }
                    }
                    break;
                }
            }
            else
            {
                printf("Press 1 : To insert the book\nPress 2 : To delete the book\nPress 3 : To search the book\nPress 4 : To display all the books\nPress 5 : To go to the main menu\n");
                scanf("%d", &k);
                printf("\n");
                switch (k)
                {
                case 1:
                    insert();
                    break;
                case 2:
                    delete ();
                    break;
                case 3:
                    temp = search();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    goto first;
                    break;
                default:
                    printf("Please make the choice between 1 to 5\n");
                    break;
                }
                break;
            default:
                printf("Please confine your choice within 1 or 2\n");
                break;
            }
        }
    }
    return 0;
}