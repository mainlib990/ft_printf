/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:37 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:54:44 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLES_H
# define STYLES_H

# include <sys/types.h>

# include "token.h"

# define FT_NULL 0

const static char		*g_space_prefix[] = {
	"-", " ", " "
};

const static char		*g_hash_prefix_upper[] = {
	"", "", "0X"
};

const static char		*g_hash_prefix_lower[] = {
	"", "", "0x"
};

const static char		*g_plus_prefix[] = {
	"-", "+", "+"
};

const static ssize_t	g_space_prefix_len[] = {
	1, 1, 1
};

const static ssize_t	g_hash_prefix_upper_len[] = {
	0, 0, 2
};

const static ssize_t	g_hash_prefix_lower_len[] = {
	0, 0, 2
};

const static ssize_t	g_plus_prefix_len[] = {
	1, 1, 1
};

/*
 * op		:	outer_padding
 * ip		:	inner_padding
 * lop_len	:	left_outer_padding_len
 * ip_len	:	inner_padding_len
 * rop_len	:	right_outer_padding_len
 */
typedef struct s_style
{
	char		op;
	const char	*prefix;
	char		ip;
	ssize_t		lop_len;
	ssize_t		prefix_len;
	ssize_t		ip_len;
	ssize_t		content_len;
	ssize_t		rop_len;
}	t_style;

typedef struct s_styles
{
	struct s_style		default_style;
	const char *const	*space_prefix;
	const char *const	*hash_prefix_upper;
	const char *const	*hash_prefix_lower;
	const char *const	*plus_prefix;
	const ssize_t		*space_prefix_len;
	const ssize_t		*hash_prefix_upper_len;
	const ssize_t		*hash_prefix_lower_len;
	const ssize_t		*plus_prefix_len;
	void				(*styles)(struct s_styles *);
	struct	s_style		(*percentage_of)(struct s_styles *, t_token);
	struct	s_style		(*upper_x_of)(struct s_styles *, t_token, unsigned int);
	struct	s_style		(*lower_c_of)(struct s_styles *, t_token);
	struct	s_style		(*lower_d_of)(struct s_styles *, t_token, ssize_t);
	struct	s_style		(*lower_i_of)(struct s_styles *, t_token, ssize_t);
	struct	s_style		(*lower_p_of)(struct s_styles *, t_token, size_t);
	struct	s_style		(*lower_s_of)(struct s_styles *, t_token, const char *);
	struct	s_style		(*lower_u_of)(struct s_styles *, t_token, unsigned int);
	struct	s_style		(*lower_x_of)(struct s_styles *, t_token, unsigned int);
}	t_styles;

void	_init_styles_(t_styles *style);

#endif
