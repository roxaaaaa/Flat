#include "Flat.h"


Flat::Flat()
{
	s = 1.0;
	amount = 1;
	price = 0;
	name= " ";
}Flat::Flat(const Flat& t)
{
	s = t.s;
	amount = t.amount;
	price = t.price;
	name = t.name;
}


Flat::Flat(float s, int amount, int price, string name)
	: s(s), amount(amount), price(price), name(name){}

void Flat::print() const
{
	cout << " --------- Flat --------" << endl;
	cout << "Name: " << name << endl;
	cout << "Amount of rooms: " << amount << endl;
	cout << "Area " << s << endl;
	cout << "Price: " << price << endl;
	cout << "----------" << endl;
}

double Flat::price_per_m() const
{
	return price/s;
}

void Flat::add_price(int n)
{
	price += n;
}

void Flat::compare_s(Flat& c)
{
	if (s > c.s) cout << name << " is bigger than" << c.name << endl;
	else if (c.s > s) cout << c.name << " is bigger than" << name << endl;
	else if (c.s == s) cout << c.name << " and " << name << " are the same " << endl;
}

void Flat::create()
{
	cout << " ---------Creating Flat --------" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Amount of rooms: ";
	cin >> amount;
	cout << "Area ";
	cin >> s;
	cout << "Price: ";
	cin >> price;
	cout << "----------" << endl;
}

string Flat::get_name() const
{
	return name;
}

int Flat::get_room() const
{
	return amount;
}

int Flat::get_price() const
{
	return price;
}

float Flat::get_s() const
{
	return s;
}

bool operator>(Flat& c, Flat& t)
{
	return c.s > t.s;
}

istream& operator>>(istream& is, Flat& t) {
	is >> t.amount >> t.s >> t.price >> t.name;
	
	return is;
}

istream& operator>>(istream& is, Duplex& t) {
	is >> t.amount >> t.s >> t.price  >> t.name >> t.amount2 >> t.s2 >>  t.discount;
	return is;
}
Duplex::Duplex() : Flat()
{
	s2 = 1.0;
	amount2 = 0;
	discount = 0;
}

Duplex::Duplex(const Duplex& d) : Flat(d)
{
	s2 = d.s2;
	amount2 = d.amount2;
	discount = d.discount;
}

Duplex::Duplex(float s, int amount, int price, string name, float s2, int amount2, int discount):
	Flat(s, amount, price, name), s2(s2), amount2(amount2), discount(discount) {}

void Duplex::print() const
{
	cout << " --------- Duplex Flat --------" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Amount of rooms: " << this->amount << endl;
	cout << "Area " << this->s << endl;
	cout << "Amount of rooms on the 2nd floor:" << amount2 << endl;
	cout << "Area 2nd floor" << s2 << endl;
	cout << "Price: " << this->price<< endl;
	cout << "Discount: " << discount << endl;
	cout << "----------" << endl;
}

double Duplex::price_per_m() const
{
	double pr = ((this->price / ((this)->s + s2))* (100 - discount))/100;
	return pr;
}
void Duplex::change_discount(int n)
{
	discount = n;
}

void Duplex::create()
{
	cout << " ---------Creating Duplex Flat --------" << endl;
	cout << "Name: ";
	cin >> this->name;
	cout << "Amount of rooms: ";
	cin >> this->amount;
	cout << "Area ";
	cin >> this->s;
	cout << "Amount of rooms2: ";
	cin >> amount2;
	cout << "Area2 ";
	cin >> s2;
	cout << "Price: ";
	cin >> this->price;
	cout << "Discount; ";
	cin >> discount;
	cout << "----------" << endl;
}

int Duplex::get_room() const
{
	return (amount2+this->amount);
}

int Duplex::get_price() const
{
	float dis = (100 - discount) / 100;
	return this->price * dis;
}

float Duplex::get_s() const
{
	return this->s+s2;
}
