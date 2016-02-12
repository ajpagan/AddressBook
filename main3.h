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
*    File:        main3.h
*
*    Description: Holds the function's prototypes for homework3.c
******************************************************************************/

int addRecord(struct record **, char [], char [], int, char []);
int printRecord(struct record *, char []);
int modifyRecord(struct record *, char [], char [], char []); 
int printAllRecords(struct record*);
int deleteRecord(struct record **, char []);
int readFile(struct record**, char[]);
void writeFile(struct record*, char[]);
void cleanUp(struct record**);
int printMenu();
