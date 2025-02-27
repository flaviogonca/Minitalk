# 🧰 42 Project: Minitalk


![Screenshot from 2025-02-27 11-43-16](https://github.com/user-attachments/assets/e56761f3-0c25-4039-a757-bacfee40e8d8)

## About the project
Minitalk is a data exchange program that demonstrates client-server communication using UNIX signals. This project serves as an introduction to signal handling and inter-process communication.

## Features
- Client-server architecture
- Signal-based data transmission
- Error handling
- Process synchronization

## Requirements
- GCC/CC compiler
- Standard C libraries
- Unix-like operating system

## Installation
```bash
git clone https://github.com/flaviogonca/Minitalk.git
cd Minitalk/
make
```

## Usage
1. Start the server:
```bash
./server
```
2. Run the client with the server's PID:
```bash
./client <server_pid> "Hello World!"
```

## Technical Details
### Signal Handling
- Uses SIGUSR1 and SIGUSR2 for communication
- Implements bit-by-bit data transmission
- Includes proper signal synchronization

### Error Management
- Handles invalid arguments
- Manages signal transmission errors

## Contributing
Contributions are welcome! Please submit pull requests with detailed descriptions of changes.
