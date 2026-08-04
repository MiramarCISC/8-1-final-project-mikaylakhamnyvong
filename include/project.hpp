#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

using namespace std;

// Week 1: Variables, Constants
const int MIN_PRIORITY = 1;
const int MAX_PRIORITY = 5;
const int MAX_TASKS = 100;

// Week 5: Structures
struct Task {
    int id;
    string description;
    int priority;
    string dueDate;
    bool completed;
};

// Week 6: Linked list node
struct TaskNode {
    Task data;
    TaskNode* next;
};

// Week 2: Decisions, Input validation
bool isValidPriority(int priority);
bool isValidDescription(const string& description);

// Week 1: Arithmetics & Week 3: Functions
double calculateAvgPriority(const Task tasks[], int count);
int countCompletedTasks(const Task tasks[], int count);

// Week 6: Linked list operations
void insertTask(TaskNode*& head, Task task);
bool removeTaskById(TaskNode*& head, int id);
TaskNode* findTasks(TaskNode* head, const string& description);
int countTasks(TaskNode* head);
void clearTasks(TaskNode*& head);

// Week 4: Arrays, Searching, Sorting
int taskListToArr(TaskNode* head, Task arr[], int maxSize);
void sortTasks(Task arr[], int count);
int findTaskIndex(const Task arr[], int count, int id);

// Week 7: File I/O
int loadTasks(const string& filename, TaskNode*& head);
bool saveTasks(const string& filename, TaskNode* head);

// Week 2: Repeating menu
void printMenu();

#endif
