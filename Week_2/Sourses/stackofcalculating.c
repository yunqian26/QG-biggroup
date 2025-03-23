#include<stdio.h>
#include<string.h>
#define null NULL
typedef struct
{
	char data;
	struct stack* next;
}type; //节点结构体 

typedef struct
{
	type *top;
}type_s;//栈顶指针 

void start_stack(type_s *stack)
{
	stack->top=null;//初始化栈 
}

int check_empty(type_s *stack)
{
	if(stack->top==null) return 1;//若栈顶为空则栈为空 
	else return 0;//若栈顶不为空则栈不为空
	 
}

void push(type_s *stack,char value)
{
	type *newpoint=(type*)malloc(sizeof(type));//申请分配内存 
	if(newpoint==null) 
	{
		printf("分配空间失败\n");
		exit(1);
	}
	newpoint->data=value;//将新数据存入节点中 
	newpoint->next=stack->top;//将数据至于栈顶 
	stack->top=newpoint;//移动栈顶指针 
}

char pop(type_s *stack)
{
	if(check_empty(stack))
	{
		printf("该栈中没有元素(pop)\n");
		return;
	}
	type* tem=stack->top;//存储栈顶指针 
	char value=tem->data;//取得栈顶数据 
	stack->top=tem->next;//移动栈顶指针 
	free(tem);//释放内存 
	return value;//返回栈顶数据 
}

char peek(type_s *stack)
{
	if(check_empty(stack))
	{
		printf("该栈中没有元素(peek)\n");
		return;
	}
	return stack->top->data;//返回栈顶数据 
}

void destory(type_s *stack)
{
	while(!check_empty(stack))
	{
		pop(stack);//弹出栈所有数据直至栈为空 
	}
}

void print(type_s *stack)
{
	printf("栈：");
	type *nowpoint=stack->top;//从栈顶开始输出 
	while(nowpoint!=null)
	{
		printf("%c",nowpoint->next); //输出 
		nowpoint=nowpoint->next;//移动 
		
	} 
	stack->top=null;//指针悬空 
}

int precedence(char operation)
{
	if(operation=='+'||operation=='-') return 1;//若加减则为1优先级 
	else if(operation=='*'||operation=='/') return 2;//若乘除则为2优先级 
	return 3;
}

int check_space(char operation)
{
	if (operation==' '||(operation>='A'&&operation<='z')) return 1;//为空格返回1，否则为0 
	else return 0;
}

int check_number(char operation)
{
	if (operation>='0'&&operation<='9') return 1;//为数字返回1，否则为0 
	else return 0;
}

void change_perform(char *orgin,char*numbers)
{
//	type_s operators;
//	start_stack(&operators);//初始化栈 
//	int i=0,j=0;
//	for(i=0;orgin[i]!='\0';i++)//在遇到输入式子的结束符前 
//	{
//		if(check_space(orgin[i])) continue;
//			else if(check_number(orgin[i]))
//			{
//				while(check_number(orgin[i]))
//				{
//					outformula[j++]=orgin[i++];//舍去空格 ，将所有数字放进后缀表达式中 
//				}
//			}
//			
//			else if(orgin[i]=='+'||orgin[i]=='-'||orgin[i]=='*'||orgin[i]=='/') push(&operators,orgin[i]);
//			else if(orgin[i]=='(') 	push(&operators,orgin[i]);//前括号则入栈 
//			else if(orgin[i]==')')	//遇到后括号的时候 
//			{
//				while(check_empty(&operators)&&peek(&operators)!='(')//若此时栈不为空且栈顶不为前括号 
//				{
//					outformula[j++]=pop(&operators);//将栈顶操作输出到后缀表达式中 
//					//跳过符号位置，将索引放置到空位置方便输入 
//				}
//				pop(&operators);//否则则入栈 
//			}//将所有运算符推入栈中 
//	}
//	while(!check_empty(&operators))
//		{
//		outformula[j++]=pop(&operators); 
//		
//		}//将运算符逐步弹出栈	
//	
//	outformula[j]='\0';//数组结束符 
//	destory(&operators);//释放内存 
//	
	type_s operators;
	start_stack(&operators);
	int i=0,j=0;
	for (i=0;orgin[i]!='\0';i++)
		{
		while(check_space(orgin[i])) continue;//遇到空格/字母跳过
		if(check_number(orgin[i]))
			{	
			numbers[j++]=orgin[i];		
			} 
		else if(orgin[i]=='+'||orgin[i]=='-'||orgin[i]=='*'||orgin[i]=='/') 
			{
			if(check_empty(&operators)==0)
				{
					if(precedence(orgin[i])<precedence(peek(&operators)))
					{
					numbers[j++]=pop(&operators);
					push(&operators,orgin[i]);
					}
				else 
					{
					push(&operators,orgin[i]);
					}
				}
			else push(&operators,orgin[i]);
			}
		else if(orgin[i]=='(')  push(&operators,orgin[i]);
		else if(orgin[i]==')')
			{
			while(check_empty(&operators)==0)
				{
				if(peek(&operators)=='(') pop(&operators);break;
				numbers[j++]=pop(&operators);
				}
			}
		}
	
	while(check_empty(&operators)==0)
		{
		numbers[j++]=pop(&operators);	
		}
	numbers[j]='\0';
	destory(&operators);
}

float calculate_fix(char *formula) 
{
	type_s value;
	start_stack(&value);
	int i=0;
	float result=0;
	for (i=0;formula[i]!='\0';i++)
		{
		if(check_number(formula[i])) push(&value,formula[i]);
		else
			{
			int a=pop(&value)-'0';//更靠近栈顶 
			int b=pop(&value)-'0';//更靠近栈底 
			switch(formula[i])
				{
				case '+':push(&value,b+a);break;
				case '-':push(&value,b-a);break;
				case '*':push(&value,b*a);break;
				case '/':
					if(a==0) 
					{
					printf("被除数为0！\n");
					exit(1);
					}
				push(&value,b/a);break;
				}
			}
		}
	result=pop(&value);
	destory(&value);
	return result;
			
}

int menu()
{
	int i,choice;
	char order[100];
	for (i=0;i<25;i++)
	{
		printf("*");
	}
	printf("\n");
	printf("*%*s[^._.^]?彡你好！   *\n",4," ");
	printf("选择你的操作：\n");
	printf("1.开始计算！\n");
	printf("2.清屏\n");
	printf("3.退出程序\n"); 
	scanf("%s",&order);//接收字符串防止输入字母错误 
	choice=order[0]-'0';//转换至整型类型数字 
	return choice;
}

void doit_all()
{
	getchar();
	printf("输入你需要计算的算式！，可以包含括号或字母（会跳过）:\n");
	char formula[108];
	char numbers[100];
	gets(formula);
	formula[strlen(formula)]='\0';
	change_perform(formula,numbers);
	printf("后缀表达式：%s\n",numbers);
	float result=calculate_fix(numbers);
	printf("算式结果(保留两位小数)：%.2f\n",result);
	system("pause");
	return;
}

int main() 
{
	int choice=0;
	while(1)
		{
		choice=menu();	
		switch(choice)
			{
			case 1:doit_all();break;
			case 2:system("cls");break;
			case 3:exit(0);break;
			default:break;
			}
		}
	return 0;
		
}









