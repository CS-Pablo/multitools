#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char *task_name) {
    if (task_count < MAX_TASKS) {
        strncpy(tasks[task_count].name, task_name, TASK_NAME_LEN);
        tasks[task_count].completed = 0;
        task_count++;
    } else {
        printf("Task list is full!\n");
    }
}

void complete_task(int task_index) {
    if (task_index >= 0 && task_index < task_count) {
        tasks[task_index].completed = 1;
    } else {
        printf("Invalid task index!\n");
    }
}

void list_tasks() {
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s [%s]\n", i, tasks[i].name, tasks[i].completed ? "completed" : "not completed");
    }
}

int main() {
    add_task("Learn C");
    add_task("Develop 42 Multitools");
    complete_task(0);
    list_tasks();
    return 0;
}
