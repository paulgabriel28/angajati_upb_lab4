
#include <iostream>
#include <cstring>
#include "angajat.h"

using namespace std;

Angajat::Angajat():nume(NULL), salariu(0) {
    strcpy(CNP, "0000000000000");
    nr_obiecte++;
}

Angajat::Angajat(const char *new_nume, const char new_CNP[], int new_salariu):salariu(new_salariu) {
    if(nume != NULL) {
        delete [] nume;
        nume = NULL;
    }

    nume = new char[strlen(new_nume) + 1];

    strcpy(nume, new_nume);

    strcpy(CNP, new_CNP);

    nr_obiecte++;
}

Angajat::Angajat(const Angajat &a) {
    // cout<<"\nconst de copiere\n";
    
    Angajat::copie(a);

    // if(nume != NULL) {
    //     delete [] nume;
    //     nume = NULL;
    // }

    // nume = new char[strlen(a.nume) + 1];

    // strcpy(nume, a.nume);

    // strcpy(CNP, a.CNP);

    // salariu = a.salariu;

    nr_obiecte++;
}

Angajat::~Angajat() {
    if(nume != NULL) {
        delete [] nume;
    }
    strcpy(CNP, "0000000000000");
    salariu = 0;

    nr_obiecte--;
}


void Angajat::afisare() const{
    if(nume != NULL) {
        cout<<"Nume: "<<nume<<endl;
    }
    else
        cout<<"Nume: --"<<endl;

    cout<<"CNP: "<<CNP<<endl;
    
    cout<<"Salariu: "<<salariu<<endl;
}


void Angajat::copie(const Angajat &a) {
    if(nume != NULL) {
        delete [] nume;
        nume = NULL;
    }

    nume = new char[strlen(a.nume) + 1];

    strcpy(nume, a.nume);

    strcpy(CNP, a.CNP);

    salariu = a.salariu;
}

int Angajat::getSalariu() const {
    return salariu;
}

int Angajat::getType() const {
    if(CNP[0] == '1' || CNP[0] == '5')
        return 0;
    else if(CNP[0] == '2' || CNP[0] == '6')
        return 1;

    return 2;
}

char* Angajat::getNume() const {
    return nume;
}


// Lab 3:
Angajat& Angajat::operator=(const Angajat &a) {
    if(this != &a) {
        copie(a);
    }

    return *this;
}

bool operator==(const Angajat &a, const Angajat &b) {
    return ((strcmp(a.nume, b.nume) == 0) && (strcmp(a.CNP, b.CNP) == 0) && a.salariu == b.salariu) ? 1 : 0;
}

bool operator!=(const Angajat &a, const Angajat &b) {
    return !(a==b);
}

void sortare(Angajat *vec, const int dim) {
    for(int i = 0; i < dim-1; i++) {
        for(int j = i+1; j < dim; j++) {
            if(strcmp(vec[i].nume, vec[j].nume) > 0) {
                Angajat temp;
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}


// Lab 4:
ostream& operator<<(ostream &dev, const Angajat &a) {
    dev << "Nume: " << a.nume << endl;
    dev << "CNP: " << a.CNP << endl;
    dev << "Salariu: " << a.salariu << endl;
    dev << " --\n";
}

istream& operator>>(istream &dev, Angajat &a) {
    char temp[100];
    cout << "Nume: ";
    dev >> temp;
    a.nume = new char[strlen(temp) + 1];
    strcpy(a.nume, temp);

    cout<<"CNP: ";
    dev >> a.CNP;

    cout<<"Salariu: ";
    dev >> a.salariu;
}

int Angajat::getNrObiecte() {
    return nr_obiecte;
}

bool operator<(const Angajat &a1, const Angajat &a2) {
    return (a1.salariu < a2.salariu)? 1 : 0;
}

bool operator<=(const Angajat &a1, const Angajat &a2) {
    return (a1.salariu <= a2.salariu)? 1 : 0;
}

bool operator>(const Angajat &a1, const Angajat &a2) {
    return !(a1 < a2);
}

bool operator>=(const Angajat &a1, const Angajat &a2) {
    return !(a1 <= a2);
}

void sortare_vector_operator(Angajat *&vec, const int &dim) {
    for(int i = 0; i < dim-1; i++) {
        for(int j = i+1; j < dim; j++) {
            if(vec[i] > vec[j]) {
                Angajat temp;
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}