#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdbool.h> //bool, true, false 사용 헤더파일
#include <math.h>

void showRandom(void)
{
	int randO = rand() % 10;
	int arr[3][3] = {7, 8, 9, 0, 5, 6, 1, 2, 3};
	printf("%d", randO);
	printf("%d", *arr[randO]);

}

int main(void)
{
	showRandom();

	return 0;
}