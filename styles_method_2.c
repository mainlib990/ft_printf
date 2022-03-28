/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles_method_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:14 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:33:48 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "styles_method.h"

#include <sys/types.h>

#include "styles.h"
#include "token.h"

void	_styles(t_styles *this)
{
	this->space_prefix = g_space_prefix;
	this->hash_prefix_upper = g_hash_prefix_upper;
	this->hash_prefix_lower = g_hash_prefix_lower;
	this->plus_prefix = g_plus_prefix;
	this->space_prefix_len = g_space_prefix_len;
	this->hash_prefix_upper_len = g_hash_prefix_upper_len;
	this->hash_prefix_lower_len = g_hash_prefix_lower_len;
	this->plus_prefix_len = g_plus_prefix_len;
	this->default_style = (t_style){' ', FT_NULL, '0', 0, 0, 0, 0, 0};
}

t_style	_percentage_of(t_styles *this, t_token token)
{
	t_style	style;

	token.is_precision = 0;
	style = this->default_style;
	style.content_len = 1;
	_set_inner_padding(this, &style, token);
	_set_outer_padding(this, &style, token);
	return (style);
}

t_style	_upper_x_of(t_styles *this, t_token token, unsigned int n)
{
	t_style		style;
	const int	sign = (0 < n) - (0 > n);

	style = this->default_style;
	if (token.is_hash)
	{
		style.prefix = this->hash_prefix_upper[1 + sign];
		style.prefix_len = this->hash_prefix_upper_len[1 + sign];
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

t_style	_lower_c_of(t_styles *this, t_token token)
{
	t_style	style;

	style = this->default_style;
	style.content_len = 1;
	_set_outer_padding(this, &style, token);
	return (style);
}

t_style	_lower_d_of(t_styles *this, t_token token, ssize_t n)
{
	t_style		style;
	const int	sign = (0 < n) - (0 > n);

	style = this->default_style;
	if (token.is_space)
	{
		style.prefix = this->space_prefix[1 + sign];
		style.prefix_len = this->space_prefix_len[1 + sign];
	}
	else if (token.is_plus || (0 > sign))
	{
		style.prefix = this->plus_prefix[1 + sign];
		style.prefix_len = this->plus_prefix_len[1 + sign];
	}
	n *= sign;
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
