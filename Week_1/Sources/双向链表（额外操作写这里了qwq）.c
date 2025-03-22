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

void doinsert(struct chain* head)
{
	float newvalue;
	printf("请输入需要插入的数值：");
	scanf("%f",&newvalue);
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

void dodelete(struct chain* head)
{
	float delete_value;
	printf("请输入需要删除的数值：");
	scanf("%f",&delete_value);
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

void check_cycle(struct chain* head)
{
	if(head==null||head->next==null)
		{
		printf("非环！\n");
		return;//显然不是环 
		}
	struct chain* slowchecker=head->next;//慢 
	struct chain* fastchecker=head->next->next;//快 
	
	while((fastchecker!=null)&&(fastchecker->next))
		{
		if(slowchecker==fastchecker)
			{
			printf("成环！\n");
			return;//成环！ 
			}
		slowchecker=slowchecker->next;//走一步 
		fastchecker=fastchecker->next->next;//走两步	
		}
	printf("非环！\n");
	
}//检查成环 

void print(struct chain* head)
{
	struct chain* nowdic=head->next;
	printf("链表为：\n");
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
	if(head==null||head->next)
		{
		*head_location=head;
		return;
		}
		reverse(head->prev,head_location);//递归交换 
	struct chain* tem=head->prev;//交换指针，前换为后，后换为前  
	head->prev=head->next;
	head->next=tem;
	
	if(head->prev==null)
		{
		*head_location=head;//走到头，更新头结点 
		}

}//递归反转 

void reversenon(struct chain** head) {
    if (*head==null||(*head)->next==null )
		{
        return;
    	}
    struct chain* nowdic = *head;//导入头结点 
    struct chain* tem = NULL;//悬空暂用 
    
    while (nowdic != NULL) 
		{
        tem = nowdic->prev;//将当前节点的上一个节点存储 
        nowdic->prev = nowdic->next;//前后指针互换 
        nowdic->next = tem;//交换 
        nowdic = nowdic->prev;//遍历 
    	}
    if (tem != NULL) 
		{
        *head = tem->prev;//更新头结点 
    	}
}//非递归反转 

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
	printf("1.显示当前链表\n");
	printf("2.插入节点(尾插)\n");
	printf("3.删除指定元素\n");
	printf("4.检查是否成环\n");
	printf("5.奇偶位置交换\n");
	printf("6.递归反转\n");
	printf("7.非递归反转（似乎会出现暂时无法解决的问题）\n");
	printf("8.寻找中点\n");
	printf("9.退出程序\n");
	
	scanf("%s",&order);//接收字符串防止输入字母错误 
	choice=order[0]-'0';//转换至整型类型数字 
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

























