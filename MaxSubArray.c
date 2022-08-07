/*
 *
 * 最大子数组和
 * 给你一个整数数组nums
 * 请你找出一个具有最大和的连续子数组(子数组最少包含一个元素)
 * 返回其最大和。
 *
 */
#include <stdio.h>

// 动态规划
int int_max(int i, int j)
{
	return i > j ? i : j;
}

int max_sub_array(int *nums, int nums_size)
{
	int cur = 0;
	int max = nums[0];

	for(int i = 0; i < nums_size; ++i) {
		cur = int_max(cur + nums[i], nums[i]);
		max = int_max(max, cur);
	}
	return max;
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("Use: ./a.out <arr>\n");
		return -1;
	}
	int size = argc - 1;
	int nums[size];
	for (int i = 0; i < size; ++i)
	{
		sscanf(argv[i + 1], "%d", &nums[i]);
	}
	int max_sub = max_sub_array(nums, size);
	printf("the max_sub_array's sum = %d\n", max_sub);
	return 0;
}

