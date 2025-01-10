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
This C++ program is a simple utility that retrieves and displays the current user's username and the hostname of the machine on which it is running. It achieves this by accessing environment variables for the username and using the `gethostnam` function to fetch the machine's hostname. The program ensures compatibility across Unix-like systems and Windows, making it a versatile tool for system diagnostics or personal use.

The program first attempts to retrieve the username from the `USER` environment variable, which is standard on Unix-like systems. If this variable is unavailable, it checks the `USERNAME` variable, commonly used on Windows systems. For the hostname, the program uses the `gethostname` function from the `unistd.h` library to populate a character array. It also includes basic error handling to display an error message if the hostname retrieval fails.


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
## Part 2
This code demonstrates several important programming concepts in C++, including dynamic memory management, the use of Standard Template Library (STL) containers, the definition and manipulation of custom data structures, and the design of modular and reusable functions for managing data. Each concept is implemented in a structured way to build a simple process management system. 

The `Process` struct defines a custom data structure that models a process in a system (we will talk more about this in the lecture). It includes fields for a process ID (pid), name (the name of the process), and status (in what state the process is in). These attributes encapsulate the essential characteristics of a process, making it easy to manage and manipulate process data. By using macros (#define), the code also defines constants for common process statuses like Running, Stopped, and Terminated.

The code employs dynamic memory allocation to create `Process` objects. Each process is allocated memory using the `new` operator and stored as a pointer in a `list`. This dynamic approach allows the program to manage memory efficiently for an arbitrary number of processes. However, dynamic memory allocation requires careful management to avoid memory leaks. The program addresses this by explicitly deleting each process object in a cleanup step at the end of the main function.

The program includes two functions (that you will implement), `searchProcessById` and `kill`, designed for searching and deleting processes by ID. The `searchProcessById` function is intended to iterate over the process list and return a pointer to the process matching a given ID. Similarly, the `kill` function is designed to remove a process with a specified ID from the list and free its memory.

```cpp
#include <iostream>
#include <list>
#include <string>

using namespace std;

// Define status macros
#define STATUS_RUNNING "Running"
#define STATUS_STOPPED "Stopped"
#define STATUS_TERMINATED "Terminated"

// Define the Process struct
struct Process {
    int pid;
    string name;
    string status;
};

// Function to search for a process by ID
Process* searchProcessById(const list<Process*>& processList, int pid) {
    //TODO find by id 
    return nullptr; // Return nullptr if not found
}

// Function to delete a process by ID
bool kill(list<Process*>& processList, int pid) {
    // TODO delete by id
    return false; // Process not found
}

int main() {
    // List to hold pointers to Process objects
    list<Process*> processList;

    // Create processes and add pointers to the list
    processList.push_back(new Process{1, "Process1", STATUS_RUNNING});
    processList.push_back(new Process{2, "Process2", STATUS_STOPPED});
    processList.push_back(new Process{3, "Process3", STATUS_RUNNING});
    processList.push_back(new Process{4, "Process4", STATUS_TERMINATED});
    processList.push_back(new Process{5, "Process5", STATUS_RUNNING});
    processList.push_back(new Process{6, "Process6", STATUS_STOPPED});
    processList.push_back(new Process{7, "Process7", STATUS_RUNNING});
    processList.push_back(new Process{8, "Process8", STATUS_TERMINATED});
    processList.push_back(new Process{9, "Process9", STATUS_STOPPED});
    processList.push_back(new Process{10, "Process10", STATUS_RUNNING});

    // Iterate through the list and print process details
    cout << "List of Processes:\n";
    for (const auto& process : processList) {
        cout << "Process ID: " << process->pid << ", Name: " << process->name << endl;
    }

    // Search for a process by ID
    int searchId = 2;
    Process* foundProcess = searchProcessById(processList, searchId);
    if (foundProcess) {
        cout << "Found Process - ID: " << foundProcess->pid << ", Name: " << foundProcess->name << ", Status: " << foundProcess->status << endl;
    } else {
        cout << "Process with ID " << searchId << " not found." << endl;
    }

    // Delete a process by ID
    int deleteId = 5;
    if (kill(processList, deleteId)) {
        cout << "Process with ID " << deleteId << " deleted successfully." << endl;
    } else {
        cout << "Process with ID " << deleteId << " not found for deletion." << endl;
    }

    // Clean up dynamically allocated memory
    for (auto& process : processList) {
        delete process;
    }

    return 0;
}
```



