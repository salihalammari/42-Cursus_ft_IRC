/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:16:55 by sayar             #+#    #+#             */
/*   Updated: 2023/01/06 21:56:46 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/network/Server.hpp"

Server::Server(std::string const &port, std::string const &password) : _running(1), _host("127.0.0.1"),
	 _port(port), _password(password) {

	_sock = newSocket();

}

Server::~Server(void) {
}

int	Server::newSocket(void) {

	/*
	** Socket() creates an end point for communication and return a file descripto
	** AF_INET let the socket to the IPv4 Protocol
	** SOCK_STREAM is used to specify the socket type, witch allow the socket
	** to use TCP protocol, that means that the data is transimitted in
	** continuous stream
	*/
	int	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		throw std::runtime_error("Error while opening socket...");
	}

	// Forcefully attaching socket to port
	int value = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)) < 0) {
		throw std::runtime_error("Error while setting socket options...");
	}

    /*
	** setting the socket to NON_BLOCKING mode to allow it
	** to return any data in it's read buffer without waiting
	** for it!
	*/
	if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
		throw std::runtime_error("Error while setting socket to NON_BLOCKING...");
	}

	struct sockaddr_in server_address = {};

	// Clearing the structure address to avoid any segmentation fault
	bzero((char *) &server_address, sizeof(server_address));

	/*
	** Htons() function converts the unsigned short integer
	** hostshort from host byte order to network byte order.
	*/
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(std::stoi(_port));

	// Binding the socket to the current IP address on the selected port
	if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		throw std::runtime_error("Error while binding socket...");
	}

	// Letting the socket to listen to incoming requests
	if (listen(sockfd, MAX_CONNECTIONS) < 0) {
		throw std::runtime_error("Error while listening on socket...");
	}
	return (sockfd);
}