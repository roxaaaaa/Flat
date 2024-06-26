#pragma once

#include <iostream>
#include <string>
#include <istream>
using namespace std;
class Flat {
protected:
	float s;
	int amount;
	int price;
	string name;
public:
	Flat();
	Flat(const Flat& t);
	Flat(float s,
		int amount,
		int price,
		string name);
	virtual void print() const;
	virtual double price_per_m() const;
	void add_price(int n);
	void compare_s(Flat& c);
	friend bool operator>(Flat& c, Flat& t);
	virtual void create();
	string get_name() const;
	virtual int get_room() const;
	virtual int get_price() const;
	virtual float get_s() const;
	friend istream& operator>>(istream& is, Flat& t);
};/*
 додатково памТ€таЇ к≥льк≥сть к≥мнат другого поверху та в≥дсоток знижки, зм≥нюЇ спос≥б виведенн€ 
в "ƒвоповерхова квартира" Ц пот≥к та обчисленн€ ц≥ни квадратного метра
(потр≥бно врахувати додатков≥ к≥мнати та знижку), 
даЇ змогу зм≥нювати в≥дсоток.*/
class Duplex: public Flat {
private:
	float s2;
	int amount2;
	int discount;
public:
	Duplex();
	Duplex(const Duplex& d);
	Duplex(float s,
		int amount,
		int price,
		string name, float s2,
		int amount2,
		int discount);
	void print() const override;
	double price_per_m() const override;
	void change_discount(int n);
	void create() override;
	int get_room() const override;
	int get_price() const override;
	float get_s() const override;
	friend istream& operator>>(istream& is, Duplex& t);

};