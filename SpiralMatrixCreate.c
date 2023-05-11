/*
 * LeetCode 59
 * 给一个正整数n，生成一个包含1~n^2所有元素
 * 且按照顺时针螺旋排列的n x n方阵matrix
 *
 * intput: n = 3;
 * output:
 *          1  2  3
 *          8  9  4
 *          7  6  5
 * 由外而内逐层创建
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 传入矩阵的行数，传出矩阵的行数，传出矩阵每行的列数
int **generate_matrix(int n, int *return_size, int **return_col_sizes)
{
    int count = 0;
    int **matrix = (int **)malloc(n * sizeof(int *));
    *return_size = n;
    *return_col_sizes = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int)); // 为每行分配每列的内存
        // 复制字符0到matrix[i]所指向字符串的前n个位置(即该行的每列)
        memset(matrix[i], 0, n * sizeof(int));
        (*return_col_sizes)[i] = n; // 返回该行所含的列数
    }

    int left =0, right = n - 1, top = 0, bottom = n - 1;

    while(left <= right && top <= bottom)
    {
        for(int col = left; col <= right; col++)
            matrix[top][col] = ++count;
        for(int row = top + 1; row <= bottom; row++)
            matrix[row][right] = ++count;
        // 是否到达最内一层
        if(left < right && top < bottom)
        {
            for(int col = right - 1; col > left; col--)
                matrix[bottom][col] = ++count;
            for(int row = bottom; row > top; row--)
                matrix[row][left] = ++count;
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return matrix;
}

int main(int argc, char **argv)
{
    if(argc != 2)
        fprintf(stderr, "Usage: ./a.out 3\n");

    int n = atoi(argv[1]);
    int count = 0;
    int *col_sizes;

    int **matrix = generate_matrix(n, &count, &col_sizes);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
