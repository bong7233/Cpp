#include <iostream>
#include <cassert> // assert()

using namespace std;

// �ܼ� ī��Ʈ
int Count(int* arr, int n, int x)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			cnt += 1;
	}

	return cnt;
}

// ���� Ž�� (ã���� �ڷ� �Ȱ��� �ٷ� �ε��� ����)
int SequentialSearch(int* arr, int n, int x)
{
	int xIndex(-1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			return i;
	}

	return -1;
}

// ����Ž�� (���ĵ� �迭 ���) - ������ ������ �յڷ� ���� ����
int BinarySearch(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] > x)
		{
			right = mid - 1;
			cout << "right " << right << endl;
		}
		else if(arr[mid] < x)
		{
			left = mid + 1;
			cout << "left " << left << endl;
		}
		else
		{
			cout << "Found " << mid << endl;
			return mid;
		}
	}
	return -1;

}



int main()
{
	// ���ĵ��� ���� arr
	//int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 , 1, 1 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	// ���ĵ� arr
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int result = BinarySearch(arr, n, 4); // 3 ���;� ��
	cout << result << endl;

	return 0;
}



