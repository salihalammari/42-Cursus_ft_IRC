/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:05:08 by sayar             #+#    #+#             */
/*   Updated: 2023/02/14 21:24:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/commands/CommandHandler.hpp"

CommandHandler::CommandHandler(Server *server) : _server(server) {
	_commands["NICK"] = new NickCommand(_server, false);
	_commands["PASS"] = new PassCommand(_server, false);
	_commands["USER"] = new UserCommand(_server, false);

	_commands["JOIN"] = new JoinCommand(_server);
	_commands["PART"] = new	PartCommand(_server);
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

			if (!client->getState() && command->authRequired()) {
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
