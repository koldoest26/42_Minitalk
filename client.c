/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:45:56 by luestira          #+#    #+#             */
/*   Updated: 2025/02/16 13:18:43 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage: ./client PID MESSAGE_TO_SEND\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("PID must be a number.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!argv[2][0])
	{
		ft_printf("Message cannot be empty.\n");
		exit(EXIT_FAILURE);
	}
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (!g_ack)
			usleep(50);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
	int		i;

	i = 0;
	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	msg = ft_strjoin(argv[2], "\n");
	if (!msg)
		return (EXIT_FAILURE);
	signal(SIGUSR1, ack_handler);
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\0');
	free(msg);
	return (EXIT_SUCCESS);
}
