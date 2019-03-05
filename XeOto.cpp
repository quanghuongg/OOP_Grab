#include "XeOto.h"


XeOto::XeOto()
{
}


XeOto::~XeOto()
{
}

void XeOto::Input(istream &is)
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
	//cout << "Nhap so cho cua o to: ";
	is >> SoCho;
}
void XeOto::Output(ostream &os)
{
	//os << "Thong tin xe: " << endl;
	os << "\tBien so xe la: " << BienSo << endl;
	os << "\tHo ten cua lai xe la: " << HoTenTaiXe << endl;
	os << "\tNhan hieu cua xe la: " << NhanHieuXe << endl;
	os << ToaDoXe;
	os << "\tSo cho cua o to la: " << SoCho << endl;
}


