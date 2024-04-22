#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>

template<typename T>
class Queue // Circular Queue
{
public:
	Queue(int capacity = 2)
	{
		assert(capacity > 0);

		capacity_ = capacity;
		queue_ = new T[capacity_];
		front_ = rear_ = 0;
	}

	~Queue()
	{
		if (queue_) delete[] queue_;
	}

	bool IsEmpty() const
	{
		return front_ == rear_;
	}

	bool IsFull() const
	{
		// ���� ť���� �� á���� ����
		return (rear_ + 1) % capacity_ == front_;
	}

	T& Front() const
	{
		assert(!IsEmpty());

		return queue_[(front_ + 1) % capacity_]; // ���� + 1
	}

	T& Rear() const
	{
		assert(!IsEmpty());

		return queue_[rear_];
	}

	int Size() const
	{
		if (front_ > rear_)
			return capacity_ - (front_ - rear_);
		else if (front_ < rear_)
			return rear_ - front_;
		else
			return 0;
	}

	void Resize() // 2�辿 ����
	{
		return;
	}

	void Enqueue(const T& item) // �� �ڿ� �߰�, Push()
	{
		if (IsFull())
			Resize();

		// TODO:
	}

	void Dequeue() // ť�� ù ��� ����, Pop()
	{
		assert(!IsEmpty());

		// TODO: 
	}

	void Print()
	{
		using namespace std;

		for (int i = (front_ + 1) % capacity_; i != (rear_ + 1) % capacity_; i = (i + 1) % capacity_)
			cout << queue_[i] << " ";
		cout << endl;

		if (print_debug_)
			PrintDebug();
	}

	void PrintDebug()
	{
		using namespace std;

		cout << "Cap = " << capacity_ << ", Size = " << Size();
		cout << endl;

		// front�� rear ��ġ ǥ��
		for (int i = 0; i < capacity_; i++) {
			if (i == front_) cout << " F ";
			else if (i == rear_) cout << " R ";
			else cout << "   ";
		}
		cout << endl;

		// 0 based index
		for (int i = 0; i < capacity_; i++)
			cout << setw(2) << i << " ";
		cout << endl;

		if (front_ < rear_)
		{
			// front �� ������� ���� ����
			for (int i = 0; i < front_ + 1; i++)
				cout << " - ";

			// ����� ���빰
			for (int i = front_ + 1; i <= rear_; i++)
				cout << setw(2) << queue_[i] << " ";

			// rear �� ������� ���� ����
			for (int i = rear_ + 1; i < capacity_; i++)
				cout << " * ";

			cout << endl << endl;
		}
		else if (front_ > rear_)
		{
			// rear ������ ����� ���빰
			for (int i = 0; i <= rear_; i++)
				cout << setw(2) << queue_[i] << " ";

			// rear�� front ���� ������� ���� ����
			for (int i = rear_ + 1; i <= front_; i++)
				cout << " * ";

			// front �� ���빰
			for (int i = front_ + 1; i < capacity_; i++)
				cout << setw(2) << queue_[i] << " ";

			cout << endl << endl;
		}
		else // ����� ���
		{
			for (int i = 0; i < capacity_; i++)
				cout << " - ";
			cout << endl << endl;
		}
	}

	void SetDebugFlag(bool flag)
	{
		print_debug_ = flag;
	}

protected: // �ڿ��� ����ؼ� ���
	T* queue_; // array for queue elements
	int front_ = 0; // ���� �ε������� �ϳ� ���� ��
	int rear_ = 0; // ������ �ε��� (ù ���� 1�� �߰�)
	int capacity_; // �� ĭ�� �ϳ� �־� �ϱ� ������ �ʿ� �޸𸮴� �ִ� ���差 + 1
	bool print_debug_ = false;
};