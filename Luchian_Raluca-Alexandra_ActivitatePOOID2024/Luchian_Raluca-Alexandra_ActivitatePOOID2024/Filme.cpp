#include <iostream>
using namespace std;

class Filme {
private:
	const int id;
	static int nrFilme;
	string titlu;
	string regizor;
	int anulLansarii;
	float rating;
	char* descriere;
	int durata;
public:
	Filme() :id(++nrFilme) {
		this->titlu = "N/A";
		this->regizor = "N/A";
		this->anulLansarii = 0;
		this->rating = 0;
		this->descriere = NULL;
		this->durata = 0;
	}

	Filme(string titlu, string regizor, int anulLansarii, float rating, const char* descriere, int durata) :id(++nrFilme) {
		this->titlu = titlu;
		this->regizor = regizor;
		this->anulLansarii = anulLansarii;
		if (rating > 0 && rating < 10) {
			this->rating = rating;
		}
		else {
			cout << "Rating invalid, se va considera valoare nula";
			this->rating = 0;
		}
		this->descriere = new char[strlen(descriere) + 1];
		strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
		this->durata = durata;
	}

	Filme(const Filme& f):id(++nrFilme) {
		this->titlu = f.titlu;
		this->regizor = f.regizor;
		this->anulLansarii = f.anulLansarii;
		this->rating = f.rating;
		this->descriere = new char[strlen(f.descriere) + 1];
		strcpy_s(this->descriere, strlen(f.descriere) + 1, f.descriere);
		this->durata = f.durata;
	}

	~Filme() {
		if (this->descriere != NULL) {
			delete[] descriere;
		}
	}

	const char* getDescriere() {
		if (this->descriere != NULL) {
			return this->descriere;
		}
		else return "Descriere: N/A";
	}

	float getRating() {
		return this->rating;
	}

	int getDurata() {
		return this->durata;
	}

	void setRegizor(string regizor) {
		this->regizor = regizor;
	}

	void setTitlu(string titlu) {
		this->titlu = titlu;
	}

	void setDescriere(const char* nouaDescriere) {
		if (this->descriere != NULL) {
			delete[] this->descriere;
		}
		this->descriere = new char[strlen(nouaDescriere) + 1];
		strcpy_s(this->descriere, strlen(nouaDescriere) + 1, nouaDescriere);
	}

	friend ostream& operator<<(ostream& out, Filme& film) {
		out << "Id: " << film.id << ";"
			<< "Titlu: " << film.titlu << ";"
			<< "Regizor: " << film.regizor << ";"
			<< "Anul lansarii: " << film.anulLansarii << ";"
			<< "Rating: " << film.getRating() << ";"
			<< "Descriere: " << film.getDescriere() << ";"
			<< "Durata: " << film.getDurata() << ";";
		return out;
	}

	void afisare() {
		cout << "Id: " << this->id << ";" << endl;
		cout << "Titlu: " << this->titlu;
		cout << "Regizor: " << this->regizor;
		cout << "Anul lansarii: " << this->anulLansarii;
		cout << "Rating: " << this->rating;
		if (this->descriere != NULL) {
			cout << "Descriere: " << this->descriere;
		}
		else cout << "Descriere: N/A";
		cout << "Durata: " << this->durata << endl;
	}
};

int Filme::nrFilme = 0;

int main() {
	Filme film;
	Filme f1("Shining", "Stanely Kubrick", 1980, 8.4 , "A family heads to an isolated hotel for the winter, where a sinister presence influences the father into violence", 146);

	/*film.afisare();
	f1.afisare();*/

	cout << film;
	cout << f1;

	return 0;
}