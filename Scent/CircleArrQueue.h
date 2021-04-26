#pragma once
#include <iostream>

/// <summary>
/// 数组模拟环形队列
/// </summary>
class CircleArrQueue
{
public:
	CircleArrQueue(int size) :_maxSize(size) {
		_front = _rear = 0;
		arr = new int[size];
	}
	~CircleArrQueue() {
		if (arr)	delete arr;
	}

	//队列是否满
	bool isFull() {
		return (_rear + 1) % _maxSize == _front;
	}
	//队列是否空
	bool isEmpty() {
		return _front == _rear;
	}
	//加数据到队列
	void Add(int n) {
		if (!isFull()) {
			arr[_rear] = n;
			_rear = (_rear + 1) % _maxSize;
		}
	}

	//出队列
	int Get() {
		if (!isEmpty()) {
			int ret = arr[_front];
			_front = (_front + 1) % _maxSize;
			return ret;
		}
	}

	// 求当前队列有效长度
	int GetSize() {
		return (_rear + _maxSize - _front) % _maxSize;
	}

	//显示队列所有数据
	void ShowQueue() {
		if (!isEmpty()) {
			// 从front开始遍历, 遍历多少个元素
			int dataSize = GetSize();
			for (int i = _front; i < _front + dataSize; i++)
			{
				printf("arr[%d]=%d\n", i % _maxSize, arr[i % _maxSize]);
			}
			printf("\n");
		}
	}

	//显示头部数据
	int Head() {
		if (!isEmpty())
			return arr[_front];
	}

private:
	int _maxSize;
	int _front; //指向队头的前一个位置
	int _rear; //指向队尾的数据
	int* arr;
};