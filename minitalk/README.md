# Minitalk

## Overview

The `minitalk` project is a small data exchange program using UNIX signals. It consists of a server and a client that communicate by sending and receiving signals. The goal is to send a string from the client to the server, which then displays it.

## Features

- Server can handle multiple clients
- Client sends a string to the server
- Server displays the received string
- Communication using UNIX signals (`SIGUSR1` and `SIGUSR2`)

## Usage

### Compiling

To compile the project, run:

```sh
make
```

This will generate two executables: `server` and `client`.

### Running the Server

To start the server, run:

```sh
./server
```

The server will display its process ID (PID), which you will need to provide to the client.

### Running the Client

To send a string to the server, run:

```sh
./client [server_pid] [message]
```

Example:

```sh
./client 12345 "Hello, World!"
```

## Signals

The communication between the client and server is done using the following UNIX signals:

- `SIGUSR1`: Represents `0`
- `SIGUSR2`: Represents `1`

The client converts each character of the message into its binary representation and sends the corresponding signals to the server. The server reconstructs the message from the received signals and displays it.

## Resources

- [UNIX Signals](https://man7.org/linux/man-pages/man7/signal.7.html)
