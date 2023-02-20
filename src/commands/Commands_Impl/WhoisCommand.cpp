/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhoisCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:43:38 by slammari          #+#    #+#             */
/*   Updated: 2023/02/20 13:35:29 by slammari         ###   ########.fr       */
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
// client->reply(RPL_WHOISUSER(client->getNickName(), client->getUserName(), client->getHostName(), client->getRealName()));
std::cout << "---->> " << _server->getName() << std::endl; 
client->reply(RPL_WHOISSERVER(client->getNickName(), _server->getName()));
// client->reply(RPL_ENDOFWHOIS(client->getNickName()));
// client->reply(RPL_ENDOFWHOWAS(client->getNickName()));

return;
}
