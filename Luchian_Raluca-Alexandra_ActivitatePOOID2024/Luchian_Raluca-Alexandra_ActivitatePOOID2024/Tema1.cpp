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
			cout << "Prea multe persoane imbarcate pentru numarul de scaune disponibile. Ajustez numarul de pasageri in functie de acest factor." << endl;
			this->nrPersoaneImbarcate = capacitate;
		}
		else this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);

	};

	//constructor copiere
	Autobuz(const Autobuz& altul) :idAutobuz(++nrAutobuze) {
		this->capacitate = altul.capacitate;
		this->nrPersoaneImbarcate = altul.nrPersoaneImbarcate;
		this->producator = new char[strlen(altul.producator) + 1];
		strcpy_s(this->producator, strlen(altul.producator) + 1, altul.producator);
	};

	//destructor
	~Autobuz() {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
	};

	//metoda get pentru producator
	const char* getProducator() {
		return this->producator;
	};

	//metoda set pentru producator
	void setProducator(const char* nouProducator) {
		if (this->producator != nullptr) {
			//eliberare memorie existenta
			delete[] this->producator;  
		}
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

	//supraincarcare operator de atribuire
	Autobuz& operator=(const Autobuz& altul) {
		//Verificare auto atribuire
		if (this != &altul) {
			//eliberare memorie existenta
			delete[] this->producator;
			//copiere atribute
			this->capacitate = altul.capacitate;
			this->nrPersoaneImbarcate = altul.nrPersoaneImbarcate;
			if (altul.producator) {
				this->producator = new char[strlen(altul.producator) + 1];
				strcpy_s(this->producator, strlen(altul.producator) + 1, altul.producator);
			}
			else this->producator = nullptr;
		}
		else cout << "Nu se poate autoatribui. Mai incearca" << endl;
		return *this;
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Autobuz& autobuz) {
		out << "Id: " << autobuz.idAutobuz << "; "
			<< "Capacitate: " << autobuz.capacitate << "; "
			<< "Numar pasageri: " << autobuz.nrPersoaneImbarcate << "; "
			<< "Producator: " << (autobuz.producator ? autobuz.producator : "N/A");

		return out;
	}

	//metoda pentru afisare locuri libere in autobuz
	int getNumarLocuriLibere() {
		return (this->capacitate - this->nrPersoaneImbarcate);
	}

	//supraincarcare operator de cast la int
	operator int() {
		return nrPersoaneImbarcate;
	}

	//supraincarcare operator >
	bool operator>(Autobuz& other) {
		return this->capacitate > other.capacitate;
	}

	//functie de afisare
	void afisareAutobuz() {
		cout << "Id: " << this->idAutobuz << endl;
		cout << "Capacitate: " << this->capacitate << endl;
		cout << "Numar persoane imbarcate: " << this->nrPersoaneImbarcate << endl;
		if (this->producator != nullptr) {
			cout << "Producator: " << this->producator << endl<<endl;
		}
		else cout << "Nu are producator" << endl<<endl;
	}
};

int Autobuz::nrAutobuze = 0;

int main() {
	//testare constructor fara parametrii
	Autobuz autobuz0;
	cout << "Test constructor fara parametrii: " << endl;
	autobuz0.afisareAutobuz();

	//testare constructor cu parametrii
	Autobuz autobuz1(20, 21, "Volswagen");
	cout << "Test constructor cu parametrii: " << endl;
	autobuz1.afisareAutobuz();

	//testare constructor copiere
	Autobuz autobuzCopie = autobuz1;
	cout << "Test constructor de copiere: " << endl;
	autobuzCopie.afisareAutobuz();

	//testare getteri si setteri pt nr pasageri (persoane imbarcate) si producator
	cout << "Test getteri si setter pentru numar persoane imbarcate si producator: " << endl;
	cout << "Producatorul initial pentru autobuzul 2 este: " << autobuz1.getProducator() << endl;
	autobuz1.setProducator("Toyota");
	cout << "Noul producator pentru autobuzul 2 este: " << autobuz1.getProducator() << endl;
	cout << "Numarul initial de persoane imbarcate in autobuzul 1 este: " << autobuz0.getNrPersoaneImbarcate() << endl;
	autobuz0.setNrPersoaneImbarcate(1);
	cout << "Noul numar de persoane imbarcate in autobuzul 1 este: " << autobuz0.getNrPersoaneImbarcate() << endl<<endl;

	//testare supraincarcare operator de atribuire
	cout << "Testare supraincarcare operator=: " << endl;
	Autobuz autobuz2(40, 30, "Mercedes");
	Autobuz autobuz3(36, 20, "Volvo");
	cout << "Autobuz 2:" << endl;
	autobuz2.afisareAutobuz();
	cout << endl;
	cout << "Autobuz 3 (initial):" << endl;
	autobuz3.afisareAutobuz();
	cout << endl;

	//atribuire
	autobuz3 = autobuz2;
	cout << "Autobuz 3 (dupa atribuirea atributelor autobuzului 2):" << endl;
	autobuz3.afisareAutobuz();
	cout << endl;

	//test autoatribuire
	autobuz2 = autobuz2;
	cout << "Dupa autoatribuire:" << endl;
	autobuz2.afisareAutobuz();

	//testare supraincarcare operator <<
	cout << "Test supraincarcare operator<<: " << endl;
	cout << "Autobuz initial: " << autobuz0 << endl;
	cout << "Autobuz 1: " << autobuz1 << endl;
	cout << "Autobuz 2: " << autobuz2 << endl;
	cout << "Autobuz 3: " << autobuz3 << endl<<endl;

	//testare metoda de returnare locuri libere
	cout << "Test metoda de returnare locuri libere: " << endl;
	cout << "Numar locuri libere in autobuz 2: " << autobuz2.getNumarLocuriLibere() << endl<<endl;

	//testare supraincarcare operator de cast la int
	cout << "Test supraincarcare operator de cast la int: " << endl;
	int persoaneImbarcate = autobuz3;
	cout << "Numarul de persoane imbarcate in autobuzul 3 este: " << persoaneImbarcate << endl<<endl;

	//testare supraincarcare operator >
	cout << "Test supraincarcare operator>: " << endl;
	(autobuz2 > autobuz3) ? (cout << "Autobuzul 2 are o capacitate mai mare decat autobuzul 3.") : (cout << "Autobuzul 2 are o capacitate mai mica sau egala cu cea a autobuzului 3");

}