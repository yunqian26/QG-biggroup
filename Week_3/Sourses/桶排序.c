#include<stdio.h>
#include<stdlib.h>

/*
��������(Ͱ����):���������ǲ��ñȽϵ����򷽷�����ͼ�����͵Ļ���ͦ�򵥵ģ������Ҿ��ô���д�������鷳��
�򵥽�����һ��ʼ���ҳ������е��������Ȼ���������������λ����������λ��������Ҫ���е�������
������������λ��֮�󣬾͵ö���Ͱ������˵��������ʮ����������ô����Ҫ����ʮ��ָ�����飬ÿ��ָ��ָ��һ�����飬ÿ������
����һ��Ͱ��Ͱ�Ĵ�С�������д洢�����Ķ���(n)������ 
*/

//��ӡ
void printArr(int arr[],int n){
	int i;
	for(i=0; i < n;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
} 

//��ȡ��������������ĳ��λ��
int getDigit(int num,int digit){
	int temp = 1;
	int i;
	for(i = 0;i < digit - 1;i++){
		temp *= 10;
	}
	return (num/temp)%10;
} 


//����������
void RadixCountSort(int arr[],int n){
	//�����ҳ������������
	int maxValue = arr[0];
	int i;
	for (i=0;i < n;i++) {
		if(arr[i]>maxValue){
			maxValue = arr[i];
		}
	} 
	int maxDigit;
	//������������λ��(digit)�Ƕ��٣���maxDigit��ʾ�������λ��
	while(maxValue > 0){
		maxValue /= 10;
		maxDigit++;
	} 
	//����ָ������,����ʾͰ (ducket) 
	int *duckets[10];
	for(i=0;i < 10;i++){
		//�����ڴ�,ÿ��Ͱ�����Դ洢n������ 
		duckets[i] = (int*)malloc(n*sizeof(int)); 
	}
	//��ʱ��Ͱ�Ĵ�СΪ�� 
	int ducketSize[10] = {0};
	int digit;
	//�������λ��Ϊ3,��ô��ֻ��Ҫ�������˴�ѭ�� 
	for (digit = 1;digit <= maxDigit; digit++){
		int i;
		for(i = 0;i < n; i++){
			//������λ���ĺ������õ�������digitλ��
			int currentDigit = getDigit(arr[i],digit); 
			//��ȡ��ǰ�����ĵ�ǰλ��֮�󣬾���Ҫ���ݸ�λ���������ŵ���Ӧ��Ͱ֮��ȥ��
			duckets[currentDigit][ducketSize[currentDigit]++] = arr[i]; 
		}
		//�������������ŵ���Ӧ��Ͱ֮�󣬾���Ҫ��λ����С����ȡ���ŵ�������
		//��λ��Ϊ0�����鿪ʼȡ 
		int index = 0;
		for(i = 0;i < 10;i++){
			int j;
			for(j = 0;j < ducketSize[i];j++){
				arr[index++] = duckets[i][j];
			}
			//���½�ÿ��Ͱ�Ĵ�С��Ϊ0
			ducketSize[i] = 0;
		}  
	} 
	//�������֮���ͷſռ䣬����ռ���ڴ�
	for (i = 0;i < 10;i++){
		free(duckets[i]);
	} 
}

int main(){
	int arr[] = {14,50,45,60,101,123,23,89,40,158};
	int n = 10;
	//��ӡԭ���� 
	printArr(arr,n);
	//���û���������
	RadixCountSort(arr,n); 
	//��ӡ����֮�������
	printArr(arr,n); 
	system("pause");
	return 0;
}
