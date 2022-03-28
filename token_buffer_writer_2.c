/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer_writer_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:19 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:36:10 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_buffer_writer.h"

#include <stdarg.h>

#include "styles.h"
#include "token.h"

int	write_asc(t_token_buffer_writer *this, t_token token)
{
	this->super.write(&(this->super), token.val, token.width);
	return (this->super.len >= 0);
}

int	write_percentage(t_token_buffer_writer *this, t_token token)
{
	const t_style	style = this->styles.percentage_of(&(this->styles), token);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write_char(&(this->super), style.ip, style.ip_len)
		->write_char(&(this->super), '%', 1)
		->write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}

int	write_upper_x(t_token_buffer_writer *this, t_token token)
{
	const unsigned int	n = va_arg(*(this->ap), unsigned int);
	const t_style		style
		= this->styles.upper_x_of(&(this->styles), token, n);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write(&(this->super), style.prefix, style.prefix_len)
		->write_char(&(this->super), style.ip, style.ip_len)
		->write_unsigned_number(&(this->super), n, "0123456789ABCDEF")
		->write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}

int	write_lower_c(t_token_buffer_writer *this, t_token token)
{
	const char		ch = va_arg(*(this->ap), int);
	const t_style	style = this->styles.lower_c_of(&(this->styles), token);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write_char(&(this->super), ch, 1)
		->write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}

int	write_lower_d(t_token_buffer_writer *this, t_token token)
{
	const int			n = va_arg(*(this->ap), int);
	const unsigned int	pos_n = n * ((0 < n) - (0 > n));
	const t_style		style
		= this->styles.lower_d_of(&(this->styles), token, n);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write(&(this->super), style.prefix, style.prefix_len)
		->write_char(&(this->super), style.ip, style.ip_len);
	if ((0 == token.is_precision) || token.precision || pos_n)
	{
		this->super.write_unsigned_number(&(this->super), pos_n, FT_NULL);
	}
	this->super.write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}
