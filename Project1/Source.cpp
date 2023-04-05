#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>
using namespace std;
#define MAX 100
struct Students
{
    string ID;
    string firstName;
    string lastName;
    double midtermMark;
    double finalMark;
};
void ReadData(Students students[], int &n) // đọc file 
{
    ifstream inData;
    inData.open("input.txt");
    string s;
    int dem = 0;
    if (inData.is_open())
    {
        while (!inData.eof())
        {
            getline(inData, s);
            if (s == "")
                break;
            dem++;
        }
        n = dem;
        inData.close();
        inData.open("input.txt");
        if (inData.is_open())
        {
            for (int i = 0; i < n; i++)
            {
                getline(inData, students[i].ID, '-');
                getline(inData, students[i].lastName, '-');
                getline(inData, students[i].firstName, '-');
                inData >> students[i].midtermMark;
                inData.ignore();
                inData >> students[i].finalMark;
                inData.ignore();
            }
            cout << "Doc file thanh cong\n";
            inData.close();
        } 
    }
    else cout << "Doc file khong thanh cong\n";
}
void WriteFile(Students students[], int n) // ghi file 
{
    ofstream outData;
    outData.open("text.txt");
    if (outData.is_open())
    {
        for (int i = 0; i < n; i++)
            outData << students[i].ID << "-" << students[i].lastName << "-" << students[i].firstName
            << "-" << students[i].midtermMark << "-" << students[i].finalMark << endl;
        outData.close();
    }
    else cout << "Ghi file khong thanh cong\n";
}
void AddOneStudents(Students& students) // thêm 1 học sinh
{
    cin.ignore();
    cout << "Nhap mssv\n";
    getline(cin, students.ID);
    cout << "Nhap ho va ten lot\n";
    getline(cin, students.lastName);
    cout << "Nhap ten \n";
    getline(cin, students.firstName);
    cout << "Nhap diem thu 1\n";
    cin >> students.midtermMark;
    cout << "Nhap diem thu 2\n";
    cin >> students.finalMark;
}
void OutPutStudents(Students students)
{
    cout << "MSSV: " << students.ID << endl;
    cout << "Ho va ten lot : " << students.lastName << endl;
    cout << "Ten: " << students.firstName << endl;
    cout << "Diem so 1: " << students.midtermMark << endl;
    cout << "Diem so 2:" << students.finalMark << endl;
}
void OutPut(Students students[], int n)
{
    for (int i = 0; i < n; i++)
        OutPutStudents(students[i]);
}
void OutPutMSSV(Students students[], int n, string mssv)
{
    for (int i = 0; i < n; i++)
        if (students[i].ID==mssv)
        {
            OutPutStudents(students[i]);
            break;
        }
}
void Add(Students students[], int& n)
{
    AddOneStudents(students[n]);
    n++;
    for (int i = 0; i < n-1; i++)
        if (students[i].ID == students[n].ID)
            return;
    WriteFile(students, n);
}
void Deletes(Students students[], int &n, int vitri)
{
    for (int i = vitri; i < n; i++)
        students[i] = students[i + 1];
    n--;
}
void DeleteStudents(Students students[], int &n, string mssv)
{
    for (int i = 0; i < n; i++)
        if (students[i].ID==mssv)
        {
            Deletes(students, n, i);
            i--;
        }
    WriteFile(students, n);
}
void HeightNames(Students students[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (students[i].firstName > students[j].firstName)
                swap(students[i], students[j]);
    }
}
void SortDownByPoints(Students students[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if ((students[i].midtermMark + students[i].finalMark) / 2 < (students[j].midtermMark + students[j].finalMark) / 2)
                swap(students[i], students[j]);
    }
}
void Passes(Students students[], int n)
{
    cout << "Danh sach sinh vien dau\n";
    for (int i = 0; i < n; i++)
    {
        if ((students[i].midtermMark + students[i].finalMark) / 2 >= 5)
        {
            OutPutStudents(students[i]);
            cout << "==================\n";
        }
    }
}
void Fail(Students students[], int n)
{
    cout << "Danh sach sinh vien rot \n";
    for (int i = 0; i < n; i++)
    {
        if ((students[i].midtermMark + students[i].finalMark) / 2 < 5)
        {
            OutPutStudents(students[i]);
            cout << "==================\n";
        }
    }

}
int main()
{
    bool in = false;
    int n ;
    Students students[MAX];
    string mssv;
    string mssv1;
    string mssv2;
    int chon;
    do {
        system("cls");
        cout << "\t\tMenu\n";
        cout << "1:Doc file \n";
        cout << "2:Xuat thong tin toan bo sinh vien\n";
        cout << "3:Tim va in thong tin ma so sinh vien\n";
        cout << "4:Them mot danh sach vao sinh vien\n";
        cout << "5:Xoa sinh vien\n";
        cout << "6:In danh sach sinh vien theo ten tang dan\n";
        cout << "7:In danh sach sinh vien theo diem trung binh giam dan\n";
        cout << "8:In danh sach sinh vien dau\n";
        cout << "9:In danh sach sinh vien rot\n";
        cout << "10:Exit\n";
        cout << "=======================\n";
        cout << "Moi ban chon chuc nang \n";
        cin >> chon;
        switch (chon)
        {
        case 1:
            ReadData(students, n);
            in = true;
            break;
        case 2:
            if (in)
                OutPut(students, n);
            else cout << "Khong co du lieu\n";
            break;
        case 3:
            if (in)
            {
                cin.ignore();
                cout << "Nhap ma so sinh vien ban muon xuat thong tin\n";
                getline(cin, mssv);
                OutPutMSSV(students, n, mssv);
            }
            else cout << "Khong co du lieu\n";
            break;
        case 4:
            if (in)
                Add(students, n);
            else cout << "Khong co du lieu\n";
            break;
        case 5:
            if (in)
            {
                cin.ignore();
                cout << "Nhap mssv ban muon xoa\n";
                getline(cin, mssv2);
                DeleteStudents(students, n, mssv2);
            }
            else cout << "Khong co du lieu\n";
            break;
        case 6:
            if (in)
            {
                HeightNames(students, n);
                cout << "Vui long bam so 2 de xem ket qua \n";
            }
            else cout << "Khong co du lieu\n";
            break;
        case 7:
            if (in)
            {
                SortDownByPoints(students, n);
                cout << "Vui long bam so 2 de xem ket qua \n";
            }
            else cout << "Khong co du lieu\n";
            break;
        case 8:
            if (in)
                Passes(students, n);
            else cout << "Khong co du lieu\n";
            break;
        case 9:
            if (in)
                Fail(students, n);
            else cout << "Khong co du lieu\n";
            break;
        case 10:
            break;
        default:
            cout << "Khong co chuc nang tren\n";
            break;
        }
        _getch();
    } while (chon > 0 && chon < 10);
    return 0;
}