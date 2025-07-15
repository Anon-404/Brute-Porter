# 🔐 Brute-Porter

Fast and flexible SSH & FTP brute-force tool built in C++ with multi-threading support.

---

## 🌟 Overview

**Brute-Porter** is a lightweight, powerful brute-forcer that supports **SSH** and **FTP** services. Whether you're conducting a penetration test or studying authentication protocols, this tool gives you fast and efficient brute-force capabilities with colorful terminal output and flexible attack modes.

---

## 🎯 Features

- 🔓 SSH & FTP brute-force support
- ⚡ Multi-threaded performance
- 🧾 Wordlist-based attacks (usernames, passwords, or both)
- 🔍 Target host and port scanner built-in
- 🖥️ Clean and colorful terminal UI

---

## 🧰 Requirements

- **C++11+**
- `libssh`
- `libcurl`
- `pthread`

### 🧪 Install dependencies

**Debian based distro**
```bash
sudo apt install libssh-dev libcurl4-openssl-dev build-essential
```

**Arch based distro**
```bash
sudo pacman -S libssh curl
```
**Termux (Android)**
```bash
pkg update && pkg upgrade
pkg install git clang openssl curl libssh
```
---

## ⚙️ Compile
**Linux**
```bash
g++ brute-porter.cpp -o brute-porter -lssh -lcurl -pthread
```
**Termux (Android)**
```bash
clang++ brute-porter.cpp -o brute-porter -lssh -lcurl
```

---

## 🚀 Run
```bash
./brute-porter
```

---

## 📌 Supported Attack Modes

### Mode	Description

- 1	Brute usernames with a known pass
- 2	Brute passwords with a known user
- 3	Full brute-force (user + pass list)



---

💡 Example Usage
```bash
[?] Enter target IP: 192.168.0.101
[?] Choose service: 1 (SSH)
[?] Enter port: 22
[?] Choose mode: 3 (Full brute-force)
[?] Enter userlist path: users.txt
[?] Enter passlist path: passwords.txt
[?] Max Threads: 10
[*] Starting brute-force...
[*] Trying: admin:admin123
```

---

## 👤 Author

**Name:** William Steven  
**GitHub:** [Anon-404](https://github.com/Anon-404)



---

## 📄 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).  
You are free to use, modify, and distribute this software with proper credit.
