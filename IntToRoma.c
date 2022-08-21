/*
 *
 * 整数转罗马数字
 * 1 <= num <= 3999
 * 将给定的数字减去特定的值，
 * 然后以此类推替换为相应的罗马符号
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 13个基本的罗马数字 */
const int values[] = {1000, 900, 500, 400, 100, 90,
					50, 40, 10, 9, 5, 4, 1};
const char *symbols[] = {"M", "CM", "D", "CD", "C", "XC",
					"L", "XL", "X", "IX", "V", "IV", "I"};

char *int_to_roman(int num)
{
	char *roman = malloc(sizeof(char) * 16);
	roman[0] = '\0';
	for (int i = 0; i < 13; ++i) {
		while (num >= values[i]) {
			num -= values[i];
			strcpy(roman + strlen(roman), symbols[i]);
		}
		if (num == 0)
			break;
	}
	return roman;
}

int main(int argc, char **argv)
{
	int num = 0;
	sscanf(argv[1], "%d", &num);
	printf("int = %d\n", num);
	printf("roman = %s\n", int_to_roman(num));
	return 0;
}
