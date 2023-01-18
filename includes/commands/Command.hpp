/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:24:13 by sayar             #+#    #+#             */
/*   Updated: 2023/01/18 19:44:13 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <string>
#include <numeric>
#include <regex>
#include "../network/Server.hpp"

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

class Command {

protected:
	Server	*_server;
	bool	_authRequired;

public:
	explicit Command(Server *server, bool authRequired = true) : _server(server), _authRequired(authRequired) {}
	virtual ~Command(void) {};

	bool authRequired(void) const {
		return (_authRequired);
	}

	virtual void execute(Client *client, std::vector<std::string> arguments) = 0;

};

class JoinCommand : public Command {



};

#endif