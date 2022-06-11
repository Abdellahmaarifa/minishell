/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:23:30 by amaarifa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/10 18:45:58 by mkabissi         ###   ########.fr       */
=======
/*   Updated: 2022/06/11 11:27:23 by amaarifa         ###   ########.fr       */
>>>>>>> 865717e9c1097d1274135c1d8dfe888d64d16c0c
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <unistd.h>
# include "./src/libft/libft.h"
# include "fcntl.h"
# include "signal.h"

# define EMPTY_TOKEN -1
# define AMBIGUOUS_REDIRECT -2
# define HERE_DOC 0				/*	<<		*/
# define IN_REDERCTIONT 1		/*	< 		*/
# define OUT_TRUNC 2			/*	>		*/
# define APPEND 3				/*	>>		*/
# define WORD 4					/*	ex: ls	*/

/* EXIT STATUS */
int	g_exit_status;

/* ENV */
typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* TOKEN */
typedef struct s_token {
	char			*value;	
	int				type;
	int				expand_heredoc;
	struct s_token	*next;
}	t_token;

/* TOKEN SOURCE */

typedef struct s_token_source {
	char	*source;
	char	current_char;
	long	current_position;
	long	size;
}	t_token_source;

/* MUILPILE PIP COMMANDS REPRESNTATION STRUCUER */

typedef struct s_cmd_list {
	char	*source;
	char	*cmd_line;
	t_token	**tokens;
	int		n_cmd;
	int		exit;
	t_env	**env;
}	t_cmd_list;

void	rl_replace_line(char *string, int i);

#endif

/*
	int ***pip;
	pip[3] = {{0,1}, ...};

	while (i < 3)
	{
		in = get_in(token); // -1
		out = get_out  // -1
		cmd = get_cmd(token);
		
		i++;
	}
*/
