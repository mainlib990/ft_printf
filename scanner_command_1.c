/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_command_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:03 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner_command.h"

#include "token.h"

void	empty(void *token, char lexeme)
{
	(void)token;
	(void)lexeme;
}

void	set_asc(void *token, char lexeme)
{
	((t_token *)token)->id = 1;
	(void)lexeme;
}

void	increase_width(void *token, char lexeme)
{
	((t_token *)token)->width += 1;
	(void)lexeme;
}

void	set_space(void *token, char lexeme)
{
	((t_token *)token)->is_space = 1;
	(void)lexeme;
}

void	set_hash(void *token, char lexeme)
{
	((t_token *)token)->is_hash = 1;
	(void)lexeme;
}
