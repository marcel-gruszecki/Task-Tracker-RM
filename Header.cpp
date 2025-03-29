#include "Header.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using json = nlohmann::json;

std::string get_current_date() {
	auto now = std::chrono::system_clock::now();
	auto now_time = std::chrono::system_clock::to_time_t(now);
	return std::format("{:%Y-%m-%d %H:%M:%S}", std::chrono::system_clock::from_time_t(now_time));
}


void add(std::string des)
{
	//Read file
	const std::string filename = "database.json";
	int new_id = 0;
	std::ifstream file(filename);
	json data;
	file >> data;
	file.close();

	//Check if new_id is in the database
	for (auto& [id, task] : data.items()) {
		if (std::stoi(id) > new_id) {
			new_id = std::stoi(id);
		} 
	}
	new_id += 1;
	
	json j;
	j["description"] = des;
	j["status"] = "todo";
	j["createdAt"] = get_current_date().substr(0, 19);
	j["updatedAt"] = get_current_date().substr(0, 19);


	data[std::to_string(new_id)] = j;

	//Writing data
	std::ofstream out_file("database.json");
	out_file << data.dump(4);
	out_file.close();

	std::cout << "Task added successfully (ID: " << new_id << ")" << std::endl;
}

void update(int id = -1, std::string des = "")
{
	const std::string filename = "database.json";
	std::ifstream file(filename);
	json data;
	file >> data;
	file.close();
	
	for (auto& [i, task] : data.items()) {
		if (std::stoi(i) > id) {
			id = std::stoi(i);
		}
	}
	if (id == -1) {
		std::cout << "This id is not in the database!!!" << std::endl;
	}
	else {
		data[id]["description"] = des;
	}

}
