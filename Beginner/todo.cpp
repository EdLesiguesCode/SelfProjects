#include <iostream>
#include <vector>
#include <limits>
#include "Task.h"
using namespace std;

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? 'X' : ' ') << "] " << tasks[i].description << "\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    size_t taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    cin.ignore(); // Clear newline character from input buffer
    if (taskNumber == 0 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void deleteTask(vector<Task>& tasks) {
    size_t taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    cin.ignore(); // Clear newline character from input buffer
    if (taskNumber == 0 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task deleted successfully.\n";
}

int validation(const std::string& prompt){
    int value;

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "❌ Invalid input! Please enter a number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear any leftover input
            return value; // valid number, return it
        }
    }
}
