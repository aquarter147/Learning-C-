#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class Shape{
    public:
        float x, y; //tọa  độ x,y
        string color, name; // màu
        float thickness; // độ rộng
		int index=0;
		float a=0,b=0,c=0;

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
    cout << "(" << x << "," << y << ")              " <<setw(20) << left<< color <<setw(20) << left << thickness;
}


//CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE CIRCLE
class circle : public Shape{
    public: 
        void Set();
        void Get();
        float Acreage();
		circle (){
			this ->color = "un";
			this ->x= 0;
			this ->y = 0;
			this ->thickness =0;
			this ->index =0;
		}
};

void circle::Set(){   // Hàm nhập các thông số
    cout << "Hinh tron co thong so: ";
	cout << "\nBan kinh = ";
    cin >> a;
	while(a<=0){
		cout << "vo li! Moi nhap lai ban kinh:";
		cin >> a; 
	}
    Shape::Set();
}

float circle::Acreage(){ // Hàm tính diện tích
    return 3.14 *a*a;
}

void circle::Get(){    // Hàm xuất
    cout << setw(20) << left <<"Hinh tron";
    cout << setw(30) << left<< a;
    Shape::Get();
    cout << setw(20) << left << Acreage()<<endl;
}


//RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE RECTANGLE
class rectangle: public Shape{
    public:
        void Set();
        void Get();
        float Acreage();
		rectangle (){
			this ->color = "un";
			this ->x= 0;
			this ->y = 0;
			this ->thickness =0;
			this ->index =0;
		}
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
    cout << setw(20) << left <<"Hinh chu nhat";
    cout << setw(15) << left<< a;
    cout << setw(15) << left  << b;
    Shape::Get();
    cout <<setw(20) << left <<Acreage()<<endl;
}


//TRIANGLE
class triangle: public Shape{
    public:
        void Set();
        void Get();
        int Check(float a, float b, float c);
        float Acreage();
		triangle (){
			this ->color = "un";
			this ->x= 0;
			this ->y = 0;
			this ->thickness =0;
			this ->index =0;
		}
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
    cout <<setw(20) << left << "Hinh tam giac";
    cout << setw(10) << left<< a << setw(10) << left<< b << setw(10) << left << c ;
    Shape::Get();
    cout << setw(20) << left << Acreage()<<endl;
}


//SQUARE
class square: public Shape{
    public:
        void Set();
        void Get();
        float Acreage();
		square (){
			this ->color = "un";
			this ->x= 0;
			this ->y = 0;
			this ->thickness =0;
			this ->index =0;
		}
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
    cout <<setw(20) << left << "Hinh vuong";
    cout << setw(30) << left  << a;
    Shape::Get();
    cout << setw(20) << left << Acreage()<<endl;
}


//OVAL
class oval: public Shape{
    public:
        void Set();
        void Get();
        float Acreage();
		oval (){
			this ->color = "un";
			this ->x= 0;
			this ->y = 0;
			this ->thickness =0;
			this ->index =0;
		}
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
    cout <<setw(20) << left << "Hinh elip";
    cout << setw(15) << left<< a;
    cout << setw(15) << left << b;
    Shape::Get();
    cout << setw(20) << left << Acreage()<<endl;
}


//LINE
class line: public Shape{
    public:
        void Set();
        void Get();
        float Acreage(){
            return -1;
        }
		line (){
			this ->color = "un";
			this ->x= 0;
			this ->y = 0;
			this ->thickness =0;
			this ->index =0;
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
	cout <<setw(20) << left << "Doan thang";
	cout << setw(30) << left << a;
	Shape::Get();
	cout << setw(20) << left << "Khong co dien tich!" << endl;
}


//CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE CLASS EDGE
class Edge : public Shape{
	public:
	 	string color;
		float thickness;
		int src, des;
		Shape* S1;
		Shape* S2;
		
	public:
		void set_S1(Shape* S){ // con trỏ 1 chỉ tới hình thứ nhất
			S1=S;
		}
		void set_S2(Shape* S){ // con trỏ 2
			S2 =S;
		}
		
		void Set(){ // Hàm nhập thông tin của cạnh muốn tạo
			cout << "Nhap thong tin cua canh: ";
			cout << "\nMau sac: ";
			cin.ignore(1);
			getline(cin,color);
			cout << "Do day net ve: ";
			cin >> thickness;
		}

		void Get(){ //Hàm in thông tin của cạnh đã được tạo
			cout << "\nCanh noi tam cua hinh thu: " << S1->index << " va " << S2->index;
			cout << "\n*2 dau cua canh: (" <<  S1 ->get_x() << "," << S1->get_y() << ") va (" << S2->get_x() << "," << S2->get_y()<< ") ";
			cout << "\n*Mau sac: " << color;
			cout << "\n*Do day: " << thickness;
			cout << "\n*Do dai cua canh: " << sqrt( pow((S1->get_x() - S2->get_x()),2)  +  pow((S1->get_y() - S2->get_y()),2) );
		}
		Edge(){
			S1 = new Shape();
			S2 = new Shape();
			color = "unnknown";
			thickness = 0;
			src = des =0;
		}
};


// // CLASS FACTORY
class ShapeFactory
{
public:
	static Shape* createShape(char s)
	{
		Shape* shape = nullptr;

		if (s == 'c')
			shape = new circle;
		if (s == 'r')
			shape = new rectangle;
		if (s == 's')
			shape = new square;
		if (s == 'o')
			shape = new oval;
		if (s == 'l')
			shape = new line;
		if (s == 't')
			shape = new triangle;
		return shape;
	}
};

class Graph{
	public: 
		vector <Shape*> DS,SS;
		vector <Edge*> E,EE;
	public:
		int n;
		int i=0;

		// Them canh
		void Nhap_hinh(vector <Shape*>& DS,int &i) {
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
				DS.push_back(ShapeFactory :: createShape('c'));
				DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
				i+=1;
				DS.back()->index = i;
				break;
			}

			case 2: {
				DS.push_back(ShapeFactory::createShape('r'));
				DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
				i+=1;
				DS.back()->index = i;
				break;
			}

			case 3: {
				DS.push_back(ShapeFactory::createShape('s'));
				DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
				i+=1;
				DS.back()->index = i;
				break;
			}

			case 4: {
				DS.push_back(ShapeFactory::createShape('o'));
				DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
				i+=1;
				DS.back()->index = i;
				break;
			}

			case 5: {
				DS.push_back(ShapeFactory::createShape('l'));
				DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
				i+=1;
				DS.back()->index = i;
				break;
			}

			case 6: {
				DS.push_back(ShapeFactory::createShape('t'));
				DS.back()->Set(); //Gọi đến hàm nhập của hình vừa nhập
				i+=1;
				DS.back()->index = i;
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
			if (DS.empty())
			{ 
				cout << "\nDanh sach hinh hien dang rong!";
			} //Trường hợp danh sách rỗng
			else{
				cout << setw(5) << left << "STT";		
				cout << setw(5) << left << "MSC";
				cout << setw(20) << left << "Loai hinh";		
				cout << setw(30) << left << "Dac trung";	
				cout << setw(20) << left << "Toa do tam";		
				cout << setw(20) << left << "Mau sac";
				cout << setw(20) << left << "Do day net";		
				
				cout << setw(20) << left << "Dien tich" << endl;
				
				for (int i = 0; i < DS.size(); i++) {
					cout << "\n"<< setw(5) << left << i + 1 << setw(5) << left<< DS[i]->index;
					DS[i]->Get(); //Gọi đến hàm in của hình thứ i
				}
			}
		}


		//Hàm xóa 1 hình
		void Delete(vector <Shape*>& DS,vector<Edge*> &E) {
			if (DS.empty()) cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
			int n;
			cout << "\nBan muon xoa hinh thu may? ";
			cin >> n;
			n-=1;
			if(DS.size()<(n+1) || (n+1)<=0){
				cout << "Danh sach khong co hinh nay";
			}
			else{
				for(int i=0;i<E.size();i++)
				{
					if (E[i]->src == DS[n] -> index || E[i]->des == DS[n]->index)
					{
						E.erase(E.begin()+i);
						i--;
					}
				}
				DS.erase(DS.begin() + n );
				cout << "Danh sach hinh con lai: \n";
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
			int check = 1;
			if(DS.empty()){
				cout << "\nDanh sach hinh rong! Moi nhap them it nhat 2 hinh";
				return;
			}
			if(DS.size() ==1){
				cout << "\nDanh sach hinh khong du de tao canh noi tam. Moi nhap them it nhat 1 hinh.";
				return;
			}
			E.push_back(new Edge);
			cout << "\nNhap 2 hinh ban muon noi tam: ";
			cout << "\nNhap STT hinh thu nhat: ";
			cin >> E.back()->src;
			
			do{
				for(int i = 0; i < DS.size(); i++){
					if(E.back()->src == DS.at(i)->index){
						check = 0;
						break;
					} 
				}
	
				if(check == 1){
					cout << "Danh sach khong co hinh nay!";
					cout << "\nMoi ban nhap lai hinh thu nhat: ";
					cin >>E.back()->src;
				}
			}while(check);
				
			check = 1;

			cout << "Nhap STT hinh thu 2: ";
			cin >> E.back()->des;

			do{
				for(int i = 0; i < DS.size(); i++){
					if(E.back()->des == DS.at(i)->index){
						check = 0;
						break;
					} 
				}

				if(check == 1){
					cout << "Danh sach khong co hinh nay!";
					cout << "\nMoi ban nhap lai hinh thu nhat: ";
					cin >>E.back()->des;
				}
			}while(check);

			E.push_back(new Edge);
			E.back()->set_S1(DS[E.back()->src-1]);
			E.back()->set_S2(DS[E.back()->des-1]);
			E.back()->Set();
		}

		//Hàm in ra các cạnh của class Edge
		void Print_Edge(vector <Edge*>& E) {
			if (E.empty()) cout << "\nDanh sach canh hien dang rong!"; //Trường hợp danh sách rỗng
			for(int i=0;i<E.size();i++){
				cout << "\nCanh thu (" << i + 1 << "): ";
				E[i]->Get(); //Gọi đến hàm in của hình thứ i
			}
		}


		//Hàm in ra thông tin các cạnh xuất phát từ một Shape
		void Print2_Shape(vector <Edge*>& E, vector <Shape*>& DS) {
			if (E.empty()) {
				cout << "\nDanh sach hinh hien dang rong!"; //Trường hợp danh sách rỗng
				return;
			}
			int n;
			cout << "\nBan muon xem thong tin cua hinh so may: ";
			cin >> n;
			for(int i=0;i<E.size();i++){
				if(E[i]->src == n || E[i] ->des == n){
					E[i]->Get();
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////
		// đếm dấu phẩy trong 1 dòng
		int count_comma(string input){
			int count =0 ;
			for ( int i=0 ; i<input.length();i++){
				if(input[i]== ',') count ++;
			}
			return count;
		}

		//Hình hay cạnh
		string get_type(string input){
			if(input[0] == 's') return "Shape";
			else return "Edge";
		}

		// Hình gì
		char get_type2(string input){
			int m;
			for(int i=0;i<input.length();i++){
				if(input[i] == '{'){
					m=i;
					continue;
				}
			}
			return input[m+1];
		}

		// string to int
		int str2int(string input){
			stringstream x(input);
			int output =0;
			x >> output;
			return output;
		}

		//string to float
		float str2f(string input){
			stringstream x(input);
			float output =0.0;
			x >> output;
			return output;
		}

		// string int2str(int input){
		//     stringstream ss;
		//     ss << input;
		//     return ss.str();
		// }

		// string f2str(float input){
		//     stringstream ss;
		//     ss << input;
		//     return ss.str();
		// }

		float get_x(string input){
			string s;
			int i=0,count =0;
			while (count < 2){
				if(input[i] ==',') count ++;
				if(count == 1 && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
			}
			return str2f(s);
		}
		float get_y(string input){
			string s;
			int i=0,count =0;
			while (count < 3){
				if(input[i] ==',') count ++;
				if(count == 2 && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
			}
			return str2f(s);
		}

		float get_c1(string input){
			string s;
			int i=0,count =0;
			while (count < 4){
				if(input[i] ==',') count ++;
				if(count == 3 && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
			}
			return str2f(s);
		}
		float get_c2(string input){
			string s;
			int i=0, count =0;
			if(count_comma(input)==5) return 0;
			if(count_comma(input)==6 ||count_comma(input)==7){
				while (count < 5){
				if(input[i] ==',') count ++;
				if(count == 4 && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
				}
			}
			return str2f(s);
		}
		float get_c3(string input){
			string s;
			int i=0, count = 0;
			if(count_comma(input)==5 || count_comma(input)==6) return 0;
			if(count_comma(input)==7){
				while (count < 6){
				if(input[i] ==',') count ++;
				if(count == 5 && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
				}
			}
			return str2f(s);
		}

		string get_color(string input){
			string s;
			int i=0, count =0;
			while (count < count_comma(input)){
				if(input[i] ==',') count ++;
				if(count == (count_comma(input)-1) && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
			}
			return s;
		}

		float get_thickness(string input){
			string s;
			int i=0, count =0;
			while(count < count_comma(input)+1){
				if(input[i] ==',') count ++;
				if(count == count_comma(input) && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
			}
			return str2f(s);
		}


		int get_index1(string input){
		string s;
		s.push_back(input[5]);
			return str2int(s);
		}

		int get_index2(string input){
		string s;
		s.push_back(input[7]);
		return str2int(s);
		}   

		string get_color2(string input){
		string s;
			int i=0,count =0;
			while (count < 3){
				if(input[i] ==',') count ++;
				if(count == 2 && input[i+1] != ',') s.push_back(input[i+1]);
				++i;
			}
			return s;
		}   

		float get_thickness2(string input){
		string s;
			int i=0,count =0;
			while (count < 4){
				if(input[i] ==',') count ++;
				if(count == 3 && input[i+1] != '}') s.push_back(input[i+1]);
				++i;
			}
			return str2f(s);
		}   

		//////////////////////////////////////////////////////////////////////////////////////////

		// Đọc file
		void Read_data(vector<Shape*> & SS, vector <Edge*> & EE,int &i){
			ifstream fileInput("C:/Users/admin/Documents/t.a/nhat.txt");

			if (fileInput.fail())
			{
				cout << "Failed to open this file!" << endl;
				return;
			}
			while (!fileInput.eof())
			{
				string a;
				fileInput >> a;

				if(get_type(a)=="Shape"){
					SS.push_back(ShapeFactory::createShape(get_type2(a)));
					SS.back()->x = get_x(a);
					SS.back()->y = get_y(a);
					SS.back()->a = get_c1(a);
					SS.back()->b = get_c2(a);
					SS.back()->c = get_c3(a);
					SS.back()->thickness = get_thickness(a);
					SS.back()->color = get_color(a);
					i+=1;
					SS.back()->index = i;

				}
				if(get_type(a) == "Edge"){
					EE.push_back(new Edge);
					EE.back()->src = get_index1(a);
					EE.back()->des = get_index2(a);
					EE.back()->color = get_color2(a);
					EE.back()->thickness = get_thickness2(a);
					EE.back()->S1 = SS.at(get_index1(a)-1);
					EE.back()->S2 = SS.at(get_index2(a)-1);
				}
			}
			std::cout << std::endl;

			fileInput.close();
		}
		~Graph(){
			DS.clear();
			E.clear();
		}

		void Menu(){
			again:
				cout << "\n\n=========================================================================";
				cout << "\n\nMoi ban thuc thuc hien chuong trinh " << endl;
				cout << "\n\t(1). Nhap vao thong tin cac hinh.";
				cout << "\n\t(2). In ra man hinh thong tin cua cac hinh moi nhap vao.";
				cout << "\n\t(3). Xoa mot hinh.";
				cout << "\n\t(4). Sap xep cac hinh theo thu tu giam dan ve dien tich.";
				cout << "\n\t(5). Tim kiem mot hinh voi toa do tam cua hinh duoc nhap vao tu ban phim.";
				cout << "\n\t(6). Them 1 canh noi tam.";
				cout << "\n\t(7). In ra tat ca cac canh noi tam da co.";
				cout << "\n\t(8). In tat ca cac canh noi tam tu 1 hinh.";
				cout << "\n\t(9). Doc tu file cac hinh va canh";
				cout << "\n\t(10). Thoat!\n";
				cin >> n;

				switch (n) {
				case 1: {
					Nhap_hinh(DS,i);
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
					Delete(DS,E);
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
					Print2_Shape(E,DS);
					goto again;
					break;

				case 9: 
					cout <<" \n===========Danh sach cac canh va hinh co trong file===========" << endl;
					Read_data(DS, E,i);
					Print(DS);
					Print_Edge(E);
					goto again;
					break;

				case 10: break;

				default: {
					cout << "\nNhap lai!";
					goto again;
					break;
				}
			}
		}
};

int main(){
    Graph g; 
	int a;
	// do{
	g.Menu(); 
	// }while(1); 
	return 0;
	// Print_F(Factory::Circle);
}
