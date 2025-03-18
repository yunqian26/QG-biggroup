#include<stdio.h>
#define len sizeof(struct chain)
#define null NULL
struct chain{
	float data;
	struct chain* next;
};//创建链表结构 

struct chain* create()
{
	struct chain* head;
	head=(struct chain*)malloc(len);//申请分配 
	if (head==null)
		{
		printf("error!\n");
		exit(1);
		}//分配空间失败 
	head->next=null;//指针悬空 
	return head;
}//创建链表 

void doinsert(struct chain* head,float newvalue)
{
	struct chain* p1;
	p1=(struct chain*)malloc(len);
	if (p1==null)
		{
		printf("error!\n");
		exit(1);
		}
	p1->next=null;//悬空指针 
	p1->data=newvalue;//赋值 
	struct chain* nowdic=head;
	while(nowdic->next!=null)//找到尾节点 
			{
			nowdic=nowdic->next;
			}
	nowdic->next=p1;//插点 
}//尾插 

void dodelete(struct chain* head,float delete_value)
{
	struct chain* nowdic=head;
	if(head->data==delete_value)
		{
		struct chain* forfree=head;
		head=head->next;
		free(forfree);
		}
	while(nowdic->next != null)
		{
		if(nowdic->next->data==delete_value)
			{
			struct chain*tem=nowdic->next;
			nowdic->next=nowdic->next->next;
			free(tem);
			printf("已删除:%f\n",delete_value);
			return;	
			}	
			nowdic=nowdic->next;
		}
	
}//删除指定数据 

void print(struct chain* head)
{
	struct chain* nowdic=head->next;
	while(nowdic != null)
		{
		printf("%f -> ",nowdic->data);
		nowdic=nowdic->next;//遍历 
		}
	printf("NULL\n");
}//打印 

int main()
{
	struct chain* head=create();
	doinsert(head,1.5);
	doinsert(head,8.5);
	doinsert(head,2.5);
	doinsert(head,7.5);
	doinsert(head,4.9);
	doinsert(head,7.1);
	print(head);
	dodelete(head,7.5); 
	print(head); 

}
