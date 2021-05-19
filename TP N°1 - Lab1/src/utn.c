#include <stdio.h>
#include <stdlib.h>

int getFloat(float* operand, char text[])
{
	float response;
	float bufferGet;

	printf("%s",text);
	fflush(stdin);
	if(scanf("%f",&bufferGet) == 1)
	{
		*operand = bufferGet;
		response = 1;
	}
	else
	{
		response = 0;
		printf("ERROR.");
		system("pause");
	}

	return response;
}

int getInt(char text[])
{
	int enteredOption;

	printf("%s",text);
	fflush(stdin);
	scanf("%d",&enteredOption);

	return enteredOption;
}
