/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_writer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:22 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:51:27 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_WRITER_H
# define BUFFER_WRITER_H

# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_buffer_writer
{
	size_t					buffer_size;
	size_t					loc;
	char					buf[BUFFER_SIZE];
	ssize_t					len;
	void					(*buffer_writer)(struct s_buffer_writer *);
	struct	s_buffer_writer	*(*write)(struct s_buffer_writer *,
			const char *, size_t);
	struct	s_buffer_writer	*(*write_char)(struct s_buffer_writer *,
			char, size_t);
	struct	s_buffer_writer	*(*write_signed_number)(struct s_buffer_writer *,
			ssize_t, const char *);
	struct	s_buffer_writer	*(*write_unsigned_number)(struct s_buffer_writer *,
			size_t, const char *);
	ssize_t					(*buffer_writer_flush)(struct s_buffer_writer *);
}	t_buffer_writer;

void	_init_buffer_writer_(t_buffer_writer *buffer_writer);

#endif
