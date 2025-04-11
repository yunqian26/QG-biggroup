#include<stdio.h>
#include<stdlib.h> //����Ҫ�����ڴ棬������Ҫ�õ�

/*
�鲢��Ҫ���Ƿֳɻ��ֺͺϲ����֣����ֲ�����Ҫ�õ��˵ݹ��˼�� �����򲿷��ҷ����˺ϲ����� 
*/

//��ӡ����
void printArr(int arr[],int n){
	int i=0;
	for(;i<n;i++){
		printf("%d ",arr[i]);
	}
	//��ӡ��֮���� 
	putchar('\n');
} 

//�ϲ�����
void merge(int arr[],int tempArr[],int left,int mid,int right){
	//���������������±�
	int l_left = left;
	//�����Ұ��������Ԫ��,��mid+1 
	int l_right = mid+1; 
	//��ʱ����Ԫ�ص��±�
	int t_left = left;
	//��ʼ�ϲ� 
	while(l_left <= mid && l_right <=  right){
		if(arr[l_left] < arr[l_right]){  //����������һ��Ԫ�ظ�С����ô���Ԫ���Ƚ�����ʱ 
			tempArr[t_left++] = arr[l_left++];
		} else {
			tempArr[t_left++] = arr[l_right++];
		}
	}
	//�������ʣ��Ԫ�ط�����ʱ����(ǰ������ʣ��Ԫ��)
	while(l_left <= mid){
		tempArr[t_left++]=arr[l_left++];
	}
	//���Ұ���ʣ��Ԫ�ط�����ʱ����(ǰ������ʣ��Ԫ��)
	while(l_right <= right){
		tempArr[t_left++]=arr[l_right++];
	}
	//����ʱ�������ԭ����
	while(left<=right){
		arr[left] = tempArr[left];
		left++;
	} 
} 

//���ֺ�������Ҫ���þ��ǽ�ԭʼ����ͨ���ݹ齫���黮�ֳ�һ����С�� 
void msort(int arr[],int tempArr[],int left,int right){
	if (left < right){
		//���廮�ֽ��ޣ�����mid�Լ�mid֮ǰ��Ԫ�����ǳ�֮Ϊ�������mid+1֮���Ԫ����ɵ��������ǳ�֮Ϊ�Ұ��� 
		int mid = (left + right)/2;
		//��ʼ�ݹ黮������
		//��������� 
		msort(arr,tempArr,left,mid);
		//�����Ұ���,ע�⣬�����Ұ������±��Ǵ�mid+1��ʼ�ģ�mid�±��Ӧ��Ԫ��������������� 
		msort(arr,tempArr,mid+1,right);
		//������֮�󣬿϶�Ҫ����ϲ�����ʱ���Ҫ�õ�merge����
		merge(arr,tempArr,left,mid,right);
	}
}


//�鲢�����������ڣ������ڵĹ�����Ҫ���Ƿ����ڴ��Լ����뻮�ֺ��� 
void msort_merge(int arr[],int n){
	int* tempArr = (int*)malloc(n*sizeof(int));
	if (tempArr){
		//��������ڴ�ɹ�����ô���뻮�ֺ���msort 
		msort(arr,tempArr,0,n-1);
		//���Ҫ�����ͷſռ䣬����ռ���ڴ� 
		free(tempArr);
	} else {
		printf("�����ڴ�ʧ��!����ʧ��!");
	}
} 

int main(){
	//��ʱ����һ���Ƚ�С������ 
	int arr[] = {1,6,4,2,9,7,20,5,14,8};
	int n=10;
	printf("ԭ����:\n");
	printArr(arr,n);
	//������ں��� 
	msort_merge(arr,n);
	//�������֮���ٴδ�ӡ����������Ƿ�����ɹ�
	printf("�鲢����֮������:\n");
	printArr(arr,n);
	system("pause");
	return 0; 
} 
