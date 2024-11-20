#include <iostream>
#include <string>

using namespace std;

class Racheta {
private:
	//atribute normale
	string nume;
	float capacitateCombustibil;
	float viteza;
	int nrDestinatii;
	string* destinatie; //pointer la un string de destinatie
	string status;

	//atribut constant
	const int id;

	//atribut static
	static int nrRachete;

public:
	//constructor implicit
	Racheta() :id(++nrRachete) {
		this->nume = "Prototip";
		this->capacitateCombustibil = 0;
		this->viteza = 0;
		this->nrDestinatii = 0;
		this->destinatie = nullptr;
		this->status = "Neinitializat";
	}

	//constructor explicit
	Racheta(string nume,float capacitateCombustibil, float viteza, int nrDestinatii, string* destinatie, string status) :id(++nrRachete)
		{
		this->nume = nume;
		this->capacitateCombustibil = capacitateCombustibil;
		this->viteza = viteza;
		this->nrDestinatii = nrDestinatii;
		this->destinatie = new string[nrDestinatii];
		for (int i = 0;i < nrDestinatii;i++) {
			this->destinatie[i] = destinatie[i];
		}
		this->status = status;
	}

	//destructor
	~Racheta() {
		if (destinatie) {
			delete[] destinatie;
		}
	}

	//constructor de copiere
	Racheta(const Racheta& alta) :id(++nrRachete) {
		this->nume = alta.nume;
		this->capacitateCombustibil = alta.capacitateCombustibil;
		this->viteza = alta.viteza;
		this->nrDestinatii = alta.nrDestinatii;
		this->destinatie = new string[alta.nrDestinatii];
		for (int i = 0; i < alta.nrDestinatii;i++) {
			this->destinatie[i] = alta.destinatie[i];
		}
		this->status = alta.status;
	}

	//functie afisare
	void afisareRacheta() {
		cout << "Numele rachetei cu id " << this->id<< " este " << this->nume << " si are o capacitate combustibil de "
			<< this->capacitateCombustibil << ". Atinge o viteza de " << this->viteza << " si poate vizita pana la " << this->nrDestinatii << " destinatii din spatiul cosmic. ";
		if (this->destinatie != nullptr) {
			cout << "Dintre acestea amintim: ";
			for (int i = 0; i < this->nrDestinatii; i++) {
				cout << this->destinatie[i] << ", ";
			}
		}
		cout << endl;
	}

};

int Racheta::nrRachete = 0;

int main() {
	Racheta racheta1;
	racheta1.afisareRacheta();

	Racheta racheta2("NASA", 500, 200, 3, new string[3]{"Marte", "Luna", "Venus"}, "Lansata");
	racheta2.afisareRacheta();

	Racheta racheta3 = racheta2;
	racheta3.afisareRacheta();

}