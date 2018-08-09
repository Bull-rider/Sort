#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N 10
#define Swap(a,b) {int temp=a;a=b;b=temp;}
using namespace std;
int partition(int a[],int left,int right)
{
	int i;
	int k=left;
	for(i=left;i<right;i++)
	{
		if(a[i]<a[right])
		{
			Swap(a[i],a[k]);
			k++;
		}
	}
	Swap(a[right],a[k]);
	return k;
}
void quick(int a[],int left,int right)
{
	int pivot;
	if(left<right)
	{
		pivot=partition(a,left,right);
		quick(a,left,pivot-1);
		quick(a,pivot+1,right);
	}

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
