#include "Replacer.hpp"

static int	validate(int ac, char* av[])
{
	if (ac != 4)
	{
		std::cout << "Invalid number of arguments!" << std::endl;
		return 0;
	}
	if (!av[1][0])
	{
		std::cout << "Invalid file name!" << std::endl;
		return 0;
	}
	return 1;
}

static Replacer	*parser(int ac, char* av[])
{
	if (!validate(ac, av))
		return NULL;
	Replacer *replaced = new Replacer();
	if (!replaced)
	{
		std::cout << "Error creating class!" << std::endl;
		return NULL;
	}
	if(!replaced->set_new_file(av[1]))
	{
		replaced->file_closer();
		delete replaced;
		return NULL;
	}
	return replaced;
}

int	main(int ac, char* av[])
{
	Replacer *replaced = parser(ac, av);
}
