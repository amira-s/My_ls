#include "my.h"

void help()
{
	fprintf(stderr, "Usage: my_ls [options] PATH[...]\n"
		"Options:\n"
		"  -h         Affiche ce message d'aide.\n"
		);
}

void listing_func(void (**my_ls)(char *, int, int, int), char c)
{
	if  (c =='l')
		*my_ls = ls_l;
	else if (c == 'R')
		*my_ls = ls_R;
	else
		*my_ls = ls_basic;
}

void rec_list(char **argv, int *opt, void (*my_ls)(char *, int, int, int))
{
	char buff[PATH_MAX + 1];
	char *pwd;
	int optind;

	optind = opt[2];
	pwd = my_strcat(getcwd(buff, PATH_MAX + 1), "/");
	if (opt[2] == opt[1])
		my_ls(pwd, opt[0], opt[3], opt[4]);

	while (opt[2] < opt[1])
	{
		if (opt[1] - optind > 1)
			my_putstr(my_strcat(argv[opt[2]], ":\n"));
		my_ls(my_strcat(pwd, argv[opt[2]]), opt[0], opt[3], opt[4]);
		opt[2] += 1;
	}
}

void init_opt(int opt[5], int argc)
{
	opt[4] = 0;
	opt[0] = 0;
	opt[3] = 0;
	opt[1] = argc;
}

int main(int argc, char **argv)
{
	char c;
	void (*my_ls)(char *, int, int, int);
	int opt[5];

	init_opt(opt, argc);
	my_ls = ls_basic;
	while ((c = getopt(argc, argv, "lrRtdAaL")) != -1)
	{
		if (c == 'l' || c == 'R')
				listing_func(&my_ls, c);
		else if (c == 'a')
			opt[4] = 1;
		else if (c ==  'A')
			opt[4] = 2;
		else if (c == 'r')
			opt[3] = 1;
		else if (c == 't')
			opt[0] = 2;
		else if (c == 'h')
				help();
		else
		{
			my_putstr("Ligne de commande incorrecte.\n");
			return (1);
		}
	}
	opt[2] = optind;
	rec_list(argv, opt, my_ls);
	return (0);
}
