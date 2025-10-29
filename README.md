![C++17](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

# Simple SSH Tool

A **lightweight, easy-to-use SSH profile manager** built in C++.  
It allows you to quickly create, store, and connect to SSH profiles without typing long commands each time.  
All profiles are stored locally in a simple JSON file.

---

## Features

- Create and save SSH profiles locally  
- Connect to servers instantly via saved profiles
- Profiles stored in a readable `profiles.json` file  
- Works directly from the terminal
- Simple CLI based user interface
- No external databases or servers — local only  
- Built using [nlohmann/json](https://github.com/nlohmann/json) for easy JSON handling  

---

## Installation

### Prerequisites
- C++17 or newer  
- `g++` or `clang++` compiler  
- `make` (optional but recommended)

### Clone the repository
```bash
cd C:\Path\To\Preferred\Library
git clone https://github.com/jjansen123/Simple-SSH-tool.git
cd Simple-SSH-tool
```

## Build Options
### Option 1: Open in Visual Studio 2022
Double-click or open:

```bash
SSHConnection.sln
```

Option 2: Compile with GNU C++ Compiler
```bash
g++ -std=c++17 SSHConnection/src/main.cpp -o simple-ssh
```
---
## Troubleshooting
```
❌ g++: command not found | Install g++ via your package manager (sudo apt install g++ or brew install gcc)
```
```
❌ nlohmann/json.hpp: No such file or directory | Make sure the JSON header is included in your project. You can install it via package manager or download manually from [nlohmann/json](https://github.com/nlohmann/json)
```
```
❌ SSH connection fails | Verify your profile details (host, user, port). Try connecting manually via ssh to confirm
```
```
❌ profiles.json not found | The file will be created automatically when you add a profile. Ensure write permissions in the working directory
```
---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Author

**Jur Jansen**  
GitHub: [@jjansen123](https://github.com/jjansen123)

> _“SSH doesn’t have to be complicated — keep it simple.”_
