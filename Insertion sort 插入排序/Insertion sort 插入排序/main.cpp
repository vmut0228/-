#include<iostream>
// ��������й�
#include <cstdlib>
#include <ctime> 

//�����㷨����ʱ��
#include <windows.h>
#include <time.h>
#include<winbase.h>
using namespace std;
int main() {

	int arr[100000] = {};				//�����С
	int arrLength = sizeof(arr) / 4;//��ȡ����arr�ĳ���
	//cout << arrLength << endl;

	
	int z;
	cout << "ѡ�����ģʽ��" << endl << "�����������1" << endl << "������������2" << endl << "�����ظ�ֵ��������3" << endl << "������������������4" << endl;

	cin >> z;//ѡ�����ģʽ

	//��ʼ������
	for (int y = 0; y < arrLength; y++) {

		if (z == 1) {		//��������������
			//srand(time(0));//������rand()���������ʱ�����������
			arr[y] = rand();

		}
		else if (z == 2) {	//���������������
			static int l = 1000;
			l--;
			arr[y] = l;
		}
		else if (z == 3) {//�����ظ���ֵ�������
			arr[y] = rand() % (4 - 1 + 1) + 1;//rand()%(high-low+1)+low ����1-4���ظ�����
		}
		else if (z == 4) {//�����������������
			static int l = 42;
			arr[y] = l;
			l++;           //������ȫ��������
			if (y % 10 == 0) {//��������û���������Ԫ��
				arr[y] = rand();
			}
		}
		//cout << arr[y] << " ";//�����������

	}
	
	long t1 = GetTickCount64();//����ο�ʼǰȡ��ϵͳ����ʱ��(ms) 

	//��������
	int i, j, temp;
	//int arr[5] = { 4,6,3,2,4 };
	for (i = 1; i < arrLength;i++ ) {
								//i��δ����Ԫ�صĵ�һ���±�
		int temp = arr[i];		//δ����Ԫ�صĵ�һ��ֵ
		int j = i - 1;			//������Ԫ�ص����һ������

		while(j>=0&&temp<arr[j]){
			//������Ԫ�ص����һ���±���ڵ���0 && δ����Ԫ�صĵ�һ��ֵС��������Ԫ�ص����һ��ֵ
			arr[j + 1] = arr[j];
			j--;
	}
		arr[j + 1] = temp;

}

	
	long t2 = GetTickCount64();

	//����������������
	/*
	for (int x = 0; x < arrLength; x++) {
		cout << arr[x] << endl;
	}*/
	

	 cout << "������������ʱ��" << (t2 - t1)/1000 << "s" << endl;
	 cout << "������������ʱ��" << (t2 - t1) << "ms" << endl;
}