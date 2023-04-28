/*
 * 将数组顺时针旋转90度
 */
#include <stdio.h>

int main(int argc, char **argv)
{
    int matrix[4][4] = {{5, 1, 9, 11},
                        {2, 4, 8, 10},
                        {13, 3, 6, 7},
                        {15,14,12,16}};
    printf("origin\n ");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n ");
    }
    printf("\n");
    // 先进行矩阵的转置
    for(int i=0; i<4; i++)
    {
        for(int j=i; j<4; j++)
        {
            int temp=matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // 再将矩阵左右对称交换
    int left=0,right=3;
    while(left < right)
    {
        for(int i=0; i < 4; i++)
        {
            int temp=matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
        }
        left++;right--;
    }
    printf("rotated\n ");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n ");
    }
    return 0;
}
