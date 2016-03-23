/*****希尔排序 Shell Sort*****/
#include <iostream>

void ShellInsert(int *,int,int); //第三个参数为增量
void ShellSort(int *,int,int *,int); //需把待排序的数组，以及增量序列传递给函数

using namespace std;

const int Length=20;
const int d=4;

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43}; //初始化数组，记得末尾的分号
	int dlta[d]={9,5,3,1};
	int i=0;

	ShellSort(numbers,Length,dlta,d); //希尔排序

	for(i=0; i<Length; i++)
	{
		cout << numbers[i] << '\t';
	}
	cout << endl;

	return 0;
}

void ShellSort(int *p,int m,int *dt,int dl)
{
	int i=0;
	for(i=0; i<dl; i++)
	{
		ShellInsert(p,m,dt[i]);
	}
}

void ShellInsert(int *sp,int sm,int sdl)
{
	int key=0;					//用来存储要进行插入的值
	int i=0;
	int j=0;

	for(i=sdl; i<sm; i++)
	{
		if(sp[i] < sp[i-sdl]) //此排序为非递减排序，所以当 sp[i]<sp[i-sdl] 时，才把 sp[i] 插入到子序列中
		{
			key=sp[i];			//用key来存储要进行插入的值

			for(j=i-sdl; j>=0 && key<sp[j]; j=j-sdl)
			{
				sp[j+sdl]=sp[j];
			}

			sp[j+sdl]=key;
		}
	}
}
