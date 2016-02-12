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
*    File:        record.h
*
*    Description: Holds the struct recordable variable
******************************************************************************/

struct record
{
    char name [25];
    char address [80];
    int  birthYear;
    char number [15];
    struct record* next;
};
