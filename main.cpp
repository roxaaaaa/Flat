#include "Flat.h"
#include <list>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>

int total_amount = 0;
vector<string> names;
void print_v(vector<Flat*> a) {
    for (const auto& i : a) {
        i->print();
    }
}
template <typename T>
T find_biggest_in_list(list<T>& a) {
    auto biggest = a.begin();
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (biggest->get_s() < i->get_s())  biggest = i;
    }
    return *biggest;
}
void find_diggest(list<Flat>& f, list<Duplex>& d) {
    Flat t = find_biggest_in_list<Flat>(f);
    Duplex t1 = find_biggest_in_list<Duplex>(d);

    if (t.get_s() > t1.get_s()) cout << t.get_name() << " is the biggest" << endl;
    else if (t.get_s() < t1.get_s()) cout << t1.get_name() << " is the biggest" << endl;
}
template <typename T>
void add2list(list<T>& a) {
    T f;
    f.create();
    names.push_back(f.get_name());
    total_amount += f.get_room();
    a.push_back(f);
}
void create_list(list<Flat>& f, list<Duplex>& d) {
    cout << "enter the amount of flats u want to add:";
    int am;
    cin >> am;
    for (int i(0); i < am; i++) {
        cout << " enter 1-flat, 2-duplex";
        int l;
        cin >> l;
        switch (l) {
        case 1:
            add2list<Flat>(f);
            break;
        case 2:
            add2list<Duplex>(d);
            break;
    }
    }
}

bool byPrice(const Flat* f1, const Flat* f2) {
    return f1->get_price() < f2->get_room();
}
bool room3(Flat* x) {
    return (*x).get_room() == 3;
}
int main()
{
    /*create_list(f, d);
    cout << "names: ";
    for (const auto& i : names) {
        cout << i << " ";
    }
    cout << "Total rooms: " << total_amount << endl;
    find_diggest(f, d);
    */

    ifstream file("file.txt");
    char x;
    vector<Flat*> f;
    while (file >> x) {
        switch (x) {
        case '1': {
            Flat* f1 = new Flat();
            file >> *f1;
            f1->print();
            f.push_back(f1);
            break;

        }
        case '2': {
            Duplex* f1 = new Duplex();
            file >> *f1;
            f1->print();
            f.push_back(f1);
            break;

        }
            
        }
    }
    cout << endl << endl;

    sort(f.begin(), f.end(), byPrice);
    print_v(f);
    cout << count_if(f.begin(), f.end(), room3);
    return 0;
};
