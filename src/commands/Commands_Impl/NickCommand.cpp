/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:03:08 by sayar             #+#    #+#             */
/*   Updated: 2023/02/16 21:00:21 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/commands/Command.hpp"

NickCommand::NickCommand(Server *server, bool auth) : Command(server, auth) {
}

NickCommand::~NickCommand(void) {}

void	NickCommand::execute(Client *client, std::vector<std::string> arguments) {
    (void)client;
    (void)arguments;
}
