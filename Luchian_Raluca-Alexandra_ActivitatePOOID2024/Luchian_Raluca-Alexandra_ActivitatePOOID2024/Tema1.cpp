#include <iostream>
using namespace std;

class Autobuz {
private:
	static int nrAutobuze; //contorizeaza automat nr de autobuze create
	const int idAutobuz; //id unic pt fiecare autobuz
	int capacitate; //nr de scaune
	int nrPersoaneImbarcate; //nr persoane imbarcate - nu poate fi mai mare decat capacitatea
	char* producator; // numele producatorului
public:

	//constructor default, fara parametrii
	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = nullptr;
	}

	//constructor cu parametrii
	Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) :idAutobuz(++nrAutobuze) {
		this->capacitate = capacitate;
		if (nrPersoaneImbarcate > capacitate) {
			cout << "Prea multe persoane imbarcate pentru numarul de scaune disponibile. Ajustez numarul de pasageri in functie de acest factor.";
			this->nrPersoaneImbarcate = capacitate;
		}
		else this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);

	};

	//destructor
	~Autobuz() {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
	};

	//constructor copiere
	Autobuz(const Autobuz& altul) :idAutobuz(++nrAutobuze) {
		this->capacitate = altul.capacitate;
		this->nrPersoaneImbarcate = altul.nrPersoaneImbarcate;
		this->producator = new char[strlen(altul.producator) + 1];
		strcpy_s(this->producator, strlen(altul.producator) + 1, altul.producator);
	};

	//metoda get pentru producator
	const char* getProducator() {
		return this->producator;
	};

	//metoda set pentru producator
	void setProducator(const char* nouProducator) {
		this->producator = new char[strlen(nouProducator) + 1];
		strcpy_s(this->producator, strlen(nouProducator) + 1, nouProducator);
	}

	//metoda get pentru pasageri

	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	//metoda set pentru pasageri
	void setNrPersoaneImbarcate(int nouNrPersoaneImbarcate) {
		if (nouNrPersoaneImbarcate > this->capacitate) {
			cout << "Prea multe persoane imbarcate pentru numarul de scaune disponibile. Ajustez numarul de pasageri in functie de acest factor." << endl;
			this->nrPersoaneImbarcate = this->capacitate;
		}
		else this->nrPersoaneImbarcate = nouNrPersoaneImbarcate;
	}


	//functie de afisare
	void afisareAutobuz() {
		cout << "Id: " << this->idAutobuz << endl;
		cout << "Capacitate: " << this->capacitate << endl;
		cout << "Numar persoane imbarcate: " << this->nrPersoaneImbarcate << endl;
		if (this->producator != nullptr) {
			cout << "Producator: " << this->producator << endl;
		}
		else cout << "Nu are producator" << endl;
	}
};

int Autobuz::nrAutobuze = 0;

int main() {
	//testare constructor fara parametrii
	Autobuz autobuz0;
	autobuz0.afisareAutobuz();

	//testare constructor cu parametrii
	Autobuz autobuz1(20, 21, "Volswagen");
	autobuz1.afisareAutobuz();

	//testare constructor copiere
	Autobuz autobuzCopie = autobuz1;
	autobuzCopie.afisareAutobuz();

	//testare getteri si setteri pt nr pasageri (persoane imbarcate) si producator
	cout << "Producatorul initial pentru autobuzul 2 este: " << autobuz1.getProducator() << endl;
	autobuz1.setProducator("Toyota");
	cout << "Noul producator pentru autobuzul 2 este: " << autobuz1.getProducator() << endl;

	cout << "Numarul initial de persoane imbarcate in autobuzul 1 este: " << autobuz0.getNrPersoaneImbarcate() << endl;
	autobuz0.setNrPersoaneImbarcate(1);
	cout << "Noul numar de persoane imbarcate in autobuzul 1 este: " << autobuz0.getNrPersoaneImbarcate() << endl;
}