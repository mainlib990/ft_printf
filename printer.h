/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:28 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:41:22 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdarg.h>
# include <sys/types.h>

# include "scanner.h"
# include "token_buffer_writer.h"

# define FT_NULL 0

typedef struct s_printer
{
	struct s_token					default_token;
	struct s_scanner				scanner;
	struct s_token_buffer_writer	token_buffer_writer;
	void							(*printer)(struct s_printer *,
			const char *, va_list *);
	int								(*print_next_token)(struct s_printer *);
	ssize_t							(*printer_flush)(struct s_printer *);
}	t_printer;

void	_init_printer_(t_printer *printer);

#endif
