/*��������ָ��ʵ�֣�Quick Sort*/
#include <iostream>

using namespace std;
			
void QuickSort(int*,int*);			//��������������ָ�� ͷָ���βָ��
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


void QuickSort(int* qlow,int* qhigh)		//�ݹ����ʵ�ֿ�������
{
	int *middle=NULL;

	if(qlow < qhigh)
	{
		middle=Partition(qlow,qhigh);		//��ָ�룬��¼����Ԫ�ص�λ��
		QuickSort(qlow,middle-1);
		QuickSort(middle+1,qhigh);
	}
}


int *Partition(int *plow,int *phigh)
{
	int key = *plow;		//��¼����Ԫ�ص� ֵ
	
	while(plow < phigh)
	{
		while(plow<phigh && *phigh>=key)		//������ *phigh>=key �� *plow<=key���û��=�ţ���ô ��λָ��㲻���ƶ�
		{
			phigh=phigh-1;						//���ǣ����ϵĸ�ֵ����ʱ�����������ѭ��
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
