/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:55:34 by luestira          #+#    #+#             */
/*   Updated: 2025/02/16 13:20:55 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_str;

char	*ft_stradd(char *s1, char to_add)
{
	int		len;
	int		i;
	char	*s_new;

	if (s1 == NULL)
	{
		s_new = malloc(2);
		s_new[0] = to_add;
		s_new[1] = '\0';
		return (s_new);
	}
	len = ft_strlen(s1) + 1;
	s_new = malloc((len + 1) * sizeof(char));
	if (!s_new)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_new[i] = s1[i];
		i++;
	}
	s_new[i++] = to_add;
	s_new[i] = '\0';
	free(s1);
	return (s_new);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		g_str = ft_stradd(g_str, c);
		if (c == '\0')
		{
			ft_printf("%s", g_str);
			free(g_str);
			g_str = NULL;
			kill(client_pid, SIGUSR2);
		}
		c = 0;
		bit = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server started. PID: %d\n", pid);
	ft_printf("Messages received: \n");
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	free(g_str);
	g_str = NULL;
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
