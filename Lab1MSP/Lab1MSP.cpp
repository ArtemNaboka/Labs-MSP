// Lab1MSP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"


int MaxSubstring(char* arr)
{
	int max = 0;
	int length = strlen(arr);

	for (int i = 0; i < length; i++)
	{
		int currentRepeat = 1;
		int j = i + 1;

		while (arr[i] == arr[j++])
		{
			currentRepeat++;
		}

		if (currentRepeat > max)
			max = currentRepeat;
	}

	return max;
}


int main()
{
	char mas[] = "";

	int s = MaxSubstring(mas);
	printf("%d", s);

    return 0;
}

