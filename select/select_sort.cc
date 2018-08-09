#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define Swap(a,b) {int temp=a;a=b;b=temp;}
#define N 10
void select_sort(int *a,int len)
{
	int i,j,min;
	for(i=0;i<len-1;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(!(min==i))
		{
		Swap(a[i],a[min]);
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
	select_sort(a,N);
	for(i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
