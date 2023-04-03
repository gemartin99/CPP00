#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int control;
	int i;
	int j;

	control = 0;
	i = 0;
	while (argv[++i])
	{
		if (argv[i][0])
			control = 1;
	}
	if (argc == 1 || control == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 0;
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return 0;
}