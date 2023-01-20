/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:47:16 by sayar             #+#    #+#             */
/*   Updated: 2023/01/20 16:14:46 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <time.h>

/* COMMAND REPLIES */
# define RPL_KICK(source, channel, target, reason)		":" + source + "KICK" + channel + " " + target + " :" + reason
# define RPL_JOIN(source, channel)						":" + source + "JOIN :" + channel

/* ERROR REPLIES */
# define ERR_UNKNOWNCOMMAND(source, command)			"421 " + source + " " + command + " :Unknown command"
# define ERR_NEEDMOREPARAMS(source, command)			"461 " + source + " " + command + " :Not enough parameters"
# define ERR_REGISTRED(source)							"451 " + source + " :You have not registred"
# define ERR_ALREADYREGISTRED(source)					"462 " + source + " :Already registred"
# define ERR_PASSWDMISMATCH(source)						"464 " + source + " :Password incorrect"
# define ERR_NOTREGISTRED(source)						"451 " + source + " :You have not registred"
# define ERR_NONICKNAMEGIVEN(source)					"431 " + source + " :No nickname given"
# define ERR_NICKNAMEINUSE(source)						"433 " + source + " :Nickname is already in use"

/* NUMERIC REPLIES */
# define RPL_WELCOME(source)							"001 " + source + " :Welcome to the Internet Relay Network"
# define RPL_NAMREPLY(source, channel, users)			"353 " + source + " = " + channel + " :" + users
# define RPL_ENDOFNAMES(source, channel)				"366 " + source + " " + channel + " :End of NAMES list"

void	ft_print_log(const std::string &log);

#endif