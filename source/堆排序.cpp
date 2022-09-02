// PractiseCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <vector>
#include <Windows.h>
#include <io.h>
#include <iostream>
#include <string.h>
#include <glog/logging.h>
#include "testClass.h"


using namespace std;


void  seclect(vector<int>& arrs, int firstIndex)
{
	if ( firstIndex < arrs.size() - 1)
	{
		int lastParent = (arrs.size() - firstIndex) / 2 - 1 ;
		int lastRightChild = arrs.size() - 1;
		for (int tempParent = lastParent; tempParent >= 0; tempParent--)
		{
			int leftIndex = firstIndex + tempParent * 2 + 1;
			int rightIndex = firstIndex + 2 * (tempParent + 1);
			int leftChild = arrs[leftIndex];
			int rightChild = rightIndex > lastRightChild ? arrs[lastRightChild] : arrs[rightIndex];
			int tempMin = leftChild;
			int curMinNumIndex = leftIndex;
			if (rightChild < leftChild)
			{
				tempMin = rightChild;
				curMinNumIndex = rightIndex;
			}
			int curParent = firstIndex + tempParent;
			if (tempMin < arrs[curParent])
			{
				swap(arrs[curParent], arrs[curMinNumIndex]);
			}
		}
	}
}

void heapSorted(vector<int>& arrs)
{
	for (size_t index = 0; index < arrs.size() ; index++)
	{
		seclect(arrs, index);
	}
}





int main(int argc, char* argv[])
{
	vector<int>    arrs= { 5, 4, 3, 7, 8, 9, 1, 2 };
	heapSorted(arrs);
	cout << arrs[0] << endl;

	

	return 0;
}


