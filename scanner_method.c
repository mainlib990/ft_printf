/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:09 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner_method.h"

#include <stdint.h>

#include "scanner.h"
#include "scanner_command.h"
#include "scanner_table.h"

void	_scanner(t_scanner *this, const char *lexemes)
{
	this->max_ecs_state = g_max_ecs_state;
	this->ecs = g_ecs;
	this->mecs = g_mecs;
	this->base = g_base;
	this->def = g_def;
	this->advance = g_advance;
	this->check = g_check;
	this->next = g_next;
	this->command_id = g_command_id;
	this->commands = g_commands;
	this->lexemes = lexemes;
}

const char	*_get_lexemes(t_scanner *this)
{
	return (this->lexemes);
}

int	_next_token(t_scanner *this, void *token)
{
	uint8_t	cur_state;
	uint8_t	ec;

	cur_state = 1;
	while (0 < this->base[cur_state])
	{
		ec = this->ecs[(uint8_t)(*(this->lexemes))];
		while (!(this->check[ec + this->base[cur_state]] == cur_state))
		{
			cur_state = this->def[cur_state];
			if (cur_state > this->max_ecs_state)
			{
				ec = this->mecs[ec];
			}
		}
		this->commands[this->command_id[ec + this->base[cur_state]]]
			(token, *(this->lexemes));
		cur_state = this->next[ec + this->base[cur_state]];
		this->lexemes += this->advance[cur_state];
	}
	return (cur_state);
}
