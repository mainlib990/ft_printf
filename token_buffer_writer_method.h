/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer_writer_method.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:43 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_BUFFER_WRITER_METHOD_H
# define TOKEN_BUFFER_WRITER_METHOD_H

# include <stdarg.h>

# include "token_buffer_writer.h"

void	_token_buffer_writer(t_token_buffer_writer *this, va_list *ap);

#endif
