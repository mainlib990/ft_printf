/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles_method_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:15 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:34:39 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "styles_method.h"

#include <sys/types.h>

#include "styles.h"
#include "token.h"

t_style	_lower_i_of(t_styles *this, t_token token, ssize_t n)
{
	return (_lower_d_of(this, token, n));
}

t_style	_lower_p_of(t_styles *this, t_token token, size_t ptr)
{
	t_style	style;

	style = this->default_style;
	style.prefix = this->hash_prefix_lower[2];
	style.prefix_len = this->hash_prefix_lower_len[2];
	style.content_len = 1;
	while (16 <= ptr)
	{
		style.content_len++;
		ptr /= 16;
	}
	_set_outer_padding(this, &style, token);
	return (style);
}

t_style	_lower_s_of(t_styles *this, t_token token, const char *str)
{
	t_style	style;

	style = this->default_style;
	while (str[style.content_len])
	{
		style.content_len++;
	}
	if (token.is_precision && (style.content_len > token.precision))
	{
		style.content_len = token.precision;
	}
	_set_outer_padding(this, &style, token);
	return (style);
}

t_style	_lower_u_of(t_styles *this, t_token token, unsigned int n)
{
	t_style	style;

	style = this->default_style;
	style.content_len = ((0 == token.is_precision) || token.precision || n);
	while (10 <= n)
	{
		style.content_len++;
		n /= 10;
	}
	_set_inner_padding(this, &style, token);
	_set_outer_padding(this, &style, token);
	return (style);
}

t_style	_lower_x_of(t_styles *this, t_token token, unsigned int n)
{
	t_style		style;
	const int	sign = (0 < n) - (0 > n);

	style = this->default_style;
	if (token.is_hash)
	{
		style.prefix = this->hash_prefix_lower[1 + sign];
		style.prefix_len = this->hash_prefix_lower_len[1 + sign];
	}
	style.content_len = 1;
	while (16 <= n)
	{
		style.content_len++;
		n /= 16;
	}
	_set_inner_padding(this, &style, token);
	_set_outer_padding(this, &style, token);
	return (style);
}
