#include "XeMay.h"
XeMay::XeMay()
{
}

//float TinhTienCuocXeMay(ToaDoGPS x1, ToaDoGPS x2)
//{
//
//	//Tính quảng đường chạy
//	float KhoangCach = TinhKhoangCach(x1, x2);
//	//Tính tiền
//	if (KhoangCach < 2) return 10000;
//	else
//		return 10000 + (KhoangCach - 2) * 3500;
//
//}


void XeMay::Input(istream &is)
{
	fflush(stdin);
	//cout << "Nhap bien so xe: ";
	getline(is, BienSo);
	//cout << "Nhap ho ten cua lai xe: ";
	fflush(stdin);
	getline(is, HoTenTaiXe);
	//cout << "Nhap nhan hieu cua xe: ";
	fflush(stdin);
	getline(is, NhanHieuXe);
}

void XeMay::Output(ostream &os)
{
	//os << "Thong tin xe may: " << endl;
	os << "\tBien so xe la: " << BienSo << endl;
	os << "\tHo ten cua lai xe la: " << HoTenTaiXe << endl;
	os << "\tNhan hieu cua xe la: " << NhanHieuXe << endl;
	os << ToaDoXe;

}
XeMay::~XeMay()
{
}
