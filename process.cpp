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