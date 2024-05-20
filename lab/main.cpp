#include "DataHandler.h"
#include "Airbase.h"
#include <iostream>

using namespace std;

int main()
{
	int entity_count = 1;
	int stop_signal = 0;
	int element_id;
	int field_index;
	Airbase* entities = new Airbase[entity_count];
	string file_name;
	char menu_choice = ' ';
	char sub_menu_choice = ' ';
	while (stop_signal == 0) {
		cout << "| Pick an action:"
			"\n|-- 1 - Create a new dataset"
			"\n|-- 2 - Save the current data to a file"
			"\n|-- 3 - Display the current dataset"
			"\n|-- 4 - Load data from a file"
			"\n|-- 5 - Search in the current dataset"
			"\n|-- 6 - Add new elements to the dataset"
			"\n|-- 7 - Delete an element by ID"
			"\n|-- 8 - Modify an element by ID"
			"\n|-- Enter any symbol to stop the application"
			"\n|---- Your selection: ";
		cin >> menu_choice;
		switch (menu_choice) {
		case '1':
			cout << "| Initializing new dataset..." << endl;
			DataHandler::manageEntities(&entities, &entity_count);
			break;
		case '2':
			cout << "| Enter the file name (without extension): ";
			cin >> file_name;
			DataHandler::storeData(entities, entity_count, file_name);
			break;
		case '3':
			cout << "| Displaying the current dataset..." << endl;
			DataHandler::displayEntities(entities, entity_count);
			break;
		case '4':
			cout << "| Enter the file name to load data from (without extension): ";
			cin >> file_name;
			DataHandler::retrieveData(&entities, &entity_count, file_name);
			break;
		case '5':
			cout << "| Select the field to search for an object:"
				"\n|-- 1 - Base name"
				"\n|-- 2 - Location"
				"\n|-- 3 - Peoples count"
				"\n|-- Enter your choice: ";
			cin >> sub_menu_choice;
			DataHandler::locateEntity(entities, entity_count, atoi(&sub_menu_choice));
			break;
		case '6':
			cout << "| Adding new elements to the dataset..." << endl;
			DataHandler::incorporateEntity(&entities, &entity_count);
			break;
		case '7':
			cout << "| Enter the ID of the element to delete: ";
			cin >> element_id;
			DataHandler::eliminateEntity(&entities, &entity_count, element_id);
			break;
		case '8':
			cout << "| Enter the ID of the element to modify: ";
			cin >> element_id;
			cout << "| Choose the field ID to modify:"
				"\n|-- 1 - Base name"
				"\n|-- 2 - Description"
				"\n|-- 3 - Peoples count"
				"\n|-- Enter your choice: ";
			cin >> field_index;
			DataHandler::amendEntity(&entities, entity_count, element_id, field_index);
			break;
		default:
			stop_signal = 1;
			break;
		}
	}
	return 0;
}