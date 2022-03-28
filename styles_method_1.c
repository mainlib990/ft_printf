/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles_method_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:12 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "styles_method.h"

#include <sys/types.h>

#include "styles.h"
#include "token.h"

void	_set_inner_padding(t_styles *this, t_style *style, t_token token)
{
	if (token.is_precision)
	{
		style->ip_len = token.precision - style->content_len;
	}
	else if (token.is_zero)
	{
		style->ip_len = token.width - (style->prefix_len + style->content_len);
	}
	if (0 > style->ip_len)
	{
		style->ip_len = 0;
	}
	(void)this;
}

void	_set_outer_padding(t_styles *this, t_style *style, t_token token)
{
	ssize_t	op_len;

	op_len = token.width
		- (style->prefix_len + style->ip_len + style->content_len);
	if (0 > op_len)
	{
		op_len = 0;
	}
	if (token.is_minus)
	{
		style->rop_len = op_len;
	}
	else
	{
		style->lop_len = op_len;
	}
	(void)this;
}
