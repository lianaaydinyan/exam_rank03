#include <unistd.h>
#include <stdarg.h>


int    ft_putchar(char c)
{
   return ( write(1,&c,1));
}

int s_string(char *str)
{
    int i;

    i = -1;
    if(!str)
        return(0);
    while(str[++i])
        write(1,&str[i],1);
    return (i);
}

int d_decimal(unsigned int n)
{
    int i;

    i = 0;
    if (n >= 10)
        d_decimal(n / 10);
    i++;
    ft_putchar("0123456789"[n % 10]);
    return (i);
}
int x_hexademical(unsigned int n)
{
	int i;

	i = 0;
	if(n >= 16)
		x_hexademical(n / 16);
	i++;
	ft_putchar("0123456789abcdef"[n % 16]);
	return(i);
}


int for_that_tree(char c, va_list list)
{
	int	res;

	res = 0;
    if (c == '%')
        res = ft_putchar('%');
    else if (c == 's')
        res = s_string(va_arg(list, char *));
    else if (c == 'd')
        res = d_decimal(va_arg(list, unsigned int));
    else if (c == 'x')
        res = x_hexademical(va_arg(list, unsigned int));
    return (res);
}

int ft_printf(const char *nshan, ... )
{
	int i;
	va_list my_avs;
	i = 0;
	int sum;

    sum = 0;
	va_start(my_avs , nshan);
    while(nshan[i])
    {
        if (nshan[i] == '%' && nshan[++i])
            sum += for_that_tree(nshan[i],my_avs);
        else if (nshan[i] == '%' && !nshan[i])
            break;
        else
            sum += write(1,&nshan[i],1);
        i++;
    }
    va_end(my_avs);
    return (sum);
}

int main(void)
{
    ft_printf("%s\n", "toto");
    ft_printf("Magic %s is %d\n", "number", 42);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
