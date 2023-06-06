/*
 *
 * 非递增顺序的最小子序列
 * 给你一个数组,请从中返回一个子序列
 * 满足其元素之和严格大于未包含在该子序列的各元素之和
 * 示例 nums = [4, 3, 10, 9, 8]
 * out: [10, 9]
 *
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;   // 这是从小到达的排序
    // 从大到小如下所示：
    // return *(int *)b - *(int *)a;
}

int main(int argc, char **argv)
{
	int numsSize = argc - 1;
	int nums[numsSize];
	int *returnSize;

	for(int i = 0; i < numsSize; ++i)
	{
		sscanf(argv[i+1], "%d", &nums[i]);
	}

	int sum = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		sum += nums[i];
	}

/* C语言自带的快速排序函数 
 * 与上面的cmp配合使用 */
	qsort(nums, numsSize, sizeof(int), cmp);
	printf("qsort nums = [ ");
	for (int i = 0; i < numsSize; ++i)
	{
		printf("%d ", nums[i]);
	}
	printf("]\n");

/* 将顺序数组从后向前加,直至满足条件并返回*/
	int *out_nums = (int *)malloc(sizeof(int) * numsSize);
	int cur =0, pos = 0;
	for(int i = numsSize - 1; i >= 0; --i)
	{
		cur += nums[i];
		out_nums[pos++] = nums[i];
		if (sum - cur < cur)
			break;
	}

	returnSize = &pos;
	printf("returnSize = %d\n", *returnSize);

	printf("out_nums = [ ");
	for (int i = 0; i < *returnSize; ++i)
	{
		printf("%d ", out_nums[i]);
	}
	printf("]\n");

	free(out_nums);

	return 0;
}
