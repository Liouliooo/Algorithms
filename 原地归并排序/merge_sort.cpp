# include <iostream>

using namespace std;

// reverse the array,反转数组
void reverse(int *a,int n)
{
    int i = 0, mid = (n-1)/2;
    if (n <= 1) { return ; }
    for (i=0; i<mid; i++)
    {
        int temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
}

// 循环左移,手摇算法
void rotation(int *a,int n,int pos)
{
    reverse(a,pos);
    reverse(a+pos,n-pos);
    reverse(a,n);
}


// 合并两个已排好序数组，从位置sec开始
void merge(int *a,int n,int mid)
{
    int fir = 0;
    int sec = mid;
    while (fir<sec && sec<n)
    {
        while (fir<sec && a[fir]<=a[sec]) { fir++; }
        int step = 0;
        while (sec<n && a[fir]>a[sec])
        {
            step++;
            sec++;
        }
        rotation(a+fir,sec-fir,sec-fir-step);
        fir += step;
    }
}

// 归并排序，时间复杂度O(nlogn), 空间复杂度O(1).
void merge_sort(int *a, int n)
{
    if (n<=1) { return ; }
    int mid = n/2;
    
    merge_sort(a,mid);
    merge_sort(a+mid,n-mid);
    merge(a,n,mid);
}

int main()
{
    int a[] = {12,32,3,24,35,6};
    // reverse(a,6);
    for (int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
    cout << endl;

    rotation(a,6,4);
    for (int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
    cout << endl;

    merge_sort(a,6);
    for (int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
