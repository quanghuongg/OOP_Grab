#pragma once
#include<string>
#include"ToaDoGPS.h"

enum TrangThai
{
	DangRanh,
	DangBanKhach

};

class CXe
{
protected:
	string BienSo;
	string HoTenTaiXe;
	string NhanHieuXe;

public:
	CXe();
	int LoaiXe;
	ToaDoGPS ToaDoXe;
	TrangThai p = TrangThai::DangRanh;
	virtual void Input(istream &is);
	virtual void Output(ostream &);
	~CXe();
};

