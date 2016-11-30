/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_ligne.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 17:51:29 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/13 09:47:29 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_do(t_lig *list)
{
	char	*rtr;
	size_t	i;
	int		len;

	len = BUFF_SIZE * 1000;
	list->c_read = 0;
	i = 0;
	rtr = ft_strnew(len);
	if (list->mess[list->j] == '\n')
		++list->j;
	while (list->mess[list->j] != '\n' && list->mess[list->j] &&
		list->mess[list->j] != EOF)
	{
		rtr[i++] = list->mess[list->j++];
		++(list->c_read);
	}
	rtr[i] = '\0';
	return (rtr);
}

static void		ft_copie(t_lig *list, char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
		list->mess[list->j++] = buf[i++];
}

static int		ft_buf(int fd, t_lig *list)
{
	char	*buf;
	int		ret;

	ret = 42;
	buf = ft_strnew(BUFF_SIZE);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret < 0)
		{
			list->mess[0] = '\0';
			return (-1);
		}
		ft_copie(list, buf);
	}
	list->mess[list->j] = '\0';
	list->j = 0;
	free(buf);
	buf = NULL;
	return (0);
}

static t_lig		*ft_find(int fd, t_lig *list)
{
	t_lig	*new;

	while (list->next != NULL && list->fd != fd)
		list = list->next;
	if (list->next == NULL && list->fd != fd)
	{
		if (!(new = malloc(sizeof(*list))))
			return (NULL);
		new->fd = fd;
		new->next = NULL;
		list->next = new;
		new->j = 0;
		new->first = list->first;
		list = list->next;
		ft_buf(fd, list);
		return (new);
	}
	return (list);
}

int				get_next_line(int const fd, char **line)
{
	static t_lig	*list;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (!list)
	{
		if (!(list = malloc(sizeof(*list))))
			return (-1);
		list->fd = fd;
		list->j = 0;
		list->first = list;
		list->next = NULL;
		ft_buf(fd, list);
	}
	list = list->first;
	if (list->fd != fd)
		list = ft_find(fd, list);
	if (list->mess[0] == '\0')
		return (-1);
	*line = ft_do(list);
	if (*line == NULL)
		return (-1);
	if (list->c_read != 0 || list->mess[list->j] != '\0')
		return (1);
	return (0);
}
