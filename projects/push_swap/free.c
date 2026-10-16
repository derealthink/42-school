#include "push_swap.h"

void	free_split(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
//free stack functiions would also be great;

