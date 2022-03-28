/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:31 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/29 10:51:10 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include <stdint.h>

typedef struct s_scanner
{
	uint8_t			max_ecs_state;
	const uint8_t	*ecs;
	const uint8_t	*mecs;
	const uint8_t	*base;
	const uint8_t	*def;
	const uint8_t	*advance;
	const uint8_t	*check;
	const uint8_t	*next;
	const uint8_t	*command_id;
	void (*const	*commands)(void *, char);
	const char		*lexemes;
	void			(*scanner)(struct s_scanner *, const char *);
	const	char	*(*get_lexemes)(struct s_scanner *);
	int				(*next_token)(struct s_scanner *, void *);
}	t_scanner;

void	_init_scanner_(t_scanner *scanner);

#endif
