#include "DataHandler.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void DataHandler::manageEntities(Airbase** entities, int* count)
{
retry:
	cout << "count = ";
	cin >> *count;
	if (*count <= 0) {
		cout << "Error: Invalid count value, please try again.";
		goto retry;
	}
	else {
		*entities = new Airbase[*count];
		for (int i = 0; i < *count; i++)
		{
			cout << "ID: " << i << endl;
			cin >> (*entities)[i];
		}
	}
}

void DataHandler::storeData(Airbase* entities, int count, const std::string filename)
{
	ofstream file(filename + ".txt");
	if (!file.is_open())
	{
		cout << "Error: File not found" << endl;
		return;
	}
	file << count << endl;
	for (int i = 0; i < count; i++)
		file << entities[i].get_BaseName() + " " + entities[i].get_Location() + " " << entities[i].get_PersonnelCount() << endl;
	file.close();
	cout << "| Information saved successfully" << endl;
}

void DataHandler::retrieveData(Airbase** entities, int* count, const std::string filename)
{
	ifstream file(filename + ".txt");
	if (!file.is_open())
	{
		cout << "| Error: File not found" << endl;
		return;
	}
	file >> *count;
	*entities = new Airbase[*count];
	string* words = new string[3];
	for (int i = 0; i < *count; i++)
	{
		file >> words[0] >> words[1] >> words[2];
		(*entities)[i].set_BaseName(words[0]);
		(*entities)[i].set_Location(words[1]);
		(*entities)[i].set_PersonnelCount(stoi(words[2]));
	}
	file.close();
	cout << "| Information loaded successfully" << endl;
}

void DataHandler::locateEntity(Airbase* entities, int count, const int found_key)
{
	string searchKey;
	Airbase target;
	bool initFlag = false;
	cout << "| Enter the key you seek to find an object: ";
	cin >> searchKey;
	switch (found_key) {
	case 1:
		for (int i = 0; i < count; i++) {
			if ((entities)[i].get_BaseName() == searchKey)
			{
				target = entities[i];
				initFlag = true;
				break;
			}
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			if ((entities)[i].get_Location() == searchKey)
			{
				target = entities[i];
				initFlag = true;
				break;
			}
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			if ((entities)[i].get_PersonnelCount() == stoi(searchKey))
			{
				target = entities[i];
				initFlag = true;
				break;
			}
		}
		break;
	}
	if (initFlag)
		displayEntities(new Airbase[1]{ target }, 1);
	else
		cout << "Error: Object not found" << endl;
}

void DataHandler::displayEntities(Airbase* entities, int count)
{
	for (int i = 0; i < count; i++) {
		cout << "ID: " << i << endl;
		cout << entities[i];
	}
}

void DataHandler::incorporateEntity(Airbase** entities, int* count)
{
	int additionalCount;
	Airbase* formerEntities = *entities;
	Airbase* newEntities;

	cout << "Enter the number of new elements to add: ";
	cin >> additionalCount;

	*entities = new Airbase[*count + additionalCount];
	newEntities = new Airbase[additionalCount];

	for (int i = 0; i < additionalCount; i++)
		cin >> newEntities[i];

	for (int i = 0; i < *count; i++)
		(*entities)[i] = formerEntities[i];
	for (int i = 0; i < additionalCount; i++)
		(*entities)[*count + i] = newEntities[i];

	*count = *count + additionalCount;
}

void DataHandler::eliminateEntity(Airbase** entities, int* count, int target_index)
{
	*count = *count - 1;

	Airbase* formerEntities = *entities;
	Airbase* freshEntities = new Airbase[*count];
	for (int i = 0; i < *count; i++)
	{
		if (i >= target_index)
			freshEntities[i] = formerEntities[i + 1];
		else
			freshEntities[i] = formerEntities[i];
	}
	*entities = freshEntities;
}

void DataHandler::amendEntity(Airbase** entities, int count, int entity_index, int update_index) {
	string revisedField;
	int members;
	switch (update_index)
	{
	case 1:
		cout << "Enter the new name: ";
		cin >> revisedField;
		(*entities)[entity_index].set_BaseName(revisedField);
		break;
	case 2:
		cout << "Enter the new description: ";
		cin >> revisedField;
		(*entities)[entity_index].set_Location(revisedField);
		break;
	case 3:
		cout << "Enter the new membership count: ";
		cin >> members;
		(*entities)[entity_index].set_PersonnelCount(members);
		break;
	}
}