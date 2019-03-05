#pragma once
#include<iostream>
using namespace std;
class ToaDoGPS
{
private:
	int tungDo;
	int hoanhDo;
public:
	ToaDoGPS();
	ToaDoGPS(const ToaDoGPS&);
	ToaDoGPS &operator=(const ToaDoGPS&x);
	void PhatSinh();
	friend double TinhKhoangCach(ToaDoGPS x1, ToaDoGPS x2);
	friend istream& operator >>(istream &, ToaDoGPS&);
	friend ostream& operator <<(ostream &, ToaDoGPS);
	~ToaDoGPS();
};

