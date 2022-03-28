/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_writer_method.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:23 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:41:54 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_WRITER_METHOD_H
# define BUFFER_WRITER_METHOD_H

# include <sys/types.h>

# include "buffer_writer.h"

# define FT_NULL 0

void			_internal_flush(t_buffer_writer *this);
void			_write_signed_number_rec(t_buffer_writer *this, ssize_t n,
					const char *base, size_t num_base);
void			_write_unsigned_number_rec(t_buffer_writer *this, size_t n,
					const char *base, size_t num_base);

void			_buffer_writer(t_buffer_writer *this);
t_buffer_writer	*_write(t_buffer_writer *this, const char *str, size_t len);
t_buffer_writer	*_write_char(t_buffer_writer *this, char ch, size_t repeat);
t_buffer_writer	*_write_signed_number(t_buffer_writer *this,
					ssize_t n, const char *base);
t_buffer_writer	*_write_unsigned_number(t_buffer_writer *this,
					size_t n, const char *base);
ssize_t			_buffer_writer_flush(t_buffer_writer *this);

#endif
