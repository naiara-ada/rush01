/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:14:24 by narrospi          #+#    #+#             */
/*   Updated: 2024/07/22 10:14:28 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allheaders.h"

// Introducir los combis en la matriz 6x6
void    ft_biggersize(int A[6][6], int B[4][4])
{
    int i;
    int j;

    i = 0;
    while (i <= 3)
    {
        j = 0;
        while (j <= 3)
        {
            A[i + 1][j + 1] = B[i][j];
            j = j + 1;
        }
        i = i + 1;
    }
}

// Llamar a conseguir las combis
void    callcombis(int matrix[6][6])
{
    int (*all_combinations)[SIZE * SIZE];
    int *combi[SIZE][SIZE];
    int i;
    int row;
    int col;

    
    all_combinations = get_combinations();
    i = 0;
    while (i < 576){
        count = 0;
        row = 0;
        col = 0;
        while (row < SIZE) {
            col = 0;
            while (col < SIZE) {
                combi[row][col] = &all_combinations[i][count];
                count++;
                col++;
            }
            row++;
        }

    }
    ft_biggersize(matrix, combi);
}


void    fillclues(int matrix[6][6], int *clues)
{
    int    i;

    i = 0;
    while (i < 4)
    {
        matrix[0][i + 1] = clues[i];
        matrix[5][i + 1] = clues[i + 4];
        matrix[i + 1][0] = clues[i + 8];
        matrix[i + 1][5] = clues[i + 12];
        i++;
    }
    callcombis(matrix);
}

void    resetmatrix(int matrix[6][6], int *clues)
{
    int    i;
    int    j;

    i = 0;
    while (i < 6)
    {
        j = 0;
        while (j < 6)
        {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }
    fillclues(matrix, clues);
}


// Introducir los valores en los bordes
void	ft_logic_start(char *values)
{
    int     *clues;
    int     i;
    int     j;
    int     matrix[6][6];

    i = 0;
    j = 0;
    clues = (int*) malloc(16 * sizeof(int));
    while ( i <= 31 && j < 16)
    {
        clues[j] = values[i] - '0';
        i = i + 2;
        j++;    
    }
    resetmatrix(matrix, clues);
    free(clues);
}
