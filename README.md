# Distributed Systems Analysis

**Custom Remote Procedure Call (RPC) Framework**

This project involves the development of a custom RPC framework using C and Sockets, along with the implementation of six load balancing algorithms. The framework allows for distributed task allocation and performance analysis across multiple PCs within a network.

## Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Load Balancing Algorithms](#load-balancing-algorithms)
- [Performance Analysis](#performance-analysis)
- [Results](#results)
- [Contributing](#contributing)
- [License](#license)

## Features

- Custom RPC framework built using C and Sockets
- Implementation of six different load balancing algorithms
- Performance analysis based on various metrics

## Technologies Used

- **C**
- **Linux**
- **gRPC**
- **Sockets**

## Getting Started

To set up the project on your local machine, follow these instructions:

### Prerequisites

- A Linux-based operating system
- GCC compiler
- Git

### Installation

1. Clone the repository:

```
git clone https://github.com/dhruvsatyapanthi007/Automatic-Remote-Task-Allocator.git
```

2. Navigate into the project directory:

```
cd Automatic-Remote-Task-Allocator
```

3. Compile the project:

```
make
```

4. Run the server and client applications on multiple PCs connected to the same network.

## Usage

1. Start the server:

```
./server <port_number>
```

2. On each client, connect to the server:

```
./client <server_ip> <port_number>
```

3. Use the client application to send tasks to the server and observe the load balancing.

## Load Balancing Algorithms

The following load balancing algorithms have been implemented for task allocation:

1. **Round Robin**
2. **Least Connections**
3. **Weighted Round Robin**
4. **Random**
5. **Least Response Time**
6. **IP Hashing**

## Performance Analysis

The performance of the RPC framework was evaluated using the following metrics:

- **Response Time**: The time taken by the server to respond to a client's request.
- **Throughput**: The number of requests processed by the server in a given time period.
- **Server Utilization**: The percentage of server capacity being used during the operation.

To conduct the performance analysis, tests were run across multiple PCs on the same network, varying the number of concurrent clients.

## Results

The results of the performance analysis, including response times, throughput rates, and server utilization metrics, can be found in the `results` directory. Each algorithm's performance can be compared based on the collected metrics.

## Contributing

Contributions to this project are welcome. If you have suggestions or improvements, please create an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
This version has no language specified inside the backticks for commands. Let me know if there’s anything else you need!
