#include <string.h>

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
*    File:        Homework3.c
*
*    Description: Holds all the method calls for main3.c which include add 
*		  record, modify record, delete record, print record,
*		  write file, read file and clean up
******************************************************************************/


#include "record.h"
#include <stdio.h>
#include <stdlib.h>
extern int debugMode;


/*******************************************************************************
 *
 *  Function name:  	addRecord   
 *
 *  DESCRIPTION:        adds a record to the "address book"
 *                 	 
 *  Parameters:      	pStart (struct record**): start of list
 *			name (char*): Name of the person		  
 *			address (char*): Address of person
 *			birthYear (int): Year the person was born
 *			number (char*): Telephone number of the person
 *
 *  Return values:  	 0 : success	
 *
 ******************************************************************************/


int addRecord(struct record** start,char name[], char address[], int birthYear, char number[])
{
	if(debugMode ==1)
	{
	    printf("\n(Add Record) Name: %s\n", name);
	    printf("(Add Record) Address: %s\n", address);
	    printf("(Add Record) Year of birth: %d\n", birthYear);
	    printf("(Add Record)Telephone number: %s\n", number); 
	}

	struct record *contact;
	contact = *start;

	if((*start) == NULL)
	{
	    *start = malloc(sizeof(struct record));
    	     
    	    strcpy((**start).name, name);

	    strcpy((**start).address, address);

	    (**start).birthYear = birthYear;

	    strcpy((**start).number, number);

	    (**start).next = NULL;  
	}
	else
	{
	    while((*contact).next != NULL)
	    {
		contact = (*contact).next;
	    }
	  
	    (*contact).next = malloc(sizeof(struct record));
	        
	    strcpy((*contact).next->name, name);
            
	    strcpy((*contact).next->address, address);
           
            (*contact).next->birthYear = birthYear;

	    strcpy((*contact).next->number, number);
	    
	    (*contact).next->next = NULL;
	}
        return 0;
}


/*******************************************************************************
 *
 *  Function name:      printRecord   
 *
 *  DESCRIPTION:        prints a record from the "address book" using the name as the key
 *
 *  Parameters:         start (struct record*) :
 *                      name (char*): Name of the person
 *
 *  Return values:       0 : success
 *
 ******************************************************************************/

int printRecord(struct record* start, char name[])
{
    int found = 0;
    if(debugMode == 1)
    {
	printf("(Print Record) \nName: %s\n", name);
    }
    
    if(start != NULL)
    {
    	while(start != NULL)
	{
            if(strcmp((*start).name, name) == 0)
            {
                printf("Name:    %s\n", (*start).name);

	        if((*start).address[strlen((*start).address)- 1] == '!')
                {
                    (*start).address[strlen((*start).address) -1] = '\0';
                    printf("Address: %s\n",(*start).address);
                    (*start).address[strlen((*start).address)] = '!';
                    (*start).address[strlen((*start).address)+1] = '\0';
                }
                else
                printf("Address: %s\n",(*start).address);

	        printf("Birth:   %d\n", (*start).birthYear);
	        printf("Number:  %s\n", (*start).number);
		printf("\n");
		found = 1;
		start = (*start).next;
            }
	    else
	    {
	        start = (*start).next;  
	    }
        }	
    }   
    	
    return found;
}


/*******************************************************************************
 *
 *  Function name:      modifyRecord   
 *
 *  DESCRIPTION:        Modifys a record to the "address book"
 *
 *  Parameters:         start (struct record*) :
 *                      name (char*): Name of the person
 *                      address (char*): Address of person
 *                      number (char*): Telephone number of the person
 *
 *  Return values:       0 : success
 *
 ******************************************************************************/


int modifyRecord(struct record* start, char name[], char address[], char number[])
{ 
    int found = 0;
    if(debugMode == 1)
    {
	printf("\n(Modify Record) Name: %s\n", name);
	printf("(Modify Record) Address: %s\n", address);
	printf("(Modify Record) Telephone number: %s\n", number);
    }
	       
    if(start != NULL)
    {
        while(start != NULL)
        {
            if(strcmp((*start).name, name) == 0)
            {
                strcpy((*start).name, name); 
                strcpy((*start).address, address);
                strcpy((*start).number, number);
                found = 1;
                start = (*start).next;
            }
            else
            {
                start = (*start).next;
            }
        }
    }
    else
    {
        found = 2;
    }
           

    return found;
}


/*******************************************************************************
*
*  Function name:      printAllRecords   
*
*  DESCRIPTION:        Prints all the records in the "address book"
*
*  Parameters:         start (struct record*) :
*                      
*  Return values:      0: success
*                      1: No records        
*
 ******************************************************************************/

int printAllRecords(struct record* start)
{
    struct record *contact;  
    contact = start;

    if(debugMode == 1)
    {
        printf("(Print All Records)\n");
    }

    if(start != NULL)
    {
	while(contact != NULL)
	{   
	    printf("Name:    %s\n", (*contact).name);      
	    if((*contact).address[strlen((*contact).address)- 1] == '!')
	    {
                (*contact).address[strlen((*contact).address) -1] = '\0';
	        printf("Address: %s\n",(*contact).address);
		(*contact).address[strlen((*contact).address)] = '!'; 
                (*contact).address[strlen((*contact).address)+1] = '\0';
	    }
            else
	    printf("Address: %s\n",(*contact).address);

	    printf("Birth:   %d\n", (*contact).birthYear);
            printf("Number:  %s\n", (*contact).number);
	    printf("\n");
            contact = contact -> next; 

	}
    }
    else
    {
	return 1;
    }
    return 0;
}


/*******************************************************************************
 *   
 *  Function name:      deleteRecord   
 *
 *  DESCRIPTION:        Deletes a the record in the "address book" using the name as the key
 *   
 *  Parameters:         start (struct record*) :
 *
 *  Return values:      0 Success
 *
 ******************************************************************************/


int deleteRecord(struct record** start, char name[])
{
    if(debugMode == 1)
    {
	printf("\n(Delete Record)\n Name: %s\n", name);	
    }

    struct record* searchContact;
    struct record* previousContact;
    searchContact = *start;
    previousContact = *start;
    int found = 0;           
    if(start != NULL)
    {
        while(searchContact != NULL)
        {
            if(strcmp((**start).name, name) == 0)
            {
                searchContact = (**start).next;
		free(*start);
		(*start) = searchContact;
                found = 1;
            }
            else
            {
                while(searchContact != NULL)
		{
		    if(strcmp((*searchContact).name, name) == 0)
		    {
			(*previousContact).next = (*searchContact).next;
			free(searchContact);
			searchContact = (*previousContact).next;
		    }
		    else
		    {
			previousContact = searchContact;
			searchContact = (*searchContact).next;
		    }    
		}
		
            }
        }
    }
            
    return found;
}


/*******************************************************************************
 *   
 *  Function name:      writeFile
 *
 *  DESCRIPTION:        Writes all the contacts in the "address book" to a designated file
 *
 *  Parameters:         start (struct record*) fileName char[]:
 *
 *  Return values:      none
 *
 ******************************************************************************/


void writeFile(struct record* start, char fileName[])
{
    struct record *contact;
    contact = start;
    FILE *file = fopen(fileName, "w");
	       
    if(start != NULL)
    {   fprintf(file,"\n");
        while(contact != NULL)
        { 
	    fprintf(file,"\n");
            fprintf(file,"%s\n", (*contact).name);
            fprintf(file,"%s\n",(*contact).address);
            fprintf(file,"%d\n", (*contact).birthYear);
            fprintf(file,"%s\n", (*contact).number);
            contact = contact -> next;
 
        }
    }

}


/*******************************************************************************
 *   
 *  Function name:      readFile
 *
 *  DESCRIPTION:        Reads all the records from the designated file
 *
 *  Parameters:         start (struct record**) fileName char[]:
 *
 *  Return values:      0 Success
 *
 ******************************************************************************/


int readFile(struct record** start, char fileName[])
{
    int found = 0;
    char name[25];
    char address[80];
    int birthYear;
    char number[15];
    FILE *file = fopen(fileName, "r");
    int i;
    char letter;    
    if(file != NULL)
    {
	if((letter = fgetc(file)) != EOF)
	{ 
	    if(letter == '\n')
	    {
	        if((letter = fgetc(file)) != EOF)
		{
	            do
	            {   
 		        fgets(name,25,file);

		        if(name[strlen(name)-1] == '\n')
		        name[strlen(name) -1] = '\0';
	        
	                i = 0;
		        letter = fgetc(file);
		        while(letter != '!')
		        {
		            address[i] = letter;
  		            i++;
		            letter = fgetc(file);
		        }
		        address[i] = '!';
                        i++;
		        address[i] = '\0';
		        fscanf(file, "%d", &birthYear);
		        letter = fgetc(file); /* Catches the new line character*/


		        fgets(number,15,file);
		        if((number[strlen(number) - 1]) == '\n')
                        number[strlen(number) -1] = '\0';
		        addRecord(start,name,address,birthYear,number);
		        }while(fgetc(file) != EOF);
	        }
	    }
	}
	else
        {           
            found = 1; 
        }            
}

    
    return found;
}


/*******************************************************************************
 *
 *  Function name:      cleanUp
 *
 *  DESCRIPTION:        Goes through all records and deletes each one from the heap
 *
 *  Parameters:         start (struct record**)
 *
 *  Return values:      none
 *
 ******************************************************************************/


void cleanUp(struct record** start)
{
    struct record *contact;
    contact = *start;

    if(*start != NULL)
    {
        while(contact != NULL)
        {
            free(contact);
            contact = contact -> next;
     
        }               
    start = NULL;
    
    }
   
}
