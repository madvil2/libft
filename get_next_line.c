/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:02:40 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/23 01:45:12 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	*multy[10240];
	char		buf[BUFF_SIZE + 1];
	int			rd;
	char		*str;

	while ((!(!(line)) || (rd != -1)) &&
			(rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		str = multy[fd];
		if (!(multy[fd] = ft_strjoin(multy[fd], buf)))
			multy[fd] = ft_strdup(buf);
		ft_strdel(&str);
	}
	if ((rd == -1 || !ft_strlen(multy[fd])) && (!line || (*line = ft_strnew(0))))
		return (rd);
	str = ft_strchr(multy[fd], '\n');
	if (str && !(*str = '\0'))
		str = ft_strdup(str + 1);
	else
		str = ft_strnew(0);
	*line = ft_strdup(multy[fd]);
	free(multy[fd]);
	multy[fd] = str;
	return (1);
}
