/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer_writer_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:17 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_buffer_writer.h"

#include "styles.h"
#include "token_buffer_writer_method.h"

void	_init_token_buffer_writer_(t_token_buffer_writer *token_buffer_writer)
{
	_init_buffer_writer_(&(token_buffer_writer->super));
	_init_styles_(&(token_buffer_writer->styles));
	token_buffer_writer->token_buffer_writer = _token_buffer_writer;
}
