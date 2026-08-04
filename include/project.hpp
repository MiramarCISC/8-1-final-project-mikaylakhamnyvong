#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

using namespace std;

const int MIN_PRIORITY = 1;
const int MAX_PRIORITY = 5;
const int MAX_TASKS = 100;

struct Task {
    int id;
    string description;
    int priority;
    string dueDate;
    bool completed;
};

struct TaskNode {
    Task data;
    TaskNode* next;
};

bool isValidPriority(int priority);
bool isValidDescription(const string& description);

double calculateAvgPriority(const Task tasks[], int count);
int countCompletedTasks(const Task tasks[], int count);

void insertTask(TaskNode*& head, Task task);
bool removeTaskById(TaskNode*& head, int id);
TaskNode* findTasks(TaskNode* head, const string& description);
int countTasks(TaskNode* head);
void clearTasks(TaskNode*& head);

int taskListToArr(TaskNode* head, Task arr[], int maxSize);
void sortTasks(Task arr[], int count);
int findTaskIndex(const Task arr[], int count, int id);

int loadTasks(const string& filename, TaskNode*& head);
bool saveTasks(const string& filename, TaskNode* head);

void printMenu();

#endif
