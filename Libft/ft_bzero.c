/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:11:16 by chsassi           #+#    #+#             */
/*   Updated: 2023/10/14 16:17:38 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n != 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

/*int		main(void)
{
	char	str[] = "Ciao";
	printf("Before bzero:	%s\n", str);
	ft_bzero(str, 5);
	printf("After bzero:	%s\n", str);
}*/