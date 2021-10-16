#include "Input.h"

void getString(char message[],char string[],int tam)
{
	char auxiliar[tam];

	printf("%s", message);
	fflush(stdin);
	fgets(auxiliar, sizeof auxiliar, stdin);
	strcpy(string, auxiliar);
}

int getNumber(int* pResult, char message[], char errorMessage[], int min, int max, int retries)
{
	int number;
	int validation = -1;

	printf("%s", message);
	while(retries > 0)
	{
		retries--;
		if (stringValidation(&number) == 0)
		{
			if (number >= min && number <= max)
			{
				*pResult = number;
				validation = 0;
				break;
			}
			break;
		}
		printf("%s", errorMessage);
	}

	return validation;
}
int stringValidation(int* pResult)
{
	int validation = -1;
	char string[20];

	scanf("%s", string);

		if(numberValidation(string) == 0)
		{
		*pResult = atoi(string);
		validation = 0;
		}

	return validation;
}
int numberValidation(char string[])
{
	int i = 0;
	int validation = 0;

		if (string[i] == '-')
		{
			i = 1;
			while (string[i] != '\0')
			{
				if ((isdigit(string[i])) == 0)
				{
					validation = -1;
					break;
				}
				i++;
			}
		}
		else
		{
			while (string[i] != '\0')
			{
				if ((isdigit(string[i])) == 0)
				{
					validation = -1;
					break;
				}
				i++;
			}
		}
	return validation;
}

int getFloat(float* pResult, char message[], char errorMessage[], int min, int max, int retries)
{
	float number;
	int validation = -1;

	printf("%s", message);

	while(retries > 0)
	{
		retries--;
		if (floatStringValidation(&number) == 0)
		{
			if (number >= min && number <= max)
			{
				*pResult = number;
				validation = 0;
				break;
			}
			break;
		}
		printf("%s", errorMessage);
	}
	return validation;
}

int floatStringValidation(float* result)
{
	int validation = -1;
	char string[20];

	scanf("%s", string);

	if(floatNumberValidation(string) == 0)
	{
		*result = atof(string);
		validation = 0;
	}
	return validation;
}

int floatNumberValidation(char string[])
{
	int i = 0;
	int validation = 0;
	int flagDot = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '.' && flagDot == 0)
		{
			i++;
			flagDot = 1;
			if ((isdigit(string[i])) == 0)
			{
				validation = -1;
				break;
			}
			i++;
		}
		else
		{
			if ((isdigit(string[i])) == 0)
			{
				validation = -1;
				break;
			}
			i++;
		}
	}
	return validation;
}
