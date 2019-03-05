#include"ToaDoGPS.h"
#include"Xe.h"
#include"CongTy.h"
#include<iostream>
#include"ThongTinDatXe.h"
#include<time.h>
#include "conio.h"
using namespace std;
int main()
{
	srand(time(NULL));
	cout << "\n\n\t\t\t------------UNG DUNG GOI XE ------------\n" << endl;
	//Nhập danh sách xe của công ty
	CongTy ct;
	cin >> ct;
	ChuyenDiThanhCong cd;
	//Phát sinh vị trí ngẩu nhiên của các xe trong danh sách
	for (int i = 0; i < ct.SoLuong; i++)
	{
		ct.DanhSachXe[i]->ToaDoXe.PhatSinh();
	}
	////Xuất danh sách xe của công ty
	cout << ct;
	//Khách hàng gọi xe
	int key = 1;
	do
	{
		//Sau 5 lượt gọi xe, chương trình tự động cập nhật lại tọa độ GPS của các xe khi
		//hoàn thành chuyến đi của mình(tọa độ GPS mới chính là tọa độ điểm đến củ chuyến đi).
		if (cd.XeGoiThanhCong.size() == 5)
		{
			//Cho tất cả các xe về lại trạng thái rảnh khách
			for (int i = 0; i < ct.SoLuong; i++)
			{
				ct.DanhSachXe[i]->p = DangRanh;
			}
			//Cập nhật lại trị trí 
			for (int i = 0; i < 5; i++)
			{
				//Gán cho vị trí xe gọi thành công bằng vị trí điểm đến thành công
				ct.DanhSachXe[cd.XeGoiThanhCong[i]]->ToaDoXe = cd.ToaDoDiemDenThanhCong[i];
			}
			// Xóa đi các vị trí đã lưu
			cd.XeGoiThanhCong.clear();
			cd.ToaDoDiemDenThanhCong.clear();
		}
		KhachHang kh;
		kh.GoiXe();
		TimXeThoaMan(ct, kh, cd);
		cout << "\n\tBAN CO MUON TIEP TUC GOI XE HAY KHONG? \n\tNhap 1 de tiep tuc!\n\tNhap 0 de thoat! " << endl;
		//cin >> key;
		key = _getch();
	} while (key == '1');

	return 0;
}