/*
 * 课程表,返回学习顺序
 * prerequisites[i] = [ai, bi]表示学ai之前必须先学bi
 * input : numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * output: [0,1,2,3]
 *
 * 用到拓扑
 */
#include <stdio.h>
#include <stdlib.h>

void find_order(int num_courses, int (*prerequisites)[2], int prerequisites_size)
{
    int Hash[1024] = {0};   // 哈希表
    int *queue = (int *) malloc (sizeof(int) * (num_courses + 1));  // 创建队列
    int front = 0, rear = 0;    // 队头队尾
    for(int i = 0; i < prerequisites_size; i++)
        Hash[prerequisites[i][0]]++; // Hash存储每门科目所需的前置课程数目    
                                     // (如课程1需要1门，课程3需要2门)
    for(int i = 0; i < num_courses; i++)
    {
        if(Hash[i] == 0)
            queue[rear++] = i;  // 将没有前置要求的课程入队列
    }
    while(front < rear) // 遍历队列
    {
        int val = queue[front++];
        printf("%d ", val); // 输出无前置要求的课
        for(int i = 0; i < prerequisites_size; i++)
        {
            if(prerequisites[i][1] == val)  // 找到需要该课程为前置的课程
            {
                // 将其前置课程数目-1，并判断是否为无前置要求的课程
                if(--Hash[prerequisites[i][0]] == 0)    
                    queue[rear++] = prerequisites[i][0];
            }
        }
    }
    if(rear < num_courses)  // 如果最后输出的课程数目小于总课程数目，说明有冲突
        printf("Error, there are course conflicts ");
}

int main(int argc, char **argv)
{
    // 课程总数目
    // 课程前置要求表
    // 前置要求表的行数
    int numCourses = 4;
    int prerequisites[][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int prerequisites_size = sizeof(prerequisites) / sizeof(prerequisites[0]);

    printf("The default courses num is: 4\n");
    printf("The default prerequisites is: [[1,0], [2,0], [3,1], [3,2]]\n");
    printf("The courses order should be: [ ");
    find_order(numCourses, prerequisites, prerequisites_size);
    printf("]\n");
    
    return 0;
}
