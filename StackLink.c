#include <stdio.h>
#include <stdlib.h>
#include "StackLink.h"

nodeptr create(int item){
	nodeptr p;
	p = (nodeptr)malloc(sizeof(struct node));
	p->item = item;
	p->next = NULL;
	return p;
}
Stack newStack(){
	Stack m = create(0);
	return m;
}
void push(Stack s, stackItem string){
	nodeptr temp = create(string);
	temp->next= s->next;
	s->next = temp;
}
void pop(Stack s){
	nodeptr p= s->next;
	if(s!=NULL){
		s->next= p->next;
		free(p);
	}
}
char peek(Stack s){
	char top = '\0';
	if(s!=NULL){
		nodeptr p=s->next;
		top=p->item;
	}
	return top;
}
void destroyStack(Stack *s){
	free(*s);
	*s = NULL;
}
void display(Stack s){
	nodeptr d = s->next;
	printf("[");
	while(d!=NULL){
		printf("%c ", d->item);
		d = d->next;
	}
	printf("]");
}
void clear (Stack s){
	while(s->next!=NULL){
		nodeptr d = s->next;
		if(d!=NULL){
			s->next = d->next;
			free(d);
		}
	}
}
boolean isEmpty(Stack s){
	return (s->next==0 ? true:false);
}
int check(char data[]){
	Stack s = newStack();
	int i, errorcode=1;
	char temp='\0';
	for(i=0; data[i]!='\0'; i++){
		temp=data[i];
		if(temp=='('){
			push(s, ')');
		}
		else if(temp=='['){
			push(s,']');
		}
		else if(temp=='{'){
			push(s, '}');
		}
		else if(temp==')'){
			if(!isEmpty(s)){
				if(peek(s)==temp){
					pop(s);		
				}
				else if(peek(s)!=temp){
				errorcode=2;
				break;
				}
			}
			else{
				errorcode=2;
				break;
			}
		
		}
		else if(temp==']'){
			if(!isEmpty(s)){
				if(peek(s)==temp){
					pop(s);		
				}
				else if(peek(s)!=temp){
				errorcode=2;
				break;
				}
			}
			else{
				errorcode=2;
				break;
			}
		
		}
		else if(temp=='}'){
			if(!isEmpty(s)){
				if(peek(s)==temp){
					pop(s);		
				}
				else if(peek(s)!=temp){
				errorcode=2;
				break;
				}
			}
			else{
				errorcode=2;
				break;
			}	
		}
	}
	
	if(!isEmpty(s)){
		errorcode=3;
	}

	destroyStack(&s);
	return errorcode;
}
