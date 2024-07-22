/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:07:07 by narrospi          #+#    #+#             */
/*   Updated: 2024/07/22 11:07:38 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

int	ft_continue_verify(char *values, int i)
{
	if (i != 31 || (i % 2 == 0 && values[i] == ' '))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_logic_start(values);
	return (0);
}

int	ft_verify(int argc, char *values)
{
	int	i;

	i = 0;
	if (argc != 2 || values == '\0' || values[30] == ' ')
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (values[i])
	{
		if ((values[i] != ' ' && values[i] != '1' && values[i] != '2'
				&& values[i] != '3' && values[i] != '4'))
		{
			ft_putstr("Error\n");
			return (0);
		}
		else if ((i % 2 != 0) && values[i] != ' ')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	ft_continue_verify(values, i);
	return (0);
}
