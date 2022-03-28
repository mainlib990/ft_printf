/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:04 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner_command.h"

#include "token.h"

void	set_plus(void *token, char lexeme)
{
	((t_token *)token)->is_plus = 1;
	(void)lexeme;
}

void	set_minus(void *token, char lexeme)
{
	((t_token *)token)->is_minus = 1;
	(void)lexeme;
}

void	set_precision(void *token, char lexeme)
{
	((t_token *)token)->is_precision = 1;
	(void)lexeme;
}

void	set_zero(void *token, char lexeme)
{
	((t_token *)token)->is_zero = 1;
	(void)lexeme;
}

void	add_width(void *token, char lexeme)
{
	((t_token *)token)->width *= 10;
	((t_token *)token)->width += lexeme - '0';
}
