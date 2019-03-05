#pragma once
#include<vector>
#include"ToaDoGPS.h"
//Class này nhằm mục đich là lưu lại cái chuyến gọi xe thành công
//Đê sau 5 lượt gọi xe thành công chúng ta sẽ cập nhật lại vị trí đặt xe cho cái xe
class ChuyenDiThanhCong
{
public:
	//Khởi tạo mảng để lưu vị trí của xe đã được gọi thành công
	vector<int> XeGoiThanhCong;
	//Khởi tạo mảng để lưu vị trí điểm đến của khách đã đặt xe thành công
	vector <ToaDoGPS> ToaDoDiemDenThanhCong;
	ChuyenDiThanhCong();
	~ChuyenDiThanhCong();
};

