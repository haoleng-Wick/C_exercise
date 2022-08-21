/*
 *
 * 罗马数字转整数
 * 用一个数组记录罗马数字每一个字符对应的数值
 * 然后通过比较大小进行加减
 * 最后输出整数
 *
 */
#include <stdio.h>
#include <string.h>

int roman_to_int(char *s)
{
	int sum = 0;
	int size = strlen(s);
	int temp[size];
	for (int i = 0; i < size; ++i) {
		switch(s[i]) {
			case 'I':
				temp[i] = 1;
				break;
			case 'V':
				temp[i] = 5;
				break;
			case 'X':
				temp[i] = 10;
				break;
			case 'L':
				temp[i] = 50;
				break;
			case 'C':
				temp[i] = 100;
				break;
			case 'D':
				temp[i] = 500;
				break;
			case 'M':
				temp[i] = 1000;
				break;
		}
	}

	for (int i = 0; i < size-1; ++i) {
		if(temp[i] >= temp[i+1]) {
			sum += temp[i];
		} else {
			sum -= temp[i];
		}
	}
	printf("temp = [ ");
	for (int i = 0; i < size; ++i) {
		printf("%d ",temp[i]);
	}
	printf("]\n");
	sum += temp[size-1];
	return sum;
}

int main(int argc, char **argv)
{
	printf("roman = %s\n", argv[1]);
	printf("int = %d\n",roman_to_int(argv[1]));
	return 0;
}
