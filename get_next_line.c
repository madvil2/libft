/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:02:40 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/22 16:50:30 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	cut_lines(char **line, char *multy)
{
	char *str;

	str = ft_strchr(multy, '\n');
	if (str)
	{
		str[0] = '\0';
		*line = ft_strdup(multy);
		ft_strcpy(multy, str + 1);
		return (1);
	}
	else if (ft_strlen(multy) > 0)
	{
		*line = ft_strdup(multy);
		*multy = 0;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*multy[10240];
	char		buffer[BUFF_SIZE + 1];
	ssize_t		rd;
	char		*temp;

	if (fd < 0 || fd > 10240 || !line)
		return (-1);
	if (!multy[fd] && !(multy[fd] = ft_strnew(1)))
		return (-1);
	while (!ft_strchr(multy[fd], '\n'))
	{
		if ((rd = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		if (rd == 0)
			break ;
		buffer[rd] = '\0';
		temp = ft_strjoin(multy[fd], buffer);
		free(multy[fd]);
		multy[fd] = temp;
	}
	return (cut_lines(line, multy[fd]));
}