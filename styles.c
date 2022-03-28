/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:07:11 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:32:43 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "styles.h"

#include "styles_method.h"

void	_init_styles_(t_styles *styles)
{
	styles->styles = _styles;
	styles->percentage_of = _percentage_of;
	styles->upper_x_of = _upper_x_of;
	styles->lower_c_of = _lower_c_of;
	styles->lower_d_of = _lower_d_of;
	styles->lower_i_of = _lower_i_of;
	styles->lower_p_of = _lower_p_of;
	styles->lower_s_of = _lower_s_of;
	styles->lower_u_of = _lower_u_of;
	styles->lower_x_of = _lower_x_of;
}
