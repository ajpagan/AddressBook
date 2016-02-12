/*****************************************************************************
*
*    Name:        Allen Pagan
*
*    Homework:    Project1
*
*    Class:       ICS 212
*
*    Instructor:  Ravi Narayan
*
*    Date:        October 18, 2014
*
*    File:        main3.c
*
*    Description: This is a driver for Homework3.c to test the address book
*                 functions,add record, modify record, print record, delete
*                 record, read file, write file, and clean up functions
******************************************************************************/

#include <stdio.h>
#include "record.h"
#include "main3.h"
int debugMode;
#include <string.h>
int main(int argc, char* argv[])
{  
    if(argc == 2)
    {
        if(strncmp(argv[1], "debug", 5) == 0)
        {
            debugMode = 1;   
        }
        else
        {
            printf("Error: Incorrect arguments\n");
            printf("To execute program enter Hw3\n");
            debugMode = 2;
        }
    }
    else
    {
        if(argc > 2)
        {
            printf("Error: To many arguments.\n");
            printf("To execute program enter Hw3\n");
            debugMode = 2;
        }
    }

    if(debugMode == 1)
    {
        printf("\n\n\t\t\tDEBUG MODE IS ON \n\n");
    }
    struct record* start = NULL;
    struct record** pStart;
    pStart = &start;
        
    char name [25];
    char address [80];
    char number [15];
    int birthYear = 0;
    int menuChoice;
    char extra;
    char  input1;
    int i = 0;
    int x = 0;
     
    if(readFile(pStart, "Project1.txt") == 1)
    {
        printf("\nFile is empty.\n");
    }

    do{
                     
        if(debugMode != 2)
        {
            menuChoice = printMenu();
        }
        else
        {
            menuChoice = 6;
        }

        switch(menuChoice)
        {
            case 1 :
                i = 0;
                printf("Please enter the name:\n");
                extra = getchar();
                while(extra != '\n')
                {
                    name[i] = extra;
                    extra = getchar();
                    i++;
                    x++;
                    if(x > 24)
                    {
                    extra = getchar();
                    while(extra != '\n')
                    {
                        extra = getchar();
                    }
        
                    }
                }
                name[i] = '\0';


		printf("Please enter your address followed by an !\n");
                x = 0;
                i = 0;
                do
                {   
                    input1 = getchar();
                    address[i] = input1;
                    i++;
                    x++;
                }while(input1 != '!' && x < 79);
                    
                extra = getchar();
                while(extra != '\n')
                extra = getchar();
                    
                address[i] = '\0';


		printf("Please enter the year of birth:\n");
                    
                birthYear = -1;
                while(birthYear > 2014 || birthYear < 0)
                {
                    if(scanf("%d", &birthYear) == 1)
                    {
                        if(birthYear > 2014 || birthYear < 0)
                        printf("Please enter valid year\n");
                    }
                    else 
                    { 
                        printf("Invalid input, please enter a number:\n");
                    }
                
                    extra = getchar();
                    while(extra != '\n')
                    extra = getchar();
                }


		printf("Please enter the phone number:\n");
                i = 0;
                x = 0;
                extra = getchar();
                while(extra != '\n')
                {   
                    number[i] = extra;
                    extra = getchar();
                    i++;
                    x++;
                    if(x > 14)
                    {
                        extra = getchar();
                        while(extra != '\n')
                        {
                            extra = getchar();
                        }
                      
                    }
                }
                number[i] = '\0';
                    
                addRecord(pStart, name, address, birthYear, number);
                break;


	    case 2:
                printf("Please enter the name:");
                
                x = 0;
                i = 0;
                extra = getchar();
                while(extra != '\n' && x < 25)
                {
                    name[i] = extra;
                    extra = getchar();
                    i++;
                }
                name[i] = '\0';
                    
                printf("Please enter your address followed by an !\n");
                i = 0;
                do
                {
                    input1 = getchar();
                    address[i] = input1;
                    i++;
                }while(input1 != '!');
                 
                 extra = getchar();
                while(extra != '\n')
                extra = getchar();
                address[i] = '\0';


		printf("Please enter the phone number:\n");
                i = 0;
                x = 0;
                extra = getchar();
                while(extra != '\n' && x < 15)
                {
                    number[i] = extra;
                    extra = getchar();
                    i++;
                    x++;
                }
                number[i] = '\0';
                if(modifyRecord(start, name, address, number) == 0)
                {   
                    printf("There is no one named %s in the address book\n\n",name);
                }
                else
                {
                    if(modifyRecord(start, name, address, number) == 2)
                    printf("The address book is empty\n\n");
                }
                break;


	    case 3:
                printf("Please enter the name:");
                x = 0;
                i = 0;
                extra = getchar();
                while(extra != '\n' && x < 25)
                {
                    name[i] = extra;
                    extra = getchar();
                    i++;
                }
                name[i] = '\0';
                    
                    
                if(printRecord(start, name) == 0)
                {
                    printf("There is no one named %s in the address book\n\n",name);
                }
                    
                break;
                 
            case 4: 
                if(printAllRecords(start)== 1)
                {
                    printf("No records available in the address book.\n\n");
                }
                break;

	    case 5:
                i = 0;
                printf("Please enter the name:");
                x = 0;
                extra = getchar();
                while(extra != '\n' && x < 25)
                {
                    name[i] = extra;
                    extra = getchar();
                    i++;
                }
                name[i] = '\0';
                    
                    
                if(deleteRecord(pStart, name) == 0)
                {
                    printf("There is no one named %s in the address book\n\n", name);
                }
                    
                break;
        }        
    }while(menuChoice != 6);
    writeFile(start, "Project1.txt");
    cleanUp(&start);
    return 0;
}



