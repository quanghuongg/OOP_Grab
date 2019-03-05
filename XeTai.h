#pragma once
#include"Xe.h"
//Lớp xe tải kế thừa từ lớp xe
class XeTai :public CXe
{
public:
	int TaiTrong;
public:
	XeTai();
	virtual void Input(istream &is);
	virtual void Output(ostream &);
	~XeTai();
};

