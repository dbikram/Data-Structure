#include<stdio.h>
#include<stdlib.h>
char stack[100];
int top=-1;
void push(char elem)
{
                stack[++top]=elem;
}
char pop()
{
                return(stack[top--]);
}
int main()
{
                char exp[100],c;
                int i=0;
                printf("Enter the expression:");
                scanf("%s",exp);
                while(exp[i]!='\0')
                {
                                if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){ //if open bracket, push it onto the stack
                                                push(exp[i]);
                                                i++; //for next element
                                }
                                else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){ //if closing bracket, pop it from the stack
                                                c=pop();
                                                if(c=='('&&exp[i]==')')  //match the parenthesis
                                                                i++;
                                                else if(c=='{'&&exp[i]=='}')
                                                                i++;
                                                else if(c=='['&&exp[i]==']')
                                                                i++;
                                                else{
                                                                printf("Not matched\n");
                                                                exit(0);
                                                }
                                }
                                else
                                                i++;
                }
                printf("Matched\n");
                return 0;
}
