#include "../src/my.h"

int	my_strlen(char *str);

char	*my_strcpy(char *src)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (my_strlen(src) + 1));
	while (i < my_strlen(src))
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}


