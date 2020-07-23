#include  <unistd.h>
#include  <stdio.h>

void 	ft_putchar(char c)
{

	write (1, &c, 1);
}

//#include <libft.h>

int		ft_putnbr(int n)
{
	unsigned int i;

	i=0;
	if (n == -2147483648)
		write(1, n++, 1);
	if ((n < 0) && (n != -2147483648))
	{
		ft_putchar('-');
		n = -1 * n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if ((n < 10) && (n != -2147483648))
		ft_putchar(n + '0');
}
