#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

/*===================================================SHAPE===================================================*/

//class Shape
class Shape {
private:
	double X, Y; //Tọa độ tâm hình vẽ
	string color; //Màu sắc hình vẽ
	double thickness; //Độ rộng nét vẽ

public:
	virtual void Nhap(); //Hàm nhập (virtual tượng trưng cho tính đa hình)

	virtual void In(); //Hàm vẽ (virtual tượng trưng cho tính đa hình)

	virtual double Dien_tich() {
		double S = 0;
		return S;
	};

	double getX(); //Hàm lấy tọa độ X của tâm hình vẽ

	double getY(); //Hàm lấy tọa độ Y của tâm hình vẽ
};

//Hàm nhập-class Shape
void Shape::Nhap() {
	cout << "\nNhap toa do tam cua hinh: " << endl; //Tọa độ tâm hình vẽ
	cout << "\n\tx = ";
	cin >> X;
	cout << "\n\ty = ";
	cin >> Y;
	cout << "\nNhap mau sac: "; //Màu sắc hình vẽ
	cin.ignore(1);
	getline(cin, color);
	cout << "\nNhap do rong net ve: "; //Độ rộng nét vẽ
	cin >> thickness;
}

//Hàm in dữ liệu-class Shape
void Shape::In() {
	cout << "\n+) Toa do tam cua hinh: "; //Tọa độ tâm hình vẽ
	cout << "\n\tx = " << X;
	cout << "\n\ty = " << Y;
	cout << "\n+) Mau sac cua hinh: " << color; //Màu sắc hình vẽ
	cout << "\n+) Do rong net ve: " << thickness; //Độ rộng nét vẽ
}

//Hàm lấy giá trị tọa độ X-class Shape
double Shape::getX() {
	return X;
}

//Hàm lấy giá trị tọa độ Y-class Shape
double Shape::getY() {
	return Y;
}

/*===================================================CIRCLE===================================================*/

//class Circle
class Circle : public Shape {
private:
	double R; //Bán kính

public:
	void Nhap(); //Hàm nhập

	void In(); //Hàm in

	double Dien_tich(); //Hàm tính diện tích
};

//Hàm nhập-class Circle
void Circle::Nhap() {
	cout << "HINH TRON: ";
	cout << "\nNhap cac thong so cua hinh tron: ";
	cout << "\nBan kinh hinh: ";
	cin >> R;
	Shape::Nhap();
}

//Hàm tính diện tích-class Circle
double Circle::Dien_tich() {
	double S;
	S = 3.14 * R * R;
	return S;
}

//Hàm in thông số hình vẽ-class Circle
void Circle::In() {
	cout << " THONG TIN HINH TRON VUA NHAP: ";
	cout << "\n+) Ban kinh hinh: " << R;
	Shape::In();
	cout << "\n+) Dien tich: " << Dien_tich() << endl;
}

/*=================================================RECTANGLE=================================================*/

//class Rectangle
class Rectangle : public Shape {
private:
	double chieu_dai, chieu_rong; //Chiều dài, chiều rộng hình chữ nhật

public:
	void Nhap(); //Hàm nhập

	void In(); //Hàm in

	double Dien_tich(); //Hàm tính diện tích
};


//Hàm nhập thông số hình vẽ-class Rectangle
void Rectangle::Nhap() {
	cout << "HINH CHU NHAT: ";
	cout << "\nNhap cac thong so cua hinh chu nhat: ";
	cout << "\nChieu dai: ";
	cin >> chieu_dai;
	cout << "\nChieu rong: ";
	cin >> chieu_rong;
	Shape::Nhap();
}

//Hàm tính diện tích hình vẽ-class Rectangle
double Rectangle::Dien_tich() {
	double S;
	S = chieu_dai * chieu_rong;
	return S;
}

//Hàm in thông số hình vẽ-class Rectangle
void Rectangle::In() {
	cout << " THONG TIN HINH CHU NHAT VUA NHAP: ";
	cout << "\n+) Chieu dai: " << chieu_dai;
	cout << "\n+) Chieu rong: " << chieu_rong;
	Shape::In();
	cout << "\n+) Dien tich: " << Dien_tich() << endl;
}

/*===================================================SQUARE===================================================*/

//class Square
class Square : public Shape {
private:
	double canh; //Cạnh hình vuông

public:
	void Nhap(); //Hàm nhập

	void In(); //Hàm in

	double Dien_tich(); //Hàm tính diện tích
};

//Hàm nhập thông số hình vẽ-class Square
void Square::Nhap() {
	cout << "HINH VUONG: ";
	cout << "\nNhap cac thong so cua hinh chu nhat: ";
	cout << "\nDo dai canh: ";
	cin >> canh;
	Shape::Nhap();
}

//Hàm tính diện tích-class Square
double Square::Dien_tich() {
	double S;
	S = canh * canh;
	return S;
}

//Hàm in thông số hình vẽ-class Square
void Square::In() {
	cout << " THONG TIN HINH VUONG VUA NHAP: ";
	cout << "\n+) Canh: " << canh;
	Shape::In();
	cout << "\n+) Dien tich: " << Dien_tich() << endl;
}

/*===================================================OVAL===================================================*/

//class Oval
class Oval : public Shape {
private:
	double a, b; //Cạnh dài, cạnh ngắn

public:
	void Nhap(); //Hàm nhập

	void In(); //Hàm in

	double Dien_tich(); //Diện tích
};

//Hàm nhập thông số hình vẽ-class Oval
void Oval::Nhap() {
	cout << "HINH ELIP: ";
	cout << "\nNhap cac thong so cua hinh elip: ";
	cout << "\nCanh ngan: ";
	cin >> a;
	cout << "\nCanh dai: ";
	cin >> b;
	Shape::Nhap();
}

//Hàm tính diện tích-class Square
double Oval::Dien_tich() {
	double S;
	S = 3.14 * a * b;
	return S;
}

//Hàm in thông số hình vẽ-class Oval
void Oval::In() {
	cout << " THONG TIN HINH ELIP VUA NHAP: ";
	cout << "\n+) Canh ngan: " << a;
	cout << "\n+) Canh dai: " << b;
	Shape::In();
	cout << "\n+) Dien tich: " << Dien_tich() << endl;
}

/*===================================================LINE===================================================*/

//class Line
class Line : public Shape {
private:
	double l; //Độ dài đoạn thẳng

public:
	void Nhap(); //Hàm nhập

	void In(); //Hàm in

	double Dien_tich() {
		double S = 0;
		return S;
	};
};

//Hàm nhập thông số hình vẽ-class Line
void Line::Nhap() {
	cout << "DOAN THANG: ";
	cout << "\nNhap cac thong so cua doan thang: ";
	cout << "\nDo dai doan thang: ";
	cin >> l;
	Shape::Nhap();
}

//Hàm in thông số hình vẽ-class Line
void Line::In() {
	cout << " THONG TIN DOAN THANG VUA NHAP: ";
	cout << "\n+) Do dai doan thang: " << l;
	Shape::In();
	cout << "\n+) Dien tich: Khong co dien tich!" << endl;
}

/*===================================================TRIANGLE===================================================*/

//class Triangle
class Triangle : public Shape {
private:
	double a, b, c; //3 cạnh tam giác

public:
	void Nhap(); //Hàm nhập

	bool Test_Tri(double a, double b, double c); //Hàm kiểm tra 3 cạnh có phải 3 cạnh tam giác hay không 

	void In(); //Hàm in

	double Dien_tich(); //Hàm tính diện tích
};

//Hàm kiểm tra 3 cạnh nhập vào có phải 3 cạnh tam giác hay không
bool Triangle::Test_Tri(double a, double b, double c) {
	if ((a + b >= c) && (a + c >= b) && (b + c >= a)) return 1;
	return 0;
}

//Hàm nhập thông số hình vẽ-class Triangle
void Triangle::Nhap() {
	cout << "HINH TAM GIAC: ";
	cout << "\nNhap cac thong so cua hinh tam giac: ";
	do
	{
		cout << "\nDo dai 3 canh hinh tam giac: ";
		cin >> a >> b >> c;
		if (Test_Tri(a, b, c) == 0) cout << "\n3 do dai nhap vao khong phai 3 canh cua mot tam giac!";
	} while (Test_Tri(a, b, c) == 0);
	Shape::Nhap();
}

//Hàm tính diện tích-class Triangle
double Triangle::Dien_tich() {
	double S, p;
	p = (a + b + c) / 2;
	S = sqrt((p - a) * (p - b) * (p - c));
	return S;
}

//Hàm in thông số hình vẽ-class Triangle
void Triangle::In() {
	cout << " THONG TIN TAM GIAC VUA NHAP: ";
	cout << "\n+) Do dai 3 canh tam giac: " << a << "\t" << b << "\t" << c;
	Shape::In();
	cout << "\n+) Dien tich: " << Dien_tich() << endl;
}

/*==================================================================================================================*/

//Hàm nhập vào danh sách thông tin các hình
void Nhap_hinh(vector <Shape*>& DS) { //Tạo vector để lưu trữ các phần tử hình, dùng Shape* để cấp phát động cho các phần tử hình
	int s;
	tryAgain:
		cout << "\n\n(*) HINH THU " << DS.size() + 1 << ": ";
		cout << "\nBan muon nhap hinh gi? ";
		cout << "\n\t(1). Hinh tron.";
		cout << "\n\t(2). Hinh chu nhat.";
		cout << "\n\t(3). Hinh vuong.";
		cout << "\n\t(4). Hinh elip.";
		cout << "\n\t(5). Doan thang.";
		cout << "\n\t(6). Hinh tam giac." << endl;
		cin >> s;

		switch (s) {
		case 1: {
			DS.push_back(new Circle);
			DS.back()->Nhap(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 2: {
			DS.push_back(new Rectangle);
			DS.back()->Nhap(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 3: {
			DS.push_back(new Square);
			DS.back()->Nhap(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 4: {
			DS.push_back(new Oval);
			DS.back()->Nhap(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 5: {
			DS.push_back(new Line);
			DS.back()->Nhap(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 6: {
			DS.push_back(new Triangle);
			DS.back()->Nhap(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		default: {
			cout << "\nYeu cau nhap cac so thu tu tu 1 den 6, khong nhap cac so khac!";
			goto tryAgain; //Nhảy đến nhãn tryAgain
		}

		}
}

/*==================================================================================================================*/

//Hàm in danh sách thông tin các hình
void In_hinh(vector <Shape*>& DS) {
	if (DS.empty() == 1) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	for (int i = 0; i < DS.size(); i++) {
		cout << "\n(" << i + 1 << "). ";
		DS[i]->In(); //Gọi đến hàm in của hình thứ i
	}
}

/*==================================================================================================================*/

//Hàm xóa 1 hình
void Xoa_hinh(vector <Shape*>& DS) {
	if (DS.empty() == 1) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	int n;
	cout << "\nBan muon xoa hinh thu may? ";
	cin >> n;
	DS.erase(DS.begin() + n - 1);
	In_hinh(DS);
}

/*==================================================================================================================*/

//Hàm sắp xếp hình theo diện tích giảm dần
void Sap_xep(vector <Shape*>& DS) {
	if (DS.empty() == 1) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	Shape* tmp;
	for (int i = 0; i < DS.size() - 1; i++)
		for (int j = i + 1; j < DS.size(); j++) 
			if (DS[i]->Dien_tich() < DS[j]->Dien_tich()) {
				tmp = DS[i];
				DS[i] = DS[j];
				DS[j] = tmp;
			}
	In_hinh(DS);
}

/*==================================================================================================================*/
//Hàm tìm kiếm một hình với tọa độ nhập từ bàn phím
void Tim_kiem(vector <Shape*>& DS) {
	if (DS.empty() == 1) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	double X, Y;
	int count = 0;
	cout << "\nNhap toa do tam hinh ve ma ban muon tim: "; //Tọa độ tâm hình vẽ
	cout << "\n\tx = ";
	cin >> X;
	cout << "\n\ty = ";
	cin >> Y;
	for (int i = 0; i < DS.size(); i++) {
		if ((DS[i]->getX() == X) && (DS[i]->getY() == Y))
		{
			count++;
			if (count == 1) cout << "\nHinh ban muon tim la hinh thu ";
			cout << i + 1 << ": " << endl;
			DS[i]->In();
		}
	}
	if (count == 0) cout << "\nKhong co hinh nao co toa do tam nhu vay!";
}

/*==================================================================================================================*/

int main() {
	vector <Shape*> DS;
	int n;
		cout << "DE BAT DAU CHUONG TRINH, HAY NHAP CAC THONG TIN SAU:";
	while (1) {
		cout << "\n\n====================================================";
		cout << "\n\nBan muon thuc hien ham gi? " << endl;
		cout << "\n\t(1). Nhap vao thong tin cac hinh.";
		cout << "\n\t(2). In ra man hinh thong tin cua cac hinh moi nhap vao.";
		cout << "\n\t(3). Xoa mot hinh.";
		cout << "\n\t(4). Sap xep cac hinh theo thu tu giam dan ve dien tich.";
		cout << "\n\t(5). Tim kiem mot hinh voi toa do tam cua hinh duoc nhap vao tu ban phim.";
		cout << "\n\t(6). Thoat." << endl;
		cin >> n;

		switch (n) {
		case 1: {
			Nhap_hinh(DS);
			continue;
		}

		case 2: {
			cout << "\n===========Danh sach hinh ve da nhap===========" << endl;
			In_hinh(DS);
			continue;
		}

		case 3: {
			cout << "\n===========Danh sach cac hinh sau khi xoa===========" << endl;
			Xoa_hinh(DS);
			continue;
		}

		case 4: {
			cout << "\n===========Sap xep cac hinh theo thu tu giam dan ve dien tich===========" << endl;
			Sap_xep(DS);
			continue;
		}

		case 5: {
			cout << "\n===========Ket qua tim kiem===========" << endl;
			Tim_kiem(DS);
			continue;
		}

		case 6: {
			char y_n;
			cout << "\nBai em lam on khong a? (y/n)";
			cin >> y_n;
			if (y_n == 'y') cout << "\nEm cam on a!";
			else cout << "\nEm se co gang lan sau a!";
			cout << "\nChuc anh/chi mot ngay vui ve!";
			cout << "\nPham Quang Anh - 20182359 - Dien tu 03 - K63";
			return 0; 
		}

		default: {
			cout << "\n===========Yeu cau nhap cac so thu tu tu 1 den 6, khong nhap cac so khac!===========";
			continue;
		}

		}
	}
	return 0;
}