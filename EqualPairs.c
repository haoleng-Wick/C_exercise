/*
 * LeetCode  No.2352
 * 给定一个NxN方阵
 * 如果行和列以相同的顺序包含相同的元素，则二者相等
 × 要求输出行列相等的个数
 *
 * 例如：
 * 1  4  3 
 * 4  4  6 ----> 第二行和第二列相等，则输出为1
 * 7  6  9 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int **create_grid(int row, int col)
{
    srand((unsigned)time(NULL));
    int **grid = (int **)malloc(sizeof(int *) * row);
    printf("The martix randomly created is:\n");
    for(int i = 0; i < row; i++)
    {
        grid[i] = (int *)malloc(sizeof(int) * col);
        for(int j = 0; j < col; j++)
        {
            grid[i][j] = rand() % 2;
            printf("%d ", grid[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');

    return grid;
}

bool equal_rc(int row, int col, int size, int **grid)
{
    for(int i = 0; i < size; i++)
    {
        if(grid[row][i] != grid[i][col])
            return false;
    }
    return true;
}

int equal_pairs(int **grid, int row)
{
    int res = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if(equal_rc(i, j, row, grid))
                res++;
        }
    }
    return res;
}

int main(int argc, char **argv)
{
    if(argc != 2)
        fprintf(stderr, "Usage: ./a.out 4\n");

    int row = atoi(argv[1]); 
    int col = row;

    int **matrix = create_grid(row, col);

    printf("The same row and col number is: %d\n", equal_pairs(matrix, row));

    return 0;
}
