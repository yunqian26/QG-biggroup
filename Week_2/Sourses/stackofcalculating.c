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
		printf("��ջ��û��Ԫ��\n");
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
		printf("��ջ��û��Ԫ��\n");
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
	return 0;
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

void change_perform(char *orgin,char*outformula)
{
	type_s operators;
	start_stack(&operators);//��ʼ��ջ 
	int i=0,j=0;
	for(i=0;orgin[i]!='\0';i++)//����������ʽ�ӵĽ�����ǰ 
	{
		if(check_space(orgin[i])) continue;
			else if(check_number(orgin[i]))
			{
				while(check_number(orgin[i]))
				{
					outformula[j++]=orgin[i++];//��ȥ�ո� �����������ַŽ���׺���ʽ�� 
				}
			}
			else if(orgin[i]=='(') 	push(&operators,orgin[i]);//ǰ��������ջ 
			else if(orgin[i]==')')	//���������ŵ�ʱ�� 
			{
				while(check_empty(&operators)&&peek(&operators)!='(')//����ʱջ��Ϊ����ջ����Ϊǰ���� 
				{
					outformula[j++]=pop(&operators);//��ջ�������������׺���ʽ�� 
					j++;//��������λ�ã����������õ���λ�÷������� 
				}
				push(&operators,orgin[i]);//��������ջ 
			}//���������������ջ�� 
	}
	while(!check_empty(&operators))
		{
		outformula[j++]=pop(&operators); 
		j++;
		}//��������𲽵���ջ	
	
	outformula[j]='\0';//��������� 
	destory(&operators);//�ͷ��ڴ� 
	
}

float calculate_fix(char *formula_back) 
{
	type_s value;
	start_stack(&value);
	int i=0;
	float result;
	while(formula_back[i]!='\0')
		{
		if (check_space(formula_back[i])) i++;
		else if(check_number(formula_back[i]))
			{
			int num=0;
			while(check_number(formula_back[i]))
				{
				num=num*10+formula_back[i];
				i++;
				}
			push(&value,num);
			}
		else
			{
			int a=pop(&value);//������ջ�� 
			int b=pop(&value);//������ջ�� 
			switch(formula_back[i])
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
			i++;
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
	char back_formula[100];
	gets(formula);
	formula[strlen(formula)-1]='\0';
	change_perform(formula,back_formula);
	printf("��׺���ʽ��%s\n",back_formula);
	float result=calculate_fix(back_formula);
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









