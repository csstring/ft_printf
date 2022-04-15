#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int a = 100;
	int	b;
	int c;

	b = ft_printf("aaaa\n%u\n%c\n%s\n%x\n%%\n%X\n%p",a,'b', "111111", 1000000,a,&a);
	printf("\n%d\n",b);
	c = printf("aaaa\n%u\n%c\n%s\n%x\n%%\n%X\n%p",a, 'b', "111111", 1000000,a,&a );
	printf("\n%d",c);
	return (0);
}
