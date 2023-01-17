/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:24:13 by sayar             #+#    #+#             */
/*   Updated: 2023/01/17 20:36:27 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

class Command;

#include <string>
#include <numeric>
#include <regex>
#include "network/Server.hpp"

/*
**	JOIN Command
**	NICK Command
**	MODE Command
**	USER Command
**	PASS Command
**	PART Command
**	PING Command
**	PONG Command
**	KICK Command
**	QUIT Command
**	NOTICE Command
**	PRIVMSG Command
*/

class ACommand {

protected:
	Server	*_server;
	bool	_authRequired;

public:
	explicit Command(Server *server, bool authRequired = true) : _server(server), _authRequired(authRequired) {}
	~Command(void);

};

#endif