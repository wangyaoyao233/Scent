#pragma once
#include <iostream>

class ArrQueue
{
public:
	ArrQueue(int size) : _maxSize(size){
		_front = _rear = -1;
		arr = new int[_maxSize];
	}
	~ArrQueue(){
		if (arr) delete arr;
	}

	//队列是否满
	bool isFull() {
		return _rear >= _maxSize - 1;
	}
	//队列是否空
	bool isEmpty() {
		return _front == _rear;
	}
	//加数据到队列
	void Add(int n) {
		if (!isFull()) {
			_rear++;
			arr[_rear] = n;
		}
	}

	//出队列
	int Get() {
		if (!isEmpty()) {
			int ret = arr[_front + 1];
			_front++;
			return ret;
		}
		else
			return INT_MIN;
	}

	//显示队列所有数据
	void ShowQueue() {
		if (!isEmpty()) {
			int ref = _front;
			while (ref != _rear){
				ref++;
				printf("%d ", arr[ref]);
			}
			printf("\n");
		}
	}

	//显示头部数据
	int Head() {
		if (!isEmpty())
			return arr[_front + 1];
		else 
			return INT_MIN;
	}

private:
	int _maxSize;
	int _front; //指向队头的前一个位置
	int _rear; //指向队尾的数据
	int* arr;
};