#include "CongTy.h"
#include<fstream>
CongTy::CongTy()
{
}


CongTy::~CongTy()
{
}

//Hàm nhập danh xe của công ty
istream &operator>>(istream &is, CongTy &ct)
{
	ifstream fin;
	int LoaiXe[100];
	fin.open("input.txt");
	fin >> ct.SoLuong;
	string s;
	getline(fin, s);
	for (int i = 0; i < ct.SoLuong; i++)
	{
		fin >> LoaiXe[i];
		string s1;
		getline(fin, s1);
		if (LoaiXe[i] == 1)
		{
			CXe *a = new XeMay;
			a->Input(fin);
			a->LoaiXe = 1;
			int x;
			fin >> x;
			ct.DanhSachXe.push_back(a);
		}
		else if (LoaiXe[i] == 2)
		{
			CXe *b = new XeOto;
			b->Input(fin);
			b->LoaiXe = 2;
			ct.DanhSachXe.push_back(b);
		}
		else
		{
			CXe *c = new XeTai;
			c->Input(fin);
			c->LoaiXe = 3;
			ct.DanhSachXe.push_back(c);
		}
	}
	fin.close();
	return is;
}


//Hàm xuất danh sách xe của công ty
ostream &operator<<(ostream &os, CongTy ct)
{

	os << "\n\t\t_____THONG TIN DANH SACH XE CUA CONG TY_____" << endl;
	for (int i = 0; i < ct.SoLuong; i++)
	{
		os << endl;
		os << "\tXe thu " << i + 1 << ": " << endl;
		ct.DanhSachXe[i]->Output(os);

	}
	return os;
}


