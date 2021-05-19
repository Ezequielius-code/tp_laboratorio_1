float addition(float a, float b)
{
	float result;

	result = a + b;

	return result;
}

float subtraction(float a, float b)
{
	float result;

	result = a - b;

	return result;
}

float multiplication(float a, float b)
{
	float result;

	result = a * b;

	return result;
}

float division(float a, float b)
{
	float result;

	if (b == 0)
	{
		result = 0;
	}
	else
	{
		result = a / b;
	}

	return result;
}

int isInteger(float a)
{
	int result = 0;

	if ((a - (int) a) == 0)
	{
		result = 1;
	}

	return result;
}

int factorial(float a)
{
	int result = a;
	int i;

	if (isInteger(a) == 1 && a > 0)
	{
		for (i = result; i > 1; --i)
		{
			result = ((i - 1) * result);
		}
	}
	else
	{
		result = 0;
	}

	return result;
}
