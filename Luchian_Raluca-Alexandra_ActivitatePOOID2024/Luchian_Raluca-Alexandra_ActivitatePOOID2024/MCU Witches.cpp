#include <iostream>
#include <vector>
using namespace std;

class Witch {
private:
	string name;
	vector <string> aliases;
	vector <string> powers;
	string status;
public:
	//constructor implicit
	Witch() {
		this->name = "Unkown";
		this->aliases = { "Unnkown" };
		this->powers = { "Unknown" };
		this->status = "Unknown";
	}

	//constructor cu parametrii
	Witch(string name, vector <string> aliases, vector <string> powers, string status) {
		this->name = name;
		this->aliases =  aliases ;
		this->powers =  powers ;
		this->status = status;
	}

	//destructor
	~Witch() {
		cout << "Goodbye, " << this->name << "!"<<endl;
	}

	//functie afisare
	void wichWitch() {
		cout << "Name: " << this->name << endl;
		cout << "Aliases: ";
		for (const auto& alias : aliases) {
			cout << alias << ", ";
		}
		cout <<" "<< endl;
		cout << "Powers: ";
		for (const auto& power : powers) {
			cout<< power << ", ";
		}
		cout <<" "<< endl;
		cout << "Status: " << this->status<<endl<<endl;

	}
};

int main() {
	Witch unknown;
	Witch wanda("Wanda Maximoff", { "The Scarlet Witch"}, {"Chaos Magic", "Telekinesis", "Mind Control"}, "Unknown");
	Witch agatha("Agatha Harkness", { "Witch Killer", "The Covenless Witch", "Jolene", "Nosy Neighbor" }, { "Succubus", "Dark Magic", "Necromancy"}, "Ghost");
	unknown.wichWitch();
	wanda.wichWitch();
	agatha.wichWitch();

	return 0;
}