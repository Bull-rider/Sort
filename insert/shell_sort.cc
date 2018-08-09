#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#include <time.h>
using namespace std;
void shell_sort(int *a,int len)
{
	int i,j,dk,val;
	for(dk=len/2;dk>=1;dk=dk/2)//外层循环控制排序进行的次数，直到dk=1时
	{
		for(i=dk;i<len;i++)//一次等差距离为dk的直接插入排序
		{
			if(a[i]<a[i-dk])
			{
				val=a[i];
				//这里注意移动元素的坐标相差为dk,也就是说每次移动dk个位置而不是1
				for(j=i-dk;j>=0&&val<a[j];j-=dk)
				{
					a[j+dk]=a[j];
				}
				a[j+dk]=val;//上面的循环判断中，插入位置j多减了一个dk故这里要加上
			}
		}
	}
}
int main()
{
	int a[N];
	int i;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	shell_sort(a,N);
	for(i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
