#pragma once
#include"Xe.h"
//Lớp xe máy kế thừa từ lớp xe	
class XeMay : public CXe
{
public:
	XeMay();
	virtual void Input(istream &);
	virtual void Output(ostream &);
	~XeMay();
};

