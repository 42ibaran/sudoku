/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:43:55 by ibaran            #+#    #+#             */
/*   Updated: 2019/10/14 17:46:10 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H

# define SUDOKU_H

# include <stdbool.h>
# include "libft.h"

# define HORIZONTAL "\n- - - + - - - + - - -\n"
# define MAX_SOLUTIONS 42

enum				e_errors
{
	ERR_USAGE,
	ERR_OPEN_FILE,
	ERR_MEMORY,
	ERR_TOO_MANY_LINES,
	ERR_TOO_FEW_LINES,
	ERR_TOO_MANY_VALUES,
	ERR_TOO_FEW_VALUES,
	ERR_INVALID_NUMBER,
	ERR_INVALID_GRID,
	ERR_MAX_SOLUTION,
	ERR_NO_SOLUTION
};

typedef struct		s_cell
{
	char			value;
	bool			given;
	bool			error;
}					t_cell;

typedef struct		s_free
{
	t_cell			**grid;
}					t_free;

t_free				g_free;
int					g_solutions;

void				error(int flag, int line);
void				f_free(void);
void				print_grid(t_cell **grid);
void				init_globals(void);
t_cell				**allocate_grid(void);

t_cell				**parse(char *file_name);

int					solve(t_cell **grid, int i, int j);
bool				check_line(t_cell **grid, int i, int j);
bool				check_column(t_cell **grid, int i, int j);
bool				check_square(t_cell **grid, int i, int j);

#endif
