# PCC‑CS692: Computer Networks Lab 🌐

A collection of C-based networking experiments for the PCC‑CS692 course under MAKAUT. These hands-on labs help students explore core concepts like sockets, error control, inter-process communication, and more.

## 🗓 Lab List & Overview

| Lab # | Topic | Description |
|------:|:------|:------------|
| 1 | Message Queues | Convert decimal to binary/octal/hex and process via message queue. Extract and display in separate processes. |
| 2 | UNIX File Sockets | Build client-server parity generator via UNIX file socket |
| 3 | CRC via Sockets | Compute CRC codeword over socket communication |
| 4 | Cabling & Network Tools | RJ-45 termination, static/DHCP setup, and usage of network utilities |
| 5 | TCP Socket Bit‑Stuffing | Client-server bit-stuffing over TCP |
| 6 | Multi‑client IP Validator | TCP server validates IPv4 addresses from multiple clients |
| 7 | Hamming Code with UDP | Error-correction coding using UDP transport |
| 8 | Simple UDP Chat | Single-server UDP chat app |
| 9 | Multicast UDP Chat | Group chat via multicast UDP |
| 10 | Broadcast UDP | Continuous broadcast to multiple receivers |
| 11 | FTP/HTTP Traffic Analysis | Transfer via FTP/HTTP and inspect packets with Wireshark/tcpdump |
| 12 | Stop-and-Wait ARQ | Simulate data link ARQ protocol over TCP |

---

## 📝 Getting Started

1. **Clone the repo**
   ```bash
   git clone https://github.com/SamyakMishra072/PCC-CS692.git
   cd PCC-CS692
   gcc server.c -o server
   gcc client.c -o client
   ./server &
   ./client

