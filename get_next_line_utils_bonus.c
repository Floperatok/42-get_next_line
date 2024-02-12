/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:21:14 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 03:47:55 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	Calculates the length of the string pointed to by s, excluding the
 *	terminating null byte '\0'.
 * 	ARGUMENTS:
 * 		const char *s	: The string to calcultate the length from.
 * 	RETURN VALUE:
 * 		size_t	: Number of byte in the string pointed to by s as a size_t.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 *	Returns a pointer to a new string which is a duplicate of the string.
 *	Memory for the new string is obtained with malloc(3), and can be freed with
 * 	free(3).
 * 	ARGUMENTS:
 * 		const char *s	: The string to copie.
 * 	RETURN VALUE:
 * 		char *	: On success, this function returns a pointer to the duplicated
 * 		string. It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(char *s)
{
	char	*d;
	int		i;

	d = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
 *	Combines the string s1 and the string s2 together into one string.
 *	Memory for the new string is obtained with malloc(3), and can be freed
 *	with free(3).
 *	ARGUMENTS:
 *		char const *s1	: The first string, will be at the begginning of
							the final string.
		char const *s2	: The second string, will be at the end of
							the final string.
	RETURN VALUE:
		char *	: The first and the second string joined together.
	IMPORTANT NOTE : in this specific strjoin, s1 is freed.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < lens1)
		res[i] = s1[i];
	i--;
	while (++i < lens1 + lens2)
		res[i] = s2[i - lens1];
	res[i] = '\0';
	free(s1);
	return (res);
}
