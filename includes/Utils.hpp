/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:47:16 by sayar             #+#    #+#             */
/*   Updated: 2023/01/18 15:36:05 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <time.h>

/* COMMAND REPLIES */
# define RPL_KICK(source, channel, target, reason)		":" + source + "KICK" + channel + " " + target + " :" + reason

/* ERROR REPLIES */
# define ERR_UNKNOWNCOMMAND(source, command)			"421 " + source + " " + command + " :Unknown command"
# define ERR_NEEDMOREPARAMS(source, command)			"461 " + source + " " + command + " :Not enough parameters"
# define ERR_REGISTRED(source)							"451 " + source + " :You have not registred"
# define ERR_ALREADYREGISTRED(source)					"462 " + source + " :Already registred"
# define ERR_PASSWDMISMATCH(source)						"464 " + source + " :Password incorrect"
# define ERR_NOTREGISTRED(source)						"451 " + source + " :You have not registred"


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