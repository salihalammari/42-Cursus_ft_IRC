/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:16:55 by sayar             #+#    #+#             */
/*   Updated: 2023/01/11 11:54:14 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/network/Server.hpp"

Server::Server(std::string const &port, std::string const &password) : _running(1), _host("127.0.0.1"),
	 _port(port), _password(password) {

	_sock = newSocket();

}

Server::~Server(void) {
}

void	Server::MessageClient(int fd) {

	try {
		Client *client = _clients.at(fd);
		// ??COMMAND
	}
	catch (const std::out_of_range &e) {}

}

void	Server::DisconnectClient(int fd) {

	try {

		Client *client = _clients.at(fd);
		client->leave();

		char log[1000];
		sprintf(log, "%s:%d has disconnected...", client->getHostName().c_str(), client->getPort());
		ft_print_log(log);

		_clients.erase(fd);
		for (pollfds_iterator it = _pollfds.begin(); it != _pollfds.end(); it++) {
			if (it->fd != fd)
				continue ;
			_pollfds.erase(it);
			close(fd);
			break ;
		}
		delete client;
	}
	catch (const std::out_of_range &e) {}

}

void	Server::ConnectClient(void) {

	int fd;
	/*
	** Sockaddr_in used to represent an Internet socket address
	** Sin_family specifies the address family (AKA IPv4/IPv6)
	** Sin_port specifies the port number in network byte order
	*/
	sockaddr_in s_addr = {};
	socklen_t	s_len = sizeof(s_addr);

	/*
	** Accept() is a function used to accept a connection request on a socket
	** s_addr will be filled with the address of the connecting socket
	** socklen_t is the variable that specifies the size of the "sockaddr" structure
	*/
	fd = accept(_sock, (struct sockaddr *)&s_addr, &s_len);
	if (fd < 0) {
		throw std::runtime_error("Error while accepting client connection...");
	}

	/*
	** Pollfd is a structure used to describe a file descriptor that being
	** monitored by poll()
	** POLLIN is the event that poll should monitor for
	*/
	pollfd	pollfd = {_sock, POLLIN, 0};
	_pollfds.push_back(pollfd);


	/*
	** Getnameinfo() is a function that is used to convert a socket
	** address to a hostname and service name
	*/
	char hostname[NI_MAXHOST];
	if (getnameinfo((struct sockaddr *)&s_addr, s_len, hostname, NI_MAXHOST, NULL, 0, NI_NUMERICSERV) < 0) {
		throw std::runtime_error("Error while getting hostname on new client...");
	}

	Client *client = new Client(fd, hostname, ntohs(s_addr.sin_port));
	_clients.insert(std::make_pair(fd, client));

	char log[1000];
	sprintf(log, "%s:%d has connected", client->getHostName().c_str(), client->getPort());
	ft_print_log(log);

}

void	Server::start(void) {

	pollfd	server_fd = {_sock, POLLIN, 0};
	_pollfds.push_back(server_fd);

	while (_running) {

		// Loop waiting for incoming connects or for incoming data on any of the connected sockets
		if (poll(_pollfds.begin().base(), _pollfds.size(), -1) < 9) {
			throw std::runtime_error("Error while Polling from fd...");
		}

		pollfds_iterator	it;
		for (it = _pollfds.begin(); it != _pollfds.end(); it++) {
			if (it->revents == 0)
				continue ;

			if ((it->revents & POLLHUP) == POLLHUP) {
				DisconnectClient(it->fd);
				break ;
			}

			if ((it->revents & POLLIN) == POLLIN) {
				if (it->fd == _sock) {
					ConnectClient();
					break ;
				}
				MessageClient(it->fd);
			}
		}

	}

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

Channel	*Server::getChannel(std::string const &name) {

	for (channel_iterator it = _channels.begin() ; it != _channels.end(); it++) {
		if (it.operator*().getName() == name) {
			return (it.operator*());
		}
		return (NULL);
	}
}

Channel	*Server::createChannel(std::string const &name, std::string const &password, Client *client) {

	Channel	*channel = new Channel(name, password, client);
	_channels.push_back(channel);

	return (channel);
}

Client	*Server::getClient(std::string const &nickname) {

	for (client_iterator it = _clients.begin(); it != _clients.end(); it++) {
		if (!nickname.compare(it->second->getNickName()))
			return (it->second);
	}
	return (NULL);
}

std::string Server::readMessage(int fd) {

	std::string msg;
	char buffer[100];

	bzero(buffer, 100);

	while (!std::strstr(buffer, "\r\n")) {

		bzero(buffer, 1000);
		if (recv(fd, buffer, 100, 0) < 0) {
			if (errno != EWOULDBLOCK)
				throw std::runtime_error("Error while reading buffer from client");
		}
		msg.append(buffer);
	}
	return (msg);
}

std::string Server::getPassword(void) const {
	return (this->_password);
}
