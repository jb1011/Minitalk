#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	letter;
	int		size;
}			t_data;

void	get_data(int sig);
void	ft_send(char *str, int pid);
void	send_char(char c, int pid);

#endif