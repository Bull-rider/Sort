#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define Swap(a,b) {int temp=a;a=b;b=temp;}
using namespace std;
void bubble(int a[],int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(a[i]>a[j])
			{
				Swap(a[i],a[j]);
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
	bubble(a,10);
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
