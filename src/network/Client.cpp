/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:26:29 by schahid           #+#    #+#             */
/*   Updated: 2023/01/18 18:49:44 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(int fd_, int port_, std::string hostname_)
{
    this->fd = fd_;
    this->port = port_;
    this->hostname = hostname_;
    this->state = HANDSHAKE;
}

void    Client::write(std::string const &message)
{
    std::string buffer = message;

    if (send(this->fd, buffer.c_str(), buffer.length(), 0) < 0) {
		throw std::runtime_error("Error while sending message to client");
	}
}

Client::~Client(void) {}

void    Client::reply(std::string const &message)
{
    write (":" + getPrefix() + " " + message);
}

void    Client::welcome(void)
{
    if (this->state != LOGIN)
        //error
    this->state= PLAY;
    reply("Welcome to the Internet Relay Network " + getPrefix());

}

void Client::join(Channel *channel)
{
    channel->addClient(this);
    this->channel = channel;
    std::string users;
    std::vector<std::string> nicknames = channel->getNicknames();
    for (std::vector<std::string>::iterator it = nicknames.begin(); it != nicknames.end(); it++)
        users += " ";
    reply(channel->getName() + ": " + users); //RPL_names
    reply(channel->getName() + ": End of NAMES list"); //RPL_endnames

    ft_print_log(this->nick_name + "has joined channel " + channel->getName());
}

void Client::leave(void)
{
    this->channel->removeClient(this);
    ft_print_log(this->nick_name + "has left channel " + channel->getName());
}

std::string Client::getPrefix(void) const
{
    std::string user = this->user_name;
    std::string host = this->hostname;

    if (user_name.empty())
        user = this->user_name;
    else
        user = "!" + this->user_name;
    if (hostname.empty())
        host = this->hostname;
    else
        host = "@" + this->hostname;
    return ( this->nick_name + user + host);
}

Channel*  Client::getChannel(void) const
{
    return (this->channel);
}

std::string Client::getHostName(void) const
{
    return (this->hostname);
}

int Client::getFD(void) const
{
    return (this->fd);
}

int Client::getPort(void) const
{
    return (this->port);
}

std::string Client::getRealName(void) const
{
    return (this->real_name);
}

std::string Client::getNickName(void) const
{
    return (this->nick_name);
}

std::string Client::getUserName(void) const
{
    return (this->user_name);
}

int Client::getState(void) const
{
    return (this->state);
}

