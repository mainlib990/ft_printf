/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer_writer_method.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:22 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:26 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_buffer_writer_method.h"

#include <stdarg.h>

#include "token_buffer_writer.h"

void	_token_buffer_writer(t_token_buffer_writer *this, va_list *ap)
{
	this->super.buffer_writer(&(this->super));
	this->styles.styles(&(this->styles));
	this->ap = ap;
	this->write = g_write;
}
