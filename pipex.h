/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:29:30 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/17 19:22:05 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Headers file
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

// Macros
# define O_READ 2
# define O_WRITE_TRUNC 1
# define O_WRITE_APPEND 0

// Mandatory part

void	error(void);
int		openfile(char *argv, int mode);
void	child_process(char **argv, char **envp, int *fd);
char	*find_path(char *cmd, char **envp);
void	execute_command(char *argv, char **envp);

#endif