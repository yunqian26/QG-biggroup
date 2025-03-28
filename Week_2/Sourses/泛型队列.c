#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义队列节点结构
typedef struct Node 
{
    void* data; // 使用void*指针存储数据
    struct Node* next; // 指向下一个节点的指针
} Node;

// 定义队列结构
typedef struct 
{
    Node* front; // 队列的头节点
    Node* rear; // 队列的尾节点
    int size; // 队列的大小
} Queue;

// 创建队列
Queue* createQueue()
{
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    if (queue==NULL) 
	{
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE);
    }
    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
    return queue;
}

// 判断队列是否为空
int isEmpty(Queue* queue) 
{
    return queue->size==0;
}

// 获取队列的大小
int size(Queue* queue) 
{
    return queue->size;
}

// 入队操作
void enqueue(Queue* queue, void* data) 
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) 
	{
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data=data;
    newNode->next=NULL;

    if (queue->rear==NULL) 
	{
        queue->front=newNode;
        queue->rear=newNode;
    } 
	else 
	{
        queue->rear->next=newNode;
        queue->rear=newNode;
    }
    queue->size++;
}

// 出队操作
void* dequeue(Queue* queue) 
{
    if (isEmpty(queue)) 
	{
        fprintf(stderr, "Queue is empty\n");
        return NULL;
    }
    Node* temp=queue->front;
    void* data=temp->data;
    queue->front=queue->front->next;
    if (queue->front==NULL) 
	{
        queue->rear=NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

// 查看队列头部的元素
void* peek(Queue* queue) 
{
    if (isEmpty(queue)) 
	{
        fprintf(stderr, "Queue is empty\n");
        return NULL;
    }
    return queue->front->data;
}

// 销毁队列
void destroyQueue(Queue* queue)
{
    while (!isEmpty(queue)) 
	{
        dequeue(queue);
    }
    free(queue);
}

int menu() {
    int i, choice;
    char order[100];
    for (i = 0; i < 25; i++) 
	{
        printf("*");
    }
    printf("\n");
    printf("*%*s[^._.^]?彡你好！   *\n", 4, " ");
    printf("选择你的操作：\n");
    printf("1.入队\n");
    printf("2.出队\n");
    printf("3.查看队列头\n");
    printf("4.退出程序\n");
    scanf("%s", order); // 接收字符串防止输入字母错误
    choice = order[0] - '0'; // 转换至整型类型数字
    return choice;
}

// 测试函数
int main() 
{
    Queue* queue=createQueue();

    while (1) 
	{
        int choice=menu();
        switch (choice) 
		{
            case 1:
                printf("选择需要入队的类型：\n");
                printf("1.数字\n");
                printf("2.字符\n");
                int sub_choice=0;
                scanf("%d", &sub_choice);
                printf("输入需要入队的元素：\n");
                if (sub_choice==1) 
				{
                    float num;
                    scanf("%f", &num);
                    enqueue(queue, &num);
                } else if (sub_choice==2) 
				{
                    char chara;
                    scanf(" %c", &chara); // 注意前面的空格，用于跳过换行符
                    enqueue(queue, &chara);
                }
                break;
            case 2:
                if (!isEmpty(queue)) 
				{
                    void* data=dequeue(queue);
                    if (data!=NULL) 
					{
                        printf("该元素已出队：%c\n", *(char*)data);
                    }
                }
                break;
            case 3:
                if (!isEmpty(queue)) 
				{
                    void* data=peek(queue);
                    if (data!=NULL) 
					{
                        printf("Peek: %d\n", *(int*)data);
                    }
                }
                break;
            case 4:
                destroyQueue(queue);
                exit(0);
            default:
                printf("error，请重新输入。\n");
                break;
        }
    }

    return 0;
}
