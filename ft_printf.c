/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:50 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>

#include "printer.h"

int	ft_printf(const char *format, ...)
{
	t_printer	printer;
	va_list		ap;

	_init_printer_(&printer);
	va_start(ap, format);
	printer.printer(&printer, format, &ap);
	while (printer.print_next_token(&printer))
		;
	va_end(ap);
	return (printer.printer_flush(&printer));
}
