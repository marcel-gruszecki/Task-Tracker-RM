#include <iostream>
#include "Header.h"




int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Available commands:" << std::endl;
		std::cout << "1. add" << std::endl;
		std::cout << "2. update" << std::endl;
		std::cout << "3. remove" << std::endl;
		std::cout << "4. mark-in-progress" << std::endl;
		std::cout << "5. mark-done" << std::endl;
		std::cout << "6. list" << std::endl;
		std::cout << "7. list-todo" << std::endl;
		std::cout << "8. list-in-progress" << std::endl;
	}

	std::string commands[8] = {"add", "update", "remove", "mark-in-progress",
		"mark-done", "list", "list-todo", "list-in-progress"};

	int task = -1;
	for (int i = 0; i < 8; i++) {
		if (argv[1] == commands[i]) {
			task = i;
			break;
		}
	}

	if (task == -1) {
		std::cout << "Incorrect command!!!" << std::endl;
	}

	switch (task) {
		case 0:
			if (argc == 3) {
				add(argv[2]);
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;
		
		case 1:
			if (argc == 4) {
				update(std::stoi(argv[2]), argv[3]);
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;
		
		case 2:
			if (argc == 3) {
				remove(std::stoi(argv[2]));
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;

		case 3:
			if (argc == 3) {
				mark_in_progress(std::stoi(argv[2]));
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;

		case 4:
			if (argc == 3) {
				mark_done(std::stoi(argv[2]));
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;

		case 5:
			if (argc == 2) {
				list();
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;

		case 6:
			if (argc == 2) {
				list_todo();
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;

		case 7:
			if (argc == 2) {
				list_in_progress();
			}
			else {
				std::cout << "error!!!" << std::endl;
			}
			break;

		default:
			std::cout << "error!!!" << std::endl;
			break;
	}
	
	return 0;
}