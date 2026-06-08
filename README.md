<div align="center">

# ⚡ AetherOS

### A Lightweight Educational x86 Operating System Built From Scratch

[![C](https://img.shields.io/badge/C-Language-00599C?style=for-the-badge\&logo=c\&logoColor=white)]
[![Assembly](https://img.shields.io/badge/x86-Assembly-red?style=for-the-badge)]
[![Architecture](https://img.shields.io/badge/Architecture-x86-orange?style=for-the-badge)]
[![Kernel](https://img.shields.io/badge/Kernel-Custom-success?style=for-the-badge)]
[![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)]

**A custom operating system developed from scratch to explore kernel development, memory management, hardware interaction, and low-level systems programming.**


</div>

---

# 📌 Overview

AetherOS is an educational operating system designed to provide hands-on experience with operating system internals and low-level computer architecture.

The project implements core OS concepts including bootstrapping, kernel initialization, interrupt handling, memory management, and hardware communication. It serves as both a learning platform and a foundation for experimenting with advanced operating system features.

The primary goal of the project is to understand how modern operating systems work beneath the abstraction layers provided by existing platforms.

---

# ✨ Features

| Feature                    | Description                                        |
| -------------------------- | -------------------------------------------------- |
| 🚀 Custom Boot Process     | Boots directly into a custom kernel                |
| 🧠 Memory Management       | Low-level memory allocation and management         |
| ⚡ Interrupt Handling       | CPU exception and hardware interrupt support       |
| 🔄 Process Management      | Task scheduling and execution                      |
| 📂 File System Support     | Basic storage and file operations                  |
| 🖥️ Hardware Communication | Direct interaction with hardware devices           |
| 🔧 Modular Design          | Easy-to-expand architecture for future development |

---

# 🏗️ System Architecture

```text
+---------------------+
|      User Space     |
+---------------------+
           |
           v
+---------------------+
|      Kernel         |
| Memory Management   |
| Process Scheduler   |
| Interrupt Handler   |
| Device Drivers      |
+---------------------+
           |
           v
+---------------------+
|      Hardware       |
+---------------------+
```

---

# 🛠️ Tech Stack

| Technology   | Purpose                           |
| ------------ | --------------------------------- |
| C            | Kernel Development                |
| x86 Assembly | Bootloader & Low-Level Operations |
| GCC          | Compilation                       |
| NASM         | Assembly                          |
| GNU Make     | Build Automation                  |
| QEMU         | Virtual Machine Testing           |
| Git & GitHub | Version Control                   |

---

# 🚀 Installation

## Prerequisites

```bash
gcc
nasm
make
qemu-system-x86_64
grub
```

## Clone Repository

```bash
git clone https://github.com/ahmedayman2825/OS.git
cd OS
```

## Build

```bash
make
```

## Run

```bash
make run
```

Or manually:

```bash
qemu-system-x86_64 -kernel kernel.bin
```

---

# 🎮 Usage

After booting:

1. Bootloader loads the kernel.
2. Kernel initializes memory and hardware.
3. Core system services start.
4. User interacts with the operating system environment.

---

# 📁 Repository Structure

```text
OS/
│
├── shell.h
├── shell.c
├── myShell
├── main.c
├── Makefile
└── README.md
```

---

# 📈 Development Goals

The project explores:

* Operating System Design
* Computer Architecture
* CPU Privilege Levels
* Interrupt Handling
* Memory Management
* Process Scheduling
* File Systems
* Hardware Abstraction

---

# 🔭 Future Improvements

* [ ] Virtual Memory Support
* [ ] User Mode Processes
* [ ] Advanced Scheduler
* [ ] Multi-threading
* [ ] Networking Stack
* [ ] Graphical User Interface
* [ ] USB Support
* [ ] Multi-Core Processing (SMP)
* [ ] Advanced File System
* [ ] Package Management

---

# 👥 Contributors

 **Ahmed Ayman**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/eng-ahmed-ayman/)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/ahmedayman2825)

**Ahmed Tawfik**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ah-mo-tawfik/)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/tAwFiK2005)

**Ahmed Abdelwahab**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ahmed-abdalwahab/)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/ahmedabdalwahab)

**Ahmed Emad**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ahmed-zamel09/)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/AhmedZamel09)

Contributions, issues, and feature requests are welcome.

---

# ⭐ Support

If you find this project interesting, consider giving it a star on GitHub.

It helps the project gain visibility and motivates future development.

---

<div align="center">

### Built with ❤️ and low-level programming

⭐ Star the repository if you like the project

</div>
