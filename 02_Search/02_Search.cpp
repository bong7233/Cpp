#include <iostream>
#include <cassert> // assert()

using namespace std;

// 단순 카운트
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

// 순차 탐색 (찾으면 뒤로 안가고 바로 인덱스 리턴)
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

// 이진탐색 (정렬된 배열 대상) - 반으로 나눠서 앞뒤로 범위 좁힘
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
	// 정렬되지 않은 arr
	//int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 , 1, 1 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	// 정렬된 arr
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int result = BinarySearch(arr, n, 4); // 3 나와야 함
	cout << result << endl;

	return 0;
}



