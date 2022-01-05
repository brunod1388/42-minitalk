/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:50:19 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/01/01 23:39:21 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H
# include "libft/libft.h"
# define BSIZE 1024

typedef unsigned char	t_uchar;

typedef struct s_com
{
	int		isreading;
	int		index;
	int		bi;
	char	buffer[BSIZE];
}	t_com;

#endif