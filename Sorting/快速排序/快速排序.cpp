/*****快速排序Quick Sort*****/
#include <iostream>

void QuickSort(int*,int,int);   //快速排序
int Partition(int*,int,int);	//计算一趟快速排序后，枢轴元素的位置，并返回

using namespace std;
const int Length=20;

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43};   //初始化数组，记得末尾的分号
	int i=0;
	int low=0;
	int high=Length-1;

 	QuickSort(numbers,low,high);

	for(i=0; i<Length; i++)
	{
		cout << numbers[i] << '\t';
	}
	
	cout << endl;

	return 0;
}


void QuickSort(int *p,int qlow,int qhigh)		//对数组进行递归排序
{
	int point=0;			//记录枢轴的位置
	if(qlow < qhigh)
	{
		point=Partition(p,qlow,qhigh);	//将数组numbers[]一分为二
		QuickSort(p,qlow,point-1);		//对低子表递归排序
		QuickSort(p,point+1,qhigh);		//对高子表递归排序
	}
}


int Partition(int *pp,int plow,int phigh)
{
	int pivotloc=pp[plow];		//把每个子序列第一个元素作为 枢轴(尤其是递归调用是容易出错)

	while(plow < phigh)
	{
		while(plow<phigh && pp[phigh]>=pivotloc)		//从表的最右端往左扫描
		{
			--phigh;
		}
		pp[plow]=pp[phigh];

		while(plow<phigh && pp[plow]<=pivotloc)			//从表的最左端往右扫描
		{
			++plow;
		}
		pp[phigh]=pp[plow];
	}

	pp[plow]=pivotloc;

	return plow;
}