#pragma once
#include"ToaDoGPS.h"
class KhachHang
{
public:
	ToaDoGPS DiemKhoiHanh;
	ToaDoGPS DiemKetThuc;
	int LoaiXeGoi;
	int socho;
	int khoiluong;
public:
	KhachHang();
	void GoiXe();
	~KhachHang();
};

