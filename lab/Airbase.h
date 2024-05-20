#include <string>
#include <iostream>
#pragma once

class Airbase
{
private:
	std::string _baseName;
	std::string _location;
	int _personnelCount;

public:
	std::string get_BaseName();
	void set_BaseName(std::string baseName);

	std::string get_Location();
	void set_Location(std::string location);

	int get_PersonnelCount();
	void set_PersonnelCount(const int personnelCount);

	friend std::ostream& operator <<(std::ostream& out, Airbase& r);
	friend std::istream& operator >>(std::istream& in, Airbase& r);
};