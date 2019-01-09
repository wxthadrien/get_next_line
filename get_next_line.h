/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:19 by hmeys             #+#    #+#             */
/*   Updated: 2019/01/09 11:50:00 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 100

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_next_line(const int fd, char **line);
int ft_strchr_idx(char *str);
char *ft_strend(char *str, int idx);
