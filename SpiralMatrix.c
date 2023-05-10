/*
 * 给定m行n列的矩阵matrix
 * 返回矩阵顺时针螺旋遍历的元素
 *
 * 1  2  3  4
 * 5  6  7  8       ----> {1,2,3,4,8,12,11,10,9,5,6,7}
 * 9  10 11 12
 *
 * 由外而内逐层遍历
 */
#include <stdio.h>
#include <stdlib.h>

int *spiral_order(int **matrix, int row_size, int *col_sizes, int *return_size)
{
    // 非空判断
    if(row_size == 0)
    {
        *return_size = 0;
        return NULL;
    }

    int rows = row_size, cols = col_sizes[0];
    int total = rows * cols;
    int *order = (int *)malloc(total * sizeof(int));    // 分配内存
    *return_size = 0;   // 从零遍历

    int left = 0, right = cols - 1;
    int top = 0, bottom = rows - 1; // 四个角的下标

    while(left <= right && top <= bottom)
    {
        for(int col = left; col <= right; col++)
            order[(*return_size)++] = matrix[top][col];
        for(int row = top + 1; row <= bottom; row++)
            order[(*return_size)++] = matrix[row][right];
        // 是否到达最内一层
        if(left < right && top < bottom)
        {
            for(int col = right - 1; col > left; col--)
                order[(*return_size)++] = matrix[bottom][col];
            for(int row = bottom; row > top; row--)
                order[(*return_size)++] = matrix[row][left];
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return order;
}

int main(int argc, char **argv)
{
    if(argc != 3)
        fprintf(stderr, "Usage: ./a.out 3 4\n");

    int count;
    int row_size = atoi(argv[1]);
    int cow = atoi(argv[2]);

    int *col_sizes = (int *)malloc(row_size * sizeof(int));
    int **matrix = (int **)malloc(row_size * sizeof(int *));

    for(int i = 0; i < row_size; i++)
    {
        col_sizes[i] = cow;
        matrix[i] = (int *)malloc(col_sizes[i] * sizeof(int *));
        for(int j = 0; j < col_sizes[i]; j++)
        {
            matrix[i][j] = ++count;
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }

    int *nums = spiral_order(matrix, row_size, col_sizes, &count); 

    for(int i = 0; i < count; i++)
        printf("%d ", nums[i]);
    putchar('\n');

    return 0;
}
