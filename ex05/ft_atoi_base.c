#include <stdio.h>

int			valid_str(char *str, int i)
{
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		if (str[i - 1] == '+' || str[i - 1] == '-')
			return (0);
	}
	else if (str[i] != '+' && str[i] != '-' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != '\v' && str[i] != '\f'
			&& str[i] != '\r')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int			def_str_start(char *str, char *base, int str_end, int base_len)
{
	int i;
	int j;
	int str_start;

	i = 0;
	j = 0;
	str_start = 0;
	while (str_start == 0)
	{
		i = 0;
		while (base[i] != '\0' && str_start == 0)
		{
			if (str[str_end] == base[i])
				break ;
			else if (str[str_end] != base[i] && i + 1 == base_len)
				str_start = str_end - 1;
			i++;
		}
		str_end++;
	}
	return (str_start);
}

int			dec(char *base, int base_len)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (base_len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == ' ')
				return (0);
			else if (base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int			to_num(char *str, char *base, int str_start, int str_end)
{
	int i;
	int j;
	int result;
	int base_len;

	i = 0;
	j = 1;
	result = 0;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	while (str_start != str_end - 1)
	{
		i = -1;
		while (base[++i] != '\0')
		{
			if (str[str_start] == base[i])
			{
				result = result + (j * i);
				j *= base_len;
			}
		}
		str_start--;
	}
	return (result);
}

int			ft_atoi_base(char *str, char *base)
{
	int str_start;
	int str_end;
	int base_len;
	int i;
	int mark;

	base_len = 0;
	i = 0;
	mark = 1;
	while (base[base_len] != '\0')
		base_len++;
	while (str[i] == ' ' || str[i] == '+' || str[i] == '-' ||
			(str[i] >= 9 && str[i] <= 13))
		if (valid_str(str, i++) == 0)
			return (0);
	str_end = i;
	str_start = def_str_start(str, base, i, base_len);
	while (str[i - 1] == '+' || str[i - 1] == '-')
		if (str[i-- - 1] == '-')
			mark *= -1;
	if (dec(base, base_len))
		return (mark * to_num(str, base, str_start, str_end));
	return (0);
}

int	main	()
{
	char str[] = "A5160df49";
	char base[] = "23B";
	printf("the result : %d", ft_atoi_base(str, base));
	return 0;
}
