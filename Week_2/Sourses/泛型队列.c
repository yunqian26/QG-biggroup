#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������нڵ�ṹ
typedef struct Node 
{
    void* data; // ʹ��void*ָ��洢����
    struct Node* next; // ָ����һ���ڵ��ָ��
} Node;

// ������нṹ
typedef struct 
{
    Node* front; // ���е�ͷ�ڵ�
    Node* rear; // ���е�β�ڵ�
    int size; // ���еĴ�С
} Queue;

// ��������
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

// �ж϶����Ƿ�Ϊ��
int isEmpty(Queue* queue) 
{
    return queue->size==0;
}

// ��ȡ���еĴ�С
int size(Queue* queue) 
{
    return queue->size;
}

// ��Ӳ���
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

// ���Ӳ���
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

// �鿴����ͷ����Ԫ��
void* peek(Queue* queue) 
{
    if (isEmpty(queue)) 
	{
        fprintf(stderr, "Queue is empty\n");
        return NULL;
    }
    return queue->front->data;
}

// ���ٶ���
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
    printf("*%*s[^._.^]?����ã�   *\n", 4, " ");
    printf("ѡ����Ĳ�����\n");
    printf("1.���\n");
    printf("2.����\n");
    printf("3.�鿴����ͷ\n");
    printf("4.�˳�����\n");
    scanf("%s", order); // �����ַ�����ֹ������ĸ����
    choice = order[0] - '0'; // ת����������������
    return choice;
}

// ���Ժ���
int main() 
{
    Queue* queue=createQueue();

    while (1) 
	{
        int choice=menu();
        switch (choice) 
		{
            case 1:
                printf("ѡ����Ҫ��ӵ����ͣ�\n");
                printf("1.����\n");
                printf("2.�ַ�\n");
                int sub_choice=0;
                scanf("%d", &sub_choice);
                printf("������Ҫ��ӵ�Ԫ�أ�\n");
                if (sub_choice==1) 
				{
                    float num;
                    scanf("%f", &num);
                    enqueue(queue, &num);
                } else if (sub_choice==2) 
				{
                    char chara;
                    scanf(" %c", &chara); // ע��ǰ��Ŀո������������з�
                    enqueue(queue, &chara);
                }
                break;
            case 2:
                if (!isEmpty(queue)) 
				{
                    void* data=dequeue(queue);
                    if (data!=NULL) 
					{
                        printf("��Ԫ���ѳ��ӣ�%c\n", *(char*)data);
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
                printf("error�����������롣\n");
                break;
        }
    }

    return 0;
}
