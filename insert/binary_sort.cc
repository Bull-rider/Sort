#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
using namespace std;
void binary_insert(int *a,int len)
{
	int i,j,low,hight,mid,val;
	for(i=1;i<len;i++)//外层循环控制插入元素个数
	{
		val=a[i];
		low=0;
		hight=i-1;
		while(low<=hight)//查找插入点位置
		{
			mid=(low+hight)/2;
			if(val<a[mid])
			{
				hight=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		for(j=i-1;j>=hight+1;j--)//元素整体后移一个位置
		{
			a[j+1]=a[j];
		}
		a[hight+1]=val;//待插入点插入位置
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
	binary_insert(a,N);
	for(i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
//这里多开辟出一个空间a[0],a[0]中临时存放当前要操作的元素，找到插入位置，移动完位置时再把啊a[0]放到插入位置
//就是把上面的val替换为a[0],切记开辟数组空间时为a[N+1],数组的起始地址从a[1]开始
/*void binary_insert(int *a,int len)
{
	int i,j,low,hight,mid;
	for(i=2;i<=len;i++i)//
	{
		val=a[i];
		low=1;
		hight=i-1;
		while(low<=hight)
		{
			mid=(low+hight)/2;
			if(val<a[mid])
			{
				hight=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		for(j=i-1;j>=hight+1;j--)
		{
			a[j+1]=a[j];
		}
		a[hight+1]=val;
	}
}*/
