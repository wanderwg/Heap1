#include "Heap.h"



void AdjustDown(int* array, int size, int parent) {
	int child = parent * 2 + 1;//child标记了左孩子
	
	while (child < size) {
		//找双亲中较小的孩子
		if (child + 1 < size && array[child + 1] < array[child]) {
			child = child + 1;
		}

		if (array[child] < array[parent]) {
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void Swap(HPDatatype* pLeft, HPDatatype* pRight) {
	HPDatatype tmp = *pLeft;
	*pLeft = *pRight;
	*pRight = tmp;
}

void InitHeap(Heap* hp, HPDatatype* array, int size) {
	assert(hp);
	hp->_array = (HPDatatype*)malloc(sizeof(HPDatatype)*size);
	if (hp->_array == NULL) {
		assert(0);
		return;
	}
	hp->_capacity = size;
	for (int i = 0; i < size; ++i)
		hp->_array[i] = array[i];
	hp->_size = size;

	//将该完全二叉树进行调整使其满足堆的性质

	//找完全二叉树中倒数第一个非叶子节点
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root)
		AdjustDown(array, size, root);
}