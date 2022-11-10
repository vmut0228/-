#include<iostream>

//随机函数有关
#include <cstdlib>
#include <ctime> 

//测试算法运行时间
#include <windows.h>
#include <time.h>
#include<winbase.h>
using namespace std;

int main() {

	int arr[2000] = {};				//数组大小
	int relay = 0;					//中继变量
	int arrLength = sizeof(arr) / 4;//获取数组arr的长度
	//cout << arrLength << endl;
	int z;
	cout << "选择测试模式：" << endl << "随机数组输入1" << endl << "逆序数组输入2" << endl << "大量重复值数组输入3" << endl << "基本已排序数组输入4" << endl;

	cin >> z;//选择测试模式

	//初始化数组
	for (int y = 0; y < arrLength; y++) {

		if (z == 1) {		//产生随机数组测试
			//srand(time(0));//来设置rand()产生随机数时的随机数种子
			arr[y] = rand();

		}
		else if (z == 2) {	//产生逆序数组测试
			static int l = 1000;
			l--;
			arr[y] = l;
		}
		else if (z == 3) {//大量重复数值数组测试
			arr[y] = rand() % (4 - 1 + 1) + 1;//rand()%(high-low+1)+low 产生1-4的重复数字
		}
		else if (z == 4) {//基本已排序数组测试
			static int l = 42;
			arr[y] = l;
			l++;           //产生完全排序数组
			if (y % 10 == 0) {//产生少数没排序的数组元素 
				arr[y] = rand();
			}
		}
		//cout << arr[y] << " ";//输出产生数组

	}

	long t1 = GetTickCount64();//程序段开始前取得系统运行时间(ms) 
	//冒泡算法

	for (int j = 0; j < arrLength - 1; j++) {

		for (int i = 0; i < arrLength - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				relay = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = relay;  //如果前者比后者大则交换位置
			}
		}
	}
	
	//优化冒泡算法
	/*
	boolean flag; //是否发生交换的标志
	for (int j = 0; j < arrLength - 1; j++) {
		flag = false;
		for (int i = 0; i < arrLength - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				relay = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = relay;  //如果前者比后者大则交换位置
				flag = true;    //只要有发生了交换，flag就置为true
			}
		}
		
		if (!flag) break;// 判断标志位是否为false，如果为false，说明后面的元素已经有序，就直接结束排序
	}*/
	long t2 = GetTickCount64();

	//输出最后排序后的数组
	/*
	for (int x = 0; x < arrLength; x++) {
		cout << arr[x] << endl;
	}*/
	cout << "冒泡排序运行时间" << (t2 - t1) << "ms" << endl;

}