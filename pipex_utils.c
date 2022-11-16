/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:51:17 by sopopa            #+#    #+#             */
/*   Updated: 2022/11/16 14:51:38 by sopopa           ###   ########.fr       */
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
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (mode == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (mode == 2)
		file = open(argv, O_RDONLY | O_CLOEXEC, 0777);
	return (file);
}

void	execute_command(char *argv, char **envp)
{
	char **cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}


char	*find_path(char *argv_cmd, char **envp)
{	
	int i;
	char	**split_of_envpath;
	char	*temp;
	char	*path_with_cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) != 0)
		i++;
	split_of_envpath = ft_split(envp[i] + 5, ':');
	i = 0;
	while (split_of_envpath[i] != NULL)
	{
		temp = ft_strjoin(split_of_envpath[i], "/");
		free(split_of_envpath[i]);
		path_with_cmd = ft_strjoin(temp, argv_cmd);
		free(temp);	
		if (access(path_with_cmd, F_OK) == 0)
		{
			printf("%s", path_with_cmd);
			return (path_with_cmd);
		}
		free(path_with_cmd);
		i++;	
	}
	return (0);
}






int main(int argc, char **argv, char **envp)
{
	char *str;
	
	
	str = find_path(argv[1], envp);
	
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
