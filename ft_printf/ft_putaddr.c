/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:17:14 by chsassi           #+#    #+#             */
/*   Updated: 2023/11/21 15:58:58 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(void *ptr, int *length)
{
	uintptr_t	address;

	if (ptr == NULL)
	{
		putstr_pf("(nil)", length);
		return ;
	}
	address = (uintptr_t)ptr;
	putstr_pf("0x", length);
	ft_putnbr_base_unsigned_long(address, BASE16, length);
}

/* int main()
{
	int length = 0;
	int value = 42;
	void *ptr = &value;
	ft_putaddr(ptr, &length);
} */
