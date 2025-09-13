// Khai báo các thư viện cần dùng
#include<iostream>
#include<string> // Thao tác với chuỗi
#include<cctype> // Dùng hàm tolower và toupper
using namespace std;

// Định nghĩa các thông tin liên quan đến sinh viên hiện tại(người dùng)
struct Sinh_vien{
    string name; // Họ và tên
    int birth; // Năm sinh
    string major; // Ngành học
};
// Định nghĩa một môn học sẽ có những gì liên quan
struct Mon_hoc{
    string name; // Tên môn học
    string loai; // Loại học phần: Lý thuyết, thực hành, tích hợp
    int tc; // Số tín chỉ của môn học
    int tc_lt; // Số chỉ lý thuyết của học phần tích hợp
    int tc_th; // // Số chỉ thực hành của học phần tích hợp
    int sclt; // Số cột điểm lý thuyết thường kỳ thực tế sẽ dùng
    float lt[7]; // Tối đa 7 cột điểm lí thuyết thường kì
    int scth; // Số cột điểm thực hành thường kỳ thực tế sẽ dùng
    float th[7]; // Tối đa 7 cột điểm thực hành thường kì 
    float gk_lt; // Điểm trung bình lý thuyết thường kì
    float gk_th; // Điểm trung bình thực hành thường kì
    float gk_thop; // Điểm trung bình tích hợp thường kì
    float gk; // Điểm thi giữa kỳ
    float ck; // Điểm thi cuối kỳ
    float dtb10; // Điểm tổng kết hệ 10
    float dtb4; // Điểm tổng kết hệ 4
    string dc; // Điểm chữ A+, A, B+, B, C+, C, D+, D ,F
    string xl; // Xếp loại: Yếu, trung bình, khá, giỏi, xuất sắc
    bool dat; // true = Đạt; false = Học lại ( Xếp loại = Yếu)
};

//-------------------------------------------------------
// Viết prototype để không cần quan tâm đến thứ tự khai báo hàm sau này nếu có lỗi và đông thời nêu ý nghĩa của nó
void Nhap_monhoc_moi(Mon_hoc &mh); // Hàm dùng để nhập thông tin liên quan đến môn học
void In_thongtin_monhoc(Mon_hoc mh); // Hàm in ra thông tin của môn học
double Tinh_diem_lythuyet(double a, double b, double c); // Hàm tính điểm trung bình đối với học phần lý thuyết
string Xu_ly_chuoi(string s); // Hàm dùng để đưa chuỗi ký tự về đúng định dạng: In hoa chữ đầu và tất cả chữ còn lại in thường
//-------------------------------------------------------

// Hàm dùng để nhập thông tin liên quan đến môn học
void Nhap_monhoc_moi(Mon_hoc &mh){
    string temp1; // Khai báo một biến chuỗi để lưu các thành phần tín chỉ
    cout << "-----Nhap thong tin mon hoc-----" << endl; // Viết cái tiêu đề
    cout << "Nhap ten mon hoc: "; // Nhập tên môn học
    getline(cin, mh.name);
    cout << "Nhap so tin chi: "; // Nhập số chỉ của môn học đó
    cin >> mh.tc;
    cin.ignore(); // trước khi nhập một chuỗi thì xóa cái \n 
    cout << "Nhap loai hoc phan: "; // Nhập loại học phần đó: lý thuyết, thực hành, tích hợp
    getline(cin, mh.loai);

/*
    Trước khi nhập điểm ta cần hiểu với mỗi loại thành phần sẽ có một logic khác nhau
    Nếu môn đó là lý thuyết và có 2 chỉ => có 2 cột thường kì
    Nếu môn đó là lý thuyết và có 3 chỉ => có 3 cột thường kì 
    ... Đúng với n tín chỉ với môn lý thuyết
    Các môn thực hành hoặc tích hợp sẽ có cách tính điểm riêng tùy trường
*/      

    if(Xu_ly_chuoi(mh.loai) == "Ly thuyet"){
        mh.sclt = mh.tc; // Số cột thường kì lý thuyết ứng với số tín chỉ
        for(int i = 0; i < mh.sclt; i++){
            cout << "Nhap diem thuong ki " << i+1 << ": ";
            cin >> mh.lt[i];
        }
    }
    cout << "Nhap diem thi giua ki: ";
    cin >> mh.gk;
    cout << "Nhap diem thi cuoi ki: ";
    cin >> mh.ck;

}
// Hàm in ra thông tin của môn học
void In_thongtin_monhoc(Mon_hoc mh){
    // Cần một hàm xử lý chuỗi để đưa về dạng chuẩn nhất: viết hoa chữ đầu tiên và tất cả chữ còn lại viết thường
    cout << "Ten mon hoc: " << Xu_ly_chuoi(mh.name) << endl;
    cout << "Tin chi: " << mh.tc << endl;
    cout << "Loai hoc phan: " << Xu_ly_chuoi(mh.loai) << endl;
    // In ra cột điểm thường kì ứng với số tín chỉ
    for(int i = 0; i < mh.sclt; i++){
        cout << "Thuong ki " << i+1 << ": " << mh.lt[i] << endl;
    }
    cout << "Diem thi giua ki: " << mh.gk;
    cout << "Diem thi cuoi ki: " << mh.ck;
    cout << "Diem trung binh tong ket he 10: " << Tinh_diem_lythuyet();
}
// Hàm tính điểm trung bình đối với học phần lý thuyết
double Tinh_diem_lythuyet(double a, double b, double c){
    double dtb_lythuyet;
    dtb_lythuyet = a * 0.2 + b * 0.3 + c * 0.5;
    return dtb_lythuyet;
}
// Hàm dùng để đưa chuỗi ký tự về đúng định dạng: In hoa chữ đầu và các chữ còn lại in thường
string Xu_ly_chuoi(string s){
    if (!s.empty()) {
        s[0] = toupper(s[0]); // chỉ viết hoa ký tự đầu tiên
        for (size_t i = 1; i < s.length(); ++i) {
            s[i] = tolower(s[i]); // các ký tự còn lại viết thường
        }
    }
    return s;
}

//---------------------------------------------------------
int main(){
    Sinh_vien sv;
    Mon_hoc mh;
    cout << "Chuc nang: Them thong tin mon hoc moi" << endl;
    Nhap_monhoc_moi(mh);
    In_thongtin_monhoc(mh);

    return 0;
}
