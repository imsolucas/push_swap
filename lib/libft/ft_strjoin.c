/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:04:22 by djin              #+#    #+#             */
/*   Updated: 2024/04/02 20:29:53 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		len1;
	int		len2;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	join = ft_calloc(1, len1 + len2 + 1);
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len1)
		join[i] = s1[i];
	i = -1;
	while (++i < len2)
		join[len1 + i] = s2[i];
	join[len1 + i] = '\0';
	free((void *)s1);
	return (join);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello", " There"));
// }
