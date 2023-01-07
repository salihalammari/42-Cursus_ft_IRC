/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:47:16 by sayar             #+#    #+#             */
/*   Updated: 2023/01/07 15:24:32 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <time.h>

void	ft_print_log(const std::string &log) {
	time_t  raw;
    struct tm *time_info;
    char buff[80];

    time(&raw);
    time_info = localtime(&raw);

    strftime(buff, sizeof(buff), "%d-%m-%Y %H-%M-%S", time_info);
    std::string str(buff);

    std::cout << "[" << str << "]" << log << std::endl;
}

#endif