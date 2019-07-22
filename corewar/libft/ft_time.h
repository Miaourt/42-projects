/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 09:07:22 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/11 17:17:01 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# include <time.h>

typedef struct			s_date
{
	char				*raw_data;
	char				*day;
	char				*month;
	char				*day_of_month;
	char				*time;
	char				*year;
}						t_date;

t_date					*ft_parse_date(time_t *time);
void					ft_destroy_date(t_date *to_del);

#endif
