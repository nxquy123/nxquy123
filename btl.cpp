#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;
struct quan_li
{
	char ma_hang[30];
	char ten_hang[30];
	char donvi_tinh[12];
	float don_gia;
	int so_luong;
	int thanh_tien ;
};
void nhapvao(quan_li hh[], int &n) 
{  
    cout << "\t\t\t\tNHAP DANH SACH MAT HANG \n";
    cout << " \t\t\t---------------------------------------\n";
    cout << "\tNhap so mat hang muon them vao danh sach : ";cin >> n;
    cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t+) Nhap Thong Tin Mat Hang Thu " << i + 1 << "\n";
		cin.ignore();
		cout << "\t   Nhap Ma Mat Hang : ";
		cin.getline(hh[i].ma_hang, 30);
		cout << "\t   Nhap Ten Hang Hoa : ";
		cin.getline(hh[i].ten_hang, 30);
		cout << "\t   Nhap don vi tinh : ";
		cin.getline(hh[i].donvi_tinh, 12);
		cout << "\t   Nhap don gia : ";
		cin >> hh[i].don_gia;
		cout << "\t   Nhap so luong : ";
		cin >> hh[i].so_luong;
		cout << endl;
     }
}
void tieude()
{
	cout << "\t\t+=====================================================================================+\n";
    cout << "\t\t|"<< setw(15)<< left << "Ma Mat Hang"<< "|"
		 << setw(15)<< left << "Ten mat Hang"<< "|"
		 << setw(15)<< left << "Don vi tinh" << "|"
		 << setw(10)<< left << "Don gia" << "|"
		 << setw(10)<< left << "So luong"<<"|"
		 << setw(15)<< left << "Thanh Tien"<<"|"<<endl;
	cout << "\t\t+=====================================================================================+";
}
void xuat_thong_tin_vua_nhap(quan_li hh[],int n)
{
	tieude();
	for(int i=0;i<n;i++)
	{
		hh[i].thanh_tien=hh[i].don_gia*hh[i].so_luong;
		cout <<endl;
		cout << "\t\t|"<< setw(15) << hh[i].ma_hang << "|"
		           << setw(15) << hh[i].ten_hang << "|"
		           << setw(15) << hh[i].donvi_tinh<< "|"
		           << setw(10) << hh[i].don_gia<< "|"
		           << setw(10) << hh[i].so_luong<< "|"
	               << setw(15) << hh[i].thanh_tien<<"|";
	}
	cout << "\n\t\t+=====================================================================================+\n";
	
}
void sap_xep_tang ( quan_li hh[], int n)
{
	for( int i = 0 ; i<n ; i++)
	{
		for (int j = i+1 ; j<n ; j++)
		{
			if (hh[i].so_luong > hh[j].so_luong)
			{
				quan_li tg=hh[i];
				hh[i]=hh[j];
				hh[j]=tg;
			}
		}
	}
}
void sap_xep_giam ( quan_li hh[], int n)
{
	for( int i = 0 ; i<n ; i++)
	{
		for (int j = i+1 ; j<n ; j++)
		{
			if (hh[i].thanh_tien < hh[j].thanh_tien)
			{
				quan_li tg=hh[i];
				hh[i]=hh[j];
				hh[j]=tg;
			}
		}
	}
}
void them(quan_li hh[],int &n)
{
  	quan_li hh1;
  	cin.ignore();
  	    cout<<"\n\t+) Nhap ma san pham : ";cin.getline(hh1.ma_hang,30);
		cout<<"\n\t+) Nhap ten san pham : ";cin.getline(hh1.ten_hang,30);
		cout<<"\n\t+) Nhap don vi tinh : ";cin.getline(hh1.donvi_tinh,12);
		cout<<"\n\t+) Nhap don gia : ";cin>>hh1.don_gia;
		cout<<"\n\t+) Nhap so luong : ";cin>>hh1.so_luong;
   
  	n++;
    hh[n-1]=hh1;
    cout<<"\n\t\t\t       Danh sach thong tin san pham moi sau khi them thong tin vao\n";
    sap_xep_tang(hh,n);
	xuat_thong_tin_vua_nhap(hh,n);
}
void xoa_don_vi_tinh(quan_li hh[], int &n)
{
	char s[12];
	cin.ignore();
	cout<<"\n\tNhap don vi tinh muon xoa : ";cin.getline(s,12);
	cout << endl;
	cout << "\t\t\t\t\tBang Sau Khi Xoa Don Vi Tinh La \n";
	int vitri=0 , x=0;
	for(int i = 0 ; i <= n ; i++)
	if(strcmpi(hh[i].donvi_tinh,s)==0)
	{
		vitri=i;
		x++;
		break;
	}
	if(x==0)
	{
		cout<<"\n---Don vi tinh khong ton tai!---";
	}
	else
	{
		for(int i =  vitri ; i<n ; i++)
		{
			hh[i]=hh[i+1];
		}
		n--;
	    sap_xep_tang(hh,n);
	    xuat_thong_tin_vua_nhap(hh,n);
	}
}
void Luu_file(quan_li hh[],int n)
{
	ofstream luu;
	luu.open("C:\\Users\\Admin\\OneDrive\\Desktop\\product.dat",ios::out);
	if(!luu)
	{
		cout<<"Khong the luu tep tin!";
		exit(1);

	}
	luu << "\t\t+=====================================================================================+\n";
	luu << "\t\t|"
		<< setw(15)<< left << "Ma Mat Hang"<< "|"
		<< setw(15)<< left << "Ten mat Hang"<< "|"
		<< setw(15)<< left << "Don vi tinh" << "|"
		<< setw(10)<< left << "Don gia" << "|"
		<< setw(10)<< left << "So luong"<<"|"
		<< setw(15)<< left << "Thanh Tien"<<"|"<<endl;
	luu << "\t\t+=====================================================================================+";
	for(int i=0;i<n;i++)
	{
		hh[i].thanh_tien=hh[i].don_gia*hh[i].so_luong;
		luu <<endl;
		luu << "\t\t|"
		<< setw(15) << hh[i].ma_hang << "|"
		<< setw(15) << hh[i].ten_hang << "|"
		<< setw(15) << hh[i].donvi_tinh<< "|"
		<< setw(10) << hh[i].don_gia<< "|"
		<< setw(10) << hh[i].so_luong<< "|"
	    << setw(15) << hh[i].thanh_tien<<"|";
	}
	luu << "\n\t\t+=====================================================================================+\n";
	cout<<"\n\t\t\t\t\t* DA LUU TEP THANH CONG *";
	luu.close();
	
}
void in_ra (quan_li hh[],int n)
{
	ifstream in;
	in.open("C:\\Users\\Admin\\OneDrive\\Desktop\\product.dat",ios::in);
	if(!in)
	{
		cout<<"[!]Khong the doc tep tin!";
		exit(1);
	}
	in>>n;
	for(int i =  0 ; i<n ; i++)
	{
		in>>hh[i].ma_hang;
		in>>hh[i].ten_hang;
		in>>hh[i].donvi_tinh;
		in>>hh[i].don_gia;
		in>>hh[i].so_luong;
	}
	cout<<"\n\t\t\t\t\t* XUAT CHUONG TRINH DA DOC *";
	cout << endl;
	xuat_thong_tin_vua_nhap(hh,n);
	in.close();
}
void Menu ()
{
	cout<<"\n\t+-----------------------------------MENU----------------------------------+";
	cout<<"\n\t|            +++ HAY LUA CHON CHUC NANG BAN MUON THUC HIEN +++            |";
	cout<<"\n\t+-------------------------------------------------------------------------+";
	cout<<"\n\t|         1.Nhap thong tin cac mat hang tu ban phim                       |";
	cout<<"\n\t|         2.In danh sach thong tin cac mat hang                           |";
	cout<<"\n\t|         3.Sap xep cac mat hang theo thu tu tang dan ve so luong va in ra|";
	cout<<"\n\t|         4.In thong tin mat hang co thanh tien lon nhat                  |";
	cout<<"\n\t|         5.Them thong tin mat hang vao danh sach va in ra                |";
    cout<<"\n\t|         6.Xoa mat hang khoi danh sach                                   |";
    cout<<"\n\t|         7.Luu danh sach mat hang                                        |";
    cout<<"\n\t|         8.Doc ket qua da luu                                            |";
    cout<<"\n\t|         9.Exit - ket thuc -                                             |";
	cout<<"\n\t+-------------------------------------------------------------------------+";
}
int main()
{
	    int n;
	    int cn;
		quan_li hh[100];
//	Menu(); //hien thi menu 1 lan
     	do{
		 Menu();
     	cout << "\n\n\tHAY LUA CHON CAC CHUC NANG TU 1--->10 : "; 
     	cin >> cn;
     	cout<< endl;
     	switch(cn)
    {
    	case 1:
    	{
	    	nhapvao(hh,n);
            break;
	    }
    	case 2:
	    {
                cout << "\t\t\t\t\t\t   DANH SACH MAT HANG LA \n";
    		    xuat_thong_tin_vua_nhap(hh,n);
    		    break;
    	}
    	case 3:
   		        cout << "\t\t\t\t\t   Danh Sach Sau Khi Xap Xep Tang La\n";
		        sap_xep_tang(hh,n);
		        xuat_thong_tin_vua_nhap(hh,n);
    		    break;
        case 4:
        {
        	    cout << "\t\t\t\t\tDanh Sach Mat Hang Co Thanh Tien Lon Nhat La\n";
		        sap_xep_giam(hh,n);
		        xuat_thong_tin_vua_nhap(hh,1);
    		    break;
        }
	    case 5:
        {
        	    cout << "\tThem Vao Danh Sach Mat Hang ";
        	    them(hh,n);
    		   break;
        }
	    case 6:
		{
			    xoa_don_vi_tinh(hh,n);
    		   break;
		}
		case 7:
		{
			    Luu_file(hh,n);
    		   break;
		}
		case 8:
		{
			    in_ra(hh,n);
    		    break;
		}
		case 9:
		{
			cout<<"\n\t\t\t\t\t\t\t#####\t BAN DA KET THUC CHUONG TRINH \t##### ";
			break;
		}
		default:
		{
			cout<<" Chuc nang khong co trong danh muc . Vui long nhap lai!";
			break;
		}
    }
}    while(cn);
    getche ();
    return 0;
}
