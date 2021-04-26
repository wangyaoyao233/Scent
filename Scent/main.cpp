#include <iostream>
#include "SparseArray.h"
#include "ArrQueue.h"
#include "CircleArrQueue.h"

int main()
{
	CircleArrQueue queue(4);

	queue.Add(1);
	queue.ShowQueue();
	queue.Add(2);
	queue.ShowQueue();
	queue.Add(3);
	queue.ShowQueue();

	printf("get %d\n", queue.Get());
	printf("size %d\n", queue.GetSize());
	queue.ShowQueue();

	queue.Add(4);
	queue.ShowQueue();
}