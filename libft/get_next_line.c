/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:51:57 by tyassine          #+#    #+#             */
/*   Updated: 2016/06/20 17:22:36 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_join(char **line, char *buf, int nb)
{
	char	*tmp;

	tmp = *line;
	buf[nb] = '\0';
	(*line) = ft_strjoin(*line, buf);
	free(tmp);
}

static void	ft_sub(char **line, char **chr_ret, int nb)
{
	char	*tmp;

	if (nb == -1)
		return ;
	tmp = *line;
	*line = ft_strsub(*line, 0, *chr_ret - *line);
	*chr_ret = *chr_ret + 1;
	*chr_ret = ft_strdup(*chr_ret);
	free(tmp);
}

int			get_next_line(int const fd, char **line)
{
	static char	*chr_ret;
	char		buf[BUFF_SIZE + 1];
	int			nb;

	if (!line)
		return (-1);
	if (fd > -1)
	{
		*line = ft_strnew(1);
		if (chr_ret != NULL)
		{
			*line = ft_strdup(chr_ret);
			free(chr_ret);
		}
		while (((chr_ret = ft_strchr(*line, '\n')) == NULL)
				&& ((nb = read(fd, buf, BUFF_SIZE)) > 0))
			ft_join(line, buf, nb);
		if (nb == 0 && chr_ret == NULL)
			return (0);
		nb = (nb == -1) ? -1 : 1;
		ft_sub(line, &chr_ret, nb);
		return (nb);
	}
	else
		return (-1);
}
