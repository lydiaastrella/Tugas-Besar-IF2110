#ifndef _WAITINGCUST_h
#define _WAITINGCUST_h

#include "library.h"

/*---------- CUSTOMER ----------*/
/* Constructor */
void NewCustomer (Customer * C);
// Generates a new customer

/*---------- QUEUE ----------*/
/* Prototypes */
boolean IsEmpty (Queue Q); 
// Returns TRUE if Head = Tail = 0
boolean IsFull (Queue Q);  
// Returns TRUE if NBElmt = MaxEl
int NBElmt (Queue Q);
// Returns Tail - Head + 1

/* Constructor */
void CreateEmpty (Queue * Q, int Max); 
// Creates empty queue; MaxEl = Max

/* Add/Delete queue element */
void Add (Queue * Q, Customer C);
// Adds new element to tail of Q
void StarAdd (Queue * Q, Customer C);
// Adds new element to head of Q
void Del (Queue * Q, Customer * C);
// Deletes head element of Q
void DelX (Queue * Q, int X, Customer * C);
// Deletes X-th element

/* Queue changes after 1 tick */
void LessPatient (Queue * Q);
// Decreases patience of all customers in the queue
void CustomersLeave (Queue *Q);
// Detects and deletes customers with patience = 0
void InitiateQueue (Queue * Q);
// Determines state of queue during start of game
void UpdateQueue (Queue * Q);
/* Collection of changes made after 1 tick:
    - LessPatient
    - CustomersLeave
    - Determines whether to add a new customer to the queue
*/

/* Print queue */
void PrintQueue (Queue Q);
// Prints every element of Q with format of C for each regular customer and S for each star customer

/* Debugging */
void PrintPatience (Customer C);
// Prints the patience of customer

#endif