/*
 *
 * 动态规划
 * 给定一个集合,和一个测试数,求集合的子集的和是否等于该数
 * 例如(arr[] = {7, 10, 12, 8}, key = 16, 则输出false, 若key = 15, 则输出true)
 * 本程序规定 1表示true, 0表示false
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int re_dp(int arr[], int cur, int key);
int ure_dp(int arr[], int key);
int size;

// 递归求法
int re_dp(int arr[], int cur, int key)
{
	if(key == 0)	//key == 0时说明已经找到了和为测试数的子集
	{
		printf("select %d ", arr[cur]);
		return 1;
	}
	else if(cur == 0)	//递归到第一个数,则要判断它是否等于缺少的值
		return (arr[0] == key);
	else if(arr[cur] > key)	//若当前值大于缺少的值,则要弃掉
		return re_dp(arr, cur - 1, key);
	else
		return (re_dp(arr, cur - 1, key - arr[cur]) || re_dp(arr, cur - 1, key));	//选取当前值 || 不选当前值
}

// 非递归方法
// 用一个二维数组保存结果,避免重复计算
int ure_dp(int arr[], int key)
{
	int i, j, A, B;
	int temp[size][key + 1];	//行: arr[]内元素总数, 列: 0~key
	//初始化全为0
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < key + 1; ++j)
			temp[i][j] = 0;
	}

	for(i = 0; i < size; ++i)
		temp[i][0] = 1;		//第一种情况(key == 0)
	if(arr[0] == key)
		temp[0][0] = 1;		
	temp[0][arr[0]] = 1;	//到第一个数若相等则为true,否则为false

	for(i = 1; i < size; ++i)
	{
		for(j = 1; j < key + 1; ++j)
		{
			if(arr[i] > key)
				temp[i][j] = temp[i - 1][j];	//抛弃,直接选用前一个
			else {
				A = temp[i - 1][j - arr[i]];	//选取
				B = temp[i - 1][j];				//抛弃
				temp[i][j] = (A || B);
			}
		}
	}

	//打印二维数组
	int count = 0;
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < key + 1; ++j)
		{
			printf("%d ", temp[i][j]);
			count++;
			if(count == key + 1)
			{
				printf("\n");
				count = 0;
			}
		}
	}
	printf("\n");

	printf("temp[%d][%d] = %d\n", size - 1, key, temp[size - 1][key]);
	return temp[size - 1][key];
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("用法: 将数组以参数形式输入\n");
		printf("USE: ./a.out x x ...\n");
		return 0;
	}
	size = argc - 1;
	int arr[size];
	printf("arr[] = ");
	for(int i = 0; i < size; ++i)
	{
		sscanf(argv[i+1], "%d", &arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n");

	int key = 0;
	printf("please input the key: ");
	scanf("%d:\t", &key);
	printf("key = %d\n", key);

	int flag = re_dp(arr, size - 1, key);
	//int flag = ure_dp(arr, key);
	if(flag == 1)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
