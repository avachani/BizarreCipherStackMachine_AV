// helper.c (implementation file)
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
Abhi Vachani
apv9448
Prof. Kayar 
CSO
Project 1
*/




void push(StackNodePtr *topPtr, BizarreNumber_t info)
{

	// Push bizzare number into stack
	StackNodePtr newPtr = malloc(sizeof(StackNode));

	// Insert node at top of stack
	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else { // No space available
		printf("%d not inserted. No memory available.\n", info);
	}

}



BizarreNumber_t pop(StackNodePtr *topPtr)
{

	// Pop the top item from the stack and return it
	StackNodePtr tempPtr = *topPtr;
	BizarreNumber_t popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;

}

int isEmpty(StackNodePtr topPtr) 
{

	// Return 1 if the stack is empty; return 0 otherwise.
	return topPtr == NULL;

}


void printStack(StackNodePtr currentPtr)
{


	// print only values in one line: TOP -> number of node -> number of node -> ... -> BOTTOM

	// if stack is empty
	if (currentPtr == NULL) {
		puts("The stack is empty.\n");
	}
	else { // stack is not empty
		printf("TOP --> ");

		// while not at end of stack
		while (currentPtr != NULL) {
			if ((currentPtr->data).num == -1) {
				printf("NULL --> ");
			}
			else {

				printf("%d --> ", (currentPtr->data).num);
				
			}

			currentPtr = currentPtr->nextPtr;
			
		}

		puts("BOTTOM\n");

	}

}

void printStackDetailed(StackNodePtr currentPtr)
{

	// Print line by line in detail: 

	// if stack is empty
	if (currentPtr == NULL) {
		puts("The stack is empty.\n");
	}
	else { // stack is not empty
		puts("**TOP**");

		// while not at end of stack
		while (currentPtr != NULL) {
			printf("%d, %d, %s", (currentPtr->data).num, (currentPtr->data).nrOfOpr); puts(currentPtr->data.type);
			currentPtr = currentPtr->nextPtr;
		}

		puts("**BOTTOM**\n");

	}

}


int isAbundantNumber(int num) 
{

	/*
	checks the number and returns the abundance so that if the abundance is
	larger than 0, the number is abundant, if equals to 0, the number is perfect,
	if smaller than 0, the number is deficient.
	*/

	int sum = 0;

	// calculate sum of divisors (not including num)
	for (int i =1; i < num; i++)
	{
		if (num % i == 0) {
			sum = sum + i;
		}
	}

	// return abundance/perfect/defficient amount
	return (sum - num);





}


int isPrime(int num)
{
	// returns 1 if the number is prime, 0 otherwise.

	if (num <= 1)
	{
		return 0;
	}

	for (int i = 2; i <= num/2; i = i+1)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}

	return 1;
	

}


int isPerfectSquare(int num)
{
	// returns 1 if the number is a perfect square, 0 otherwise

	// convert sqrt(num) to a float
	float f; 
	f = sqrt((double)num);

	// set num = f (this only works if sqrt(num) is a perfect square)
	num = f;
	if (num == f) {
		return 1;
	}
	else {
		return 0;
	}



}



StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack)
{

	// checks the type of each node and recovers the number using the main stack
    // and the helper stack, and returns the newly created recovered stack.

	// new recovered stack
    StackNodePtr RecoveredStackPtr = NULL;
	
    // prime 
    if (strcmp((mainStack->data).type, "PR") == 0) {
    	BizarreNumber_t bn;
    	strcpy(bn.type, "PR");
    	bn.nrOfOpr = (mainStack->data).nrOfOpr;
    	bn.num = sqrt((mainStack->data).num);
    	push(&RecoveredStackPtr, bn);

    }

    

 
    // perfect square 
    else if (strcmp((mainStack->data).type, "SQ") == 0) {
    	BizarreNumber_t bn;
    	strcpy(bn.type, "SQ");

    	bn.nrOfOpr = (mainStack->data).nrOfOpr;
    	bn.num = (mainStack->data).num;

    	for (int i = 1; i <= bn.nrOfOpr; i++)
    	{
    		bn.num = bn.num * bn.num;

    	}
    	
    	push(&RecoveredStackPtr, bn);

    }

    
    // perfect number
    else if (strcmp((mainStack->data).type, "PF") == 0) {
    	BizarreNumber_t bn;
    	strcpy(bn.type, "PF");
    	bn.nrOfOpr = (mainStack->data).nrOfOpr;
    	bn.num = (mainStack->data).num;
    	push(&RecoveredStackPtr, bn);

    }



    // deficient number
    else if (strcmp((helperStack->data).type, "DF") == 0) {
    	BizarreNumber_t bn;
    	strcpy(bn.type, "DF");
    	bn.nrOfOpr = (helperStack->data).nrOfOpr;
    	bn.num = (helperStack->data).num;
    	push(&RecoveredStackPtr, bn);

    }


    // abundant number
    else if (strcmp((mainStack->data).type, "AB") == 0) {
    	BizarreNumber_t bn;
    	strcpy(bn.type, "AB");
    	bn.nrOfOpr = (mainStack->data).nrOfOpr;
    	bn.num = (mainStack->data).num + (helperStack->data).num;
    	push(&RecoveredStackPtr, bn);

    }

    

    // return new stack
    return RecoveredStackPtr;

    

}





