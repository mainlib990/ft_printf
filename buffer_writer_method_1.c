/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_writer_method_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:45 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_writer_method.h"

#include <sys/types.h>
#include <unistd.h>

void	_internal_flush(t_buffer_writer *this)
{
	const ssize_t	len = write(1, this->buf, this->loc);

	this->loc = 0;
	if (len < 0)
	{
		this->len = -1;
	}
	else
	{
		this->len += len;
	}
}

void	_write_signed_number_rec(t_buffer_writer *this,
	ssize_t n,
	const char *base,
	size_t	num_base)
{
	if (0 < n)
	{
		_write_signed_number_rec(this, n / num_base, base, num_base);
		_write_char(this, base[n % num_base], 1);
	}
}

void	_write_unsigned_number_rec(t_buffer_writer *this,
	size_t n,
	const char *base,
	size_t	num_base)
{
	if (0 < n)
	{
		_write_unsigned_number_rec(this, n / num_base, base, num_base);
		_write_char(this, base[n % num_base], 1);
	}
}
