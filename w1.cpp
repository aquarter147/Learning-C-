#include<iostream>

using namespace std;

class sinhVien{
    string name, birthday, msv, add;
    int mark;
public:
    void input(){
        string _name, _birthday, _msv, _add;
        int _mark;
        cout << "Nhap ten: " ;
        getline(cin, _name);
        cout << "Nhap ngay, thang, nam sinh(dd/mm/yyyy): ";
        getline(cin, _birthday);
        cout << "Nhap ma sinh vien: ";
        getline(cin, _msv);
        cout << "Nhap que quan: ";
        getline(cin, _add);
        cout << "Nhap diem: ";
        cin >> _mark;
        cin.ignore();
    }
    void print(){
        cout << name << endl << birthday << endl << msv << endl << add << endl << mark << endl;
    }
    static void sx(sinhVien a[], int n){
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++){
                if (a[i].mark>a[j].mark)
                    swap(a[i], a[j]);
        }
    }
    static void del(sinhVien a[], int &n, int k) //xoa tai vi tri k
    {
        for (int i=k; i<n-1; i++){
            a[i] = a[i+1];
        }
        n = n-1;
    }
    static void nhom(sinhVien a[], int n, string st)
    {
        for (int i=0; i<n; i++)
            if (a[i].add == st)
                cout << a[i].name << ", ";
        cout << endl;
    }
    static void theo_ten(sinhVien a[], int n)
    {
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++)
                if (a[i].name>a[j].name)
                    swap(a[i], a[j]);
    }
    static void theo_ngaysinh(sinhVien a[], int n)
    {
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++)
                if (a[i].birthday>a[j].birthday)
                    swap(a[i], a[j]);
    }
    static void theo_msv(sinhVien a[], int n)
    {
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++)
                if (a[i].msv>a[j].msv)
                    swap(a[i], a[j]);
    }
    static void theo_que(sinhVien a[], int n)
    {
        for (int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++)
                if (a[i].add>a[j].add)
                    swap(a[i], a[j]);
    }
};
int main(){
    int n;
    cin >> n;
    cin.ignore();
    sinhVien a[n];
    for (int i=0; i<n; i++)
        a[i].input();
    sinhVien::sx(a, n);
    for (int i=0; i<n; i++)
        a[i].print();

    string que;
    cout << "Nhao que: ";
    getline(cin, que);
    cout << "Sinh vien cung que " << que << "la: ";
    sinhVien::nhom(a, n, que);

    string s;
    cout << "Ban muon sap xep theo(ten, ngay sinh, msv, que, diem): " ;
    getline(cin, s);
    if (s == "ten")
        sinhVien::theo_ten(a, n);
    else if (s== "ngay sinh")
        sinhVien::theo_ngaysinh(a, n);
    else if (s== "msv")
        sinhVien::theo_msv(a, n);
    else if (s == "que")
        sinhVien::theo_que(a, n);
    else if (s== "diem")
        sinhVien::sx(a, n);
    else
        cout << "Ban nhap khong hop le! "<< endl;

    for (int i=0; i<n; i++)
        a[i].print();
    return 0;
}
