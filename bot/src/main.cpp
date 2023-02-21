/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:38:23 by sayar             #+#    #+#             */
/*   Updated: 2023/02/18 15:33:38 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bot.hpp"

int main(int ac, char **av) {

	try {
		if (ac <= 3)
			throw std::runtime_error("Usage: /Bot <host> <port> <password>");
		else {

			Bot	bot(av[1], av[2], ac == 4 ? av[3] : "");
			bot.start();
		}
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}