#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    // ���ڿ� �������� ����Ʈ�ϱ�

    const char str[] = "Hi bong!";
    const int l = sizeof(str) - 1;

    cout << str << endl;

    Stack<char> stack;

    for (int i = 0; i < l; i++)
        stack.Push(str[i]);

    stack.Print();

    while (!stack.IsEmpty())
    {
        cout << stack.Top();
        stack.Pop();
    }

    cout << endl;

    return 0;
}
