#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N 10
using namespace std;
int *b=(int *)malloc(sizeof(int)*(N+1));
void merge(int a[],int low,int mid,int hight)
{
	int i,j,k;
	for(k=low;k<hight;k++)//把数组a复制给数组b
	{
		b[k]=a[k];
	}
	for(i=low,j=mid+1,k=i;i<=mid&&j<=hight;k++)
	{
		if(b[i]<=b[j])
		{
			a[k]=b[i+1];
		}
		else
		{
			a[k]=b[j++];
		}
	}
	while(i<=mid)
		a[k++]=b[i++];
	while(j<=hight)
		a[k++]=b[j++];
}
void merge_sort(int a[],int low,int hight)
{
	if(low<hight)
	{
		int mid=(low+hight)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,hight);
		merge(a,low,mid,hight);
	}
}
int main()
{
	srand(time(NULL));
	int a[N];
	int i;
	cout<<"排序前:"<<endl;
	for(i=0;i<N;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"排序后:"<<endl;
	merge_sort(a,0,N-1);
	for(i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
