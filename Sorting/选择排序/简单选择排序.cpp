/*****简单选择排序 Simple Select Sort *****/
#include <iostream>

using std::cout;
using std::endl;
const int Length=20;
void SimpleSelectSort(int *,int);

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43};  //初始化数组，尾部有一个分号
	int i=0;
	
	SimpleSelectSort(numbers,Length);

	for(i=0; i<Length; i++)
	{
		cout << numbers[i] << '\t';
	}
	cout << endl;

	return 0;
}  

void SimpleSelectSort(int *p,int m)
{
	int temp=0;
	int i=0;
	int j=0;
	int foot=0;

	for(i=0; i<m; i++)
	{
		foot=i;
		for(j=i; j<m-1; j++)   //寻找最小值所在的位置
		{
			if(p[foot]>p[j+1])
			{
				foot=j+1;
			}
		}

		if(i!=foot)
		{
			temp=p[i];
			p[i]=p[foot];
			p[foot]=temp;
		}
	}
}