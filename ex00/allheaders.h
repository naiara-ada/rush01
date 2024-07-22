/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allheaders.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:11:08 by narrospi          #+#    #+#             */
/*   Updated: 2024/07/22 10:40:48 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>

extern int combinations[576][4 * 4];
extern int count;

// printers.c
void	ft_putchar(char c);
void	ft_putstr(char *str);

// verify.c
int		ft_continue_verify(char *values,int i);
int		ft_verify(int counts, char *values);

// combis.c
bool    is_safe(int **matrix, int row, int col, int num);
void    store_combination(int **matrix);
void    solve(int **matrix, int row, int col);
int     (*get_combinations())[4 * 4];

// logic.c
void    ft_biggersize(int A[6][6], int B[4][4]);
void	ft_logic_start(char *values);

// testings.c
int     visibility(int matrix[6][6]);
int     view_left(int matrix[6][6]);
int     view_top(int matrix[6][6]);

#endif
