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

void doinsert(struct chain* head,float newvalue)
{
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

void dodelete(struct chain* head,float delete_value)
{
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

int check_cycle(struct chain* head)
{
	if(head==null||head->next==null)
		{
		return 0;//��Ȼ���ǻ� 
		}
	struct chain* slowchecker=head->next;//�� 
	struct chain* fastchecker=head->next->next;//�� 
	
	while((fastchecker!=null)&&(fastchecker->next))
		{
		if(slowchecker==fastchecker)
			{
			return 1;//�ɻ��� 
			}
		slowchecker=slowchecker->next;//��һ�� 
		fastchecker=fastchecker->next->next;//������	
		}
	return 0;
	
}//���ɻ� 

void print(struct chain* head)
{
	struct chain* nowdic=head->next;
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
	if(head==null)
		{
		return;
		}
		
	struct chain* tem=head->prev;//����ָ�룬ǰ��Ϊ�󣬺�Ϊǰ  
	head->prev=head->next;
	head->next=tem;
	
	if(head->prev==null)
		{
		*head_location=head;//�ߵ�ͷ������ͷ��� 
		}
	else
		{
		reverse(head->prev,head_location);//�ݹ齻�� 
		}
}//�ݹ鷴ת 

void reversenon(struct chain** head) {
    if (*head == NULL )
		{
        return;
    	}
    struct chain* nowdic = *head;
    struct chain* tem = NULL;
    while (nowdic != NULL) 
		{
        tem = nowdic->prev;
        nowdic->prev = nowdic->next;
        nowdic->next = tem;//���� 
        nowdic = nowdic->prev;//���� 
    	}
    if (tem != NULL) 
		{
        *head = tem->prev;//����ͷ��� 
    	}
}//�ǵݹ鷴ת 

int main()
{
	struct chain* head=create();
	doinsert(head,1.5);
	doinsert(head,8.5);
	doinsert(head,2.5);
	doinsert(head,7.5);
	doinsert(head,4.9);
	doinsert(head,7.1);//�������� 
	if (check_cycle(head)==0)
		{
			printf("�ǻ�\n");
			print(head);
			dodelete(head,7.5); 
			find_middle(head);
			change_singleanddouble(head); 
			print(head);
			find_middle(head);
		}
	system("pause"); 
}

























