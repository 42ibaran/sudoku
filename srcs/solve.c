/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:06:34 by ibaran            #+#    #+#             */
/*   Updated: 2019/10/14 17:42:55 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

bool	check_line(t_cell **grid, int i, int j)
{
	int		j_check;

	j_check = -1;
	while (++j_check < 9)
		if (grid[i][j_check].value == grid[i][j].value && j != j_check)
			return (FALSE);
	return (TRUE);
}

bool	check_column(t_cell **grid, int i, int j)
{
	int		i_check;

	i_check = -1;
	while (++i_check < 9)
		if (grid[i_check][j].value == grid[i][j].value && i != i_check)
			return (FALSE);
	return (TRUE);
}

bool	check_square(t_cell **grid, int i, int j)
{
	int		i_plus;
	int		j_plus;
	int		value_check;

	i_plus = 0;
	while (i_plus < 3)
	{
		j_plus = 0;
		while (j_plus < 3)
		{
			value_check = grid[i - i % 3 + i_plus][j - j % 3 + j_plus].value;
			if (value_check == grid[i][j].value
					&& i != i - i % 3 + i_plus
					&& j - j % 3 + j_plus)
				return (FALSE);
			j_plus++;
		}
		i_plus++;
	}
	return (TRUE);
}

int		solve(t_cell **grid, int i, int j)
{
	if (i == 9 && ++g_solutions)
	{
		if (g_solutions > 1)
			ft_printf("\nAnother solution:\n");
		print_grid(grid);
		if (g_solutions > MAX_SOLUTIONS)
			error(ERR_MAX_SOLUTION, 0);
		return (-1);
	}
	if (j == 9)
		return (solve(grid, i + 1, 0));
	if (grid[i][j].given)
		return (solve(grid, i, j + 1));
	while (++grid[i][j].value <= 9)
		if (check_line(grid, i, j)
				&& check_column(grid, i, j)
				&& check_square(grid, i, j)
				&& solve(grid, i, j + 1) == 1)
			return (1);
	grid[i][j].value = 0;
	return (-1);
}
