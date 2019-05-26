#include<iostream>

void insertionsort(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		int value = arr[i];
		int k = i;
		while (k > 0 && arr[k - 1] > value) {
			arr[k] = arr[k - 1];
			k--;
		}
		arr[k] = value;
	}
}

int binarysearch(int *arr, int p, int q, int value) {
	while (p <= q) {
		int m = p + (q - p) / 2;
		if (value == arr[m]) {
			return m;			
		}
		else if (value > arr[m]) {
			return binarysearch(arr, m+1, q, value);
		}
		else if (value < arr[m])
		{
			return binarysearch(arr, p, m - 1, value);
		}
	}
}

int main()
{
	int size; std::cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	insertionsort(arr, size);

	int value; std::cin >> value;
	int index=binarysearch(arr, 0, size-1, value);
	std::cout << "Value Index   " << index << std::endl;
	system("pause");
	return 0;
}