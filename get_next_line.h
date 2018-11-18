/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:19 by hmeys             #+#    #+#             */
/*   Updated: 2018/11/14 12:52:53 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 100

int get_next_line(const int fd, char **line);
int ft_strchr_idx(char *str);
char *ft_strend(char *str, int idx);
