/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PongCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:01:55 by slammari          #+#    #+#             */
/*   Updated: 2023/02/18 20:19:33 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/commands/Command.hpp"

PongCommand::PongCommand(Server *server) : Command(server) {

}

PongCommand::~PongCommand(void) {

}

void	PongCommand::execute(Client *client, std::vector<std::string> arguments) {

	if (arguments.empty()) {
		client->reply(ERR_NEEDMOREPARAMS(client->getNickName(), "PING"));
		return ;
	}

	client->write(RPL_PING(client->getPrefix(), arguments.at(0)));

}
