// Lab1MSP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int MaxRepetition(char* arr, char* ch)
{
	int max = 0;

	for (int i = 0; arr[i] != '\0';)
	{
		int currentRepeat = 1;
		int j = i + 1;

		while (arr[i] == arr[j++])
		{
			currentRepeat++;
		}

		if (currentRepeat > max)
		{
			max = currentRepeat;
			*ch = arr[i];
		}

		i += currentRepeat;
	}

	return max;
}



int main()
{

	char* arr[] = { "", "Hello", "HHeeellllooooo" };
	char n = 0;

	for (int i = 0; i < 3; i++)
	{
		
		printf("%d ", MaxRepetition(arr[i],&n));
		printf("%c\n", n);
	}


    return 0;
}

