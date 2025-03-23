#include<stdio.h>
#include<string.h>
#define null NULL
typedef struct
{
	char data;
	struct stack* next;
}type; //�ڵ�ṹ�� 

typedef struct
{
	type *top;
}type_s;//ջ��ָ�� 

void start_stack(type_s *stack)
{
	stack->top=null;//��ʼ��ջ 
}

int check_empty(type_s *stack)
{
	if(stack->top==null) return 1;//��ջ��Ϊ����ջΪ�� 
	else return 0;//��ջ����Ϊ����ջ��Ϊ��
	 
}

void push(type_s *stack,char value)
{
	type *newpoint=(type*)malloc(sizeof(type));//��������ڴ� 
	if(newpoint==null) 
	{
		printf("����ռ�ʧ��\n");
		exit(1);
	}
	newpoint->data=value;//�������ݴ���ڵ��� 
	newpoint->next=stack->top;//����������ջ�� 
	stack->top=newpoint;//�ƶ�ջ��ָ�� 
}

char pop(type_s *stack)
{
	if(check_empty(stack))
	{
		printf("��ջ��û��Ԫ��(pop)\n");
		return;
	}
	type* tem=stack->top;//�洢ջ��ָ�� 
	char value=tem->data;//ȡ��ջ������ 
	stack->top=tem->next;//�ƶ�ջ��ָ�� 
	free(tem);//�ͷ��ڴ� 
	return value;//����ջ������ 
}

char peek(type_s *stack)
{
	if(check_empty(stack))
	{
		printf("��ջ��û��Ԫ��(peek)\n");
		return;
	}
	return stack->top->data;//����ջ������ 
}

void destory(type_s *stack)
{
	while(!check_empty(stack))
	{
		pop(stack);//����ջ��������ֱ��ջΪ�� 
	}
}

void print(type_s *stack)
{
	printf("ջ��");
	type *nowpoint=stack->top;//��ջ����ʼ��� 
	while(nowpoint!=null)
	{
		printf("%c",nowpoint->next); //��� 
		nowpoint=nowpoint->next;//�ƶ� 
		
	} 
	stack->top=null;//ָ������ 
}

int precedence(char operation)
{
	if(operation=='+'||operation=='-') return 1;//���Ӽ���Ϊ1���ȼ� 
	else if(operation=='*'||operation=='/') return 2;//���˳���Ϊ2���ȼ� 
	return 3;
}

int check_space(char operation)
{
	if (operation==' '||(operation>='A'&&operation<='z')) return 1;//Ϊ�ո񷵻�1������Ϊ0 
	else return 0;
}

int check_number(char operation)
{
	if (operation>='0'&&operation<='9') return 1;//Ϊ���ַ���1������Ϊ0 
	else return 0;
}

void change_perform(char *orgin,char*numbers)
{
//	type_s operators;
//	start_stack(&operators);//��ʼ��ջ 
//	int i=0,j=0;
//	for(i=0;orgin[i]!='\0';i++)//����������ʽ�ӵĽ�����ǰ 
//	{
//		if(check_space(orgin[i])) continue;
//			else if(check_number(orgin[i]))
//			{
//				while(check_number(orgin[i]))
//				{
//					outformula[j++]=orgin[i++];//��ȥ�ո� �����������ַŽ���׺���ʽ�� 
//				}
//			}
//			
//			else if(orgin[i]=='+'||orgin[i]=='-'||orgin[i]=='*'||orgin[i]=='/') push(&operators,orgin[i]);
//			else if(orgin[i]=='(') 	push(&operators,orgin[i]);//ǰ��������ջ 
//			else if(orgin[i]==')')	//���������ŵ�ʱ�� 
//			{
//				while(check_empty(&operators)&&peek(&operators)!='(')//����ʱջ��Ϊ����ջ����Ϊǰ���� 
//				{
//					outformula[j++]=pop(&operators);//��ջ�������������׺���ʽ�� 
//					//��������λ�ã����������õ���λ�÷������� 
//				}
//				pop(&operators);//��������ջ 
//			}//���������������ջ�� 
//	}
//	while(!check_empty(&operators))
//		{
//		outformula[j++]=pop(&operators); 
//		
//		}//��������𲽵���ջ	
//	
//	outformula[j]='\0';//��������� 
//	destory(&operators);//�ͷ��ڴ� 
//	
	type_s operators;
	start_stack(&operators);
	int i=0,j=0;
	for (i=0;orgin[i]!='\0';i++)
		{
		while(check_space(orgin[i])) continue;//�����ո�/��ĸ����
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
			int a=pop(&value)-'0';//������ջ�� 
			int b=pop(&value)-'0';//������ջ�� 
			switch(formula[i])
				{
				case '+':push(&value,b+a);break;
				case '-':push(&value,b-a);break;
				case '*':push(&value,b*a);break;
				case '/':
					if(a==0) 
					{
					printf("������Ϊ0��\n");
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
	printf("*%*s[^._.^]?����ã�   *\n",4," ");
	printf("ѡ����Ĳ�����\n");
	printf("1.��ʼ���㣡\n");
	printf("2.����\n");
	printf("3.�˳�����\n"); 
	scanf("%s",&order);//�����ַ�����ֹ������ĸ���� 
	choice=order[0]-'0';//ת���������������� 
	return choice;
}

void doit_all()
{
	getchar();
	printf("��������Ҫ�������ʽ�������԰������Ż���ĸ����������:\n");
	char formula[108];
	char numbers[100];
	gets(formula);
	formula[strlen(formula)]='\0';
	change_perform(formula,numbers);
	printf("��׺���ʽ��%s\n",numbers);
	float result=calculate_fix(numbers);
	printf("��ʽ���(������λС��)��%.2f\n",result);
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









