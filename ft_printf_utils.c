/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:35:19 by hece              #+#    #+#             */
/*   Updated: 2022/10/03 10:35:21 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Bu sayfa aşırı kolay print fonksiyonları var
// ft_strlen stringin uzunlugunu döndürmeme yarıyor
// ft_putchar gönderilen karakteri yazıp işlem sayısını döndürüyor
// ft_pustr gönderilen stringi yazdırım işlem sayısını döndürüyor
// ve bu sayfanın bütün olayı bu vesselam...

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}
