/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:49:28 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/17 17:45:20 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] is for reading
// fd[1] is for writing

void	child_process(char **argv, char **envp, int *fd)
{
	int	file_input;

	file_input = openfile(argv[1], O_READ);
	if (file_input == -1)
		error();
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_input, STDIN_FILENO);
	execute_command(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	file_output;

	file_output = openfile(argv[4], O_WRITE_TRUNC);
	if (file_output == -1)
		error();
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_output, STDOUT_FILENO);
	execute_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	process_id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		process_id = fork();
		if (process_id == -1)
			error();
		if (process_id == 0)
			child_process(argv, envp, fd);
		waitpid(process_id, 0, 0);
		parent_process(argv, envp, fd);
	}
	else if (argc <= 5 || argc >= 5)
	{	
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <input_file> \"cmd1\" \"cmd2\" <output_file>\n", 1);
	}
	return 0;
}
