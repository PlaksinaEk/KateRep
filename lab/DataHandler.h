#include "Airbase.h"
#include <string>
#pragma once

class DataHandler
{
public:
	static void manageEntities(Airbase** entities, int* count);
	static void storeData(Airbase* entities, int count, const std::string filename);
	static void retrieveData(Airbase** entities, int* count, const std::string filename);
	static void locateEntity(Airbase* entities, int count, const int found_key);
	static void displayEntities(Airbase* entities, int count);
	static void incorporateEntity(Airbase** entities, int* count);
	static void eliminateEntity(Airbase** entities, int* count, int target_index);
	static void amendEntity(Airbase** entities, int count, int found_key, int update_index);
};

