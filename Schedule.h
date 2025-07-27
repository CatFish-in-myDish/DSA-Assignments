// -*- C++ -*-

#ifndef SCHEDULE_HEADER
#define SCHEDULE_HEADER

/**
 * @file Schedule.h
 * @date Created 2025-07-25
 * 
 * This file contains the declaration of Task class in a task manager program and Schedule class with its member and method declaration.
 */

#include <string>
#include <iostream>

using namespace std;

/**
 * represents a real life task with a unique taskid, name and type of the task
 */
class Task {

    public:
        /**
         * An unique Identifier for a Task structure
         */
        string taskId;

        /**
         * One word containing the name of the task
         */
        string taskName;

        /**
         * Type of the task (Anime or Study)
         */
        string type;

        /**
         * Pointer to the next Task
         */
        Task* nextTask;

        /**
         * Initilizes an object for the task class
         * 
         * @param taskId an unique id that will be assigned to this task
         * @param taskName one word cointaing the name of the task
         * @param type type of the task (Anime or Study)
         * @param nextTask pointer to the next task, defaulted to nullptr
         */
        Task(string taskId, string taskName, string type, Task* nextTask = nullptr);
};

/**
 * Represents a task manager 
 */
class Schedule {
    private:

        /**
         * Pointer to the first task in the task manager
         */
        Task* firstTask;

    public:

        /**
         * Initializes an object for the Schedule class
         * 
         * @param firstTask pointer to the Task structure that will be the first task in the schedule, default nullptr
         */
        Schedule(Task* firstTask = nullptr);

        /**
         * Appends a task at the end of the list, if the list is empty the first task will be the specified task
         * 
         * @param id An unique identity string for the task
         * @param name name of the task
         * @param type the type of task, (Anime or Study)
         * @returns true if the task is added, false if not added or an task with the same id exists
         */
        bool addTask(string id, string name, string type);

        /**
         * Removes a task from the list using the unique id of the task
         * 
         * @param id the unique string id of the task
         * @returns Pointer of the task removed, if not found returns nullptr
         */
        Task* removeTask(string id);

        /**
         * prints all the tasks in "<TaskID> <TaskName> <TaskType>" format one task at a time
         * prints "Task list is empty" if the firstTask points to nullptr
         */
        void print();

        /**
         * works just as the print method with the tasks being reversed
         * reverses the task list first, prints the list and revereses the task list back to it's original format
         */
        void printReverse();
};

#endif