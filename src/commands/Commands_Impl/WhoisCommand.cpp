/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhoisCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:43:38 by slammari          #+#    #+#             */
/*   Updated: 2023/02/18 20:29:58 by slammari         ###   ########.fr       */
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
    if (arguments.size() <21) {
		client->reply(ERR_NEEDMOREPARAMS(client->getNickName(), "WHOIS"));
		return ;
	}
	
	std::string name = argument[0];
	std::string target = arguments[1];
	Client *client = server->getClient(name);
	Channel *channel = _server->getChannel(target);

	 if (!client)
	 {
		client->reply(ERR_NOSUCHNICK(client->getNickName(), target));
		return ;
	}
client.reply(RPL_WHOISUSER(client.getNickName(), client.getUserName(), client.getPrefix));
client.reply(RPL_WHOISSERVER);
client.reply(RPL_WHOISMODE(client.getNickName()));	
client.reply(RPL_ENDOFWHOIS);
    
return;
}

