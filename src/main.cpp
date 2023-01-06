/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:17:35 by sayar             #+#    #+#             */
/*   Updated: 2023/01/06 17:25:37 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/network/Server.hpp"

int main(int ac, char **av) {


	try {

		if (ac != 3) {
			throw std::runtime_error("Usage: ./ircserv <port> <password>");
		}

		Server server(av[1], av[2]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}



}