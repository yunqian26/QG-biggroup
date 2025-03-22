#include<stdio.h>
#define len sizeof(struct chain)
#define null NULL
struct chain{
	struct chain* prev;
	float data;
	struct chain* next;
};//��������ṹ 


struct chain*create()
{
	struct chain* head;
	head=(struct chain*)malloc(len);//������� 
	if (head==null)
		{
		printf("error!\n");
		exit(1);
		}//����ռ�ʧ�� 
	head->next=null;
	head->prev=null;//ָ������ 
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
	p1->prev=null;
	p1->next=null;//����ָ�� 
	p1->data=newvalue;//��ֵ 
	struct chain* nowdic=head;
	while(nowdic->next!=null)//�ҵ�β�ڵ� 
			{
			nowdic=nowdic->next;
			}
	p1->prev=nowdic;//����ڵ� 
	nowdic->next=p1;//��� 
}//β�� 

void dodelete(struct chain* head)
{
	float delete_value;
	printf("��������Ҫɾ������ֵ��");
	scanf("%f",&delete_value);
	struct chain* nowdic=head->next;
	while(nowdic!=null)
		{
		if (nowdic->data ==delete_value)//Ѱ��Ŀ������ 
			{
				if(nowdic->prev)
					{
					nowdic->prev->next=nowdic->next;//���ı�ɾ���ڵ����һ��next�ڵ� 
					}
				if(nowdic->next)
					{
					nowdic->next->prev=nowdic->prev;//���ı�ɾ���ڵ����һ��prev�ڵ� 
					}
				printf("��ɾ��%f\n",delete_value);
				return;
			}
		else nowdic=nowdic->next;//Ѱ��Ŀ�� 
		}
		printf("δ�ҵ�%f\n",delete_value);
}//ɾ��ָ������ 

void check_cycle(struct chain* head)
{
	if(head==null||head->next==null)
		{
		printf("�ǻ���\n");
		return;//��Ȼ���ǻ� 
		}
	struct chain* slowchecker=head->next;//�� 
	struct chain* fastchecker=head->next->next;//�� 
	
	while((fastchecker!=null)&&(fastchecker->next))
		{
		if(slowchecker==fastchecker)
			{
			printf("�ɻ���\n");
			return;//�ɻ��� 
			}
		slowchecker=slowchecker->next;//��һ�� 
		fastchecker=fastchecker->next->next;//������	
		}
	printf("�ǻ���\n");
	
}//���ɻ� 

void print(struct chain* head)
{
	struct chain* nowdic=head->next;
	printf("����Ϊ��\n");
	while(nowdic != null)
		{
		printf("%f <-> ",nowdic->data);
		nowdic=nowdic->next;//���� 
		}
	printf("NULL\n");
}//��ӡ 

void change_singleanddouble(struct chain* head)
{
	if(head==null||head->next==null)//�жϳ����Ƿ��㹻 
		{
		printf("too short!\n");
		return;
		}
	struct chain* nowdic=head->next;
	while(nowdic!=null&&nowdic->next!=null)
		{
		float tem=nowdic->data;
		nowdic->data=nowdic->next->data;
		nowdic->next->data=tem;//��ż���� 
		nowdic=nowdic->next->next;//������һ�Խڵ� 
		}
	
	
}//��ż���� 

void find_middle(struct chain* head) 
{
    if(head==NULL||head->next==NULL) //�жϳ��� 
		{
        printf("too short!\n");
        return;
   		}
    struct chain* slow = head;//��ָ�� 
    struct chain* fast = head;//��ָ�� 
    while(fast!=NULL&&fast->next!=NULL) 
		{
        slow=slow->next; //��һ�� 
        fast=fast->next->next;//������ 
   		}
    if (fast!=NULL)     
		{
        slow=slow->next;//�������������������ָ����Ҫ���ƶ�һ��
    	}
    printf("mid= %f\n",slow->data);
}//���� 

void reverse(struct chain* head,struct chain** head_location)
{
	if(head==null||head->next)
		{
		*head_location=head;
		return;
		}
		reverse(head->prev,head_location);//�ݹ齻�� 
	struct chain* tem=head->prev;//����ָ�룬ǰ��Ϊ�󣬺�Ϊǰ  
	head->prev=head->next;
	head->next=tem;
	
	if(head->prev==null)
		{
		*head_location=head;//�ߵ�ͷ������ͷ��� 
		}

}//�ݹ鷴ת 

void reversenon(struct chain** head) {
    if (*head==null||(*head)->next==null )
		{
        return;
    	}
    struct chain* nowdic = *head;//����ͷ��� 
    struct chain* tem = NULL;//�������� 
    
    while (nowdic != NULL) 
		{
        tem = nowdic->prev;//����ǰ�ڵ����һ���ڵ�洢 
        nowdic->prev = nowdic->next;//ǰ��ָ�뻥�� 
        nowdic->next = tem;//���� 
        nowdic = nowdic->prev;//���� 
    	}
    if (tem != NULL) 
		{
        *head = tem->prev;//����ͷ��� 
    	}
}//�ǵݹ鷴ת 

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
	printf("4.����Ƿ�ɻ�\n");
	printf("5.��żλ�ý���\n");
	printf("6.�ݹ鷴ת\n");
	printf("7.�ǵݹ鷴ת���ƺ��������ʱ�޷���������⣩\n");
	printf("8.Ѱ���е�\n");
	printf("9.�˳�����\n");
	
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
	system("cls");
	switch(choice)
		{
		case 1:print(head);break;
		case 2:doinsert(head);break;
		case 3:dodelete(head);break;
		case 4:check_cycle(head);break;
		case 5:change_singleanddouble(head);break;
		case 6:reverse(head,&head);break;
		case 7:reversenon(&head);break;
		case 8:find_middle(head);
		case 9:exit(0);
		default:break;
		} 
	}
	
	system("pause"); 
}

























