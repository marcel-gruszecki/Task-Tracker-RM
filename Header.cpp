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


json database()
{
	const std::string filename = "database.json";
	std::ifstream file(filename);
	json data;
	
	if (!file) {
		std::cerr << "Error: Could not open database.json" << std::endl;
		return json();  
	}

	file >> data;
	file.close();

	return(data);
}

void add(std::string des)
{
	const std::string filename = "database.json";
    int new_id = 0;
    std::ifstream file(filename);
    json data;

    if (file) {
        try {
            file >> data;
        } catch (json::parse_error& e) {
            std::cerr << "JSON Parse Error: " << e.what() << std::endl;
            data = json::object();
        }
    } else {
        std::cerr << "Warning: database.json does not exist. Creating a new one..." << std::endl;
        data = json::object();
    }
    file.close();

    for (auto& [id, task] : data.items()) {
		int current_id = std::stoi(id);
        if (current_id > new_id) {
			new_id = current_id;
        }
    }
    
    new_id += 1;

    json j;
    j["description"] = des;
    j["status"] = "todo";
    j["createdAt"] = get_current_date().substr(0, 19);
    j["updatedAt"] = get_current_date().substr(0, 19);

    data[std::to_string(new_id)] = j;

    // Zapis do pliku
    std::ofstream out_file(filename);
    if (!out_file) {
        std::cerr << "Error: Could not write to database.json" << std::endl;
        return;
    }
    out_file << data.dump(4);
    out_file.close();

    std::cout << "Task added successfully (ID: " << new_id << ")" << std::endl;
}

void update(int id = -1, std::string des = "")
{
	json data = database();
	if (!data.contains(std::to_string(id))){
		std::cout << "ID doesn't exist!!!" << std::endl;
		return;
	}

	data[std::to_string(id)]["description"] = des;
	data[std::to_string(id)]["updatedAt"] = get_current_date().substr(0, 19);
	std::ofstream out_file("database.json");
	out_file << data.dump(4);
	out_file.close();
	std::cout << "Update completed on " << id << std::endl;

}

void remove(int id)
{
	json data = database();
	if (!data.contains(std::to_string(id))) {
		std::cout << "ID doesn't exist!!!" << std::endl;
		return;
	}
	data.erase(std::to_string(id));
	std::ofstream out_file("database.json");
	out_file << data.dump(4);
	out_file.close();
	std::cout << "ID " << id << " has been removed." << std::endl;
}

void mark_in_progress(int id)
{
	json data = database();
	if (!data.contains(std::to_string(id))) {
		std::cout << "ID doesn't exist!!!" << std::endl;
		return;
	}

	data[std::to_string(id)]["status"] = "in-progress";
	data[std::to_string(id)]["updatedAt"] = get_current_date().substr(0, 19);
	std::ofstream out_file("database.json");
	out_file << data.dump(4);
	out_file.close();
	std::cout << "ID " << id << " has status 'in-progress'" << std::endl;
}

void mark_done(int id)
{
	json data = database();
	if (!data.contains(std::to_string(id))) {
		std::cout << "ID doesn't exist!!!" << std::endl;
		return;
	}

	data[std::to_string(id)]["status"] = "done";
	data[std::to_string(id)]["updatedAt"] = get_current_date().substr(0, 19);
	std::ofstream out_file("database.json");
	out_file << data.dump(4);
	out_file.close();
	std::cout << "ID " << id << " has status 'done'" << std::endl;
}

void list()
{
	bool in = false;
	const std::string filename = "database.json";
	std::ifstream file(filename);
	json data;
	file >> data;
	file.close();

	if (!file) {
		std::cerr << "Error: Could not open database.json" << std::endl;
		return;
	}

	for (auto& [i, task] : data.items()) {
		std::cout << "ID: " << i << std::endl;
		std::cout << "Description: " << task["description"] << std::endl;
		std::cout << "Status: " << task["status"] << std::endl;
		std::cout << "CreatedAt: " << task["createdAt"] << std::endl;
		std::cout << "UpdatedAt: " << task["updatedAt"] << std::endl << std::endl;
	}
}

void list_todo()
{
	bool in = false;
	const std::string filename = "database.json";
	std::ifstream file(filename);
	json data;
	file >> data;
	file.close();

	if (!file) {
		std::cerr << "Error: Could not open database.json" << std::endl;
		return;
	}

	for (auto& [i, task] : data.items()) {
		if (task["status"] == "todo") {
			std::cout << "ID: " << i << std::endl;
			std::cout << "Description: " << task["description"] << std::endl;
			std::cout << "Status: " << task["status"] << std::endl;
			std::cout << "CreatedAt: " << task["createdAt"] << std::endl;
			std::cout << "UpdatedAt: " << task["updatedAt"] << std::endl << std::endl;
		}
		
	}
}

void list_in_progress()
{
	bool in = false;
	const std::string filename = "database.json";
	std::ifstream file(filename);
	json data;
	file >> data;
	file.close();

	if (!file) {
		std::cerr << "Error: Could not open database.json" << std::endl;
		return;
	}

	for (auto& [i, task] : data.items()) {
		if (task["status"] == "in-progress") {
			std::cout << "ID: " << i << std::endl;
			std::cout << "Description: " << task["description"] << std::endl;
			std::cout << "Status: " << task["status"] << std::endl;
			std::cout << "CreatedAt: " << task["createdAt"] << std::endl;
			std::cout << "UpdatedAt: " << task["updatedAt"] << std::endl << std::endl;
		}

	}
}

