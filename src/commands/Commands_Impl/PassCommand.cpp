/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:28:06 by slammari          #+#    #+#             */
/*   Updated: 2023/02/13 22:33:12 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSCOMMAND_HPP
# define PASSCOMMAND_HPP

# include "../../../includes/commands/CommandHandler.hpp"
# include "../../../includes/commands/Command.hpp"

PassCommand::PassCommand(Server *server, bool auth) : Command(server *server, bool authRequired )
{
}

PassCommand::~PassCommand(void)
{}


#endif
