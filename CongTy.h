#pragma once
#include"Xe.h"
#include<vector>
#include"XeMay.h"
#include"XeOto.h"
#include"XeTai.h"
class CongTy
{
public:
	int SoLuong;
	vector<CXe*> DanhSachXe;
public:
	friend istream &operator>>(istream &, CongTy &);
	friend ostream &operator<<(ostream &, CongTy);
	CongTy();
	~CongTy();
};

