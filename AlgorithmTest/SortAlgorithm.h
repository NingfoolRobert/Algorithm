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
* ������(��С����)
*
* ����˵����
*     a -- �����������
*     n -- ����ĳ���
*/
void CSolution::heapSortMin(int* a, int n)
{
	int i, tmp;

	// ��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)����ѡ�
	for (i = n / 2 - 1; i >= 0; i--)
		maxHeapDown(a, i, n - 1);

	// �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (i = n - 1; i > 0; i--)
	{
		// ����a[0]��a[i]��������a[i]��a[0...i]�����ġ�
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ�����ѡ�
		// ������֤a[i-1]��a[0...i-1]�е����ֵ��
		maxHeapDown(a, 0, i - 1);
	}
}
/*
* ������(�Ӵ�С)
*
* ����˵����
*     a -- �����������
*     n -- ����ĳ���
*/
void CSolution::heapSortMax(int* a, int n)
{
	int i, tmp;

	// ��(n/2-1) --> 0��α���ÿ������֮�󣬵õ�������ʵ������һ����С�ѡ�
	for (i = n / 2 - 1; i >= 0; i--)
		minHeapDown(a, i, n - 1);

	// �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (i = n - 1; i > 0; i--)
	{
		// ����a[0]��a[i]��������a[i]��a[0...i]����С�ġ�
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ����С�ѡ�
		// ������֤a[i-1]��a[0...i-1]�е���Сֵ��
		minHeapDown(a, 0, i - 1);
	}
}

/*
* (���)�ѵ����µ����㷨
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*     ���У�NΪ�����±�����ֵ���������е�1������Ӧ��NΪ0��
*
* ����˵����
*     a -- �����������
*     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
*     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
*/
void CSolution::maxHeapDown(int* a, int start, int end)
{
	int c = start;            // ��ǰ(current)�ڵ��λ��
	int l = 2 * c + 1;        // ��(left)���ӵ�λ��
	int tmp = a[c];            // ��ǰ(current)�ڵ�Ĵ�С
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"�����ӣ�"l+1"���Һ���
		if (l < end && a[l] < a[l + 1])
			l++;        // ������������ѡ��ϴ��ߣ���m_heap[l+1]
		if (tmp >= a[l])
			break;        // ��������
		else            // ����ֵ
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}



/*
* (��С)�ѵ����µ����㷨
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*     ���У�NΪ�����±�����ֵ���������е�1������Ӧ��NΪ0��
*
* ����˵����
*     a -- �����������
*     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
*     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
*/
void CSolution::minHeapDown(int* a, int start, int end)
{
	int c = start;            // ��ǰ(current)�ڵ��λ��
	int l = 2 * c + 1;        // ��(left)���ӵ�λ��
	int tmp = a[c];            // ��ǰ(current)�ڵ�Ĵ�С
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"�����ӣ�"l+1"���Һ���
		if (l < end && a[l] > a[l + 1])
			l++;        // ������������ѡ���С��
		if (tmp <= a[l])
			break;        // ��������
		else            // ����ֵ
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

	heapSortMax(a, ilen);            // ��������
									 //heapSortDesc(a, ilen);        // ��������

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