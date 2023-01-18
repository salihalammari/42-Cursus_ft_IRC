/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:05:08 by sayar             #+#    #+#             */
/*   Updated: 2023/01/18 19:50:47 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/commands/CommandHandler.hpp"

CommandHandler::CommandHandler(Server *server) {
	this->_server = server;
}

CommandHandler::~CommandHandler(void) {

}

void	CommandHandler::request(Client *client, std::string const &message) {

	std::stringstream	ssMessage(message);
	std::string 		syntax;

	while (std::getline(ssMessage, syntax)) {

		syntax = syntax.substr(0, syntax[syntax.length() - 1] == '\r' ? syntax.length() - 1 : syntax.length());
		std::string name = syntax.substr(0, syntax.find(' '));

		try {
			Command	*command = _commands.at(name);

			std::vector<std::string> arguments;
			std::string				 buff;
			std::stringstream		 ss(syntax.substr(name.length(), syntax.length()));

			while (ss >> buff) {
				arguments.push_back(buff);
			}

			if (/* Client state*/ command->authRequired()) {
				client->reply(ERR_NOTREGISTRED(client->getNickName()));
				return ;
			}

			command->execute(client, arguments);
		}
		catch (const std::out_of_range &e) {
			client->reply(ERR_UNKNOWNCOMMAND(client->getNickName(), name));
		}

	}

}
