/*****��������Quick Sort*****/
#include <iostream>

void QuickSort(int*,int,int);   //��������
int Partition(int*,int,int);	//����һ�˿������������Ԫ�ص�λ�ã�������

using namespace std;
const int Length=20;

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43};   //��ʼ�����飬�ǵ�ĩβ�ķֺ�
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


void QuickSort(int *p,int qlow,int qhigh)		//��������еݹ�����
{
	int point=0;			//��¼�����λ��
	if(qlow < qhigh)
	{
		point=Partition(p,qlow,qhigh);	//������numbers[]һ��Ϊ��
		QuickSort(p,qlow,point-1);		//�Ե��ӱ�ݹ�����
		QuickSort(p,point+1,qhigh);		//�Ը��ӱ�ݹ�����
	}
}


int Partition(int *pp,int plow,int phigh)
{
	int pivotloc=pp[plow];		//��ÿ�������е�һ��Ԫ����Ϊ ����(�����ǵݹ���������׳���)

	while(plow < phigh)
	{
		while(plow<phigh && pp[phigh]>=pivotloc)		//�ӱ�����Ҷ�����ɨ��
		{
			--phigh;
		}
		pp[plow]=pp[phigh];

		while(plow<phigh && pp[plow]<=pivotloc)			//�ӱ�����������ɨ��
		{
			++plow;
		}
		pp[phigh]=pp[plow];
	}

	pp[plow]=pivotloc;

	return plow;
}