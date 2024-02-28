#include <iostream>

using namespace std;

// 스왑
void SwapPtr(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

// 선택정렬
void SelectionSort(int arr[], int n)
{
    int minIndex;
    for (int i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        SwapPtr(arr[i], arr[minIndex]);
    }
}

// 버블 정렬
void BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i ++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                SwapPtr(arr[j], arr[j + 1]);
        }
    }
}

// 삽입정렬
void InsertionSort(int* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i;
        for (; j > 0 && arr[j - 1] > temp; j--)
            arr[j] = arr[j - 1];

        arr[j] = temp;
    }
}


int main()
{
    int testArr[] = { 1,5,4,2,7,8,9,3,6 };
    int size = sizeof(testArr) / sizeof(testArr[0]);

    InsertionSort(testArr, size);

    cout << size << endl;
    for (auto e: testArr)
        cout << e;

    return 0;
}
