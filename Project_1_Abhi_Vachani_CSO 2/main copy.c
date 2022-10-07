// Main.c
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



int main(void)
{
	// create two stacks
	StackNodePtr MainStackPtr = NULL;
	StackNodePtr HelperStackPtr = NULL;

	// Recovery stack
	StackNodePtr RecoveredStackPoint = NULL;

	int value;

	printf("Enter an integer to push: \n");

	while (scanf("%d", &value) != EOF)
	{
		printf("Enter an integer to push: \n");
		// Cases for each type of num:


		// prime number
		if (isPrime(value) == 1) {
			BizarreNumber_t bn;
			strcpy(bn.type, "PR");
			bn.num = value * value;
			bn.nrOfOpr = 0;

			// push to main stack
			push(&MainStackPtr, bn);

			// push null to helper stack
			BizarreNumber_t bn_null;
			bn_null.num = -1;
			push(&HelperStackPtr, bn_null);



		}

		// perfect square number
		else if (isPerfectSquare(value) == 1) {
			/*
			take its square root until no more whole number root is
			found and increment the number of operations (nrOfOpr) by one each time. Push
			the last square root to the stack. (E.g. for 625, push 5 and increment the nrOfOpr
			of the node to 2)
			*/

			BizarreNumber_t bn;
			strcpy(bn.type, "SQ");
			
			// initialize nrOfOpr to 0
			bn.nrOfOpr = 0;

			// make sure value is perfect square for each loop
			while (isPerfectSquare(value) == 1) {
				value = sqrt(value);
				bn.nrOfOpr = bn.nrOfOpr + 1;
			}

			// set bn.num to value
			bn.num = value;

			// push to main stack
			push(&MainStackPtr, bn);

			// push null to helper stack
			BizarreNumber_t bn_null;
			bn_null.num = -1;
			push(&HelperStackPtr, bn_null);


		}

		// perfect number
		else if (isAbundantNumber(value) == 0) {
			BizarreNumber_t bn;
			strcpy(bn.type, "PF");
			bn.num = value;
			bn.nrOfOpr = 0;
			push(&MainStackPtr, bn);

			// push null to helper stack
			BizarreNumber_t bn_null;
			bn_null.num = -1;
			push(&HelperStackPtr, bn_null);

		}

		// abundant number
		else if (isAbundantNumber(value) > 0) {
			BizarreNumber_t bn;
			strcpy(bn.type, "AB");
			bn.num = value-isAbundantNumber(value);
			bn.nrOfOpr = 0;

			// push to main stack
			push(&MainStackPtr, bn);

			// push to helper stack
			bn.num = isAbundantNumber(value);
			push(&HelperStackPtr, bn);


		}


		// deficient number
		else if (isAbundantNumber(value) < 0) {
			BizarreNumber_t bn;
			strcpy(bn.type, "DF");
			bn.num = value;
			bn.nrOfOpr = 0;

			// push to helper stack
			push(&HelperStackPtr, bn);

			// push null to main stack
			BizarreNumber_t bn_null;
			bn_null.num = -1;
			push(&MainStackPtr, bn_null);

		}

		push(&RecoveredStackPoint, recoverCipher(MainStackPtr, HelperStackPtr)->data);


		




	}

	
	

	system("clear");

	

	

	printf("The main stack is: \n");
	printStack(MainStackPtr);


	printf("The helper stack is: \n");
	printStack(HelperStackPtr);


	printf("The recovered stack is: \n");


	printStackDetailed(RecoveredStackPoint);

	return 0;
}
