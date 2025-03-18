#include<stdio.h>
#define len sizeof(struct chain)
#define null NULL
struct chain{
	struct chain* prev;
	float data;
	struct chain* next;
};//创建链表结构 


struct chain*create()
{
	struct chain* head;
	head=(struct chain*)malloc(len);//申请分配 
	if (head==null)
		{
		printf("error!\n");
		exit(1);
		}//分配空间失败 
	head->next=null;
	head->prev=null;//指针悬空 
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
	p1->prev=null;
	p1->next=null;//悬空指针 
	p1->data=newvalue;//赋值 
	struct chain* nowdic=head;
	while(nowdic->next!=null)//找到尾节点 
			{
			nowdic=nowdic->next;
			}
	p1->prev=nowdic;//插入节点 
	nowdic->next=p1;//插点 
}//尾插 

void dodelete(struct chain* head,float delete_value)
{
	struct chain* nowdic=head->next;
	while(nowdic!=null)
		{
		if (nowdic->data ==delete_value)//寻找目标数据 
			{
				if(nowdic->prev)
					{
					nowdic->prev->next=nowdic->next;//更改被删除节点的上一个next节点 
					}
				if(nowdic->next)
					{
					nowdic->next->prev=nowdic->prev;//更改被删除节点的下一个prev节点 
					}
				printf("已删除%f\n",delete_value);
				return;
			}
		else nowdic=nowdic->next;//寻找目标 
		}
		printf("未找到%f\n",delete_value);
}//删除指定数据 

int check_cycle(struct chain* head)
{
	if(head==null||head->next==null)
		{
		return 0;//显然不是环 
		}
	struct chain* slowchecker=head->next;//慢 
	struct chain* fastchecker=head->next->next;//快 
	
	while((fastchecker!=null)&&(fastchecker->next))
		{
		if(slowchecker==fastchecker)
			{
			return 1;//成环！ 
			}
		slowchecker=slowchecker->next;//走一步 
		fastchecker=fastchecker->next->next;//走两步	
		}
	return 0;
	
}//检查成环 

void print(struct chain* head)
{
	struct chain* nowdic=head->next;
	while(nowdic != null)
		{
		printf("%f <-> ",nowdic->data);
		nowdic=nowdic->next;//遍历 
		}
	printf("NULL\n");
}//打印 

void change_singleanddouble(struct chain* head)
{
	if(head==null||head->next==null)//判断长度是否足够 
		{
		printf("too short!\n");
		return;
		}
	struct chain* nowdic=head->next;
	while(nowdic!=null&&nowdic->next!=null)
		{
		float tem=nowdic->data;
		nowdic->data=nowdic->next->data;
		nowdic->next->data=tem;//奇偶交换 
		nowdic=nowdic->next->next;//步入下一对节点 
		}
	
	
}//奇偶交换 

void find_middle(struct chain* head) 
{
    if(head==NULL||head->next==NULL) //判断长度 
		{
        printf("too short!\n");
        return;
   		}
    struct chain* slow = head;//慢指针 
    struct chain* fast = head;//快指针 
    while(fast!=NULL&&fast->next!=NULL) 
		{
        slow=slow->next; //走一步 
        fast=fast->next->next;//走两步 
   		}
    if (fast!=NULL)     
		{
        slow=slow->next;//如果链表长度是奇数，慢指针需要再移动一次
    	}
    printf("mid= %f\n",slow->data);
}//找中 

void reverse(struct chain* head,struct chain** head_location)
{
	if(head==null)
		{
		return;
		}
		
	struct chain* tem=head->prev;//交换指针，前换为后，后换为前  
	head->prev=head->next;
	head->next=tem;
	
	if(head->prev==null)
		{
		*head_location=head;//走到头，更新头结点 
		}
	else
		{
		reverse(head->prev,head_location);//递归交换 
		}
}//递归反转 

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
        nowdic->next = tem;//交换 
        nowdic = nowdic->prev;//遍历 
    	}
    if (tem != NULL) 
		{
        *head = tem->prev;//更新头结点 
    	}
}//非递归反转 

int main()
{
	struct chain* head=create();
	doinsert(head,1.5);
	doinsert(head,8.5);
	doinsert(head,2.5);
	doinsert(head,7.5);
	doinsert(head,4.9);
	doinsert(head,7.1);//输入数据 
	if (check_cycle(head)==0)
		{
			printf("非环\n");
			print(head);
			dodelete(head,7.5); 
			find_middle(head);
			change_singleanddouble(head); 
			print(head);
			find_middle(head);
		}
	system("pause"); 
}

























