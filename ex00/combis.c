/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:16:13 by narrospi          #+#    #+#             */
/*   Updated: 2024/07/22 11:47:16 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

bool	is_safe(int **matrix, int row, int col, int num)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (matrix[row][x] == num || matrix[x][col] == num)
		{
			return (false);
		}
		x++;
	}
	return (true);
}

void	store_combination(int **matrix)
{
	int	idx;
	int	i;
	int	j;
	int	count;
	int	combinatrions[576][16];

	count = 0;
	idx = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			g_combinations[count][idx++] = matrix[i][j];
			j++;
		}
		i++;
	}
    g_count++;
}

void solve(int **matrix, int row, int col) {
    if (row == 4 - 1 && col == 4) {
        store_combination(matrix);
        return;
    }
    if (col == 4) {
        row++;
        col = 0;
    }
    int num = 1;
    while (num <= 4) {
        if (is_safe(matrix, row, col, num)) {
            matrix[row][col] = num;
            solve(matrix, row, col + 1);
            matrix[row][col] = 0; // backtrack
        }
        num++;
    }
}

int (*get_combinations())[16]
{
    int	**matrix;
    int	i;
    int	j;
    
    matrix = (int **)malloc(4 * sizeof(int *));
    i = 0;
    while (i < 4) {
        matrix[i] = (int *)malloc(4 * sizeof(int));
        j = 0;
        while (j < 4) {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }
    solve(matrix, 0, 0);

    i = 0;
    while (i < 4) {
        free(matrix[i]);
        i++;
    }
    free(matrix);

    return (combinations);
}
