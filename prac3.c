/*
 *
 * Description:
 * This program allows the user Push, Remove, Print, Get Head and Tail of list
 *
 * Inputs:
 * The program takes in a file with various arguments Push, Remove, Length, etc
 * the program then proceeds to do the actions that needs to be undertaken
 *
 * Outputs:
 * In the File will be commands like Push A the program will read push and add A to the list
 * if the file says PrintList the program will output the list as A-B-etc until the list ends
 * In the event that incorrect are letters are inputted the program will output
 * "Input not valid"
 *
 * Caveats
 * Program can only store letters from A to Z on the stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct node                                             /*This is the initialisation of the node class*/
{
    char data;                                          /*This is to access the node in the node class*/
    struct node * next;                                 /*allows the variable to have a next node*/
};

struct node * myNode=NULL;                              /*creation of the node the program uses of type node*/

int count = 0;                                          /*Initialisation of global stack counter*/

/*
 * Description:
 * This function pushes desired letters from A - Z onto the front of the list and is case sensitive
 * only allowing uppercase letters
 *
 * Inputs:
 * This function takes in a node list and a variable of type char to add to the node list
 *
 * Outputs:
 * The function has no output it does however change the myNode list directly
 */

struct node* Push(struct node **hPoint, char add)
{
    struct node * newNode = (struct node*) malloc(sizeof(struct node));         /*Initialisation of a temp node to make changes upon*/
    newNode->data = add;                                                        /*creating a node of the variable to be added*/
    newNode->next = *hPoint;                                                    /*creating a space for the next node that needs to be added*/
    *hPoint = newNode;
    count ++;                                                                   /*incrementing the length of the list*/
    return *hPoint;
}

/*
 * Description:
 * This function pushes desired letters from A - Z to the back of the list and is case sensitive
 * only allowing uppercase letters
 *
 * Inputs:
 * This function takes in a node list and a variable of type char to add to the node list
 *
 * Outputs:
 * Returns an updated version of the node inputed
 */

struct node* Append(struct node **hPoint, char add)
{
    struct node * newNode = (struct node*) malloc(sizeof(struct node));         /*Initialisation of a temp node to make changes upon*/
    newNode->data = add;                                                        /*creating a node of the variable to be added*/
    newNode->next = NULL;                                                       /*Initialising node next to null since we are adding to the back*/
    struct node * pointer = *hPoint;                                            /*Creating a pointer to iterate through*/
    struct node * prev;                                                         /*To keeping track of previous*/

    if(*hPoint == NULL)                                                         /*If the node list is empty*/
    {
        Push(hPoint,add);                                                       /*Just push a new element*/
        return *hPoint;                                                         /*Return updated node*/
    }
    while (pointer->next !=NULL)                                                /*Else iterate through until you get to the back of the node list*/
    {
        prev = pointer;                                                         /*keeping track of previous*/
        pointer = pointer->next;                                                /*Used to iterate*/
    }
    pointer->next = newNode;                                                    /*last node in list next will be the new node we created*/
    count++;                                                                    /*add one to max number of nodes in list*/
    return *hPoint;                                                             /*return updated node list*/
}

/*
 * Description:
 * This function pushes desired letters from A - Z before the requested node
 *
 * Inputs:
 * This function takes in a node list, a value to be added and where the value should be added
 *
 * Outputs:
 * Returns an updated version of the node inputed
 */

struct node* InsertBefore(struct node **hPoint, char add, char val)
{
    struct node * pointer = *hPoint;                                            /*Initialisation of node to point through list*/
    while (pointer->next !=NULL)                                                /*running through node list*/
    {
        if(pointer->next->data == val)                                          /*if the next node is the node you looking for break*/
        {
            break;
        }
        pointer = pointer->next;                                                /*else iterate*/

    }
    struct node * newNode = (struct node*) malloc(sizeof(struct node));         /*creation of newNode to be added*/
    newNode->data = add;                                                        /*setting the data*/
    newNode->next = pointer->next;                                              /*setting the newNodes next to the pointers next*/
    pointer->next = newNode;                                                    /*and then the pointers next value to the newNode*/
    count++;                                                                    /*value added to the length of list*/
    return *hPoint;                                                             /*return updated*/
}

/*
 * Description:
 * This function pushes desired letters from A - Z after the requested node
 *
 * Inputs:
 * This function takes in a node list, a value to be added and where the value should be added
 *
 * Outputs:
 * Returns an updated version of the node inputed
 */

struct node* InsertAfter(struct node **hPoint, char add, char val)
{

    struct node * pointer = *hPoint;                                            /*creating pointer to point through node list*/
    if(*hPoint == NULL)                                                         /*checks to see if the node is null*/
    {
        fprintf(stderr, "Input not valid\n");
        return *hPoint;
    }
    while (pointer->next !=NULL)                                                /*running through the node list*/
    {
        if(pointer->data == val)                                                /*if the pointers data matches data to be added after*/
        {
            break;                                                              /*break*/
        }
        pointer = pointer->next;                                                /*else iterate*/

    }
    struct node * newNode = (struct node*) malloc(sizeof(struct node));         /*creation of newNode*/
    newNode->data = add;                                                        /*adding data to the new node*/
    newNode->next = pointer->next;                                              /*newNodes next node will be the pointers next*/
    pointer->next = newNode;                                                    /*and the pointers next node will be the nowNode*/
    count++;                                                                    /*add value to the length*/
    return *hPoint;                                                             /*return updated node list*/
}

/*
 * Description:
 * This function removes the first instance of the variable that occurs on the stack
 *
 * Inputs:
 * The function takes in a variable of type char to be removed from the node list
 *
 * Outputs:
 * The function has no output other then error checking
 * In the even the valued that needs to be removed is not in the list "Input not valid
 * will be printed"
 */

int Remove(struct node **hPoint, char pop)
{
    struct node *previous;                                                      /*creating a node of type node called previous*/
    struct node *current;                                                       /*creating a node of type node called current*/
    int popCount = 0;                                                           /*creating a counter to check how much times i will be looping through*/
    int checker = -1;
    if(*hPoint == NULL)                                                          /*checks to see if the node is null*/
    {
        return -1;
    }

    current = *hPoint;                                                           /*setting current to the first node in the list in order for the loop through*/
    while (current->data != pop && current->next != NULL)                       /*checks to see if the current code is equal to the node to be popped as well as if the next node is null*/
    {
        checker = 1;
        previous = current;                                                     /*this is in order to keep track of what the previous value was*/
        current = current->next;                                                /*incrementing to the next node*/
        popCount ++;                                                            /*incrementation of the remove (pop) count*/
    }

    if (popCount == count && current->data == pop)                              /*if popCount is = to the total list size then it is at the end of the list*/
    {
        previous->next = NULL;                                                  /*using the previous node to delete the last node by setting it to null*/
        count--;                                                                /*decrement the amount of elements in the list*/
        return 0;
    }

    if (popCount == 0 && current->data == pop)                                  /*if popCount is zero then it is at the first node*/
    {
        current = current->next;                                                /*by setting current to currents next we would delete the first node*/
        *hPoint = current;                                                       /*over writing the original node to the updated node*/
        count--;                                                                /*decrementing the amount of elements in the list */
        return 0;
    }

    else if(popCount> 0 && popCount<=count && current->data == pop)             /*if popCount is in between the last element and the first and is equal to the element*/
    {
        previous->next = current->next;                                         /*previous is set to the currents next*/
        count --;                                                               /*decrementing the amount of elements in the list*/
        return 0;
    }

    else                                                                        /*if node of the previous ifs occur then it is not a valid input*/
    {
        printf("Remove2\n");
        return -1;
    }
    return 0;
}

/*
 * Description:
 * Prints out the entire list of elements from the first element to the list with a "-" in between
 *
 * Inputs:
 * Takes in no variables from the file
 *
 * Outputs:
 * Prints out all the variables in the list with a "-" in between if the list is empty "Input not valid"
 */

void PrintList(struct node **hPoint)
{
    struct node * pointer = *hPoint;                                             /*Creates a pointer of type node of myNode*/

    while (pointer != NULL)                                                     /*loop for as long as there are variables within the list*/
    {
        printf("%c", pointer->data);
        if (pointer->next != NULL)                                              /*used to print a "-" in between the elements in the list*/
        {
            printf("-");
        }
        if (pointer->next == NULL)                                              /*if the last element is null print a new line*/
        {
            printf("\n");
        }
        pointer = pointer->next;                                                /*increment to the next element*/
    }

    if (*hPoint == NULL)                                                         /*if the list is NULL "Input not valid"*/
    {
        printf("-\n");
    }
}

/*
 * Description:
 * Gets the first element in the list
 *
 * Inputs:
 * Takes in no inputs from the user
 *
 * Outputs:
 * If the list is null "Input not valid" will print. If the list is not empty it will print the first element in the list
 */

struct node* Head(struct node **hPoint)
{
    struct node * pointer = *hPoint;                                             /*Creates a pointer of type node of myNode*/
    if (pointer == NULL)                                                        /*If the list is null "input not valid"*/
    {
        fprintf(stderr, "Input not valid\n");
    }

    return pointer;
    printf("%c\n", pointer->data);                                              /*Else print the first node*/
}

/*
 * Description:
 * Gets the last element in the list
 *
 * Inputs:
 * Takes in no inputs from the user
 *
 * Outputs:
 * If the list is null "Input not valid" will print. If the list is not empty it will print the last element in the list
 */

struct node* Tail(struct node **hPoint)
{
    struct node * pointer = *hPoint;                                             /*Creates a pointer of type node of myNode*/
    int tailCount = 0;

    while (pointer != NULL)                                                     /*while the pointer is not null*/
    {
        if (pointer == NULL)                                                    /*if it is null "input not valid"*/
        {
            fprintf(stderr, "Input not valid\n");
        }

        if (pointer->next == NULL)                                              /*if the pointers next is null it is the last element in the list*/
        {
            if(count == 1)                                                      /*if its the first node print the head*/
            {
                Head(hPoint);

                break;
            }
            return pointer;                                                     /*else print the last node in the list*/
        }

        pointer = pointer->next;                                                /*increment the pointer*/
    }
}

/*
 * Description:
 * Prints the amount of elements in the list
 *
 * Inputs:
 * Takes in no inputs
 *
 * Outputs:
 * Outputs the amount of elements in the list
 */

void Length()
{
    printf("%d\n", count);                                                      /*Prints the global count variable*/
}

/*
 * Description:
 * Checks to see if the values that needs to be added is valid inputs
 *
 * Inputs:
 * Takes int he character to be checked
 *
 * Outputs:
 * returns a zero if the value is between A and Z if not prints "Input not valid" and returns a 1
 */

int invalid(char letter)
{
    if(letter>= 'A' && letter<='Z')                                             /*checks to see if the letter falls between A and Z*/
    {
        return 0;                                                               /*if yes return 0*/
    }
    else
    {

        return 1;                                                               /*else "Input not valid" return 1*/
    }
}

/*
 * Description:
 * The main procedure that reads in the file separates functions from values to be added
 * It also matches up the necessary functions and executes them.
 *
 * Inputs:
 * reads in a file with various correct and incorrect lines to be executed.
 *
 * Outputs:
 * If it is valid inputs it will process its respective functions and its respective output
 * If it is not "Input not valid"
 */

int main(int argc, char *argv[])
{
    char const* const fileName = argv[1];                                       /*Reads in the file from args*/
    FILE* file = fopen(fileName, "r");                                          /*Calls the initialise file to variable to read only*/
    char line[256];                                                             /*allocates 256 spaces for the line*/

    char piece1[20] = ""                                                        /*Initialisation of the function as piece one*/
        ,piece2[20] = ""                                                        /*Initialisation of the value to be added to the function as piece2*/
        ,piece3[20] = "";
    char * p;                                                                   /*used to the token*/
    while (fgets(line, sizeof(line), file))
    {
        //printf("%s", line);

        p = strtok (line," ");                                                  /*call the strtok with str as 1st arg for the 1st time.*/
        if (p != NULL)                                                          /*check if we got a token.*/
        {
            strcpy(piece1,p);                                                   /*save the token.*/
            p = strtok (NULL, " ");                                             /*subsequent call should have NULL as 1st arg.*/
            if (p != NULL)                                                      /*check if we got a token.*/
            {
                strcpy(piece2,p);                                               /*save the token.*/
                p = strtok (NULL, " ");
                if (p != NULL)
                {
                    strcpy(piece3,p); // save the token.
                }
            }

        }

        if (line == "\n")                                                       /*Checks to see if the line is blank*/
        {
            fprintf(stderr, "Input not valid\n");
        }

        if (strcmp(piece1,"Push")==0)                                           /*checks to see if it is the push function*/
        {
            char new2 = piece2[0];

            int caseTest = invalid(new2); /*0 is yes 1 is no*/                  /*checks for function validity*/
            //printf("%d",caseTest);
            if(caseTest == 1)
            {

                fprintf(stderr, "Input not valid\n");
                continue;
            }

            if(caseTest == 0)
            {
                //printf("final1\n");
                Push(&myNode,new2);                                             /*runs the push with the value*/
                continue;
            }
        }

        if (strcmp(piece1,"Append")==0)                                         /*checks to see if it is the push function*/
        {
            char new2 = piece2[0];

            int caseTest = invalid(new2); /*0 is yes 1 is no*/                  /*checks for function validity*/

            if(caseTest == 1)
            {
                fprintf(stderr, "Input not valid\n");
            }
            if(caseTest == 0)
            {
                Append(&myNode,new2);                                           /*runs the push with the value*/
                continue;
            }
        }

        else if(strcmp(piece1,"Remove")==0)                                     /*checks to see if it is the remove function*/
        {
            if(Remove(&myNode,piece2[0])==-1)
            {
                fprintf(stderr, "Input not valid\n");
            }
            Remove(&myNode, piece2[0]);
            continue;
        }

        else if(strcmp(piece1,"InsertBefore")==0)
        {
            char new2 = piece2[0];
            int caseTest = invalid(new2); /*0 is yes 1 is no*/                  /*checks for function validity*/

            if(caseTest == 1)
            {
                fprintf(stderr, "Input not valid\n");
            }
            if(caseTest == 0)
            {
                InsertBefore(&myNode, piece2[0], piece3[0]);                    /*runs the push with the value*/
                continue;
            }

        }

        else if(strcmp(piece1,"InsertAfter")==0)
        {
            char new2 = piece2[0];
            int caseTest = invalid(new2); /*0 is yes 1 is no*/                  /*checks for function validity*/
            if(caseTest == 0)
            {
                InsertAfter(&myNode, piece2[0], piece3[0]);                     /*runs the push with the value*/
                continue;
            }
        }

        else if(strcmp(line,"Head\n")==0 || strcmp(line,"Head")==0)             /*checks to see if it is the Head function*/
        {
            printf("%c\n",Head(&myNode)->data);                                 /*runs the head function*/
            continue;
        }

        else if(strcmp(piece1,"Tail\n")==0 || strcmp(piece1,"Tail")==0)         /*checks to see if it is the tail function*/
        {
            printf("%c\n",Tail(&myNode)->data);                                 /*runs the tail function*/
            continue;
        }

        else if(strcmp(piece1,"PrintList\n")==0 || strcmp(piece1,"PrintList")==0)   /*checks to see if it is the printList function*/
        {
            PrintList(&myNode);                                                     /*runs the printList function*/
            continue;
        }

        else if(strcmp(piece1,"Length\n")==0 || strcmp(piece1,"Length")==0)     /*checks to see if it is the length function*/
        {
            Length();                                                           /*runs the length function*/
            continue;
        }
        else                                                                    /*if it is none of the previous ifs it is an invalid input*/
        {
            fprintf(stderr, "Input not valid\n");
        }
    }

    fclose(file);

    return 0;
}
