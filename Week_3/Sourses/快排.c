#include<stdio.h>

/*
�������򣬼�����֪һ�����飬��Ҫ����ѡȡһ������Ϊ֧��(Ӣ�ľ���pivto)������low=0��high=n��low++��high-- 
�Ȼ���С�ķ���ߣ���ķ��ұߣ����֧�����low��high�غϵ�λ�� ...��֮�����Խ���������ã����ҷǳ��� 
*/
 
//��ӡ
void printArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n'); 
} 
 
// 
int partition(int arr[],int low,int high){
	//���ÿ���ѡȡ��ֱ�ӽ�low���������Ԫ����Ϊ���� 
	int pivto = arr[low];
	while(low < high){
		while(low<high && arr[high] >= pivto){
			high--;
		}
		arr[low] = arr[high];
		while(low<high && arr[low] <= pivto){
			low++;
	    }
		arr[high]=arr[low];
	}
	arr[low]=pivto;      //��ʵд��a[high]=pivtoҲһ������Ϊlow����high�غ���
	 
	//�����Ƿ���low����high�����ԣ��������low��high���غ� 
	return low;
}

//�ָ��������֧�������
void QuickSort(int arr[],int low,int high){
	//����Ҫ�����ж� 
	if(low < high){
		//���÷ָ�(partition)������������������þ����ҳ�pivto����һ������֮��������λ�ã�������λ�÷��ظ�pivto(֧��)
		//ֻ�еõ���position֮����ܽ��еݹ����� 
		int position = partition(arr,low,high);
		QuickSort(arr,low,position-1);
		QuickSort(arr,position+1,high);
	}
} 

int main(){
	int arr[] = {1,7,4,9,20,14,30,27,19,24};
	int n = 10;
	printf("ԭ����:\n");
	printArr(arr,n);
	//����QuickSort����,һ��ʼlow����������ߣ�right���������ұ� 
	QuickSort(arr,0,n-1);
	printf("�������������:\n");
	printArr(arr,n);
	system("pause");
	return 0;
}
