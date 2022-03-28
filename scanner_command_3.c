/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_command_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:06 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:18:14 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner_command.h"

#include "token.h"

void	add_precision(void *token, char lexeme)
{
	((t_token *)token)->precision *= 10;
	((t_token *)token)->precision += lexeme - '0';
}

void	set_percentage(void *token, char lexeme)
{
	((t_token *)token)->id = 2;
	(void)lexeme;
}

void	set_upper_x(void *token, char lexeme)
{
	((t_token *)token)->id = 3;
	(void)lexeme;
}

void	set_lower_c(void *token, char lexeme)
{
	((t_token *)token)->id = 4;
	(void)lexeme;
}

void	set_lower_d(void *token, char lexeme)
{
	((t_token *)token)->id = 5;
	(void)lexeme;
}
