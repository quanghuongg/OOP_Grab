#include"KhachHang.h"
#include"CongTy.h"
#include"ToaDoGPS.h"
#include"ChuyenDiThanhCong.h"

double TinhTienCuocXeMay(ToaDoGPS x1, ToaDoGPS x2)
{

	//Tính quảng đường chạy
	double KhoangCach = TinhKhoangCach(x1, x2);
	//Tính tiền
	if (KhoangCach < 2) return 10000;
	else
		return 10000 + (KhoangCach - 2) * 3500;

}
//Hàm lấy giá trị MAX trong hai giá trị
//Dùng để tính tiền cước của xe ô tô
double Max(double a, double b)
{
	if (a > b) return a;
	return b;
}


double TinhTienCuocXeOto(ToaDoGPS x1, ToaDoGPS x2, int SoCho)
{
	//Ngẩu nhiên vận tốc của xe trong khoảng 30-50 Km/h
	int VanTocXe = 30 + rand() % 21;
	//Tính quảng đường chạy
	double KhoangCach = TinhKhoangCach(x1, x2);
	//Tính thời gian chạy
	double time = (KhoangCach / VanTocXe) * 60;
	//Tính tiền theo số chỗ của ô tô
	if (SoCho <= 4) return(Max(20000, (9000 * KhoangCach + 300 * time)));
	if (SoCho > 4 && SoCho <= 7) return(Max(24000, (11000 * KhoangCach + 300 * time)));
	if (SoCho > 7 && SoCho <= 16) return(Max(30000, (15000 * KhoangCach + 400 * time)));
	else return 0;
}

double TinhTienCuocXeTai(ToaDoGPS x1, ToaDoGPS x2, int khoiluongdat)
{
	//Ngẩu nhiên vận tốc của xe trong khoảng 30-50 Km/h
	int VanTocXe = 30 + rand() % 21;
	// quảng đường chạy
	double KhoangCach = TinhKhoangCach(x1, x2);
	//Tính thời gian chạy
	double time = (KhoangCach / VanTocXe) * 60;
	//Tính tiền cho từng loại trọng tải 
	if (khoiluongdat < 750)
	{
		if (KhoangCach < 10) return 300;
		else if (KhoangCach>10 && KhoangCach <= 44)
			return 300 + (KhoangCach - 10) * 14;
		else return 300 + 34 * 14 + (KhoangCach - 44) * 13;
	}
	if (khoiluongdat >= 750 && khoiluongdat < 1500)
	{
		if (KhoangCach < 10) return 400;
		else if (KhoangCach>10 && KhoangCach <= 44)
			return 400 + (KhoangCach - 10) * 00;
		else return 400 + 34 * 15 + (KhoangCach - 44) * 14;
	}
	if (khoiluongdat >= 1500 && khoiluongdat < 1900)
	{
		if (KhoangCach < 10) return 500;
		else if (KhoangCach>10 && KhoangCach <= 44)
			return 500 + (KhoangCach - 10) * 20;
		else return 500 + 34 * 20 + (KhoangCach - 44) * 17;
	}
	else return 0;
}
//Tìm xe đang rảnh gần khách hàng nhất
//Thông báo thông tin đặt chỗ
void TimXeThoaMan(CongTy& t, KhachHang kh, ChuyenDiThanhCong &cd)
{


	//Khởi tạo các giá trị khởi đầu để tìm xe gần nhất
	int vitri = -1;
	double min = -1;
	int pos = -1;
	if (kh.LoaiXeGoi == 1)//Nếu là xe máy
	{

		//Tìm vị trí xe máy rảnh đầu tiên trong danh sách xe để làm chuẩn
		for (int i = 0; i < t.SoLuong; i++)
		{
			if (t.DanhSachXe[i]->LoaiXe == 1 && t.DanhSachXe[i]->p == DangRanh)
			{
				vitri = i;
				min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
				break;
			}
		}

		//Không có xe nào rảnh
		if (vitri == -1)
		{
			cout << "\n\tTHONG BAO DEN KHACH HANG" << endl;
			cout << "\n\tHien tai khong co xe nao dang ranh! \n\tRat xin loi quy khach! \n\tXin quy khach vui long dat xe sau mot thoi gian khac!\n " << endl;
		}
		//Duyệt để tìm vị trí xe máy rảnh gần nhất
		else
		{
			for (int i = vitri; i < t.SoLuong; i++)
			{
				if (t.DanhSachXe[i]->LoaiXe == 1 && t.DanhSachXe[i]->p == DangRanh)
				{
					if (min <= TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh))
					{
						min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
						pos = i;
					}
				}
			}

			//Xe này đã được đặt thành công nên không còn rảnh nửa gán cho nó bận khách
			t.DanhSachXe[pos]->p = DangBanKhach;
			//Push vị trí xe đặt thành công vào mảng gọi xe thành công
			cd.XeGoiThanhCong.push_back(pos);
			//Push tọa độ điểm đến thành công vào mảng tọa độ điểm đến thành công
			cd.ToaDoDiemDenThanhCong.push_back(kh.DiemKetThuc);

			//Thông báo đến khách hàng thông tin đặt xe
			cout << "\n\tTHONG BAO DEN KHACH HANG\n" << endl;
			cout << "\tXe da duoc dat thanh cong!" << endl;
			cout << "\tThong tin xe\t " << endl;
			t.DanhSachXe[pos]->Output(cout);
			int VanTocXe = 30 + rand() % 21;
			double time = (min / VanTocXe) * 60;
			cout << "\tCon " << time << " phut nua la xe se den diem don quy khach!" << endl;
			cout << "\tVan toc di chuyen: " << VanTocXe << "km/h" << endl;
			double tiencuoc = TinhTienCuocXeMay(kh.DiemKhoiHanh, kh.DiemKetThuc);
			cout << "\tTien cuoc quy khach phai tra la: " << tiencuoc << " dong!" << endl;
			cout << "\tCam on quy khac da su dung dich vu!\n" << endl;

		}
	}
	else if (kh.LoaiXeGoi == 2)//Nếu là xe ô tô
	{

		//Tìm vị trí xe ô tô rảnh đầu tiên và có số chỗ thỏa mãn số chỗ khách yêu cầu trong danh sách xe để làm chuẩn
		for (int i = 0; i < t.SoLuong; i++)
		{
			if (t.DanhSachXe[i]->LoaiXe == 2 && t.DanhSachXe[i]->p == DangRanh)
			{
				//Covert xe thành xe ô tô
				//Chỉ làm được khi biết chắc chắn xe này là ô tô
				XeOto *a = reinterpret_cast<XeOto*>(t.DanhSachXe[i]);
				if (a->SoCho == kh.socho)
				{
					vitri = i;
					min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
					break;
				}
			}
		}

		//Không có xe nào rảnh
		if (vitri == -1)
		{
			cout << "\n\tTHONG BAO DEN KHACH HANG" << endl;
			cout << "\n\tHien tai khong co xe nao dang ranh! \n\tRat xin loi quy khach! \n\tXin quy khach vui long dat xe sau mot thoi gian khac\n " << endl;
		}
		//Duyệt để tìm vị trí xe rảnh gần nhất
		else
		{
			for (int i = vitri; i < t.SoLuong; i++)
			{
				if (t.DanhSachXe[i]->LoaiXe == 2 && t.DanhSachXe[i]->p == DangRanh)
				{
					XeOto *a = reinterpret_cast<XeOto*>(t.DanhSachXe[i]);
					if (a->SoCho == kh.socho)
					{
						vitri = i;
						min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
					}
					if (min <= TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh))
					{
						min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
						pos = i;
					}
				}
			}

			//Xe ô tô này đã được đặt thành công nên không còn rảnh nửa gán cho nó bận khách
			t.DanhSachXe[pos]->p = DangBanKhach;
			//Push vị trí xe đặt thành công vào mảng
			cd.XeGoiThanhCong.push_back(pos);
			//Push tọa độ điểm đến thành công vào mảng tọa độ
			cd.ToaDoDiemDenThanhCong.push_back(kh.DiemKetThuc);

			//Thông báo đến khách hàng
			cout << "\n\tTHONG BAO DEN KHACH HANG\n" << endl;
			cout << "\tXe da duoc dat thanh cong!" << endl;
			cout << "\tThong tin xe\t " << endl;
			t.DanhSachXe[pos]->Output(cout);
			int VanTocXe = 30 + rand() % 21;
			double time = (min / VanTocXe) * 60;
			cout << "\tCon " << time << " phut nua la xe se den diem don quy khach!" << endl;
			cout << "\tVan toc di chuyen: " << VanTocXe << "km/h" << endl;
			double tiencuoc = TinhTienCuocXeOto(kh.DiemKhoiHanh, kh.DiemKetThuc, kh.socho);
			cout << "\tTien cuoc quy khach phai tra la: " << tiencuoc << " dong!" << endl;
			cout << "\tCam on quy khac da su dung dich vu!\n" << endl;

		}
	}
	else//Nếu khách hàng yêu cầu xe tải
	{
		//Tìm xe tải đầu tiên để làm chuẩn
		for (int i = 0; i < t.SoLuong; i++)
		{
			if (t.DanhSachXe[i]->LoaiXe == 3 && t.DanhSachXe[i]->p == DangRanh)
			{
				//Covert xe thành xe tải
				//Chỉ làm được khi biết chắc chắn xe này là tải
				XeTai *a = reinterpret_cast<XeTai*>(t.DanhSachXe[i]);
				//Kiểm tra trọng tải xe có phù hợp với khối lượng khách hàng cần đặt hay không
				//Ưu tiên trọng tải >= khối lượng hàng && trọng trải <=1,5*khối lượng hàng

				if (kh.khoiluong <= 750 && a->TaiTrong == 750)
				{
					
					vitri = i;
					min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
					break;
					
				}
				else if (kh.khoiluong > 750 && kh.khoiluong <= 1500 && a->TaiTrong == 1500)
				{

					vitri = i;
					min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
					break;
				}
				else if (kh.khoiluong > 1500 && kh.khoiluong <= 1900 && a->TaiTrong == 1900)
				{
					vitri = i;
					min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
					break;
				}
			}
		}

		//Không có xe nào rảnh
		if (vitri == -1)
		{
			cout << "\n\tTHONG BAO DEN KHACH HANG" << endl;
			cout << "\n\tHien tai khong co xe nao phu hop voi yeu cau cua quy khach!\n\tRat xin loi quy khach! \n\tXin quy khach vui long dat xe sau mot thoi gian khac!\n " << endl;
		}
		//Duyệt để tìm vị trí xe rảnh gần nhất 
		else
		{
			for (int i = vitri; i < t.SoLuong; i++)
			{
				//Covert xe thành xe tải
				//Chỉ làm được khi biết chắc chắn xe này là tải
				if (t.DanhSachXe[i]->LoaiXe == 3 && t.DanhSachXe[i]->p == DangRanh)
				{

					XeTai *a = reinterpret_cast<XeTai*>(t.DanhSachXe[i]);
					if (kh.khoiluong <= 750 && a->TaiTrong == 750)
					{

						vitri = i;
						min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);

						if (min <= TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh))
						{
							min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
							pos = i;
						}
					}
					else if (kh.khoiluong > 750 && kh.khoiluong <= 1500 && a->TaiTrong == 1500)
					{


						vitri = i;
						min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);

						if (min <= TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh))
						{
							min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
							pos = i;
						}
					}
					else if (kh.khoiluong > 1500 && kh.khoiluong <= 1900 && a->TaiTrong == 1900)
					{

						vitri = i;
						min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);

						if (min <= TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh))
						{
							min = TinhKhoangCach(t.DanhSachXe[i]->ToaDoXe, kh.DiemKhoiHanh);
							pos = i;
						}
					}
				}

			}
			//Xe này đã được đặt thành công nên không còn rảnh nửa gán cho nó bận khách
			t.DanhSachXe[pos]->p = DangBanKhach;
			//Push vị trí xe đặt thành công vào mảng gọi xe thành công
			cd.XeGoiThanhCong.push_back(pos);
			//Push tọa độ điểm đến thành công vào mảng tọa độ điểm đến thành công
			cd.ToaDoDiemDenThanhCong.push_back(kh.DiemKetThuc);

			//Thông báo đến khách hàng
			cout << "\n\tTHONG BAO DEN KHACH HANG\n" << endl;
			cout << "\tXe da duoc dat thanh cong!" << endl;
			cout << "\tThong tin xe\t " << endl;
			t.DanhSachXe[pos]->Output(cout);
			int VanTocXe = 30 + rand() % 21;
			double time = (min / VanTocXe) * 60;
			cout << "\tCon " << time << " phut nua la xe se den diem don quy khach!" << endl;
			cout << "\tVan toc di chuyen: " << VanTocXe << "km/h" << endl;

			double tiencuoc = TinhTienCuocXeTai(kh.DiemKhoiHanh, kh.DiemKetThuc, kh.khoiluong);
			cout << "\tTien cuoc quy khach phai tra la: " << tiencuoc << " ngan dong!" << endl;
			cout << "\tCam on quy khac da su dung dich vu!\n" << endl;
		}
	}



}
