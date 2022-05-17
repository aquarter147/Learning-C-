#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Shape{
    protected:
        float x,y; //tọa  độ x,y
        string color; // màu
        float thickness; // độ rộng

    public: 
        virtual void Set();//nhập
        virtual void Get();//vẽ
        virtual float Acreage(){ //diện tích
            return 0;
        }
        float get_x(){
            return x;
        }
        float get_y(){
            return y;
        }
};

void Shape::Set(){  // Hàm nhập các thông số
    cout << "Nhap toa do tam hinh " <<endl;
    cout << "x= ";
    cin >> x;
    cout << "y= ";
    cin >> y;
    cout << "Mau sac cua hinh: ";
    cin.ignore(1);
    getline(cin,color);
    cout << "Do rong net ve: ";
    cin >> thickness;
}

void Shape::Get(){ // Hàm in ra các thông số
    cout << "\n-Toa do cua hinh (" << x << "," << y << ")\n";
    cout << "-Mau: " << color;
    cout << "\n-Do rong net ve: " << thickness;
}


//CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE

class circle : public Shape{
    private:
        float R; // ban kinh
    public: 
        void Set();
        void Get();
        float Acreage();
};

void circle::Set(){   // Hàm nhập các thông số
    cout << "Hinh tron co thong so: ";
	cout << "\nBan kinh = ";
    cin >> R;
	while(R<=0){
		cout << "vo li! Moi nhap lai ban kinh:";
		cin >> R; 
	}
    Shape::Set();
}

float circle::Acreage(){ // Hàm tính diện tích
    return 3.14 *R*R;
}

void circle::Get(){    // Hàm xuất
    cout << "HINH TRON VUA NHAP: ";
    cout << "\n-Ban kinh: " << R;
    Shape::Get();
    cout << "\n-Dien tich = " << Acreage()<<endl;
}


//RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE


class rectangle: public Shape{
    private:
        float a, b; // chiều dài, rộng
    public:
        void Set();
        void Get();
        float Acreage();
};

void rectangle::Set(){ // Hàm nhập các thông số
    cout << "Hinh chu nhat co thong so: ";
    cout << "\nChieu dai= ";
    cin >> a;
	while(a<=0){
		cout << "vo li! Moi nhap lai chieu dai: ";
		cin >> a; 
	}
    cout << "Chieu rong = "; cin >> b;
    while(b>a || b<=0){
        cout << "Vo li!\n";
        cout << "Moi nhap lai chieu rong!\n";
		cout <<"Chieu rong = ";
        cin >> b;
    }
    Shape::Set();
}

float rectangle::Acreage(){ // Hàm tính diện tích
    return a*b;
}

void rectangle::Get(){  // Hàm xuất
    cout << "HINH CHU NHAT VUA NHAP: ";
    cout << "\n-CHieu dai = " << a;
    cout << "\n-CHieu rong = " << b;
    Shape::Get();
    cout << "\n-Dien tich = " << Acreage()<<endl;
}



//TRIANGLE

class triangle: public Shape{
    private:
        float a,b,c; //chiều dài 3 cạnh
    public:
        void Set();
        void Get();
        int Check(float a, float b, float c);
        float Acreage();
};

//Hàm kiểm tra 3 cạnh nhập vào có phải 3 cạnh tam giác hay không
int triangle::Check(float a, float b, float c) {
	if ((a + b > c) && (a + c > b) && (b + c > a) && (a>0) && (b>0) && (c>0)) return 1;
	return 0;
}

void triangle::Set() {  // Hàm nhập các thông số
	cout << "\nNhap cac thong so cua hinh tam giac: ";
	do
	{
		cout << "\nDo dai 3 canh hinh tam giac: ";
		cin >> a >> b >> c;
		if (!Check(a, b, c)) cout << "\n3 do dai nhap vao khong phai 3 canh cua mot tam giac!";
	} while (!Check(a, b, c));
	Shape::Set();
}

float triangle::Acreage(){  // Hàm tính diện tích
    float p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void triangle::Get(){  // Hàm xuất
    cout << "HINH TAM GIAC VUA NHAP: ";
    cout << "\n-CHieu dai 3 canh la: " << a << "\t" << b << " " << c ;
    Shape::Get();
    cout << "\n-Dien tich = " << Acreage()<<endl;
}



//SQUARE

class square: public Shape{
    private:
        float a;//độ dài cạnh
    public:
        void Set();
        void Get();
        float Acreage();
};

void square::Set(){  // Hàm nhập các thông số
    cout << "Hinh vuong co thong so: ";
    cout << "\nCanh = ";
    cin >> a;
	while(a<=0){
		cout << "vo li! Moi nhap lai canh hinh vuong: ";
		cin >> a; 
	}
    Shape::Set();
}

float square::Acreage(){  // Hàm tính diện tích
    return a*a;
}

void square::Get(){ // Hàm xuất
    cout << "HINH VUONG VUA NHAP: ";
    cout << "\n-Canh: " << a;
    Shape::Get();
    cout << "\n-Dien tich = " << Acreage()<<endl;
}



//OVAL

class oval: public Shape{
    private:
        float a,b; // đọ dài các bán trục 
    public:
        void Set();
        void Get();
        float Acreage();
};

void oval::Set(){  // Hàm nhập các thông số
    cout << "Hinh elip co thong so: ";
    cout << "\nBan truc lon= ";
    cin >> a;
	while(a<=0){
		cout << "vo li! Moi nhap lai ban truc lon: ";
		cin >> a; 
	}
    cout << "Ban truc nho = "; cin >> b;
    while(b>a || b<=0){
        cout << "Vo li!\n";
        cout << "Moi nhap lai ban truc nho: ";
        cin >> b;
    }
    Shape::Set();
}

float oval::Acreage(){   // Hàm tính diện tích
    return 3.14*a*b;
}

void oval::Get(){ // Hàm xuất
    cout << "HINH ELIP VUA NHAP: ";
    cout << "\n-Ban truc lon = " << a;
    cout << "\n-Ban truc nho = " << b;
    Shape::Get();
    cout << "\n-Dien tich = " << Acreage()<<endl;
}


//LINE

class line: public Shape{
    private:
        float a; // độ dài đoạn thẳng
    public:
        void Set();
        void Get();
        float Acreage(){
            return -1;
        }
};

void line::Set() {  // Hàm nhập các thông số
	cout << "\nNhap cac thong so cua doan thang: ";
	cout << "\nDo dai doan thang: ";
	cin >> a;
	while(a<=0){
		cout << "vo li! Moi nhap lai chieu dai doan thang: ";
		cin >> a; 
	}
	Shape::Set();
}

void line::Get() { // Hàm xuất
	cout << "DOAN THANG VUA NHAP: ";
	cout << "\n-Do dai doan thang: " << a;
	Shape::Get();
	cout << "\n-Dien tich: Khong co dien tich!" << endl;
}


//CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE

class Edge : public Shape{
	private:
	 	string color;
		float thickness;
		Shape* S1;
		Shape* S2;
	public:
		void set_S1(Shape* S){
			S1=S;
		}
		void set_S2(Shape* S){
			S2 =S;
		}
		
		void InPut(){
			cout << "Nhap thong tin cua canh: ";
			cout << "Mau sac: ";
			getline(cin,color);
			cout << "Do day net ve: ";
			cin >> thickness;
		}

		void OutPut(){
			cout << "\nTHONG TIN CUA CANH: ";
			cout << "\n*2 dau cua canh: (" <<  S1 ->get_x() << "," << S1->get_y() << ") va (" << S2->get_x() << "," << S2->get_y()<< ") ";
			cout << "\n*Canh nay noi hinh: ";
			S1->Get();
			S2->Get();
			cout << "\n*Mau sac: " << color;
			cout << "\n*Do day: " << thickness;
			cout << "\n*Do dai: " << sqrt( pow((S1->get_x() - S2->get_x()),2)  +  pow((S1->get_y() - S2->get_y()),2) );
		}
		void OutPut2(){
			cout << "\nTHONG TIN CUA CANH: ";
			cout << "\n*2 dau cua canh: (" <<  S1 ->get_x() << "," << S1->get_y() << ") va (" << S2->get_x() << "," << S2->get_y()<< ") ";
			cout << "\n*Canh nay noi hinh: ";
			S1->Get();
			S2->Get();
			cout << "\n*Do dai: " << sqrt( pow((S1->get_x() - S2->get_x()),2)  +  pow((S1->get_y() - S2->get_y()),2) );
		}

};



//Hàm nhập vào danh sách thông tin các hình
void Nhap_hinh(vector <Shape*>& DS) {
	int s;
	tryAgain:
		cout << "\nHINH THU " << DS.size() + 1 << ": ";
		cout << "\nChon hinh muon nhap... ";
		cout << "\n\t(1). Hinh tron.";
		cout << "\n\t(2). Hinh chu nhat.";
		cout << "\n\t(3). Hinh vuong.";
		cout << "\n\t(4). Hinh elip.";
		cout << "\n\t(5). Doan thang.";
		cout << "\n\t(6). Hinh tam giac." << endl;
		cin >> s;

		switch (s) {
		case 1: {
			DS.push_back(new circle);
			DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 2: {
			DS.push_back(new rectangle);
			DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 3: {
			DS.push_back(new square);
			DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 4: {
			DS.push_back(new oval);
			DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 5: {
			DS.push_back(new line);
			DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		case 6: {
			DS.push_back(new triangle);
			DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
			break;
		}

		default: {
			cout << "\nLua chon khong hop le! Moi nhap lai";
			goto tryAgain; //Nhảy đến nhãn tryAgain
		}

		}
}


//Hàm in danh sách thông tin các hình
void Print(vector <Shape*>& DS) {
	if (DS.empty()) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	for (int i = 0; i < DS.size(); i++) {
		cout << "\n(" << i + 1 << "). ";
		DS[i]->Get(); //Gọi đến hàm in của hình thứ i
	}
}


//Hàm xóa 1 hình
void Delete(vector <Shape*>& DS) {
	if (DS.empty()) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	int n;
	cout << "\nBan muon xoa hinh thu may? ";
	cin >> n;
	if(DS.size()<n || n<=0){
		cout << "Danh sach khong co hinh nay";
	}
	else{
		DS.erase(DS.begin() + n - 1);
		Print(DS);
	}
}


//Hàm sắp xếp hình theo diện tích giảm dần
void Swap(vector <Shape*>& DS) {
	if (DS.empty()) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	Shape* tmp;
	for (int i = 0; i < DS.size() - 1; i++)
		for (int j = i + 1; j < DS.size(); j++) 
			if (DS[i]->Acreage() < DS[j]->Acreage()) {
				tmp = DS[i];
				DS[i] = DS[j];
				DS[j] = tmp;
			}
	Print(DS);
}


//Hàm tìm kiếm một hình với tọa độ nhập từ bàn phím
void Find(vector <Shape*>& DS) {
	if (DS.empty()) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	double X, Y;
	int count = 0;
	cout << "\nNhap toa do tam hinh ve ma ban muon tim: "; //Tọa độ tâm hình vẽ
	cout << "\nx = ";
	cin >> X;
	cout << "y = ";
	cin >> Y;
	for (int i = 0; i < DS.size(); i++) {
		if ((DS[i]->get_x() == X) && (DS[i]->get_y() == Y))
		{
			count++;
			if (count == 1) cout << "\nHinh ban muon tim la hinh thu ";
			cout << i + 1 << ": " << endl;
			DS[i]->Get();
		}
	}
	if (!count) cout << "\nKhong co hinh nao co toa do tam nhu vay!";
}

//Hàm thêm 1 cạnh
void AddEdge(vector <Edge*>& E, vector <Shape*>& DS){
	int a,b;
	if(DS.empty()){
		cout << "\nDanh sach hinh rong! Moi nhap them it nhat 2 hinh";
		return;
	}
	if(DS.size() ==1){
		cout << "\nDanh sach hinh khong du de tao canh noi tam. Moi nhap them it nhat 1 hinh.";
		return;
	}
	cout << "\nNhap 2 hinh ban muon noi tam: ";
	cout << "\nNhap STT hinh thu nhat: ";
	cin >> a;
	while (a<=0 || a>DS.size()){
		cout << "Danh sach khong co hinh nay!";
		cout << "\nMoi ban nhap lai hinh thu nhat: ";
		cin >>a;
	}
	cout << "Nhap STT hinh thu 2: ";
	cin >> b;
	while (b<=0 || b>DS.size()){
		cout << "Danh sach khong co hinh nay!";
		cout << "\nMoi ban nhap lai hinh thu nhat: ";
		cin >>b;
	}

	E.push_back(new Edge);
	E.back()->set_S1(DS[a-1]);
	E.back()->set_S2(DS[b-1]);
	E.back()->InPut();

}

//Hàm in ra các cạnh của class Edge
void Print_Edge(vector <Edge*>& E){
	if (E.empty()) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
	for(int i=0;i<E.size();i++){
		cout << "\n(" << i + 1 << "). ";
		E[i]->OutPut(); //Gọi đến hàm in của hình thứ i
	}
}

//Hàm in ra tất cả các cạnh xuất phát từ 1 shape
void Print_Shape(vector <Edge*>& E_1, vector <Shape*>& DS){
	if(DS.empty()){
		cout << "\nDanh sach hinh rong! Moi nhap them it nhat 2 hinh";
		return;
	}
	if(DS.size() ==1){
		cout << "\nDanh sach hinh khong du de tao canh noi tam. Moi nhap them it nhat 1 hinh.";
		return;
	}
	int a;
	cout << "Nhap hinh ban muon tao tat ca cac canh noi tam: ";
	cin >>a;
	while(a<=0||a>DS.size()){
		cout << "Moi nhap lai STT cua hinh: ";
		cin >> a;
	}

	for(int i=1 ; a-1-i>=0 ; i++){
		E_1.push_back(new Edge);
		E_1.back()->set_S1(DS[a-1]);
		E_1.back()->set_S2(DS[a-i-1]);
		E_1.back()->OutPut2();
	}
	for(int i=1 ; a+i-1<DS.size() ; i++){
		E_1.push_back(new Edge);
		E_1.back()->set_S1(DS[a-1]);
		E_1.back()->set_S2(DS[a+i-1]);
		E_1.back()->OutPut2();
	}
}




int main(){
    vector <Shape*> DS;
	vector <Edge*> E;
	vector <Edge*> E_1;
	int n;
	again:
		cout << "\n\n=========================================================================";
		cout << "\n\nMoi ban thuc thuc hien chuong trinh " << endl;
		cout << "\n\t(1). Nhap vao thong tin cac hinh.";
		cout << "\n\t(2). In ra man hinh thong tin cua cac hinh moi nhap vao.";
		cout << "\n\t(3). Xoa mot hinh.";
		cout << "\n\t(4). Sap xep cac hinh theo thu tu giam dan ve dien tich.";
		cout << "\n\t(5). Tim kiem mot hinh voi toa do tam cua hinh duoc nhap vao tu ban phim.";
		cout << "\n\t(6). Them 1 canh noi tam";
		cout << "\n\t(7). In ra tat ca cac canh noi tam da co";
		cout << "\n\t(8). In tat ca cac canh noi tam tu 1 hinh";
		cout << "\n\t(9). Thoat!\n";
        cin >> n;

		switch (n) {
		case 1: {
			Nhap_hinh(DS);
			goto again;
			break;
		}

		case 2: {
			cout << "\n===========Danh sach hinh ve da nhap===========" << endl;
			Print(DS);
			goto again;
			break;
		}

		case 3: {
			cout << "\n===========Danh sach cac hinh sau khi xoa===========" << endl;
			Delete(DS);
			goto again;
			break;
		}

		case 4: {
			cout << "\n===========Sap xep cac hinh theo thu tu giam dan ve dien tich===========" << endl;
			Swap(DS);
			goto again;
			break;
		}

		case 5: {
			cout << "\n===========Ket qua tim kiem===========" << endl;
			Find(DS);
			goto again;
			break;
		}
		case 6: 
			AddEdge(E,DS);
			goto again;
			break;
		case 7:
			cout << "\n===========Danh sach cac canh da tao===========" << endl;
			Print_Edge(E);
			goto again;
			break;
        case 8: 
			cout << "\n===========Danh sach cac canh co the tao tu hinh duoc chon===========" << endl;
			Print_Shape(E_1,DS);
			goto again;
			break;
		case 9: break;
		default: {
			cout << "\nNhap lai!";
			goto again;
			break;
		}
		}
}

