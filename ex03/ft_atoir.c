#include <stdlib.h>
#include <stdio.h>


int	ft_is_space_or_minus_or_numeric(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	if (c == '-' || c == '+')
		return (2);
	if (47 < c && c < 58)
		return (3);
	return (0);
}

int	ft_power(int power)
{
	int i;
	int base;

	i = 0;
	base = 1;
	while (i < power - 1)
	{
		base *= 10;
		i++;
	}
	return (base);
}

int	ft_convert_to_int(int *array, int count, int len)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < len)
	{
		nb += array[i] * ft_power(len - i);
		i++;
	}
	if (count % 2 != 0)
		return (nb * -1);
	return (nb);
}

int	ft_atoi(char *str)
{
	int i;
	int j;
	int minus_count;
	int array[100];

	i = -1;
	j = 0;
	minus_count = 0;
	while (str)
	{
		i++;
		if (ft_is_space_or_minus_or_numeric(str[i]) != 0)
		{
			if (str[i] == '-')
				minus_count++;
			if (ft_is_space_or_minus_or_numeric(str[i]) == 3)
			{
				array[j] = str[i] - '0';
				j++;
			}
			continue;
		}
		return (ft_convert_to_int(array, minus_count, j));
	}
	return (0);
}

int	main	()
{
	char str[] = "+--+-+12346 7a b7789";
	printf("Atoi generate : %d\n",ft_atoi(str));
	return 0;
}
