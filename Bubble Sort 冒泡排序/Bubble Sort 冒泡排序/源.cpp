#include<iostream>

//��������й�
#include <cstdlib>
#include <ctime> 

//�����㷨����ʱ��
#include <windows.h>
#include <time.h>
#include<winbase.h>
using namespace std;

int main() {

	int arr[2000] = {};				//�����С
	int relay = 0;					//�м̱���
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
	//ð���㷨

	for (int j = 0; j < arrLength - 1; j++) {

		for (int i = 0; i < arrLength - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				relay = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = relay;  //���ǰ�߱Ⱥ��ߴ��򽻻�λ��
			}
		}
	}
	
	//�Ż�ð���㷨
	/*
	boolean flag; //�Ƿ��������ı�־
	for (int j = 0; j < arrLength - 1; j++) {
		flag = false;
		for (int i = 0; i < arrLength - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				relay = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = relay;  //���ǰ�߱Ⱥ��ߴ��򽻻�λ��
				flag = true;    //ֻҪ�з����˽�����flag����Ϊtrue
			}
		}
		
		if (!flag) break;// �жϱ�־λ�Ƿ�Ϊfalse�����Ϊfalse��˵�������Ԫ���Ѿ����򣬾�ֱ�ӽ�������
	}*/
	long t2 = GetTickCount64();

	//����������������
	/*
	for (int x = 0; x < arrLength; x++) {
		cout << arr[x] << endl;
	}*/
	cout << "ð����������ʱ��" << (t2 - t1) << "ms" << endl;

}