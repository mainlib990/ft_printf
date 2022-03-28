/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer_writer_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:21 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:56:03 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_buffer_writer.h"

#include <stdarg.h>
#include <stddef.h>

#include "styles.h"
#include "token.h"

int	write_lower_i(t_token_buffer_writer *this, t_token token)
{
	const int			n = va_arg(*(this->ap), int);
	const unsigned int	pos_n = n * ((0 < n) - (0 > n));
	const t_style		style
		= this->styles.lower_i_of(&(this->styles), token, n);

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

int	write_lower_p(t_token_buffer_writer *this, t_token token)
{
	const void		*ptr = va_arg(*(this->ap), void *);
	const t_style	style
		= this->styles.lower_p_of(&(this->styles), token, (size_t)ptr);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write(&(this->super), style.prefix, style.prefix_len)
		->write_unsigned_number(&(this->super), (size_t)ptr, "0123456789abcdef")
		->write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}

int	write_lower_s(t_token_buffer_writer *this, t_token token)
{
	const char	*str = va_arg(*(this->ap), char *);
	t_style		style;

	if (str == FT_NULL)
	{
		str = "(null)";
	}
	style = this->styles.lower_s_of(&(this->styles), token, str);
	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write(&(this->super), str, style.content_len)
		->write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}

int	write_lower_u(t_token_buffer_writer *this, t_token token)
{
	const unsigned int	n = va_arg(*(this->ap), unsigned int);
	const t_style		style
		= this->styles.lower_u_of(&(this->styles), token, n);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write_char(&(this->super), style.ip, style.ip_len);
	if ((token.is_precision && (0 == token.precision)) && (0 == n))
		;
	else
	{
		this->super.write_unsigned_number(&(this->super), n, FT_NULL);
	}
	this->super.write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}

int	write_lower_x(t_token_buffer_writer *this, t_token token)
{
	const unsigned int	n = va_arg(*(this->ap), unsigned int);
	const t_style		style
		= this->styles.lower_x_of(&(this->styles), token, n);

	this->super.write_char(&(this->super), style.op, style.lop_len)
		->write(&(this->super), style.prefix, style.prefix_len)
		->write_char(&(this->super), style.ip, style.ip_len)
		->write_unsigned_number(&(this->super), n, "0123456789abcdef")
		->write_char(&(this->super), style.op, style.rop_len);
	return (this->super.len >= 0);
}
