#ifndef STACKLINK_H
#define STACKLINK_H

typedef enum {false, true} boolean;
typedef char stackItem;
typedef struct node *nodeptr;
struct node {
	int item;
	nodeptr next;
};
typedef nodeptr Stack;

Stack newStack();
void push(Stack s, stackItem string);
void pop(Stack s);
char peek(Stack s);
void destroyStack(Stack *s);
void display(Stack s);
void clear (Stack s);
boolean isEmpty(Stack s);
int check(char data[]);

#endif
