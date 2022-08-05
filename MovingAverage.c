/*
 *
 * 滑动窗口平均值
 * 参数<窗口大小><next><next>.....
 * 示例： /.a.out 3 2 4 5 7 9 0
 * 					| \|
 * 输出:     [null, 2, 3, 3, 5 ,7 ,5, ]
 * 	2=2, 3=(2+4)/2, 3=(2+4+5)/3, 5=(4+5+7)/3, 7=(5+7+9)/3 .....
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct MovingAverage{
	int size;
	double sum;
	int* queue;
	int front;
	int rear;
}MovingAverage;


MovingAverage* movingAverageCreate(int size) {
	MovingAverage *obj = (MovingAverage *)malloc(sizeof(MovingAverage));
	obj->size = size;
	obj->sum = 0;
	obj->queue = (int* )malloc(sizeof(int) * (size + 1));
	obj->front = 0;
	obj->rear = 0;

	return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
	int size = (obj->rear - obj->front + obj->size + 1) % (obj->size + 1); //当前队列的长度
	//长度超届 入队尾出队头
	if(size == obj->size) {
		obj->sum -= obj->queue[obj->front];
		obj->front = (obj->front + 1) % (obj->size + 1);
		size--;
	}
	obj->queue[obj->rear] = val;
	obj->rear = (obj->rear + 1) % (obj->size + 1);
	obj->sum += val;
	size++;
	return obj->sum / size;

}

void movingAverageFree(MovingAverage* obj) 
{
	free(obj->queue);
	free(obj);
}


int main(int argc, char* argv[])
{
	int num = 0; int aver = 0;
	sscanf(argv[1], "%d", &num);
	MovingAverage *obj = movingAverageCreate(num);
	printf("[null, ");
	for (int i = 0; i < argc - 2; i++) {
		sscanf(argv[i+2],"%d", &num);
		aver = movingAverageNext(obj, num);
		printf("%d, ", aver);
	}

	printf("]\n");
	return 0;
}
