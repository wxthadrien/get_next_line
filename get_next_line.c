/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:41:55 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/17 12:54:48 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int end_line_verif(char **tmp, char **line, int fd)
{
	int len;
	char *back;

	len = 0;
	while (tmp[fd][len] != '\n' && tmp[fd][len] != '\0')
		len++;
	if (tmp[fd][len] == '\n')
	{
		if(!(*line = ft_strsub(tmp[fd], 0, len)))
			return(-1);
		if(!(back = ft_strdup(tmp[fd] + len + 1)))
			return (-1);
			free(tmp[fd]);
			tmp[fd] = back;
			return (1);
	}
	return (0);
}

int		end_l(char **tmp, char **line, int fd)
{
	if(!(*line = ft_strdup(tmp[fd])))
		return (-1);
	ft_strdel(&tmp[fd]);
	return (1);
}

int		ft_new_line(char **tmp, char **line, int fd)
{
	char	*back;
	int		len;

	len = 0;
	while (tmp[fd][len] != '\n' && tmp[fd][len] != '\0')
		len++;
	if (tmp[fd][len] == '\n')
	{
		if(!(*line = ft_strsub(tmp[fd], 0, len)))
			return (-1);
		if(!(back = ft_strdup(tmp[fd] + len + 1)))
			return (-1);
		free(tmp[fd]);
		tmp[fd] = back;
	}
	else if (tmp[fd][len] == '\0')
		end_l(tmp, line, fd);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*back;
	int			rd;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	if (tmp[fd] && ((rd = end_line_verif(tmp, line, fd)) != 0))
			return (rd);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (tmp[fd] == NULL)
			if(!(tmp[fd] = ft_strnew(1)))
				return (-1);
		if(!(back = ft_strjoin(tmp[fd], buf)))
			return (-1);
		free(tmp[fd]);
		tmp[fd] = back;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((rd < 0) || (rd == 0 && (tmp[fd] == NULL || tmp[fd][0] == '\0')))
		return ((rd < 0) ? -1 : 0);
	return (ft_new_line(tmp, line, fd));
}

int     main(int argc, char **argv)
{
    int fd;
    char *line;
    int ret;

    if (argc < 2)
        printf("Erreur d'entrée");
		else
    {
        if ((fd = open(argv[1], O_RDONLY)) < 1)
            return(printf("Open Error"));
        while((ret = get_next_line(fd, &line)) > 0)
        {
            if (ret > 0)
                printf("%s\n", line);
            else
                printf("error code %d", ret);
        }
        close(fd);
        return (0);
			}
			return(-1);
}
