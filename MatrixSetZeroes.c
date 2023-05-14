/*
 * 将矩阵置零 Leetcode 73.
 * 给定一个mxn的矩阵，如果一个元素为0
 * 那么将其所在的行和列全部设为0
 * 要求空间复杂度尽量少
 * input:
 * 1  1  2  0
 * 3  4  8  2
 * 1  0  2  1
 * output:
 * 0  0  0  0
 * 3  0  8  0
 * 0  0  0  0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void set_zeroes(int **matrix, int matrix_size, int *matrix_col_size)
{
    int row = matrix_size;
    int col = matrix_col_size[0];
    int flag_col0 = 0;
    for(int i = 0; i < row; i++)
    {
        //记录第一列是否出现0
        if(!matrix[i][0])
            flag_col0 = 1;
        for(int j = 1; j < col; j++)
        {
            //在第一行第一列中记录0的行和列
            if(!matrix[i][j])
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    // 第一行既作为标记数组又作为待检查数组
    // 行从下往上遍历，因为没有设置第一行的零标记
    for(int i = row - 1; i >= 0; i--)
    {
        for(int j = 1; j < col; j++)
        {
            if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
        }
        if(flag_col0)
            matrix[i][0] = 0;
    }
}

int main(int argc, char **argv)
{
    if(argc != 3)
        fprintf(stderr, "Usage: ./a.out 3 4\n");

    srand((unsigned)time(NULL));
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    int *col_sizes = (int *)malloc(col * sizeof(int));
    int **matrix = (int **)malloc(row * sizeof(int *));
    printf("Original matrix:\n");
    for(int i = 0; i < row; i++)
    {
        col_sizes[i] = col;
        matrix[i] = (int *)malloc(col_sizes[i] * sizeof(int));
        for(int j = 0; j < col_sizes[i]; j++)
        {
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    set_zeroes(matrix, row, col_sizes);

    printf("Then: \n");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col_sizes[i]; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
