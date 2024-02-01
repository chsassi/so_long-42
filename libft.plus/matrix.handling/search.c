#include "libft.h"

void	reset_matrix_to_x(char **mtx, int cols, int rows)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows )
	{
		j = -1;
		while (++j < cols)
			mtx[i][j] = 'X';
	}
}
