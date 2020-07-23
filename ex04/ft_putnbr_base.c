#include <unistd.h>
#include <stdio.h>

char	ft_putchar(char a)
{
	write(1, &a, 1);
	return 0;
}

int	ft_getlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	if (base[0] == '\0')
		return (0);
	while (base)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
	}
	while (base)
	{
		if (base[i] == base[j])
		{
			return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int i;
	char digits_rev[1024];
	int base_len;
	unsigned int unbr;
	int a;

	a = 1;
	unbr = (unsigned) nbr;
	base_len = ft_getlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = nbr * -1;
		a = 0;
	}
	while (unbr > 0)
	{
		digits_rev[i] = base[unbr % base_len];
		unbr /= base_len;
		i++;
		a = 1;
	}
	while (i > 0)
	{
		ft_putchar(digits_rev[i - 1]);
		i--;
		a = -1;
	}
	return (a * unbr);


}

int	main()
{
	char base[] = "1rtel9";
       	printf("Atoi print base ganerate: %d \n", ft_putnbr_base(300, base));
	return 0;	
}
