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
Once you did that you have a few choices

```bash
SSHConnection.sln
```
to open the project in Visual Studio 2022

```bash
g++ -std=c++17 SSHConnection/src/main.cpp -o simple-ssh
```

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Author

**Jur Jansen**  
GitHub: [@jjansen123](https://github.com/jjansen123)

> _“SSH doesn’t have to be complicated — keep it simple.”_
