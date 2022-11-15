/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:51:17 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/14 05:06:43 by sopopa           ###   ########.fr       */
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
int		openfile(char *argv, int mode)
{
	int file;

	file = 0;
	if (file == -1)
		error();
	if (mode == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND | __O_CLOEXEC, 0777);
	else if (mode == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC | __O_CLOEXEC, 0777);
	else if (mode == 2)
		file = open(argv, O_RDONLY | __O_CLOEXEC, 0777);
	return (file);
}

void	execute_command(char *argv, char **envp)
{
	char **cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1);
		error();
}


char	*find_path(char *cmd, char **envp)
{	
	int i;
	char	**splitted_path;
	char	*slash;
	char	*path_cmd;


	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) != 0)
		i++;
	splitted_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (splitted_path[i])
	{
		slash = ft_strjoin(splitted_path[i], "/");
		path_cmd = ft_strjoin(slash, cmd);
		free(slash);
		if (access(path_cmd, F_OK) == 0);
		{
			printf("String: %s",path_cmd);
			return (path_cmd);
		}
		free(path_cmd);
		i++;	
	}
}








int main (int argc, char **argv, char **envp)
{
	if (argc == 2)
	{	
		//char **cmd;
		char  *str;

		//cmd = ft_split(argv[1], ' ');
		str = find_path(argv[1], envp);
		printf("%s", str);

	}
	
}













// {
// 	if (argc == 2)
// 	{
// 		int bytes;
// 		char *str;

	
// 		int file = openfile(argv[1], 2);
// 		str = malloc(1000 * sizeof(str));
// 		bytes = read(file, str, 1000);
// 		printf("%s", str);
// 	}
// }
