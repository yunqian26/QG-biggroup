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

void doinsert(struct chain* head,float newvalue)
{
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

void dodelete(struct chain* head,float delete_value)
{
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

int main()
{
	struct chain* head=create();
	doinsert(head,1.5);
	doinsert(head,8.5);
	doinsert(head,2.5);
	doinsert(head,7.5);
	doinsert(head,4.9);
	doinsert(head,7.1);//�������� 
	print(head);
	dodelete(head,7.5); 
	print(head); 
	system("pause"); 

}
