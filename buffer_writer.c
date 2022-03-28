/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:44 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_writer.h"

#include "buffer_writer_method.h"

void	_init_buffer_writer_(t_buffer_writer *buffer_writer)
{
	buffer_writer->buffer_writer = _buffer_writer;
	buffer_writer->write = _write;
	buffer_writer->write_char = _write_char;
	buffer_writer->write_signed_number = _write_signed_number;
	buffer_writer->write_unsigned_number = _write_unsigned_number;
	buffer_writer->buffer_writer_flush = _buffer_writer_flush;
}
