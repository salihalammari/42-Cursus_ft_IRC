/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:45:11 by sayar             #+#    #+#             */
/*   Updated: 2023/02/12 20:11:29 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOINCOMMAND_HPP
# define JOINCOMMAND_HPP

# include "../../../includes/commands/CommandHandler.hpp"
# include "../../../includes/commands/Command.hpp"

JoinCommand::JoinCommand(Server *server) :  Command(server)
{
}

JoinCommand::~JoinCommand(void)
{
}

void	JoinCommand::execute(Client *client, std::vector<std::string> arguments)
{
    if(arguments.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickName(), "JOIN"));
        return;
    }
    std::string name = arguments[0];
    std::string password = arguments.size() > 1 ? arguments[1] : "";
    Channel* channel = client->getChannel();
    if(channel->_modes.find_first_of("i") != std::string::npos)
    {
        client->reply(ERR_INVITEONLYCHAN(name));
        return;
    }
    if(channel->_modes.("l") != std::string::npos)
    {
        client->reply(ERR_CHANNELISFULL(name));
        return;
    }
    
    if(channel)
    {
        client->reply(ERR_TOOMANYCHANNELS(client->getNickName(), name));
        return;
    }
    
    channel = _server->getChannel(name);
    
    if(channel->getPassword() != password)
    {
        client->reply(ERR_BADCHANNELKEY(client->getNickName(), name));
        retif(!channel)
    {
        _server->createChannel(name, password, client);
        return;
    }
    urn;
    }

    client->join(channel);
}

#endif
