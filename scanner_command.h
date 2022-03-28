/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_command.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:32 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:55:45 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_COMMAND_H
# define SCANNER_COMMAND_H

# include <stdint.h>

const static uint8_t	g_command_id[] = {
	0,
	0,		0,		0,		0,		0,		0,		0,		0,		0,		0,
	0,		0,		0,		0,		0,		0,		0,		0,		1,		3,
	4,		11,		5,		6,		7,		8,		9,		12,		13,		14,
	15,		16,		17,		18,		19,		3,		4,		11,		5,		6,
	7,		8,		9,		5,		6,		14,		15,		3,		4,		11,
	5,		6,		7,		8,		9,		12,		4,		3,		0,		6,
	5,		6,		19,		8,		3,		4,		4,		5,		11,		3,
	8,		8,		10,		10,		12,		8,		14,		15,		0,		17,
	18,		19,		3,		4,		11,		5,		6,		7,		8,		9,
	12,		3,		14,		15,		0,		6,		18,		19,		7,		9,
	9,		5,		13,		0,		8,		16,		3,		4,		11,		5,
	6,		7,		8,		9,		11,		7,		9,		9,		10,		10,
	11,		0,		14,		15,		10,		10,		12,		7,		9,		9,
	11,		1,		2,		19,		10,		10,		12,		0,		14,		15,
	0,		0,		18,		19,		7,		9,		9,		11,		7,		9,
	9,		10,		10,		0,		0,		0,		0,		0,		0,		0,
	0
};

void	empty(void *token, char lexeme);
void	set_asc(void *token, char lexeme);
void	increase_width(void *token, char lexeme);
void	set_space(void *token, char lexeme);
void	set_hash(void *token, char lexeme);
void	set_plus(void *token, char lexeme);
void	set_minus(void *token, char lexeme);
void	set_precision(void *token, char lexeme);
void	set_zero(void *token, char lexeme);
void	add_width(void *token, char lexeme);
void	add_precision(void *token, char lexeme);
void	set_percentage(void *token, char lexeme);
void	set_upper_x(void *token, char lexeme);
void	set_lower_c(void *token, char lexeme);
void	set_lower_d(void *token, char lexeme);
void	set_lower_i(void *token, char lexeme);
void	set_lower_p(void *token, char lexeme);
void	set_lower_s(void *token, char lexeme);
void	set_lower_u(void *token, char lexeme);
void	set_lower_x(void *token, char lexeme);

static	void (*const	g_commands[])(void *, char) = {
	empty,
	set_asc,
	increase_width,
	set_space,
	set_hash,
	set_plus,
	set_minus,
	set_precision,
	set_zero,
	add_width,
	add_precision,
	set_percentage,
	set_upper_x,
	set_lower_c,
	set_lower_d,
	set_lower_i,
	set_lower_p,
	set_lower_s,
	set_lower_u,
	set_lower_x
};

#endif
