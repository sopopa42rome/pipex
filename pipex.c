/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:49:28 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/16 12:36:11 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void    child_process(char **argv, char **envp, int *fd)
{
	int file_input;
	
	execute_command(argv[1], envp);

}

int main (int argc, char **argv, char **envp)
{
	int fd[2];
	int process_id;

	if (argc == 2)
	{

		if (pipe(fd) == -1)
			error();
		process_id = fork();
		if (process_id == -1)
			error()
		if (process_id == 0)
			sleep(2);
			child_process(argv, envp, fd);

	}
}