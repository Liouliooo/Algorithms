/*****��·�鲢����Merge Sort*****/
#include <iostream>

void MergeSort(int*,int*,int,int); //�鲢������
void Merge(int*,int*,int,int,int); //�����������У��鲢��һ������

using namespace std;

const int Length=20;

int main()
{
	int numbers[Length]={389,79,9,69,5,4,43,00,19,97,16,53,42,86,93,102,356,57,63,43};
	int newnumbers[Length];
  
	int i=0;
	int low=0;
	int high=Length-1;
  
	MergeSort(numbers,newnumbers,low,high);
	//Merge(numbers,newnumbers,low,9,high);

	for(i=0; i<Length; i++)
		cout << newnumbers[i]  << '\t';

	cout << endl;
 
	return 0;
}


void MergeSort(int *ms,int *nms,int mslow,int mshigh)
{ 

	int a[20]={0};
	int msmiddle=0;

	if(mslow == mshigh)		   //ע����==�����ڣ���  ����=����ֵ������
		nms[mslow]=ms[mslow];

	else
    {
		msmiddle=(mslow+mshigh)/2;

		MergeSort(ms,a,mslow,msmiddle);		//�ݹ鷽ʽ��ǰ�벿�ֹ鲢
		MergeSort(ms,a,msmiddle+1,mshigh);	//�ݹ鷽ʽ�Ժ�벿�ֹ鲢
		Merge(a,nms,mslow,msmiddle,mshigh);	//�����������н��й鲢
    }

}  


//�� m[mlow...mmiddle] �� m[mmiddle+1...mhigh] �鲢�� nm[mlow...mhigh] ��
void Merge(int *m,int *nm,int mlow,int mmiddle,int mhigh)
{
	int i=mlow;
	int j=mmiddle+1;
	int k=mlow;

	for(; i<=mmiddle && j<=mhigh; k++) //�����������н��й鲢
    {
		if(m[i] <= m[j])
		{
			nm[k]=m[i++];
		}

		else
		{
			nm[k]=m[j++];
		}
    }

	if(i <= mmiddle) //��i<=mmiddle��˵����ǰ�벿��δ�鲢�꣬��벿���ѹ鲢���ˣ���kӦ+1��i����
	{
		while(i <= mmiddle)
		{
			nm[k]=m[i];
			k++;
			i++;
		}
	}

	if(j <= mhigh)
	{
		while(j <= mhigh)
		{
			nm[k]=m[j];
			k++;
			j++;
		}
	}
}

