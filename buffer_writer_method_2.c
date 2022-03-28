/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_writer_method_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:47 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:31:59 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_writer_method.h"

#include <sys/types.h>

void	_buffer_writer(t_buffer_writer *this)
{
	this->buffer_size = BUFFER_SIZE;
	this->loc = 0;
	this->len = 0;
}

t_buffer_writer	*_write(t_buffer_writer *this, const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while ((0 <= this->len) && (i < len))
	{
		this->buf[this->loc] = str[i];
		this->loc++;
		i++;
		if (this->loc >= this->buffer_size)
		{
			_internal_flush(this);
		}
	}
	return (this);
}

t_buffer_writer	*_write_char(t_buffer_writer *this, char ch, size_t repeat)
{
	size_t	i;

	i = 0;
	while ((0 <= this->len) && (i < repeat))
	{
		this->buf[this->loc] = ch;
		this->loc++;
		i++;
		if (this->loc >= this->buffer_size)
		{
			_internal_flush(this);
		}
	}
	return (this);
}

t_buffer_writer	*_write_signed_number(t_buffer_writer *this,
	ssize_t n,
	const char *base)
{
	size_t	num_base;

	if (base == FT_NULL)
	{
		base = "0123456789";
	}
	num_base = 0;
	while (base[num_base])
	{
		num_base++;
	}
	if (n < 0)
	{
		_write_char(this, '-', 1);
		n *= -1;
	}
	if (n)
	{
		_write_signed_number_rec(this, n, base, num_base);
	}
	else
	{
		_write_char(this, base[n], 1);
	}
	return (this);
}

t_buffer_writer	*_write_unsigned_number(t_buffer_writer *this,
	size_t n,
	const char *base)
{
	size_t	num_base;

	if (base == FT_NULL)
	{
		base = "0123456789";
	}
	num_base = 0;
	while (base[num_base])
	{
		num_base++;
	}
	if (n)
	{
		_write_unsigned_number_rec(this, n, base, num_base);
	}
	else
	{
		_write_char(this, base[n], 1);
	}
	return (this);
}
