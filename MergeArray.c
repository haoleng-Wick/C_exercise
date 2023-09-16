/*
 * 给定两个非递减顺序排列的整数数组nums1和nums2
 * 另外有两个m和n 分别表示数组中元素的个数
 *
 * 请合并nums1和nums2, 使合并后的数组同样按照非递减顺序排列
 * 最终数组不应由函数返回，而是存储在nums1中。
 * 因此nums1的初始长度为 m + n
 *
 * input : nums1 = [1, 2, 3, 0, 0, 0], m = 3,
 *         nums2 = [2, 5, 6],          n = 3
 * output: [1, 2, 2, 3, 5, 6]
 *
 */
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}

void merge(int *nums1, int size1, int *nums2, int size2)
{
    for (int i = 0; i < size2; i++) {
        nums1[size1 - size2 + i] = nums2[i];
    }
    for (int i = 0; i < size1; i++) {
        printf("%d ", nums1[i]);
    }
    putchar('\n');
    qsort(nums1, size1, sizeof(int), cmp_int);
}

int main(int argc, char **argv)
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int size1 = sizeof(nums1) / sizeof(*nums1);
    int size2 = sizeof(nums2) / sizeof(*nums2);
    merge(nums1, size1, nums2, size2);
    for (int i = 0; i < size1; i ++) {
        printf("%d ", nums1[i]);
    }
    putchar('\n');
    return 0;
}
