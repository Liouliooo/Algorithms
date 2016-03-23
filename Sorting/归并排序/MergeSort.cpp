/*****二路归并排序Merge Sort*****/
#include <iostream>

void MergeSort(int*,int*,int,int); //归并排序函数
void Merge(int*,int*,int,int,int); //把两个子序列，归并成一个序列

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

	if(mslow == mshigh)		   //注意是==（等于）号  不是=（赋值）符号
		nms[mslow]=ms[mslow];

	else
    {
		msmiddle=(mslow+mshigh)/2;

		MergeSort(ms,a,mslow,msmiddle);		//递归方式对前半部分归并
		MergeSort(ms,a,msmiddle+1,mshigh);	//递归方式对后半部分归并
		Merge(a,nms,mslow,msmiddle,mshigh);	//对左右子序列进行归并
    }

}  


//将 m[mlow...mmiddle] 与 m[mmiddle+1...mhigh] 归并到 nm[mlow...mhigh] 中
void Merge(int *m,int *nm,int mlow,int mmiddle,int mhigh)
{
	int i=mlow;
	int j=mmiddle+1;
	int k=mlow;

	for(; i<=mmiddle && j<=mhigh; k++) //对两个子序列进行归并
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

	if(i <= mmiddle) //若i<=mmiddle则说明，前半部分未归并完，后半部分已归并完了，则k应+1，i不变
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

