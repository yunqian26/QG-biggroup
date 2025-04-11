#include <stdio.h>

/*
��Ŀ���ָ����������飬����Ҫ�ҵ���3С����
*/

/*
����˼·��˼·��ʹ�ÿ����еĻ��ַ�ʹ�����ǿ�����ʱ�临�Ӷ�ΪO(nlogn)��������ҵ��ض���λ����
*/

//����
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//��ӡ
void printArr(int arr[],int n){
	int i;
	for (i = 0;i < n;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
} 

//�������顢����������±�(low)���������ұ��±�(high)
int partition(int arr[], int low, int high) {
	//ѡ�����һ��Ԫ����Ϊ֧�㣬��ʵѡ���һ��Ԫ��Ҳ���� 
    int pivot = arr[high];
    //i���ڱ��С��֧��ı߽磬��ʼ��Ϊ��ʼ�±� - 1������û�ҵ�С�������Ԫ��ʱ�ı߽�
    int i = (low - 1);

    // ��������ʼ�±굽�����ڶ����±��Ԫ��
    int j;
    for (j = low; j <= high - 1; j++) {
        // �����ǰԪ��С��֧�� 
        if (arr[j] < pivot) {
            i++;
            // ������ǰС��֧���Ԫ�غͱ߽���Ԫ��
            swap(&arr[i], &arr[j]);
        }
    }
    // ��֧��ŵ���ȷ��λ��
    swap(&arr[i + 1], &arr[high]);
    // ����֧���������ڵ��±�λ��
    return (i + 1);
}

//�ҵ���kС�����ĺ���
//����ͨ���ݹ鲻����С���ҷ�Χ��ֱ���ҵ���kС����
int kSmallest(int arr[], int low, int high, int k) {
    //ȷ��kֵ����0��������Ԫ�ظ�����Χ��
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);

        //���֧���λ�øպ��ǵ�kС��λ�ã�λ�ô�0��ʼ����������Ҫ��ȥ��ʼ�±�low��
        if (pivotIndex - low == k - 1) {
            //ֱ�ӷ���֧���Ӧ��ֵ�����ҵ��˵�kС����
            return arr[pivotIndex];
        } 
        //���֧��λ���ڵ�kС��λ���ұߣ�˵����kС������֧����ߵ���������
        else if (pivotIndex - low > k - 1) {
            //�ݹ���֧����ߵ�������������ҵ�kС����
            return kSmallest(arr, low, pivotIndex - 1, k);
        } 
        //���֧��λ���ڵ�kС��λ����ߣ�˵����kС������֧���ұߵ���������
        else {
            //�ݹ���֧���ұߵ����������ҵ�kС������ͬʱ����kֵ����Ϊ���ұ����������ҵ������λ���ˣ�
            return kSmallest(arr, pivotIndex + 1, high, k - (pivotIndex - low + 1));
        }
    }
    //���kֵ��Ч������ -1 ��ʾ����
    return -1; 
}

int main() {
    int arr[] = {15, 22, 18, 4, 13, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    //��ĿҪ���ҵ�����С���� 
    int k = 3;
    //�ȱ������飬Ȼ���ٴ�ӡ����С���� 
    printArr(arr,n);
    int result = kSmallest(arr, 0, n - 1, k);
    if (result != -1) {
        printf("�� %d С������: %d\n", k, result);
    } else {
        printf("������Ч\n");
    }
    system("pause");
    return 0;
} 
