/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer_writer.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:41 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:55:00 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_BUFFER_WRITER_H
# define TOKEN_BUFFER_WRITER_H

# include <stdarg.h>

# include "buffer_writer.h"
# include "styles.h"
# include "token.h"

# define FT_NULL 0

typedef struct s_token_buffer_writer
{
	struct s_buffer_writer	super;
	struct s_styles			styles;
	int (*const				*write)(struct s_token_buffer_writer *, t_token);
	va_list					*ap;
	void					(*token_buffer_writer)(
			struct s_token_buffer_writer *, va_list *);
}	t_token_buffer_writer;

void	_init_token_buffer_writer_(t_token_buffer_writer *token_buffer_writer);

int		write_asc(t_token_buffer_writer *this, t_token token);
int		write_percentage(t_token_buffer_writer *this, t_token token);
int		write_upper_x(t_token_buffer_writer *this, t_token token);
int		write_lower_c(t_token_buffer_writer *this, t_token token);
int		write_lower_d(t_token_buffer_writer *this, t_token token);
int		write_lower_i(t_token_buffer_writer *this, t_token token);
int		write_lower_p(t_token_buffer_writer *this, t_token token);
int		write_lower_s(t_token_buffer_writer *this, t_token token);
int		write_lower_u(t_token_buffer_writer *this, t_token token);
int		write_lower_x(t_token_buffer_writer *this, t_token token);

static	int (*const	g_write[])(t_token_buffer_writer *, t_token) = {
	FT_NULL,
	write_asc,
	write_percentage,
	write_upper_x,
	write_lower_c,
	write_lower_d,
	write_lower_i,
	write_lower_p,
	write_lower_s,
	write_lower_u,
	write_lower_x
};

#endif
