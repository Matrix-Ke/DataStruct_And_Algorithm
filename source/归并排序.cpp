void merge(int* arr, int low, int mid, int high);
void mergeSort(int* arr, int low, int high)
{
	if (high - low > 1)
	{
		int mid = (high + low) /2;
		cout <<" ÖÐ¼äÖµ£º" <<mid << endl;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid, high);
		merge(arr, low, mid, high);
	}

}

void merge(int* arr, int low, int mid, int high)
{
	int preLen = mid - low;
	int postLen = high - mid;
	int* pbuffer = new int[preLen];
	for (auto index = 0; index < preLen; index++)
	{
		pbuffer[index] = arr[low + index];
	}
	int i = 0, j = 0, k = 0;
	while (i < preLen && j < postLen)
	{
		if (arr[mid + j] < pbuffer[i])
		{
			arr[low + k++] = arr[mid + j++];
		}
		else
		{
			arr[low + k++] = pbuffer[i++];
		}

	}
	while (i < preLen)
	{
		arr[low + k++] = pbuffer[i++];
	}
	delete[] pbuffer;
}