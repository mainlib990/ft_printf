/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:56 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer_method.h"

#include <stdarg.h>
#include <sys/types.h>

#include "printer.h"
#include "token.h"

void	_printer(t_printer *this, const char *pattern, va_list *ap)
{
	this->default_token = (t_token){0, 0, 0, 0, 0, 0, 0, 0, 0, FT_NULL};
	this->scanner.scanner(&(this->scanner), pattern);
	this->token_buffer_writer.token_buffer_writer(&(this->token_buffer_writer),
		ap);
}

int	_print_next_token(t_printer *this)
{
	t_token	token;

	token = this->default_token;
	token.val = this->scanner.get_lexemes(&(this->scanner));
	return (*(token.val)
		&& (0 < this->scanner.next_token(&(this->scanner), &token))
		&& (this->token_buffer_writer.write[token.id]
			(&(this->token_buffer_writer), token)));
}

ssize_t	_printer_flush(t_printer *this)
{
	return (this->token_buffer_writer.super.buffer_writer_flush
		(&(this->token_buffer_writer.super)));
}
