#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include <stack>


using namespace std;


class CSolution
{
public:

	void heapSortMin(int* a, int n);
	void heapSortMax(int* a, int n);
	int TestHeapSort();

	void quickSort(int* arr, int nStart, int nEnd);

	void quickSort_norecursion(int* arr, int nStart, int nEnd);

	int PartSort(int* arr, int nStart, int nEnd);

protected:

	void maxHeapDown(int* a, int start, int end);
	void minHeapDown(int*a, int start, int end);
private:
};


/*
* 堆排序(从小到大)
*
* 参数说明：
*     a -- 待排序的数组
*     n -- 数组的长度
*/
void CSolution::heapSortMin(int* a, int n)
{
	int i, tmp;

	// 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
	for (i = n / 2 - 1; i >= 0; i--)
		maxHeapDown(a, i, n - 1);

	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (i = n - 1; i > 0; i--)
	{
		// 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
		// 即，保证a[i-1]是a[0...i-1]中的最大值。
		maxHeapDown(a, 0, i - 1);
	}
}
/*
* 堆排序(从大到小)
*
* 参数说明：
*     a -- 待排序的数组
*     n -- 数组的长度
*/
void CSolution::heapSortMax(int* a, int n)
{
	int i, tmp;

	// 从(n/2-1) --> 0逐次遍历每。遍历之后，得到的数组实际上是一个最小堆。
	for (i = n / 2 - 1; i >= 0; i--)
		minHeapDown(a, i, n - 1);

	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for (i = n - 1; i > 0; i--)
	{
		// 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最小的。
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最小堆。
		// 即，保证a[i-1]是a[0...i-1]中的最小值。
		minHeapDown(a, 0, i - 1);
	}
}

/*
* (最大)堆的向下调整算法
*
* 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
*     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
*
* 参数说明：
*     a -- 待排序的数组
*     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
*     end   -- 截至范围(一般为数组中最后一个元素的索引)
*/
void CSolution::maxHeapDown(int* a, int start, int end)
{
	int c = start;            // 当前(current)节点的位置
	int l = 2 * c + 1;        // 左(left)孩子的位置
	int tmp = a[c];            // 当前(current)节点的大小
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"是左孩子，"l+1"是右孩子
		if (l < end && a[l] < a[l + 1])
			l++;        // 左右两孩子中选择较大者，即m_heap[l+1]
		if (tmp >= a[l])
			break;        // 调整结束
		else            // 交换值
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}



/*
* (最小)堆的向下调整算法
*
* 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
*     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
*
* 参数说明：
*     a -- 待排序的数组
*     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
*     end   -- 截至范围(一般为数组中最后一个元素的索引)
*/
void CSolution::minHeapDown(int* a, int start, int end)
{
	int c = start;            // 当前(current)节点的位置
	int l = 2 * c + 1;        // 左(left)孩子的位置
	int tmp = a[c];            // 当前(current)节点的大小
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"是左孩子，"l+1"是右孩子
		if (l < end && a[l] > a[l + 1])
			l++;        // 左右两孩子中选择较小者
		if (tmp <= a[l])
			break;        // 调整结束
		else            // 交换值
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}


int CSolution::TestHeapSort()
{
	int i;
	int a[] = { 20,30,90,40,70,110,60,10,100,50,80 };
	int ilen = (sizeof(a)) / (sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	heapSortMax(a, ilen);            // 升序排列
									 //heapSortDesc(a, ilen);        // 降序排列

	cout << "after  sort:";
	for (i = 0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}


void CSolution::quickSort(int* arr, int nStart, int nEnd)
{
	if (nStart >= nEnd)
		return;
	
	int nTmp = arr[nStart];
	int i = nStart;
	int j = nEnd;
	
	while (i < j)
	{
		while (i < j && arr[i] <= nTmp) i++;
		while (i < j && arr[j] < nTmp) j++;
		
		if (i < j && arr[i] < arr[j])
			std::swap(arr[i], arr[j]);
	}
	
	std::swap(arr[nStart], arr[i]);
	quickSort(arr, nStart, i - 1);
	quickSort(arr, nStart, i + 1);
}

void CSolution::quickSort_norecursion(int* arr, int nStart, int nEnd)
{
	std::stack<int> s;

	s.push(nStart);
	s.push(nEnd);
	
	while (!s.empty())
	{
		int rigth = s.top();
		s.pop();
		int left = s.top();
		s.pop();
		
		int nCent = PartSort(arr, left, rigth);
		
		if (nCent != -1)
		{
			s.push(nCent + 1);
			s.push(nCent - 1);
		}
	}
}

int CSolution::PartSort(int* arr, int nStart, int nEnd)
{
	if (nStart >= nEnd)
		return -1;
	
	int nTmp = arr[nStart];
	int i = nStart; 
	int j = nEnd;

	while (i < j)
	{
		while (i < j && arr[i] <= nTmp) i++;
		while (i < j && arr[j] >= nTmp) j++;
		
		if (i < j && arr[i] > arr[j])
			std::swap(arr[i], arr[j]);
	}

	std::swap(arr[i], arr[nStart]);

	return i;
}