/*
 * 给定一个长度为n的整数数组height
 * 有n条垂直线，找出其中的两条线
 * 使得它们与x轴共同构成的容器可以容纳最多的水
 * 返回其最大容水量
 * input : [1, 8, 6, 2, 5, 4, 8, 3, 7]
 *   ^
 * 10|                            
 * 9 |                         
 * 8 |   |______________|______
 * 7 |   |              |     | 
 * 6 |   |  |           |     | 
 * 5 |   |  |     |     |     | 
 * 4 |   |  |     |  |  |     | 
 * 3 |   |  |     |  |  |  |  | 
 * 2 |   |  |  |  |  |  |  |  | 
 * 1 ||  |  |  |  |  |  |  |  | 
 *   ----------------------------->
 * 0  1  2  3  4  5  6  7  8  9
 * output: 49
 *
 * 用到双指针
 */
#include <stdio.h>

int max_area(int *height, int height_size)
{
    int max = 0;
    int left = 0, right = height_size - 1;
    int area;
    while(left < right)
    {
        // 从最短的一侧开始往中间缩进
        if(height[left] < height[right])
        {
            area = height[left] * (right - left);
            left++;
        }
        else
        {
            area = height[right] * (right - left);
            right--;
        }
        max = (max > area) ? max : area;
    }
    return max;
}

int main(int argc, char **argv)
{
    int len = argc - 1;
    int height[len];
    printf("Your input is: [ ");
    for(int i = 0; i < argc - 1; i++)
    {
        sscanf(argv[i+1], "%d", &height[i]);
        printf("%d ", height[i]);
    }
    printf("]\n");
    int height_size = sizeof(height) / sizeof(height[0]);
    printf("the max area is: %d\n", max_area(height, height_size));
    return 0;
}
