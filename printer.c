/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:54 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

#include "printer_method.h"
#include "scanner.h"
#include "token_buffer_writer.h"

void	_init_printer_(t_printer *printer)
{
	_init_scanner_(&(printer->scanner));
	_init_token_buffer_writer_(&(printer->token_buffer_writer));
	printer->printer = _printer;
	printer->print_next_token = _print_next_token;
	printer->printer_flush = _printer_flush;
}
