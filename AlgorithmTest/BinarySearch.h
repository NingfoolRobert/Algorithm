#pragma once
#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

class Solution
{
public:
	int BinarySearchValue(std::vector<int> &Array, int nlow, int nHeigth, int nValue);

	void TestLowerBound();

	int BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue);

	int BinarySearchValueFirst(std::vector<int>Array, int nvalue);

	int BinarySearchValueLast(std::vector<int>Array, int nvalue);
	
	void TestSearch();

	/*���ֲ��ұ���*/
	
	// ���ҵ�һ����key��ȵ�Ԫ�أ�Ҳ����˵���ڲ���keyֵ��Ԫ���кܶ࣬������ЩԪ������ߵ�Ԫ�ص��±�
	int BinarySearchLeft(std::vector<int>Array, int nval);
	
	//�������һ����key��ȵ�Ԫ�أ�Ҳ���ǵ��ڲ���keyֵ��Ԫ���кö����������ЩԪ�����ұ�Ԫ�ص��±�
	int BinarySearchRigth(std::vector<int>Array, int nval);
	
	//�ҵ�һ�����ڻ��ߴ���key��Ԫ�أ����ҵ�һ�����ڻ��ߴ���key��Ԫ�أ�Ҳ����˵����keyֵ��Ԫ���кö����
	//������ЩԪ�������Ԫ�ص��±ꣻ���û�е���keyֵ��Ԫ�أ��򷵻ش���key�������Ԫ�ص��±ꡣ
	int BinarySearchHightBound(std::vector<int>Array, int nval);
	

	//���ҵ�һ������key��Ԫ�ء����ҵ�һ������key��ֵ��Ҳ����˵���ش���key�������Ԫ�ص��±�
	int BinarySearchfirstGreatVal(std::vector<int>Array, int nval);

	//�������һ�����ڻ���С��key��Ԫ�ء��������һ�����ڻ���С��key��Ԫ�أ�Ҳ����˵���ڲ���keyֵ�кܶ࣬
	//������ЩԪ�����ұߵ�Ԫ�ص��±ꣻ���û�е���keyֵ��Ԫ�أ��򷵻�С��keyֵ�����ұ�Ԫ�ص��±ꡣ
	int BinarySearchFirstLessVal(std::vector<int>Array, int nval);
	

	//�������һ�����ڻ���С��key��Ԫ�ء��������һ�����ڻ���С��key��Ԫ�أ�Ҳ����˵���ڲ���keyֵ�кܶ࣬
	//������ЩԪ�����ұߵ�Ԫ�ص��±ꣻ���û�е���keyֵ��Ԫ�أ��򷵻�С��keyֵ�����ұ�Ԫ�ص��±ꡣ
	int BinarySearchLastLessAEqulVal(std::vector<int>Array, int nval);


	//�������һ��С��key��Ԫ�ء��������һ��С��key��Ԫ�أ�Ҳ����˵����С��key�����ұߵ�Ԫ���±ꡣ
	int BinarySearchLastLessVal(std::vector<int>Array, int nval)

	

};
