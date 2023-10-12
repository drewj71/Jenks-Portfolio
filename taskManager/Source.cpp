#include <iostream>
#include <string>
#include "TaskList.h"

using namespace std;

int main() {
	TaskList tlist;

	int idNum = 0;
	string taskTitle = "";
	string taskDesc = "";
	string taskDueDate = "";
	string taskStatus = "";
	int userInput = 0;
	bool notQuit = true;

	while (notQuit)
	{
		cout << endl << "-- Welcome to the Task List Manager --" << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1) View Tasks" << endl;
		cout << "2) Add a Task" << endl;
		cout << "3) Update a Task" << endl;
		cout << "4) Delete a Task" << endl;
		cout << "5) Quit" << endl;
		cin >> userInput;

		switch (userInput)
		{
		case 1: {
			if (userInput == 1)
			{
				tlist.viewTasks();
			}
		}
		case 2: {
			if (userInput == 2)
			{
				cout << "Please input the task" << endl;
				cout << "Task Id:" << endl;
				cin >> idNum;
				cout << "Task Title:" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, taskTitle);
				cout << "Task Description:" << endl;
				getline(cin, taskDesc);
				cout << "Due Date:" << endl;
				getline(cin, taskDueDate);
				cout << "Status:" << endl;
				getline(cin, taskStatus);
				tlist.addTask(idNum, taskTitle, taskDesc, taskDueDate, taskStatus);
				cout << "Task has been added." << endl;
			}
		}
		case 3: {
			if (userInput == 3)
			{
				cout << "Please input the Task ID number you would like to update:" << endl;
				cin >> idNum;
				cout << "Input the updated task" << endl;
				cout << "Task Title:" << endl;
				getline(cin, taskTitle);
				cout << "Task Description:" << endl;
				getline(cin, taskDesc);
				cout << "Due Date:" << endl;
				getline(cin, taskDueDate);
				cout << "Status:" << endl;
				getline(cin, taskStatus);
				tlist.updateTask(idNum, taskTitle, taskDesc, taskDueDate, taskStatus);
				cout << "Task has been updated." << endl;
			}
		}
		case 4: {
			if (userInput == 4)
			{
				cout << "Please input the Task ID number that you would like to delete:" << endl;
				cin >> idNum;
				tlist.deleteTask(idNum);
				cout << "Task has been deleted." << endl;
			}
		}
		case 5: {
			if (userInput == 5)
			{
				cout << endl <<"Thank you for using the Task List!" << endl;
				notQuit = false;
			}
		}
		default:
			break;
		}
	}

	return 0;
};