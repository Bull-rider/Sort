#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N 10
#define Swap(a,b) {int temp=a;a=b;b=temp;}
using namespace std;
void quick(int *a,int beg,int end)
{
	if(beg>=end)
		return;
	int i=beg,j=end,x=a[(i+j)>>1];
	while(i<=j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			Swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	quick(a,beg,j);
	quick(a,i,end);
}
int main()
{
	srand(time(NULL));
	int a[10];
	int i;
	cout<<"排序前:"<<endl;
	for(i=0;i<N;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"排序后:"<<endl;
	quick(a,0,N-1);
	for(i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*
另外掌握qsort排序算法，一般步骤，qsort(1,2,3,4)
参数1：表示待排序数据
参数2：表示待排序数据的总数
参数3：表示待排序数据元素的大小
参数4：比较方式
-----int类型的比较方式
int cmp(const void *a,const void *b)
{
		return *(int *)a-*(int *)b;
}
-----char类型
int cmp(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}
-----double类型
int cmp(const void *a,const void *b)
{
	return *(double *)a>*(double *)b ?1:-1;
}
-----字符串string类型对100个字符串进行排序
struct In
{
	int data;
	char str[100];
}s[100];
int cmp(const void *a,const void *b)
{
	return strcmp((*(In *)a)->str,(*(In *)b)->str);
}*/
