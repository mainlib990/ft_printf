/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_command_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:07 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:18:14 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner_command.h"

#include "token.h"

void	set_lower_i(void *token, char lexeme)
{
	((t_token *)token)->id = 6;
	(void)lexeme;
}

void	set_lower_p(void *token, char lexeme)
{
	((t_token *)token)->id = 7;
	(void)lexeme;
}

void	set_lower_s(void *token, char lexeme)
{
	((t_token *)token)->id = 8;
	(void)lexeme;
}

void	set_lower_u(void *token, char lexeme)
{
	((t_token *)token)->id = 9;
	(void)lexeme;
}

void	set_lower_x(void *token, char lexeme)
{
	((t_token *)token)->id = 10;
	(void)lexeme;
}
