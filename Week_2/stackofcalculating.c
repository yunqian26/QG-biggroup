#include<stdio.h>
#define null NULL
typedef struct
{
	char data;
	struct stack* next;
}type; 

typedef struct
{
	type *top;
}type_s;

void start_stack(type_s *stack)
{
	stack->top=null;
}

int check_empty(type_s *stack)
{
	if(stack->top==null) return 1;
	else return 0;
}

void push(type_s *stack,char value)
{
	type *newpoint=(type*)malloc(sizeof(type));
	if(newpoint==null)
	{
		printf("分配空间失败\n");
		exit(1);
	}
	newpoint->data=value;
	newpoint->next=stack->top;
	stack->top=newpoint;
}

char pop(type_s *stack)
{
	if(check_empty(stack))
	{
		printf("该栈中没有元素\n");
		return;
	}
	type* tem=stack->top;
	char value=tem->data;
	stack->top=tem->next;
	free(tem);
	return value;
}

char peek(type_s *stack)
{
	if(check_empty(stack))
	{
		printf("该栈中没有元素\n");
		return;
	}
	return stack->top->data;
}

void destory(type_s *stack)
{
	while(!check_empty(stack))
	{
		pop(stack);
	}
}

void print(type_s *stack)
{
	printf("栈：");
	type *nowpoint=stack->top;
	while(nowpoint!=null)
	{
		type* tem=nowpoint;
		nowpoint=nowpoint->next;
	} 
	stack->top=null;
}

int precedence(char operation)
{
	if(operation=='+'||operation=='-') return 1;
	else if(operation=='*'||operation=='/') return 2;
	return 0;
}

int check_space(char operation)
{
	if (operation==' ') return 1;
	else return 0;
}

int check_number(char operation)
{
	if (operation>='0'&&operation<='9') return 1;
	else return 0;
}

void change_perform(char *orgin,char*outformula)
{
	type_s operators;
	start_stack(&operators);
	int i=0,j=0;
	for(i=0;orgin[i]!='\0';i++)
	{
		if(check_space(orgin[i])) continue;
			else if(check_number(orgin[i]))
			{
				while(check_number(orgin[i]))
				{
					outformula[j++]=orgin[i++];//去空格 
				}
			}
			else if(orgin[i]=='(') 	push(&operators,orgin[i]);
			else if(orgin[i]==')')	
			{
				while(check_empty(&operators)&&peek(&operators)!='(')
				{
					outformula[j++]=pop(&operators);
					j++;
				}
				push(&operators,orgin[i]);
			}//将所有运算符推入栈中 
	}
	while(!check_empty(&operators))
		{
		outformula[j++]=pop(&operators); 
		j++;
		}//将运算符逐步弹出栈	
	
	outformula[j]='\0';
	free(&operators);
	
}





