/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhoisCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:43:38 by slammari          #+#    #+#             */
/*   Updated: 2023/02/18 02:00:53 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/commands/CommandHandler.hpp"

WhoisCommand::WhoisCommand(Server *server) :  Command(server)
{
}

WhoisCommand::~WhoisCommand(void)
{
}

void	execute(Client *client, std::vector<std::string> arguments)
{
    
}
