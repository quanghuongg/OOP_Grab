#pragma once
#include"Xe.h"
//Lớp xe ô tô kế thừa từ lớp xe
class XeOto :public CXe
{
public:
	int SoCho;
public:
	XeOto();
	virtual void Input(istream &is);
	virtual void Output(ostream &);
	~XeOto();
};

