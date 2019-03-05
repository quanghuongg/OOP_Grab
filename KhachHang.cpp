#include "KhachHang.h"


KhachHang::KhachHang()
{
	socho = 0;
	khoiluong = 0;
}


void KhachHang::GoiXe()
{
	do{
		cout << "\n\tLOAI XE CO THE GOI" << endl;
		cout << "\n\t1 XE MAY \n\t2 XE OTO \n\t3 XE TAI " << endl;
		cout << "\n\tKHACH HANG " << endl;
		cout << "\n\tVui long chon phuong tien muon dat: ";
		cin >> LoaiXeGoi;
		if (LoaiXeGoi != 1 && LoaiXeGoi != 2 && LoaiXeGoi != 3)
		{
			cout << "\n\tTHONG BAO" << endl;
			cout << "\n\tLoai xe ban nhap khong hop le! Vui long nhap lai!" << endl;
		}
	} while (LoaiXeGoi != 1 && LoaiXeGoi != 2 && LoaiXeGoi != 3);
	
	if (LoaiXeGoi == 2)
	{
		cout << "\tNhap so cho cua o to can goi: ";
		cin >> socho;
		khoiluong = 0;
	}
	else if (LoaiXeGoi == 3)
	{
		cout << "\tNhap khoi luong hang can cho: ";
		cin >> khoiluong;
		socho = 0;

	}
	cout << "\tNhap toa do cua diem khoi hanh: ";
	cin >> DiemKhoiHanh;
	cout << "\tNhap toa do cua diem den: ";
	cin >> DiemKetThuc;
}

KhachHang::~KhachHang()
{
}
