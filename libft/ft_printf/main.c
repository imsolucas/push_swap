int	ft_printf(const char *str, ...);

#include	<stdio.h>
#include <limits.h>

int main()
{
	char	*ptr;

	ptr = "Hello";
	printf(" ,ft_printf: %d\n", ft_printf("Hello %c, %s, %d, %i, %u, %x, %X, %p, %%", 'a', "COLDPLAY", 5088, 42, 48, 6088, 6088, ptr, 10));
	// printf("ori: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	// ft_printf("mine: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	// ft_printf("ori: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	// printf("mine: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	// printf("printf: %d\n", printf("Hello %c %s %d %i %u %x %X %p %%", 'a', "COLDPLAY", 5088, 42, 48, 6088, 6088, ptr, "%"));
	return (0);
}