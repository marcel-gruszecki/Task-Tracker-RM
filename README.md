# Task - Simple Task Manager

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/std/the-standard)

Task is a simple and intuitive command-line task manager that allows you to add, edit, delete, and manage tasks efficiently.

## Installation

To install Task, clone the repository and compile the code using CMake:

```sh
git clone https://github.com/marcel-gruszecki/Task-Tracker-RM
cd Task-Tracker-RM
mkdir build && cd build
cmake ..
cmake --build .
```

After building, you can run the program using:

```sh
./task
```

## Features

- Add new tasks
- Update task descriptions
- Delete tasks
- Mark tasks as "in progress" or "done"
- Display all tasks or filtered lists

## Usage

### Adding a new task

```sh
task add "Buy groceries"
```
Task added successfully (ID: 1)

### Updating a task

```sh
task update 1 "Buy groceries and cook dinner"
```

### Deleting a task

```sh
task delete 1
```

### Marking a task as "in progress"

```sh
task mark-in-progress 1
```

### Marking a task as "done"

```sh
task mark-done 1
```

### Displaying the task list

```sh
task list
```

### Filtering tasks by status

```sh
task list-done
task list-todo
task list-in-progress
```

## License

This project is licensed under the MIT License. For details, see the LICENSE file.
