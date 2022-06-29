#include "push_swap.h"
#include "libft.h"

static int error()
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	char	**strs;

	if (argc < 2)
		return (error());
	else if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = copy_strs(argv, argc);
	if (!check_input(strs))
		return (error());
	a.size = count_arr(strs);
	a.arr = strs_to_ints(strs);
	if (!check_ints(a.arr))
		return (error());
	sort(&a);
	free(a.arr);
	free_strs(strs);
	return (0);
}
