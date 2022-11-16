/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:51:17 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/16 16:54:40 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Funzione che stampa a video un messaggio di errore standard con ritorno a 1
void	error(void)
{
	perror("\x1B[31mError\n");
	exit(EXIT_FAILURE);
}

// Function that open the files with the right flags.
int	openfile(char *argv, int mode)
{
	int	file;

	file = 0;
	if (file == -1)
		error();
	if (mode == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (mode == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (mode == 2)
		file = open(argv, O_RDONLY | O_CLOEXEC, 0777);
	return (file);
}

void	execute_command(char *argv, char **envp)
{
	char	**cmd;
	int		i;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}

char	*find_path(char *cmd, char **envp)
{	
	int		i;
	char	**split_of_path;
	char	*temp;
	char	*path_with_cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	split_of_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (split_of_path[i] != NULL)
	{
		temp = ft_strjoin(split_of_path[i], "/");
		free(split_of_path[i]);
		path_with_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path_with_cmd, F_OK) == 0)
			return (path_with_cmd);
		free(path_with_cmd);
		i++;
	}
	free(split_of_path);
	return (0);
}

int main (int argc, char **argv, char **envp)
{
	execute_command(argv[1], envp);
}
