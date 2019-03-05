#include "ToaDoGPS.h"
#include<time.h>

ToaDoGPS::ToaDoGPS()
{

}

//Khởi tạo sao chép
ToaDoGPS::ToaDoGPS(const ToaDoGPS&x)
{
	tungDo = x.tungDo;
	hoanhDo = x.hoanhDo;
}
//Toán tử nhập tọa độ
ostream& operator <<(ostream &os, ToaDoGPS x)
{

	os << "\tDang o toa do: (" << x.hoanhDo << "," << x.tungDo << ")" << endl;
	return os;
}
//Toán tử xuất tọa độ
istream& operator >>(istream &is, ToaDoGPS&x)
{
	cout << "\n\tNhap tung do: ";
	is >> x.tungDo;
	cout << "\tNhap hoanh do: ";
	is >> x.hoanhDo;
	return is;
}
//Tính khoảng cách của hai tọa độ
double TinhKhoangCach(ToaDoGPS x1, ToaDoGPS x2)
{
	return sqrt((x1.hoanhDo - x2.hoanhDo)*(x1.hoanhDo - x2.hoanhDo) + (x1.tungDo - x2.tungDo)*(x1.tungDo - x2.tungDo));
}

////Tạo ngẩu nhiên tọa đố điểm trong khoảng từ (-20,20)
void ToaDoGPS::PhatSinh()
{
	tungDo = -20 + rand() % 41;
	hoanhDo = -20 + rand() % 41;
}
//Toán tử gán
ToaDoGPS &ToaDoGPS::operator=(const ToaDoGPS&x)
{
	tungDo = x.tungDo;
	hoanhDo = x.hoanhDo;
	return *this;
}

ToaDoGPS::~ToaDoGPS()
{
}


