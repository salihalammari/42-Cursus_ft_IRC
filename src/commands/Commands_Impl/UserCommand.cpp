/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:00:17 by slammari          #+#    #+#             */
/*   Updated: 2023/02/14 22:00:37 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/commands/Command.hpp"

UserCommand::UserCommand(Server *server, bool auth) : Command(server, auth) {

}

UserCommand::~UserCommand(void) {}

void UserCommand::execute(Client *client, std::vector<std::string> arguments) {

	if (client->getState()) {
		client->reply(ERR_ALREADYREGISTRED(client->getNickName()));
		return ;
	}

	if (arguments.size() < 4) {
		client->reply(ERR_NEEDMOREPARAMS(client->getNickName(), "USER"));
		return ;
	}

	client->setUserName(arguments[0]);
	client->setRealName(arguments[3]);
	client->welcome();

}
