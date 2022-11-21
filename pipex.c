/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:49:28 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/20 17:00:18 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fd[0] is for reading
// fd[1] is for writing

/* 
   The function child opens the file with the right 
   flags and use the first cmd 
   received from the input on the file just opened,
   the results will be stored on the file descriptor 
   pipe fd[1] that is for writing.
*/
void	child_process(char **argv, char **envp, int *fd)
{
	int	file_input;

	ft_printf("The child are processing...\n");
	file_input = openfile(argv[1], O_READ);
	if (file_input == -1)
		error();
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_input, STDIN_FILENO);
	execute_command(argv[2], envp, 0);
}

/* 
   The parent opens the file with the right flags and 
   takes the second cmd and it uses on the 
   file descriptor pipe fd[0] that is for reading, 
   the output result will be stored on the output file
*/
void	parent_process(char **argv, char **envp, int *fd)
{
	int		file_output;
	char	**str;

	str = ft_split(argv[3], ' ');
	ft_printf("\033[0;37mThe father are processing...\n");
	file_output = openfile(argv[4], O_WRITE_TRUNC);
	if (file_output == -1)
		error();
	if (access(find_path(str[0], envp), F_OK) == 0)
		ft_printf("Done without errors!\n");
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_output, STDOUT_FILENO);
	free(str);
	execute_command(argv[3], envp, 1);
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
		waitpid(process_id, NULL, 0);
		parent_process(argv, envp, fd);
	}	
	ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <input_file> <cmd1> <cmd2> <output_file>\n", 1);
	return (0);
}
