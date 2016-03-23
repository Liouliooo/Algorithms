/*****冒泡排序 Bubble Sort*****/
#include <iostream>

using std::cout;
using std::endl;
const int Length=20;
void BubbleSort(int*,int);

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43};  //初始化数组，尾部有一个分号
	int i=0;
	
	BubbleSort(numbers,Length);

	for(i=0; i<Length; i++)
	{
		cout << numbers[i] << '\t';
	}
	cout << endl;

	return 0;
}


void BubbleSort(int *p,int m)
{
	int index=1;
	int i=0;
	int j=0;
	int _length=m-1;
	
	for(i=0; i<=_length; _length--)  //冒泡排序算法
	{
		index=1;
		for(j=0; j<_length; j++)
		{
			if(p[j]>p[j+1])
			{
				int temp=0;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;

				index=0;
			}
		}

		if(index)    //如果相邻两个数，只比较，而不进行交换，则说明此时数列已经有序
		{
			break;
		}
	}
}
