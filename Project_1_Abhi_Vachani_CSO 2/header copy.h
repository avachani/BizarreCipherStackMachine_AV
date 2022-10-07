// Header.h

/*
Abhi Vachani
apv9448
Prof. Kayar 
CSO
Project 1
*/



typedef struct {
    char type[3];
    int nrOfOpr;
    int num;
} BizarreNumber_t;

struct stackNode {
    BizarreNumber_t data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;



// Stack related
void push(StackNodePtr *topPtr, BizarreNumber_t info);
BizarreNumber_t pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void printStackDetailed(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);


// Math related
int isAbundantNumber(int num); //returns abundance (if 0 perfect, if > 0 abundant, if < 0 deficient)
int isPrime(int num);
int isPerfectSquare(int num);

// Recovery related
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);