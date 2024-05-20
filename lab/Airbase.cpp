#include "Airbase.h"
#include <algorithm>
using namespace std;

string Airbase::get_BaseName() { return _baseName; }
void Airbase::set_BaseName(std::string baseName) { _baseName = baseName; }

string Airbase::get_Location() { return _location; }
void Airbase::set_Location(std::string location) { _location = location; }

int Airbase::get_PersonnelCount() { return _personnelCount; }
void Airbase::set_PersonnelCount(const int personnelCount) { _personnelCount = personnelCount; }

ostream& operator <<(ostream& out, Airbase& r)
{
	out << "Base Name: " + r.get_BaseName() << endl;
	out << "Location: " + r.get_Location() << endl;
	out << "Personnel Count: " << r.get_PersonnelCount() << endl;
	return out;
}

istream& operator >>(istream& in, Airbase& r)
{
	string baseName;
	cout << "Base Name: ";
	cin >> baseName;
	r.set_BaseName(baseName);

	string location;
	cout << "Location: ";
	cin >> location;
	r.set_Location(location);

	int personnelCount;
	cout << "Personnel Count: ";
	cin >> personnelCount;
	r.set_PersonnelCount(personnelCount);
	return in;
}