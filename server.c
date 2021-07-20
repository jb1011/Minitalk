#include "minitalk.h"

void	get_data(int sig)
{
	static int	i = 0;
	static int	j = 0;
	static char	str[1000];
	int			bit;

	if (i == 7)
	{
		j++;
		i = 0;
	}
	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	str[j] += (bit << i);
	i++;
	if (i == 7 && str[j] == 0)
	{
		ft_putstr_fd(str, 1);
		if (str[j] == 0)
			ft_putstr_fd("\n", 0);
		ft_memset(str, 0, 1000);
		i = 0;
		j = 0;
	}
}

int main()
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, get_data);
	signal(SIGUSR2, get_data);
	while (42)
		pause();
}