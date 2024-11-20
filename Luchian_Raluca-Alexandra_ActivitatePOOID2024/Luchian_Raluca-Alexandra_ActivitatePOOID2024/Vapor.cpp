#include <iostream>
using namespace std;

class Vapor {
private:
	int capacitate; //nr de persoane ce pot fi imbarcate
	int nrPersoaneImbarcate; //nr de persoane aflate la bord. nu poate fi mai mare decat capacitatea
	int* varstePasageri; //varstele pasagerilor
	static int nrVapoare; //contorizeaza automat nr de vapoare create
	const int idVapor; //id unic fiecarui vapor
public:
	//constructor fara parametrii
	Vapor() :idVapor(++nrVapoare) {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstePasageri = nullptr;
	};

	//constructor cu parametrii
	Vapor(int capacitate, int nrPersoaneImbarcate, int* varstePasageri) :idVapor(++nrVapoare) {
		this->capacitate = capacitate;
		if (nrPersoaneImbarcate > capacitate) {
			this->nrPersoaneImbarcate = capacitate;
		} else this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->varstePasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < nrPersoaneImbarcate;i++) {
			this->varstePasageri[i] = varstePasageri[i];
		}
		delete[] varstePasageri;
	}

	//destructor
	~Vapor() {
		if (varstePasageri != nullptr) {
			delete[] varstePasageri;
		}
	}

	//constructor copiere
	Vapor(const Vapor& altul) :idVapor(++nrVapoare) {
		this->capacitate = altul.capacitate;
		this->nrPersoaneImbarcate = altul.nrPersoaneImbarcate;
		this->varstePasageri = new int[altul.nrPersoaneImbarcate];
		for (int i = 0; i < altul.nrPersoaneImbarcate;i++) {
			this->varstePasageri[i] = altul.varstePasageri[i];
		}
		delete[] altul.varstePasageri;
	}

	//functie afisare
	void afisare() {
		cout << "Vaporul cu id-ul " << this->idVapor << ":" << endl;
		cout << "Capacitate: " << this->capacitate << endl;
		cout << "Numar pasageri: " << this->nrPersoaneImbarcate << endl;
		if (this->nrPersoaneImbarcate) {
			cout << "Varstele pasagerilor: ";
			for (int i = 0; i < nrPersoaneImbarcate;i++) {
				cout << this->varstePasageri[i] << "; ";
			}
		}
		cout << endl;
	}
};

int Vapor::nrVapoare = 0;

int main() {
	Vapor vaportest;
	Vapor vapor1(10, 5, new int[5]{25, 30, 34, 20, 22});
	Vapor vapor2(5, 6, new int[6] {24, 25, 24, 26, 29, 27});
	vaportest.afisare();
	vapor1.afisare();
	vapor2.afisare();
	Vapor vapor3 = vapor2;
	vapor3.afisare();

	return 0;
}