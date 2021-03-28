#include <iostream>
#include "SparseArray.h"
#include "ArrQueue.h"


int main()
{
	ArrQueue aq(3);

	aq.Add(1);
	aq.Add(2);
	aq.Add(3);

	aq.ShowQueue();
	printf("%d\n", aq.Head());

	aq.Add(4);
	aq.ShowQueue();

	printf("%d\n", aq.Get());
	printf("%d\n", aq.Get());
	printf("%d\n", aq.Get());
	printf("%d\n", aq.Get());
	aq.ShowQueue();
}