#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N 10
#define Swap(a,b) {int temp=a;a=b;b=temp;}
using namespace std;
//说明一下这个代码是以最后一个元素为基准进行排序的
int partition(int a[],int left,int right)
{
	int i;
	int k=left;//这里k纪录比最后一个元素小的元素下标
	for(i=left;i<right;i++)//遍历如果找到比最后一个小的
	{
		if(a[i]<a[right])//就和a[k]交换随后将k加1，就能保证下标
		{				//(<=k的元素都比a[right]小)。
			Swap(a[i],a[k]);//遍历结束下标为k~right-1的所有元素
			k++;			//都比a[right]大
		}
	}
	Swap(a[right],a[k]);//把a[right]放在中间位置，结束！
	return k;			//返回k的下标，执行下一次循环
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
