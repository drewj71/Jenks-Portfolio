#pragma once
#include <iostream>
#include <list>

using namespace std;

struct Task
{
	int id;
	string title;
	string description;
	string dueDate;
	string status;
	Task* next;

	Task(int taskId, string& taskTitle, string& taskDescription, string& taskDueDate, string& taskStatus) {
		this->id = taskId;
		this->title = taskTitle;
		this->description = taskDescription;
		this->dueDate = taskDueDate;
		this->status = taskStatus;
		this->next = nullptr;
	}
};

class TaskList
{
public:
	TaskList() : head(nullptr) {};

	void addTask(int id, string& title, string& description, string& dueDate, string& status) {
		Task* newTask = new Task(id, title, description, dueDate, status);
		newTask->next = head;
		head = newTask;
	}

	void viewTasks() {
		Task* current = head;

		if (current == nullptr)
		{
			cout << "There are no tasks to display." << endl;
			return;
		}

		cout << "Task List:" << endl << endl;;
		while (current != nullptr)
		{
			cout << "Task ID: " << current->id << endl;
			cout << "Title: " << current->title << endl;
			cout << "Description: " << current->description << endl;
			cout << "Due Date: " << current->dueDate << endl;
			cout << "Status: " << current->status << endl;
			cout << "-----------------------------" << endl;
			current = current->next;
		}
	}

	bool updateTask(int id, string& newTitle, string& newDescription, string& newDueDate, string& newStatus) {
		Task* current = head;
		
		while (current != nullptr)
		{
			if (current->id = id)
			{
				current->title = newTitle;
				current->description = newDescription;
				current->dueDate = newDueDate;
				current->status = newStatus;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool deleteTask(int id) {
		Task* current = head;
		Task* prev = nullptr;

		while (current != nullptr) {
			if (current->id = id)
			{
				if (prev == nullptr)
				{
					head = current->next;
				}
				else
				{
					prev->next = current->next;
				}

				delete current;
				return true;
			}
			prev = current;
			current = current->next;
		}
		return false;
	}

private:
	Task* head;
};