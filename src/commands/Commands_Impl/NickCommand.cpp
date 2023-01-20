/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:03:08 by sayar             #+#    #+#             */
/*   Updated: 2023/01/20 20:29:11 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/commands/Command.hpp"

NickCommand::NickCommand(Server *server, bool auth) : Command(server, auth) {
}

NickCommand::~NickCommand(void) {}

void	NickCommand::execute(Client *client, std::vector<std::string> arguments) {

}