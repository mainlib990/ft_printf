/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_method.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:29 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:41:10 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_METHOD_H
# define PRINTER_METHOD_H

# include <stdarg.h>
# include <sys/types.h>

# include "printer.h"

void	_printer(t_printer *this, const char *pattern, va_list *ap);
int		_print_next_token(t_printer *this);
ssize_t	_printer_flush(t_printer *this);

#endif
