/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:56 by hmeys             #+#    #+#             */
/*   Updated: 2018/11/14 13:53:28 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char *ft_strend(char *str, int idx)
{
	char *ret;
	int i;

	i = 0;
	ret = malloc(sizeof(ft_strlen(str) + 1));
	while (str[idx])
	{
		ret[i] = str[idx];
		i++;
		idx++;
	}
	return (ret);
}

int ft_strchr_idx(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int get_next_line(const int fd, char **line)
{
	int rd;
	char *buf;
	static char *temp;
	char *back;
	int idx;

    rd = 1;
	idx = 0;
	back = malloc(BUFF_SIZE);
    buf = malloc(BUFF_SIZE);
	while (rd)
	{
        printf("\n\nBoucle Ok\n");
		if (temp)
        {
            printf("Temp existe, on le recupere.\n");
			buf = temp;
            temp = NULL;
        }
		else
		{
            printf("Temp existe pas, on lis depuis le fichier.\n");
			rd = read(fd, buf, BUFF_SIZE);
			buf[rd] = '\0';
		}
		if ((idx = ft_strchr_idx(buf)) == -1)
        {
            printf("Il n'y a pas de /n,");
            printf(" on tente donc de d'ajouter ' %s ' À ' %s '.   ", buf, back);
            back = ft_strjoin(back, buf);
            printf("ce qui donne: ''   %s   ''\n", back);
        }
		else
		{
            printf("Il y a un /n, on ajoute donc la partie avant le /n ");
			back = ft_strjoin(back, ft_strsub(buf, 0, idx));
			temp = ft_strend(buf, idx + 1);
            *line = back;
            printf("et revoi: %s \n\n\n", back);
			return (1);
		}
	}
	return (0);
}

int	main()
{
	int	fd;
	char *res;

	fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &res);
    //printf("Line: %s \n", res);
    get_next_line(fd, &res);
    //printf("Line: %s \n", res);
    //get_next_line(fd, &res);
    //printf("Line: %s \n", res);
	close(fd);
	return (0);
}
