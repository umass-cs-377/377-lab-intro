# COMPSCI 377 LAB: Intro

## Purpose

This lab is designed to introduce you to C++. Specifically, it covers concepts such as pointers, objects, lists, and more. While you may already be familiar with these topics, a refresher can be helpful. Ensure that all your answers to the lab questions are based on work done within the Edlab environment. Answers produced outside this environment may lead to inconsistent results and will not receive credit.

During the lab, the TA will provide a brief overview of the different sections, but you are expected to complete all questions independently. If you have any questions during the lab session, please raise your hand for assistance. Each question and section has an associated point value, indicating its contribution to your final grade for this lab.

Please read through this lab and follow the instructions. After you do that, visit Gradescope and complete the questions associated with this lab by the assigned due date.

**You may work in groups up to 3 to complete this lab. Make sure you submit as a group in Gradescope.**

## Setup

Once you have logged in to Edlab, you can clone this repo using

```bash
git clone https://github.com/umass-cs-377/377-lab-intro.git
```

Then you can use `cd` to open the directory you just cloned:

```bash
cd 377-lab-intro
```

This repo includes a Makefile that allows you to locally compile and run all the sample code listed in this tutorial. You can compile them by running `make`. Feel free to modify the source files yourself, after making changes you can run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something went wrong during the compilation so that you can start fresh.


## Part 1 


```cpp
#include <iostream>
#include <cstdlib>
#include <unistd.h> // For gethostname

int main() {
    // Get the username
    const char* username = std::getenv("USER");
    if (username == nullptr) {
        username = std::getenv("USERNAME"); // For Windows compatibility
    }

    // Get the hostname
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("gethostname failed");
        return 1;
    }

    // Print the information
    std::cout << "Whoami: " << (username ? username : "Unknown") << std::endl;
    std::cout << "Hostname: " << hostname << std::endl;

    return 0;
}
```
