/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_method.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:06:34 by seungbki          #+#    #+#             */
/*   Updated: 2022/03/28 06:07:24 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_METHOD_H
# define SCANNER_METHOD_H

# include "scanner.h"

void		_scanner(t_scanner *this, const char *lexemes);
const char	*_get_lexemes(t_scanner *this);
int			_next_token(t_scanner *this, void *token);

#endif
