/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:50:51 by hece              #+#    #+#             */
/*   Updated: 2022/10/03 10:50:53 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Burda 2 farklı açıklama koyacagım base olayı için
// uzun açıklama altta olacak başlayalım

// burdaki amacım int değer basmaktı düsünürken beni yorsa da
// ((bsaeler kadar yormadı)) doğru çıktı verdirmeyi başardım
// olayı şu ft_int_print fonksiyonu aslında modifiye itoa olarak
// düşünebiliriz int değerleri tek tek resultun indexlerine atıyoruz

// ft_get_size int değerimin basamak sayısını hesaplıyor

// ft_calculate nin amacı pprijenin norminetteye uyması için satır azaltma
// amaçlı yazılmış bir fonksiyon amacı ise olması gereken basamak sayısı
// yani size olunan basamak sayısı offset bu aralık kapanasaya kadar
// sonran başa dogru resultumun indexlerine cevabı uerleştiriyor
// baselerle alakalı aşşağıya yorum koyacagım vesselam...

int	ft_get_size(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

void	ft_calculate(int size, int offset, int nb, char *result)
{
	while (size > offset)
	{
		result[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
}

int	ft_int_print(int nb)
{
	int		offset;
	int		size;
	char	*result;

	offset = 0;
	size = ft_get_size(nb);
	result = ((char *)malloc(sizeof(char) * size + 1));
	if (result == NULL)
		return (0);
	if (nb == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		nb = 147483648;
		offset = 2;
	}
	else if (nb < 0)
	{
		result[0] = '-';
		offset = 1;
		nb = -nb;
	}
	ft_calculate(size, offset, nb, result);
	result[size] = '\0';
	return (ft_putstr(result));
}

// Burda aslında yukarıdaki uzun çözümden ziyade bu fonksiyonla int
// değerleri de çözebiliriz ama çömezliğimize verin araştırma aşaması
// sancılı idi bende çalısan kodu elleme felsefesi güttüm :)
// peki olay ne herhangi br tipte sayımız olsan data dedim
// ve taban olayı içinse base diye string gönderdim
// burda ilk olarak arraylarla çözmeye caşlıstım lakin ya segmantasyon
// yiyordum ya da yanlıs istenilmeyen çıktı alıyordum 
// mecbur tek carem pointer aritmatiği ile çözmek oldu şimdi olaya bakalım.

// pointer aritmatiginde sondan başa dogru nasıl yazarım bilmediğimden
// tampon bir adres oluşturdum ve o adrese (size + 1) kadar yer açtım yani
// basamak sayım kadar sonra ise tampon stringimin son indexini str me
// eşitledim bu sayede artık adresimin sonuna geldim
// ve pointerımın sonuna null ekledim daha sonra adresde bir geriye giderek
// base işlemine göre kalan rakamı atadım döngü ile bunu işlem biteseye kadar
// yaptırdım ve en sonunda işlemimi ft_putstr ye gönderip yazdırdım

int	ft_convert(size_t data, char *base)
{
	int			len;
	int			size;
	static char	*str;
	char		*ptr;

	size = ft_get_size(data);
	str = malloc(size + 1);
	ptr = &str[size - 1];
	len = ft_strlen(base);
	*ptr = '\0';
	*--ptr = base[data % len];
	data = data / len;
	while (data != 0)
	{
		*--ptr = base[data % len];
		data = data / len;
	}
	return (ft_putstr(ptr));
}
