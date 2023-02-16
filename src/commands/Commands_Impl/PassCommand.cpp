/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:28:06 by slammari          #+#    #+#             */
/*   Updated: 2023/02/14 20:56:50 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSCOMMAND_HPP
# define PASSCOMMAND_HPP

# include "../../../includes/commands/CommandHandler.hpp"
# include "../../../includes/commands/Command.hpp"

PassCommand::PassCommand(Server *server, bool auth) : Command(server, auth)
{
}

PassCommand::~PassCommand(void)
{}

void PassCommand::execute(Client *client, std::vector<std::string> arguments) {

	if (client->getState()) {
		client->reply(ERR_ALREADYREGISTRED(client->getNickName()));
		return ;
	}

	if (arguments.empty()) {
		client->reply(ERR_NEEDMOREPARAMS(client->getNickName(), "PASS"));
		return ;
	}

	if (_server->getPassword() != arguments[0].substr(arguments[0][0] == ':' ? 1 : 0)) {
		client->reply(ERR_PASSWDMISMATCH(client->getNickName()));
		return ;
	}

	client->setState(LOGIN);

}

#endif
