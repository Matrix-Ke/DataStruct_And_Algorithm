//
//void testNext( char* arr, int next[] )
//{
//	int i = 1;
//	int j = 0;
//	while (i < strlen(arr))
//	{
//		if (arr[i] == arr[j])
//		{
//			next[i] = j + 1;
//			i++;
//			j++;
//		}
//		else
//		{
//			if (j != 0)
//			{
//				j = next[j - 1];
//			}
//			else
//			{
//				next[i] = j;
//				i++;
//			}
//		}
//	}
//}
//
//int  test(char* source, char* tar, int next[])
//{
//	int k =0, j = 0, t = 0;
//	while (k < strlen(source) || j < strlen(tar))
//	{
//		if (source[k] == tar[j])
//		{
//			k++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	std::cout << strlen(source);
//	if (k <= strlen(source))
//	{
//		return k - j;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	char* c0 = const_cast<char*>( "D:\My_selfwork\Platform\GBM\maama\Debug\test");
//	char* c1 = const_cast<char*>("mmmaama");
//	char* c2 = const_cast<char*>("maama");
//	int nextC[5] = {0};
//	
//	testNext(c2, nextC);
//	std::cout<<test(c1, c2, nextC);
//	return 0;
//}