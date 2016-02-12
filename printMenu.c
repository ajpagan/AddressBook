/*****************************************************************************
*
*    Name:        Allen Pagan
*
*    Homework:    Project 1
*
*    Class:       ICS 212
*
*    Instructor:  Ravi Narayan
*
*    Date:        October 18, 2014  
*
*    File:        printMenu.c 
*
*    Description: Displays the menu for main3.c and gets user menu selection
******************************************************************************/

#include <stdio.h>

/*******************************************************************************
*
*  Function name:  	printMenu   
*
*  DESCRIPTION:         A userinterface function - This function displays the menu for the 
*	                user and obtains their selection
*
*  Parameters:      	none 
*
*  Return values:       The option on the menu must be a number (1-6)
*			 
******************************************************************************/


int printMenu()
{
    int menuChoice;
    char extra;   

    printf("\t\t Address Book Menu Options\n");
    printf("(1)  Add a new record to the database.\n");
    printf("(2)  Modify a record in the database using the name as the key.\n");
    printf("(3)  Print information about a record using the name as the key.\n");
    printf("(4)  Print all information in the database.\n");
    printf("(5)  Delete an existing record from the database using the name as a key.\n");
    printf("(6)  Quit.\n");
    printf("Please enter the number of your menu choice.\n");
    scanf("%d", &menuChoice);
    extra = getchar();
    while(extra != '\n')
    extra = getchar();

    while(menuChoice != 1 && menuChoice != 2 && menuChoice != 3 &&
    menuChoice != 4 && menuChoice != 5 && menuChoice != 6)
    {
	printf("Please enter a valid menu option.\n");	
	scanf("%d", &menuChoice);
        extra = getchar();
        while(extra != '\n')
        {
	    extra = getchar();
	}
    }
    
    return menuChoice;
}
