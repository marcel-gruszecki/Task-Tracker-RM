# Task - Simple Task Manager
My implementation of the task tracker from roadmap.sh.
Task is a simple and intuitive task manager that allows you to add, edit, delete, and manage tasks directly from the command line.

---

## 🎮 Installation

To install **Task**, clone the repository and compile the code:

```bash
git clone https://github.com/marcel-gruszecki/Task-Tracker-RM
cd task
make
```

Now you can run the program using:
```bash
./task
```

---

## ✨ Features

Task allows you to:
- ➕ Add tasks
- 🔄 Update task descriptions
- ❌ Delete tasks
- ✅ Mark tasks as "in progress" or "done"
- 🔍 Display all or filtered tasks

---

## 🗒 Usage

### 📓 Adding a new task
```bash
task add "Buy groceries"
```
**Output:** `Task added successfully (ID: 1)`

### 🔄 Updating a task
```bash
task update 1 "Buy groceries and cook dinner"
```

### ❌ Deleting a task
```bash
task delete 1
```

### ⏳ Marking a task as "in progress"
```bash
task mark-in-progress 1
```

### ✅ Marking a task as "done"
```bash
task mark-done 1
```

### 📝 Displaying the task list
```bash
task list
```

### 🌟 Filtering tasks by status
```bash
task list done
```
```bash
task list todo
```
```bash
task list in-progress
```

---

## 📦 License
This project is licensed under the MIT License. Full details can be found in the `LICENSE` file.




