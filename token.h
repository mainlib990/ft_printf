/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:40 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:25 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_token
{
	unsigned int	id;
	unsigned int	is_space		: 1;
	unsigned int	is_hash			: 1;
	unsigned int	is_plus			: 1;
	unsigned int	is_minus		: 1;
	unsigned int	is_precision	: 1;
	unsigned int	is_zero			: 1;
	unsigned int	width;
	unsigned int	precision;
	const char		*val;
}	t_token;

#endif
