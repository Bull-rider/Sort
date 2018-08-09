#include<stdio.h>
#include<stdlib.h>
#define N 10
#define SWAP(a,b) {int temp;temp=a;a=b;b=temp;}
void heap_max(int *a, int pos, int len)
{
	int dad = pos;
	int son = 2 * dad + 1;
	while (son < len)//结束的判定条件
	{
		if (son + 1 < len&&a[son] < a[son + 1])//下面这几行的作用就是找兄弟中较大的和父亲交换
		{
			son++;
		}
		if (a[dad]<a[son])
		{
			SWAP(a[dad], a[son]);
			dad = son;
			son = 2 * dad + 1;	
		}else{
			break;
		}
	}
}
void dui_sort(int *a,int len)
{
	int i;
	for (i = N / 2 - 1; i >= 0; i--)//每次调整的过程
	{
		heap_max(a, i, N);//建堆的时候是从i到最后一个
	}
	SWAP(a[0], a[N - 1]);
	for (i = N - 1; i > 0; i--)//总共需要交换的次数
	{
		heap_max(a, 0, i);//调整的时候是从0到最后
		SWAP(a[0], a[i - 1]);
	}
}
int main()
{
	int i;
	int a[N] = {57,86,59,99,37,7,51,66,64,59};
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	dui_sort(a, N);
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
