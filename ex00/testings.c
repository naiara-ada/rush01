/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:25:07 by narrospi          #+#    #+#             */
/*   Updated: 2024/07/22 12:10:38 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	short_view( int matrix[6][6], int i, int j, int counter2)
{
	int	k;

	k = j;
	while (--k >= 1)
	{
		if (matrix[i][j] > matrix[i][k])
			counter2 = counter2 + 1;
	}
	return (counter2);
}

int	view_left(int matrix[6][6])
{
	int	counter;
	int	counter2;
	int	i;
	int	j;

	i = 0;
	while (++i <= 4)
	{
		j = 1;
		counter = 1;
		while (++j <= 4)
		{
			counter2 = 1;
			counter2 = short_view(matrix, i, j, counter2);
			if (counter2 == j)
				counter = counter + 1;
		}
		if (counter != matrix[i][0])
			return (1);
	}
	return (0);
}

int	view_top(int matrix[6][6])
{
	int	counter;
	int	counter2;
	int	i;
	int	j;
	int	k;

	j = 0;
	while (++j <= 4)
	{
		i = 1;
		counter = 1;
		while (++i <= 4)
		{
			counter2 = 1;
			counter2 = short_view(matrix, i, j, counter2);
			if (counter2 == i)
				counter = counter + 1;
		}
		if (counter != matrix[0][j])
			return (1);
	}
	return (0);
}

int	view_right(int matrix[6][6])
{
	int	counter;
	int	counter2;
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i <= 4)
	{
		j = 4;
		counter = 1;
        while (--j >= 1)
        {
            counter2 = 0;
            k = j;
            while (++k <= 4)
            {  
                if (matrix[i][j] > matrix[i][k])
                    counter2 = counter2 + 1;
            }
            if (counter2 == 4 -j)
                counter = counter + 1;
        }
        if (counter != matrix[i][5])
            return (1);
    }
    return (0);
}

int view_bottom(int matrix[6][6])
{
    int counter;
    int counter2;
    int i;
    int j;
    int k;
   
    j = 0;
    while (++j <= 4)
    {
        i = 4;
        counter = 1;
        while (--i >= 1)
        {
            counter2 = 0 ;  // Empiezo en 0
            k = i;
            while (++k <= 4)
            {  
                if (matrix[i][j] > matrix[k][j])
                    counter2 = counter2 + 1;
            }
            if (counter2 == 4 -i)
                counter = counter + 1;
        }
        if (counter != matrix[5][j])
            return (1);
    }
    return (0);
}

int visibility(int matrix[6][6])
{
    int result;
   
    result = view_left(matrix) + view_top(matrix);
    result = result + view_right(matrix) + view_bottom(matrix);
    if (result != 0)
        return (1);
    return (0);
}
