// -*- C++ -*-

/**
 * @file Schedule.cpp
 * @date Created 2025-07-25
 * 
 * This file contains the defination of Task Class in a task manager program and Schedule class with its member and method declaration.
 */

#include <iostream>
#include <string>

#include "Schedule.h"

using namespace std;

Task::Task(string taskId, string taskName, string type, Task* nextTask){
    this->taskId = taskId;
    this->taskName = taskName;
    this->type = type;
    this->nextTask = nextTask;
}

Schedule::Schedule(Task* firstTask) {
    this->firstTask = firstTask;
}

bool Schedule::addTask(string id, string name, string type) {
    if (type != "Anime" && type != "Study") {
        cout << "Task not added\n";
        return false;
    }

    Task* newTask = new Task(id, name, type);

    if (this->firstTask == nullptr) {
        this->firstTask = newTask;
        cout << "Task " << id << "(" << type << " - " << name << ")added.\n"; 
        return true;
    }

    Task* current = this->firstTask;

    while (current->nextTask != nullptr) {
        if (current->taskId == id) {
            cout << "Task not added\n";
            return false;
        }
        current = current->nextTask;
    }
    if (current->taskId == id) {
            cout << "Task not added\n";
            return false;
    }
    current->nextTask = newTask;
    cout << "Task " << id << "(" << type << " - " << name << ")added.\n";
    return true;
}

Task* Schedule::removeTask(string id) {

    if (this->firstTask == nullptr) {
        cout << "Task " << id << " not found.\n";
        return nullptr;
    }

    if (this->firstTask->taskId == id) {
        Task* temp = this->firstTask;
        this->firstTask = this->firstTask->nextTask;
        cout << "Task " << id << " removed.\n"; 
        return temp;
    }

    Task* current = this->firstTask;

    for (; current->nextTask != nullptr; current = current->nextTask) {
        if (current->nextTask->taskId == id) {
            Task* temp = current->nextTask;
            current->nextTask = current->nextTask->nextTask;
            cout << "Task " << id << " removed.\n"; 
            return temp;
        }
    }

    cout << "Task " << id << " not found.\n";
    return nullptr;
}

void Schedule::print() {

    if (this->firstTask == nullptr) {
        cout << "Task list is empty\n";
        return;
    }

    Task* current = this->firstTask;

    for (; current != nullptr; current = current->nextTask) {
        cout << current->taskId << " " << current->taskName << " " << current->type << "\n";
    }

}

void Schedule::printReverse() {
    if (this->firstTask == nullptr) {
        return;
    }

    if (this->firstTask->nextTask == nullptr) {
        cout << this->firstTask->taskId << " " << this->firstTask->taskName << " " << this->firstTask->type + "\n";
        return;
    }

    Task* prev = nullptr;
    Task* current = this->firstTask;
    Task* next = nullptr;

    for (; current != nullptr; next = current->nextTask, current->nextTask = prev, prev = current, current = next);

    this->firstTask = prev;

    this->print();

    prev = nullptr;
    current = this->firstTask;
    next = nullptr;

    for (; current != nullptr; next = current->nextTask, current->nextTask = prev, prev = current, current = next);

    this->firstTask = prev;
}