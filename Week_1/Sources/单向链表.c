#include<stdio.h>
#define len sizeof(struct chain)
#define null NULL
struct chain{
	float data;
	struct chain* next;
};//��������ṹ 

struct chain* create()
{
	struct chain* head;
	head=(struct chain*)malloc(len);//������� 
	if (head==null)
		{
		printf("error!\n");
		exit(1);
		}//����ռ�ʧ�� 
	head->next=null;//ָ������ 
	return head;
}//�������� 

void doinsert(struct chain* head)
{
	float newvalue;
	printf("��������Ҫ�������ֵ��");
	scanf("%f",&newvalue);
	struct chain* p1;
	p1=(struct chain*)malloc(len);
	if (p1==null)
		{
		printf("error!\n");
		exit(1);
		}
	p1->next=null;//����ָ�� 
	p1->data=newvalue;//��ֵ 
	struct chain* nowdic=head;
	while(nowdic->next!=null)//�ҵ�β�ڵ� 
			{
			nowdic=nowdic->next;
			}
	nowdic->next=p1;//��� 
}//β�� 

void dodelete(struct chain* head)
{
	float delete_value;
	printf("��������Ҫɾ������ֵ��");
	scanf("%f",&delete_value);
	struct chain* nowdic=head;
	if(head->data==delete_value)//��ɾ����Ϊͷ��� 
		{
		struct chain* forfree=head;
		head=head->next;//�ƶ�ͷ�ڵ� 
		free(forfree);//�ͷ��ڴ� 
		}
	while(nowdic->next != null)
		{
		if(nowdic->next->data==delete_value)//�ҵ�Ŀ������ 
			{
			struct chain*tem=nowdic->next;
			nowdic->next=nowdic->next->next;//����ɾ����ǰһ���ڵ��ָ����� 
			free(tem);//�ͷ��ڴ� 
			printf("��ɾ��:%f\n",delete_value);
			return;	
			}	
			nowdic=nowdic->next;//���� 
		}
	
}//ɾ��ָ������ 

void print(struct chain* head)
{
	struct chain* nowdic=head->next;
	while(nowdic != null)
		{
		printf("%f -> ",nowdic->data);//��ӡ 
		nowdic=nowdic->next;//���� 
		}
	printf("NULL\n");
}//��ӡ 

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
	printf("1.��ʾ��ǰ����\n");
	printf("2.����ڵ�(β��)\n");
	printf("3.ɾ��ָ��Ԫ��\n");
	printf("4.�˳�����\n");
	printf("5.����qwq\n");
	
	scanf("%s",&order);//�����ַ�����ֹ������ĸ���� 
	choice=order[0]-'0';//ת���������������� 
	return choice;
}

int main()
{
	struct chain* head=create();
	int choice=0;
	while(1)
	{
	choice=menu();
	switch(choice)
		{
		case 1:print(head);break;
		case 2:doinsert(head);break;
		case 3:dodelete(head);break;
		case 4:exit(0);
		case 5:system("cls");break;
		default:break;
		} 
	}
	
	
	system("pause"); 

}
