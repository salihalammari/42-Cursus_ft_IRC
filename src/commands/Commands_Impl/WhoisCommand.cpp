/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhoisCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:43:38 by slammari          #+#    #+#             */
/*   Updated: 2023/02/23 18:44:17 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/commands/CommandHandler.hpp"

WhoisCommand::WhoisCommand(Server *server) :  Command(server)
{
}

WhoisCommand::~WhoisCommand(void)
{
}

void	WhoisCommand::execute(Client *client, std::vector<std::string> arguments)
{
    if (arguments.size() < 1) {
		client->reply(ERR_NEEDMOREPARAMS(client->getNickName(), "WHOIS"));
		return ;
	}
	
	std::string name = arguments[0];
	Client *_client = _server->getClient(name);
	 if (!_client)
	 {
		client->reply(ERR_NOSUCHNICK(client->getNickName(), name));
		return ;
	}
	client->reply(RPL_WHOIS(client->getRealName(), client->getNickName(), client->getUserName(), client->getHostName()));
	return;
}
