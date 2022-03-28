/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles_method.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:39 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:32:14 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLES_METHOD_H
# define STYLES_METHOD_H

# include <stddef.h>

# include "styles.h"
# include "token.h"

# define FT_NULL 0

void	_set_inner_padding(t_styles *this, t_style *style, t_token token);
void	_set_outer_padding(t_styles *this, t_style *style, t_token token);

void	_styles(t_styles *this);
t_style	_percentage_of(t_styles *this, t_token token);
t_style	_upper_x_of(t_styles *this, t_token token, unsigned int n);
t_style	_lower_c_of(t_styles *this, t_token token);
t_style	_lower_d_of(t_styles *this, t_token token, ssize_t n);
t_style	_lower_i_of(t_styles *this, t_token token, ssize_t n);
t_style	_lower_p_of(t_styles *this, t_token token, size_t ptr);
t_style	_lower_s_of(t_styles *this, t_token token, const char *str);
t_style	_lower_u_of(t_styles *this, t_token token, unsigned int n);
t_style	_lower_x_of(t_styles *this, t_token token, unsigned int n);

#endif
