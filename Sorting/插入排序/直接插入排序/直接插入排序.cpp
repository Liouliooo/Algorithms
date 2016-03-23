/*****ֱ�Ӳ������� Straight Insertion Sort*****/
#include <iostream>

void InsertSort(int *,int);

const int Length=20;
using std::cout;
using std::endl;

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43};  //��ʼ�����飬β����һ���ֺ�
	int i=0;
	
	InsertSort(numbers,Length);

	for(i=0; i<Length; i++)
	{
		cout << numbers[i] << '\t';
	}
	cout << endl;

	return 0;
}

void InsertSort(int* p,int m)
{
	int Skey=0;
	int i=0;
	int j=0;
	
	for(i=1; i<m; i++)
	{
		if(p[i]<p[i-1])
		{
			Skey=p[i];    //��p[i]��ֵ�����ڱ� Skey		

			for(j=i-1; p[j]>Skey; --j)
			{
				p[j+1]=p[j];
			}
			p[j+1]=Skey;     //��Ԫ�ز�����ʵ�λ��
		}
	}
}
