#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

json database();
void add(std::string);
void update(int id, std::string);
void remove(int id); 
void mark_in_progress(int id);
void mark_done(int id);
void list();
void list_todo();
void list_in_progress();
std::string get_current_date();
