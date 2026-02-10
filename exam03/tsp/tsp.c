#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

float distance(float *a, float *b)
{
    return sqrtf((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
}

int main(int argc, char **argv)
{
	float	**city;
	float garb;
	int i;

	while (fscanf(stdin, "%f, %f", &garb, &garb) == 2)
		i++;
	fseek(stdin, 0, SEEK_SET);
	city = calloc(i, sizeof(float *));
	for (int j = 0; j < i; j++)
	{
		city[j] = calloc(2, sizeof(float));
		fscanf(stdin, "%.2f, %.2f", &city[j][0], &city[j][1]);
	}
}
