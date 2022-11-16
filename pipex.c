/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:49:28 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/16 17:50:50 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] is for reading
// fd[1] is for writing

void    child_process(char **argv, char **envp, int *fd)
{
	int file_input;
	file_input = openfile(argv[1], O_READ);
	dup2(fd[])
	dup2(file_input, STDOUT_FILENO);

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