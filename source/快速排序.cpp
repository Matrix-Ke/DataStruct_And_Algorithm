int findIndex(int* arr, int low, int high)
{
	int pivot = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= pivot)
		{
			--high;
		}
		
		if (low < high)
		{
			cout << "high移动到low的index：" << high << "  " << low << endl;
			arr[low++] = arr[high];
		}
		
		
		while (low < high && arr[low] < pivot )
		{
			low++;
		}
		if (low <high)
		{
			cout << "low移动到high的index：" << low << "  " << high << endl;
			arr[high--] = arr[low];
		}
		

	}
	arr[low] = pivot;
	return low;
}

void qkSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int mid = findIndex(arr, low, high);
		cout << " 中间点：" << mid << endl;
		qkSort(arr, low, mid-1);
		qkSort(arr, mid+1, high);
	}
}