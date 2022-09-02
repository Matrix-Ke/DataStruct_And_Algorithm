void bubbleSort(int* arr, int length)
{
	bool sorted = true;
	for (size_t high = length; high > 0; high--)
	{
		sorted = true;
		for (size_t j = 1; j < high; j++)
		{
			if (arr[j-1] > arr[j])
			{
				
				int temp = arr[j];
				arr[j ] = arr[j-1];
				arr[j-1] = temp;
				sorted = false;
			}	
		}
		if (sorted) break;
	}
}