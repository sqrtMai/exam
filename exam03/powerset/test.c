/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <bbouarab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:03:44 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 22:00:02 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sum(int *tab, int n)
{
	int	res;

	res = 0;
	for (int i = 0; i < n; i++)
		res += tab[i];
	return (res);
}

void	powerset(int *sum, int *tab, int pos, int n, int check_val, int index)
{
	if (pos > n)
		return ;
	if (ft_sum(sum, pos) > check_val)
		return ;
	if (ft_sum(sum, pos) == check_val)
	{
		for(int i = 0; i < pos; i++)
		{
			printf("%d", sum[i]);
			if (i < pos - 1)
				printf(" ");
		}
		printf("\n");
	}
	for (int i = index; i < n; i++)
	{
		sum[pos] = tab[i];
		powerset(sum, tab, pos + 1, n, check_val, i + 1);
	}
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (1);
	int check_val = atoi(av[1]);
	int	n = ac - 2;
	int *tab = (int *)calloc(n, sizeof(int));
	if (!tab)
		return (1);
	for(int i = 0; i < ac - 2; i++)
		tab[i] = atoi(av[i + 2]);
	int *sum = (int *)calloc(n, sizeof(int));
	if (!sum)
		return (free(tab), 1);
	powerset(sum, tab, 0, n, check_val, 0);
	return (0);
}
