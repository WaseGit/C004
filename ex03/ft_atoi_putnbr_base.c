#include <unistd.h>
#include <stdio.h>

void	write_number(unsigned int nbr_tmp, unsigned int i, char *base)
{
	unsigned int share;
	unsigned int remainder;

	share = nbr_tmp / i;
	remainder = nbr_tmp % i;
	if (share != 0)
	{
		write_number(share, i, base);
	}
	write(1, &base[remainder], 1);
}

int		check_array(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (*(base + i) != '\0')
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = i + 1;
		while (*(base + j) != '\0')
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

	ft_putnbr_base(int nbr, char *base)
{
	unsigned int nbr_tmp;
	unsigned int i;

	i = check_array(base);
	if (i != 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * -1;
		}
		nbr_tmp = (unsigned int)nbr;
		write_number(nbr_tmp, i, base);
	}
}

int main ()
{
	char base[] = "poneyv";
	 printf("%d", check_array(base));
	int nbr = 100;
	ft_putnbr_base(nbr, base);

	return 0;
}
