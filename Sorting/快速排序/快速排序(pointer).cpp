/*快速排序（指针实现）Quick Sort*/
#include <iostream>

using namespace std;
			
void QuickSort(int*,int*);			//给函数传递两个指针 头指针和尾指针
int *Partition(int*,int*);

const int Length=20;

int main()
{
	int numbers[20]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43};
	int i=0;

	int *low=&numbers[0];
	int *high=&numbers[Length-1];

	QuickSort(low,high);

	for(i=0; i<Length; i++)
	{
		cout << numbers[i] << '\t';
	}
	cout << endl;
	
	return 0;
}


void QuickSort(int* qlow,int* qhigh)		//递归调用实现快速排序
{
	int *middle=NULL;

	if(qlow < qhigh)
	{
		middle=Partition(qlow,qhigh);		//用指针，记录枢轴元素的位置
		QuickSort(qlow,middle-1);
		QuickSort(middle+1,qhigh);
	}
}


int *Partition(int *plow,int *phigh)
{
	int key = *plow;		//记录枢轴元素的 值
	
	while(plow < phigh)
	{
		while(plow<phigh && *phigh>=key)		//必须是 *phigh>=key 和 *plow<=key如果没有=号，那么 首位指针便不再移动
		{
			phigh=phigh-1;						//而是，不断的赋值。此时，程序进入死循环
		}
		*plow = *phigh;

		while(plow<phigh && *plow<=key)
		{
			plow=plow+1;
		}
		*phigh = *plow;
	}
	
	*plow = key;

	return plow;
}
