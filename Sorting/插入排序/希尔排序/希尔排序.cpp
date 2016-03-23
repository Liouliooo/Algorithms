/*****ϣ������ Shell Sort*****/
#include <iostream>

void ShellInsert(int *,int,int); //����������Ϊ����
void ShellSort(int *,int,int *,int); //��Ѵ���������飬�Լ��������д��ݸ�����

using namespace std;

const int Length=20;
const int d=4;

int main()
{
	int numbers[Length]={38,7,9,66,5,4,43,100,12,17,16,53,42,86,93,102,356,57,63,43}; //��ʼ�����飬�ǵ�ĩβ�ķֺ�
	int dlta[d]={9,5,3,1};
	int i=0;

	ShellSort(numbers,Length,dlta,d); //ϣ������

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
	int key=0;					//�����洢Ҫ���в����ֵ
	int i=0;
	int j=0;

	for(i=sdl; i<sm; i++)
	{
		if(sp[i] < sp[i-sdl]) //������Ϊ�ǵݼ��������Ե� sp[i]<sp[i-sdl] ʱ���Ű� sp[i] ���뵽��������
		{
			key=sp[i];			//��key���洢Ҫ���в����ֵ

			for(j=i-sdl; j>=0 && key<sp[j]; j=j-sdl)
			{
				sp[j+sdl]=sp[j];
			}

			sp[j+sdl]=key;
		}
	}
}
