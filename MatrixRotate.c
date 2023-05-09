/*
 * 将方阵顺时针旋转90度
 * 使用翻转法
 * 先通过水平翻转，在根据主对角线翻转
 *
 * 1  2  3   水平    7  8  9   对角线     7  4  1
 * 4  5  6  ----->   4  5  6  -------->   8  5  2
 * 7  8  9           1  2  3              9  6  3
 */
#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int i, j;
    // 水平翻转
    for(i = 0; i < matrixSize / 2; i++)
    {
        for(j = 0; j < matrixColSize[i]; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - i - 1][j];
            matrix[matrixSize - i - 1][j] = tmp;
        }
    }
    // 对角线翻转
    for(i = 0; i < matrixSize; i++)
    {
        for(j = 0; j < i; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}

int main(int argc, char **argv)
{
    // 告知正确用法
    if(argc != 2)
        fprintf(stderr, "Usage: ./a.out 3\n");

    // 初始化变量
    int i, j, count = 0;
    int row_size = atoi(argv[1]);
    int *col_size = (int *)malloc(row_size * sizeof(int));
    int **matrix = (int **)malloc(row_size * sizeof(int *));

    // 创建矩阵
    printf("Original matrix:\n");
    for(i = 0; i < row_size; i++)
    {
        col_size[i] = row_size;
        matrix[i] = (int *)malloc(col_size[i] * sizeof(int));
        for(j = 0; j < col_size[i]; j++)
        {
            matrix[i][j] = ++count;
            printf("%3d ", matrix[i][j]);
        }
        putchar('\n');
    }

    // 旋转矩阵
    rotate(matrix, row_size, col_size);
    // 打印
    printf("Ortated matrix:\n");
    for(i = 0; i < row_size; i++)
    {
        for(j = 0; j < col_size[i]; j++)
        {
            printf("%3d ", matrix[i][j]);  // 输出宽度3，右对齐空缺补空格
        }
        putchar('\n'); // printf("\n");
    }

    return 0;
}
