#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Produs {
    string nume;
    float pret;
    int cantitate;
};

vector<Produs> produse;

void adaugare_produs() {
    Produs produs_nou;
    cout << "Introduceti numele produsului: ";
    getline(cin >> ws, produs_nou.nume);
    cout << "Introduceti pretul produsului: ";
    cin >> produs_nou.pret;
    cout << "Introduceti cantitatea produsului: ";
    cin >> produs_nou.cantitate;
    produse.push_back(produs_nou);
}

void afisare_produse() {
    if (produse.size() == 0) {
        cout << "Nu exista produse in lista." << endl;
        return;
    }
    cout << "Produse disponibile:" << endl;
    for (int i = 0; i < produse.size(); i++) {
        cout << i + 1 << ". " << produse[i].nume << " - " << produse[i].pret << " RON, " << produse[i].cantitate << " buc." << endl;
    }
}
void modificare_pret() {
    int index;
    double pret_nou;
    cout << "Introdu numarul produsului pentru a modifica pretul: ";
    cin >> index;
    if (index < 1 || index > produse.size()) {
        cout << "Numarul produsului este invalid!" << endl;
        return;
    }
    cout << "Introdu noul pret pentru " << produse[index - 1].nume << ": ";
    cin >> pret_nou;
    produse[index - 1].pret = pret_nou;
    cout << "Pretul pentru " << produse[index - 1].nume << " a fost modificat cu succes!" << endl;
}
int main() {
    int optiune;
    while (true) {
        cout << "*********************" << endl;
        cout << "Alegeti o optiune:" << endl;
        cout << "1. Adaugare produs" << endl;
        cout << "2. Afisare produse" << endl;
        cout << "3. Modificare pret" << endl;
        cout << "0. Iesire" << endl;
        cout << "Introdu optiunea: ";
        cin >> optiune;
        cout << "*********************" << endl;
        switch (optiune) {
        case 0:
            cout << "La revedere!" << endl;
            return 0;
        case 1:
            adaugare_produs();
            break;
        case 2:
            afisare_produse();
            break;
        case 3:
            modificare_pret();
            break;
        default:
            cout << "Optiune invalida!" << endl;
            break;
        }
    }
    return 0;
}
