#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void insert(int arr[],int size)
{
	int i,j,k,val;
	for(i=1;i<size;i++)//控制插入元素的个数：第二个元素到最后一个元素
	{
		for(j=0;j<i;j++)//查找插入位置
		{
			if(arr[i]<arr[j])
			{
				val=arr[i];
				for(k=i-1;k>=j;k--)//移动元素
				{
					arr[k+1]=arr[k];
				}
				arr[j]=val;//插入节点元素放入插入位置
				break;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int a[10];
	int i;
	cout<<"排序前:"<<endl;
	for(i=0;i<10;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"排序后:"<<endl;
	insert(a,10);
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
