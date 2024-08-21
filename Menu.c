#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"
#include "Operation.h"
#include "Menu.h"

bool validateNumber(int *num)
{

    if (scanf("%d", num) != 1 || *num <= 0) return false;
    else return true;
}

void Menu()
{

    List list;
    CreateList(&list);
    Entry e;

    int choice;
    bool exit = false;

    char buffer[50];
    bool validate = false;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add pairs to the collection.\n");
        printf("2. Remove pairs from the collection.\n");
        printf("3. Modify the values of existing pairs.\n");
        printf("4. Print values associated with a particular key.\n");
        printf("5. delete a value with key.\n");
        printf("6. Exit.\n");

        do
        {
            printf("Enter your choice: ");
            validate = validateNumber(&choice);
            if(validate) break;
            else
            {
                printf("Invalid input! enter a positive number please.\n");
                gets(buffer);
            }
        }
        while(!validate);


        switch (choice)
        {
        case 1:
        {
            int option;

                printf("\n================ Add pairs ===============\n\n");
                printf("Choose an option:\n");
                printf("1. Add a new key.\n");
                printf("2. Add a value to an existing key.\n");
                printf("3. Back.\n");

                do
                {
                    printf("Enter your choice: ");
                    validate = validateNumber(&option);
                    if(validate) break;
                    else
                    {
                        printf("Invalid input! enter a positive number please.\n");
                        gets(buffer);
                    }
                }
                while(!validate);

                if (option == 1)
                {
                    int numKeys;


                    do
                    {
                        printf("Do you want continue(1/-1): ");
                        validate = validateNumber(&numKeys);
                        if(numKeys == -1 || numKeys == 1)break;
                        else if(validate) break;
                        else
                        {
                            printf("Invalid input! enter a positive number please.\n");
                            gets(buffer);
                        }
                    }
                    while(!validate);

                    printf("\n");
                    if(numKeys == 1)
                    {
                        do
                        {
                            printf("Enter the number of keys to insert: ");
                            validate = validateNumber(&numKeys);
                            if(validate) break;
                            else
                            {
                                printf("Invalid input! enter a positive number please.\n");
                                gets(buffer);
                            }
                        }
                        while(!validate);

                        for (int i = 0; i < numKeys; i++)
                        {
                            int key;
                            Entry e;

                            do
                            {

                                do
                                {
                                    printf("Enter key %d: ", i + 1);
                                    validate = validateNumber(&key);
                                    if(validate) break;
                                    else
                                    {
                                        printf("Invalid input! enter a positive number please.\n");
                                        gets(buffer);
                                    }
                                }
                                while(!validate);

                                if (key <= 0)
                                {
                                    printf("Invalid key! Please enter a positive integer.\n");
                                }
                                else if (CheckKey(&list, key))
                                {
                                    printf("Key %d already exists! Please enter a different key.\n", key);
                                    key = 0;
                                }
                            }
                            while (key <= 0);

                            do
                            {
                                printf("Enter the values for key %d :\n", key);
                                validate = validateNumber(&e);
                                if(validate) break;
                                else
                                {
                                    printf("Invalid input! enter a positive number please.\n");
                                    gets(buffer);
                                }
                            }
                            while(!validate);

                            AddPairs(&list, key, e);

                            char c;
                            printf("Do you want to add another value? (y/n)\n");
                            scanf(" %c", &c);
                            while (c == 'Y' || c == 'y')
                            {
                                do
                            {
                                printf("Enter the next value: ");
                                validate = validateNumber(&e);
                                if(validate) break;
                                else
                                {
                                    printf("Invalid input! enter a positive number please.\n");
                                    gets(buffer);
                                }
                             }
                            while(!validate);
                                AddPairs(&list, key, e);
                                printf("Do you want to add another value? (y/n)\n");
                                scanf(" %c", &c);
                            }
                        }
                    }
                }
                else if (option == 2)
                {
                    int key;
                    Entry e;

                    do
                    {
                        printf("Do you want continue(1/-1): ");
                        validate = validateNumber(&key);
                        if(key == -1 || key == 1)break;
                        else if(validate) break;
                        else
                        {
                            printf("Invalid input! enter a positive number please.\n");
                            gets(buffer);
                        }
                    }
                    while(!validate);

                    printf("\n");
                    if(key == 1)
                    {
                        do
                        {

                            do
                            {
                                printf("Enter the key to add values for: ");
                                validate = validateNumber(&key);
                                if(validate) break;
                                else
                                {
                                    printf("Invalid input! enter a positive number please.\n");
                                    gets(buffer);
                                }
                            }
                            while(!validate);


                            if (key <= 0)
                            {
                                printf("Invalid key! Please enter a positive integer.\n");
                            }
                            else if(CheckKey(&list, key))
                            {

                                do
                                {
                                    printf("Enter the values for key %d :\n", key);
                                    validate = validateNumber(&e);
                                    if(validate) break;
                                    else
                                    {
                                        printf("Invalid input! enter a positive number please.\n");
                                        gets(buffer);
                                    }
                                }
                                while(!validate);


                                AddPairs(&list,key,e);
                                char c;
                                printf("Do you want to add another value? (y/n)\n");
                                scanf(" %c", &c);
                                while (c == 'Y' || c == 'y')
                                {
                                    do
                                    {
                                        printf("Enter the next value: ");
                                        validate = validateNumber(&e);
                                        if(validate) break;
                                        else
                                        {
                                            printf("Invalid input! enter a positive number please.\n");
                                            gets(buffer);
                                        }
                                     }
                                    while(!validate);
                                    AddPairs(&list, key, e);
                                    printf("Do you want to add another value? (y/n)\n");
                                    scanf(" %c", &c);
                                }

                                printf("\nValues added successfully.\n");
                            }

                            else
                            {
                                printf("Invalid key! Please Try again\n");
                                key=0;
                            }

                        }
                        while(key <= 0);
                    }

                }
                else if (option == 3)break;

                else
                {
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                }
                break;
        }
        case 2:
        {
            printf("\n================ Remove pairs ===============\n\n");
            int DeleteKey;
            Entry e;

            if(!ListEmpty(&list)){
            do
            {
                printf("Do you want continue(1/-1): ");
                validate = validateNumber(&DeleteKey);
                if(DeleteKey == -1 || DeleteKey == 1)break;
                else if(validate) break;
                else
                {
                    printf("Invalid input! enter a positive number please.\n");
                    gets(buffer);
                }
            }
            while(!validate);

            printf("\n");
            if(DeleteKey == 1)
            {
                do
                {

                    do
                    {
                        printf("Enter key to delete: ");
                        validate = validateNumber(&DeleteKey);
                        if(validate) break;
                        else
                        {
                            printf("Invalid input! enter a positive number please.\n");
                            gets(buffer);
                        }
                    }
                    while(!validate);


                    if (DeleteKey <= 0)
                    {
                        printf("Invalid key! Please enter a positive integer.\n");
                    }
                    else if (CheckKey(&list, DeleteKey))
                    {
                        RemovePairs(&list,DeleteKey,&e);
                        printf("\nThe key deleted successfully.\n\n");
                    }
                    else
                    {
                        printf("Invalid key! Please Try again\n");
                        DeleteKey=0;
                    }
                }
                while (DeleteKey <= 0);
            }
            break;
        }
        else printf("List is empty! There is no elements to remove.\n");
        break;
        }
        case 3:
        {
            printf("\n================ Modify values ===============\n\n");
            int key, oldValue, newValue;

            if(!ListEmpty(&list)){
            do
            {
                printf("Do you want continue(1/-1): ");
                validate = validateNumber(&key);
                if(key == -1 || key == 1)break;
                else if(validate) break;
                else
                {
                    printf("Invalid input! enter a positive number please.\n");
                    gets(buffer);
                }
            }
            while(!validate);

            printf("\n");
            if(key == 1)
            {
                do
                {


                    do
                    {
                        printf("Enter the key to modify values for: ");
                        validate = validateNumber(&key);
                        if(validate) break;
                        else
                        {
                            printf("Invalid input! enter a positive number please.\n");
                            gets(buffer);
                        }
                    }
                    while(!validate);

                    if (key <= 0)
                    {
                        printf("Invalid key! Please enter a positive integer.\n");
                    }
                    else if (CheckKey(&list, key))
                    {
                        printf("the values in the key %d before modify is : ",key);
                        PrintAllValuesAssociated(&list,key);
                        printf("\n");

                        do
                        {
                            printf("Enter old value: ");
                            validate = validateNumber(&oldValue);
                            if(validate) break;
                            else
                            {
                                printf("Invalid input! enter a positive number please.\n");
                                gets(buffer);
                            }
                        }
                        while(!validate);

                        do
                        {
                            printf("Enter new value: ");
                            validate = validateNumber(&newValue);
                            if(validate) break;
                            else
                            {
                                printf("Invalid input! enter a positive number please.\n");
                                gets(buffer);
                            }
                        }
                        while(!validate);

                        ModifyValues(&list,key,oldValue,newValue);
                        printf("the values in the key %d is after modify is : ",key);
                        PrintAllValuesAssociated(&list,key);
                        printf("\n");

                    }
                    else
                    {
                        printf("Invalid key! Please Try again\n");
                        key=0;
                    }

                }
                while(key <= 0);
            }
            }else printf("List is empty! There is no elements to modify.\n");
            break;
        }
        case 4:
        {
            printf("\n================ Print values associated with a particular key ===============\n\n");
            int key;

            if(!ListEmpty(&list)){
            do
            {
                printf("Do you want continue(1/-1): ");
                validate = validateNumber(&key);
                if(key == -1 || key == 1)break;
                else if(validate) break;
                else
                {
                    printf("Invalid input! enter a positive number please.\n");
                    gets(buffer);
                }
            }
            while(!validate);


            printf("\n");
            if(key == 1)
            {
                do
                {
                    do
                    {
                        printf("Enter the key to retrieve values for: ");
                        validate = validateNumber(&key);
                        if(validate) break;
                        else
                        {
                            printf("Invalid input! enter a positive number please.\n");
                            gets(buffer);
                        }
                    }
                    while(!validate);

                    if (key <= 0)
                    {
                        printf("Invalid key! Please enter a positive integer.\n");
                    }
                    else if (CheckKey(&list, key))
                    {
                        printf("the values in the key %d is: ",key);
                        PrintAllValuesAssociated(&list,key);
                    }
                    else
                    {
                        printf("Invalid key! Please Try again\n");
                        key=0;
                    }

                }
                while(key <= 0);
            }
        } else printf("List is empty! There is no elements to print.\n");
        break;
        }
        case 5:
        {
            printf("\n================ Remove existing value with key ===============\n\n");
            int key;
            Entry deleteValue;
            if(!ListEmpty(&list)){
            do
            {
                printf("Do you want continue(1/-1): ");
                validate = validateNumber(&key);
                if(key == -1 || key == 1)break;
                else if(validate) break;
                else
                {
                    printf("Invalid input! enter a positive number please.\n");
                    gets(buffer);
                }
            }
            while(!validate);

            printf("\n");
            if(key == 1)
            {
             do
                {


                    do
                    {
                        printf("Enter the key to delete values for: ");
                        validate = validateNumber(&key);
                        if(validate) break;
                        else
                        {
                            printf("Invalid input! enter a positive number please.\n");
                            gets(buffer);
                        }
                    }
                    while(!validate);

                    if (key <= 0)
                    {
                        printf("Invalid key! Please enter a positive integer.\n");
                    }
                    else if (CheckKey(&list, key))
                    {
                        printf("the values in the key %d before delete is : ",key);
                        PrintAllValuesAssociated(&list,key);
                        printf("\n");

                        do
                        {
                            printf("Enter the value you want delete: ");
                            validate = validateNumber(&deleteValue);
                            if(validate) break;
                            else
                            {
                                printf("Invalid input! enter a positive number please.\n");
                                gets(buffer);
                            }
                        }
                        while(!validate);



                        RemoveValue(&list,key,deleteValue);
                        printf("the values in the key %d is after deleted is : ",key);
                        PrintAllValuesAssociated(&list,key);
                        printf("\n");

                    }
                    else
                    {
                        printf("Invalid key! Please Try again\n");
                        key=0;
                    }

                }
                while(key <= 0);
            }
            }else printf("List is empty! There is no elements to modify.\n");
            break;
        }



        case 6:
        {
            exit = true;
            printf("Exiting...\n");
            break;
        }
        default:
        {
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
            break;
        }
        }
    }
    while (!exit);

}
