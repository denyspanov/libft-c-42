/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:01:53 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/22 19:21:10 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**check_fd(int fd, t_node **node)
{
	t_node *tmp;

	tmp = *node;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (&(tmp->stock));
		tmp = tmp->next;
	}
	if (!(tmp = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	tmp->stock = ft_strnew(1);
	tmp->fd = fd;
	tmp->next = (*node);
	(*node) = tmp;
	return (&(tmp->stock));
}

int		str_check(char **stock, char **line, int c)
{
	char *tmp_fj;

	tmp_fj = *stock;
	if ((*stock)[c] == '\n')
	{
		if (!(*line = ft_strsub(tmp_fj, 0, (unsigned int)c)))
			return (-1);
	}
	else if (!(*line = ft_strdup(*stock)))
		return (-1);
	if (!(*stock = ft_strsub(tmp_fj, c + 1, (ft_strlen(*stock) - c))))
		return (-1);
	ft_strdel(&tmp_fj);
	return (1);
}

int		str_c(char **stock, char **line, int c)
{
	int i;

	i = -1;
	while ((*stock)[++i])
		if ((*stock)[i] == '\n')
			return (str_check(stock, line, i));
	if (**stock && !c)
		return (str_check(stock, line, i));
	return (0);
}

int		f_reader(int fd, char **line, char **stock, char *tmp_buff)
{
	int		ret;
	char	*tmp_fj;

	if (!ft_strchr(*stock, '\n'))
		while (read(fd, tmp_buff, BUFF_SIZE))
		{
			tmp_fj = *stock;
			if (!(*stock = ft_strjoin(tmp_fj, tmp_buff)))
			{
				ft_strdel(&tmp_buff);
				return (-1);
			}
			ft_strdel(&tmp_fj);
			if ((ret = str_c(&(*stock), line, 1)))
			{
				ft_strdel(&tmp_buff);
				return (ret);
			}
			ft_strclr(tmp_buff);
		}
	if ((ret = str_c(&(*stock), line, 0)))
		return (ret);
	ft_strdel(&tmp_buff);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_node	*node;
	char			**stock;
	char			*tmp_buff;

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL ||
		!(tmp_buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((read(fd, tmp_buff, 0) < 0))
	{
		ft_strdel(&tmp_buff);
		return (-1);
	}
	stock = check_fd(fd, &node);
	return (f_reader(fd, line, stock, tmp_buff));
}
