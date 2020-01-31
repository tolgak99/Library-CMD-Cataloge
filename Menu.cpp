#include <iostream>
#include "Menu.h"
#include "Users.h"
#include "User.h"
#include "Admin.h"

using namespace std;

void Menu::show_menu(){

	int choice=0,choice_gamemode,choice_admin,choice_find;
	string name,pass;
	User user;
	Admin admin;

	mkdir("c:/LibraryProject");                                              // Create Folders
	mkdir("c:/LibraryProject/Books");
	mkdir("c:/LibraryProject/Authors");
	mkdir("c:/LibraryProject/Years");
	mkdir("c:/LibraryProject/Companies");                       
	mkdir("c:/LibraryProject/Accounts");                                 // End of create folders. 


	ifstream AdminPassword ("c:\\LibraryProject\\AdminPass.txt");         // Check Admin Password exist.

	if (admin.is_empty(AdminPassword)){
		ofstream AdminPass ("c:\\LibraryProject\\AdminPass.txt");
		AdminPass << "admin" <<endl;
		AdminPass.close();
	}

	AdminPassword.close();                                                // End of check Admin Password.


	while(true){    // Menu while
		rlutil::showcursor();
		int choose=0,key;
		rlutil::hidecursor();
		rlutil::cls();
		rlutil::setColor(3);
		rlutil::locate(50, 10); cout << "Kullanici Girisi" << endl;
		rlutil::setColor(3);
		rlutil::locate(50, 12); cout << "Admin Girisi" << endl;
		rlutil::setColor(3);
		rlutil::locate(50, 14); cout << "Cikis" << endl;
		rlutil::setColor(2);
		rlutil::locate(30, 24);
		cout << "Yon tuslari ile hareket edebilirsiniz. Enter Tusu ile secim yapabilirsiniz." << endl;
		rlutil::setColor(7);
		while (true) {  // Main menu while
			key = rlutil::getkey();
			if(key == rlutil::KEY_DOWN){ // Move in main menu
				choose +=1;
			}
			else if(key==rlutil::KEY_UP){ // Move in main menu
				choose -=1;
			}
			if(key==rlutil::KEY_ENTER){ // Choose the selection
				choice==choose;
				rlutil::cls();
				break;

			}


			if(choose==1){ // If choose is Kullanıcı Girişi set background
				rlutil::setColor(3);
				rlutil::setBackgroundColor(4);
				rlutil::locate(50, 10);  cout << "Kullanici Girisi";
				rlutil::setColor(3);
				rlutil::setBackgroundColor(0);
				rlutil::locate(50, 12);  cout << "Admin Girisi";
				rlutil::setColor(3);
				rlutil::setBackgroundColor(0);
				rlutil::locate(50, 14);  cout << "Cikis";
				rlutil::setBackgroundColor(0);
			}
			if(choose==2){ // If choose is Admin Girişi set background
				rlutil::setColor(3);
				rlutil::setBackgroundColor(0);
				rlutil::locate(50, 10);  cout << "Kullanici Girisi";
				rlutil::setColor(3);
				rlutil::setBackgroundColor(4);
				rlutil::locate(50, 12);  cout << "Admin Girisi";
				rlutil::setColor(3);
				rlutil::setBackgroundColor(0);
				rlutil::locate(50, 14);  cout << "Cikis";
				rlutil::setBackgroundColor(0);
			}
			if(choose==3){  // If choose is Çıkış set background
				rlutil::setColor(3);
				rlutil::setBackgroundColor(0);
				rlutil::locate(50, 10);  cout << "Kullanici Girisi";
				rlutil::setColor(3);
				rlutil::setBackgroundColor(0);
				rlutil::locate(50, 12);  cout << "Admin Girisi";
				rlutil::setColor(3);
				rlutil::setBackgroundColor(4);
				rlutil::locate(50, 14);  cout << "Cikis";
				rlutil::setBackgroundColor(0);
			}
			if(choose<=0)  // If user try to go down or up in menu set choose 
				choose=1;
			if(choose>3)
				choose=3;

			choice=choose;

		}//End of Main menu while-loop.




		if(choice == 1){  // If user select Kullanıcı Girişi , select Others                                       Kullanıcı Girişi

			rlutil::setColor(3);
			rlutil::locate(50,10);
			cout << "Yeni Profil" << endl;
			rlutil::setColor(3);
			rlutil::locate(50,12);
			cout << "Profili Guncelle" << endl;
			rlutil::setColor(3);
			rlutil::locate(50,14);
			cout << "Kitap Bul" << endl;
			choose=0;
			rlutil::setColor(2);
			rlutil::locate(70,25);
			cout << "Ana Menuye donmek icin ESC basiniz."<<endl;
			rlutil::setColor(7);
			while (true) { // Others while
				key = rlutil::getkey();
				if(key == rlutil::KEY_DOWN){  // Move in Kullanıcı Girişi menu
					choose +=1;
				}
				else if(key==rlutil::KEY_UP){  // Move in Kullanıcı Girişi menu
					choose -=1;
				}
				if(key==rlutil::KEY_ENTER){  // Choose  in the Kullanıcı Girişi
					choice_gamemode==choose;
					rlutil::setColor(7);
					break;
				}  
				if(key==rlutil::KEY_ESCAPE){
					show_menu();
				}



				if(choose==1){ //If user's choose is Yeni Profil
					rlutil::setBackgroundColor(4);
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Yeni Profil" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Profili Guncelle" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Kitap Bul" << endl;
					rlutil::setBackgroundColor(0);
				} // End of gamemode 1 if

				else if(choose==2){  // If user's choose is Profili Güncelle
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Yeni Profil" << endl;
					rlutil::setBackgroundColor(4);
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Profili Guncelle" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Kitap Bul" << endl;	 
					rlutil::setBackgroundColor(0);
				} // end of gamemode2 if

				else if(choose==3){  // If user's choose is Kitap Bul
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Yeni Profil" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Profili Guncelle" << endl;
					rlutil::setBackgroundColor(4);
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Kitap Bul" << endl;	 
					rlutil::setBackgroundColor(0);
				} // end of gamemode2 if

				if(choose<=0)   // If user try to go down or up in menu set choose 
					choose=1;   
				if(choose>3)    
					choose=3;

				choice_gamemode=choose;  // Set user's choose to gamemode

			}//End of Gamemode while-loop.
			if (choice_gamemode == 1) { //Yeni Profil
				rlutil::cls();
				rlutil::locate(50,12);
				cout << "Kullanici Adi: ";
				cin >>  name;
				rlutil::locate(50,14);
				cout << "Sifre: ";
				cin>>pass;

				while(!user.check_username(name)){
					rlutil::locate(50,18);
					cout << "Kullanici adi onceden alinmis." << endl;
					rlutil::msleep(1000);
					rlutil::cls();
					rlutil::locate(50,12);
					cout << "Kullanici Adi: ";
					cin >>  name;
					rlutil::locate(50,14);
					cout << "Sifre: ";
					cin>>pass;
				}

				user.set_username(name);
				user.set_password(pass);
				user.open_file();
				rlutil::locate(50,20);
				cout << "Hesabiniz Olusturuldu." ; 
				rlutil::msleep(2000);



			} // End of Gamemode 1
			else if (choice_gamemode == 2) {  // Profili Güncelle
				rlutil::cls();
				rlutil::locate(50,12);
				cout << "Kullanici Adi: ";
				if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock ON!";
					rlutil::setColor(7);
				}
				else{
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock OFF!";
					rlutil::setColor(7);
				}
				rlutil::locate(65,12);
				cin >> name;
				rlutil::locate(50,14);
				cout << "Sifre: ";
				if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock ON!";
					rlutil::setColor(7);
				}
				else{
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock OFF!";
					rlutil::setColor(7);
				}
				rlutil::locate(60,14);
				cin >> pass;
				if(user.check_profile(name,pass)){
					rlutil::cls();
					remove(name.c_str());
					rlutil::locate(50,12);
					cout << "Yeni Kullanici Adi: ";
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock ON!";
						rlutil::setColor(7);
					}
					else{
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock OFF!";
						rlutil::setColor(7);
					}
					rlutil::locate(65,12);
					cin >> name;
					rlutil::locate(50,14);
					cout << "Yeni Sifre: ";
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock ON!";
						rlutil::setColor(7);
					}
					else{
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock OFF!";
						rlutil::setColor(7);
					}
					rlutil::locate(60,14);
					cin >> pass;
					user.update_profile(name,pass);
				}

			}// End of Gamemode 2

			else if (choice_gamemode == 3) {  // Kitap Bul
				string account_username , account_password ;

				rlutil::cls();
				rlutil::locate(50,12);
				cout << "Kullanici adi: ";
				if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock ON!";
					rlutil::setColor(7);
				}
				else{
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock OFF!";
					rlutil::setColor(7);
				}
				rlutil::locate(65,12);
				cin >> account_username;
				rlutil::locate(50,14);
				cout << "Sifre: " ;
				if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock ON!";
					rlutil::setColor(7);
				}
				else{
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock OFF!";
					rlutil::setColor(7);
				}
				rlutil::locate(60,14);
				cin >> account_password;
				while(user.check_profile(account_username , account_password)){
					rlutil::cls();
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Kitap Ismine Gore" << endl;
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Kitap Yazarina Gore" << endl;
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Kitap Yilina Gore" << endl;
					rlutil::setColor(3);
					rlutil::locate(50,16);
					cout << "Basim Sirketine Gore" << endl;
					choose=0;
					rlutil::setColor(2);
					rlutil::locate(70,25);
					cout << "Ana Menuye donmek icin ESC basiniz."<<endl;
					rlutil::setColor(7);

					while (true) { // Others while
						key = rlutil::getkey();
						if(key == rlutil::KEY_DOWN){  // Move in Gamemode menu
							choose +=1;
						}
						else if(key==rlutil::KEY_UP){  // Move in Gamemode menu
							choose -=1;
						}
						if(key==rlutil::KEY_ENTER){  // Choose the gamemode
							choice_find==choose;
							rlutil::setColor(7);
							break;
						}  
						if(key==rlutil::KEY_ESCAPE){
							show_menu();
						}



						if(choose==1){ //If user's choose is Kitap ismine Göre
							rlutil::setBackgroundColor(4);
							rlutil::setColor(3);
							rlutil::locate(50,10);
							cout << "Kitap Ismine Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,12);
							cout << "Kitap Yazarina Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,14);
							cout << "Kitap Yilina Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,16);
							cout << "Basim Sirketine Gore" << endl;
							rlutil::setBackgroundColor(0);
						} // End of gamemode 1 if

						else if(choose==2){  // If user's choose is Profili Güncelle
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,10);
							cout << "Kitap Ismine Gore" << endl;
							rlutil::setBackgroundColor(4);
							rlutil::setColor(3);
							rlutil::locate(50,12);
							cout << "Kitap Yazarina Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,14);
							cout << "Kitap Yilina Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,16);
							cout << "Basim Sirketine Gore" << endl;
							rlutil::setBackgroundColor(0);
						} // end of gamemode2 if

						else if(choose==3){  // If user's choose is Kitap Bul
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,10);
							cout << "Kitap Ismine Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,12);
							cout << "Kitap Yazarina Gore" << endl;
							rlutil::setBackgroundColor(4);
							rlutil::setColor(3);
							rlutil::locate(50,14);
							cout << "Kitap Yilina Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,16);
							cout << "Basim Sirketine Gore" << endl;
							rlutil::setBackgroundColor(0);
						} // end of gamemode2 if

						else if(choose==4){  // If user's choose is Kitap Bul
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,10);
							cout << "Kitap Ismine Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,12);
							cout << "Kitap Yazarina Gore" << endl;
							rlutil::setBackgroundColor(0);
							rlutil::setColor(3);
							rlutil::locate(50,14);
							cout << "Kitap Yilina Gore" << endl;
							rlutil::setBackgroundColor(4);
							rlutil::setColor(3);
							rlutil::locate(50,16);
							cout << "Basim Sirketine Gore" << endl;
							rlutil::setBackgroundColor(0);
						} // end of gamemode2 if

						if(choose<=0)   // If user try to go down or up in menu set choose 
							choose=1;   
						if(choose>4)     
							choose=4;

						choice_find=choose;  // Set user's choose to arama kriteri

					}//End of Gamemode while-loop.
					if (choice_find == 1) {                                                                                        //Kitap ismine göre
						string name_of_book,name_of_book2;
						rlutil::cls();
						rlutil::locate(50,10);
						cout << "Kitabin Ismi: ";
						if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "Caps Lock ON!";
							rlutil::setColor(7);
						}
						else{
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "Caps Lock OFF!";
							rlutil::setColor(7);
						}
						cin.ignore();
						rlutil::locate(65,10);
						getline(cin, name_of_book);
						rlutil::cls();
						user.search_by_name(name_of_book,name_of_book2);
						rlutil::locate(70,25);
						cout << "Menuye donmek icin bir tusa basin.";
						rlutil::getkey();
					} // End of Kitap İsmine Göre


					else if (choice_find == 2) {                                                                                   // Kitap yazarına göre
						string name_of_author,name_of_author2;
						rlutil::cls();
						rlutil::locate(50,10);
						cout << "Yazarin Ismi: ";
						if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "Caps Lock ON!";
							rlutil::setColor(7);
						}
						else{
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "Caps Lock OFF!";
							rlutil::setColor(7);
						}
						cin.ignore();
						rlutil::locate(65,10);
						getline(cin, name_of_author);
						rlutil::cls();
						user.search_by_author(name_of_author,name_of_author2);
						rlutil::locate(70,25);
						cout << "Menuye donmek icin bir tusa basin.";
						rlutil::getkey();


					}// End of Kitap Yazarına Göre

					else if (choice_find == 3) {                                                                                   // Kitap yılına göre

						string year_of_book; 
						rlutil::cls();
						rlutil::locate(50,10);
						cout << "Kitabin Yili: ";
						if ((GetKeyState(VK_NUMLOCK) & 0x0001)!=0){
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "NUM Lock ON!";
							rlutil::setColor(7);
						}
						else{
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "NUM Lock OFF!";
							rlutil::setColor(7);
						}
						cin.ignore();
						rlutil::locate(65,10);
						getline(cin, year_of_book);
						rlutil::cls();
						user.search_by_year(year_of_book);
						rlutil::locate(70,25);
						cout << "Menuye donmek icin bir tusa basin.";
						rlutil::getkey();

					}// End of Kitap Yılına Göre

					else if (choice_find == 4) {                                                                                   // Basım şirketine göre

						string company_of_book;
						rlutil::cls();
						rlutil::locate(50,10);
						cout << "Kitabin Basim Sirketi: ";
						if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "Caps Lock ON!";
							rlutil::setColor(7);
						}
						else{
							rlutil::setColor(5);
							rlutil::locate(80,25);
							cout << "Caps Lock OFF!";
							rlutil::setColor(7);
						}
						cin.ignore();
						rlutil::locate(65,10);
						getline(cin, company_of_book);
						rlutil::cls();
						user.search_by_company(company_of_book);
						rlutil::locate(70,25);
						cout << "Menuye donmek icin bir tusa basin.";
						rlutil::getkey();



					}// End of Basım Şirketine Göre



				}
				rlutil::cls();
				rlutil::locate(50,12);
				cout << "Lutfen Hesap Olusturun!" <<endl;
				rlutil::locate(60,25);
				rlutil::setColor(2);
				cout << "Hesabiniz zaten varsa sifrenizi kontrol ediniz!" <<endl;
				rlutil::setColor(7);
				rlutil::msleep(2000);
			}// End of Kitap Bul
		} // End of Choose Gamemode 


		else if(choice==2){  //                                                                              Admin girişi 
			string adminpass;
			rlutil::cls();
			rlutil::locate(50,12);
			cout << "Admin Sifresi: ";
			if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
				rlutil::setColor(5);
				rlutil::locate(80,25);
				cout << "Caps Lock ON!";
				rlutil::setColor(7);
			}
			else{
				rlutil::setColor(5);
				rlutil::locate(80,25);
				cout << "Caps Lock OFF!";
				rlutil::setColor(7);
			}
			rlutil::locate(65,12);
			cin >> adminpass;
			while(!admin.check_password(adminpass)){  // Wrong password while
				rlutil::cls();
				rlutil::locate(50,14);
				cout << "Sifre Yanlis!"<<endl;
				rlutil::setColor(4);
				rlutil::locate(50,25);
				cout << "Yeniden dnemek icin ENTER , Ana menu icin ESC ye basiniz.";
				rlutil::setColor(7);
				if(rlutil::getkey() == rlutil::KEY_ESCAPE)
					show_menu();
				
				rlutil::cls();
				rlutil::locate(50,12);
				cout << "Admin Sifresi: ";
				if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock ON!";
					rlutil::setColor(7);
				}
				else{
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock OFF!";
					rlutil::setColor(7);
				}
				rlutil::locate(65,12);
				cin >> adminpass;
				
			} // End of wrong password while

			rlutil::cls();
			rlutil::setColor(3);
			rlutil::locate(50,10);
			cout << "Kitap Ekle" << endl;
			rlutil::setColor(3);
			rlutil::locate(50,12);
			cout << "Kitap Bul" << endl;
			rlutil::setColor(3);
			rlutil::locate(50,14);
			cout << "Sifre Degistir" << endl;
			choose=0;
			rlutil::setColor(2);
			rlutil::locate(70,25);
			cout << "Ana Menuye donmek icin ESC basiniz."<<endl;
			rlutil::setColor(7);
			while (true) { // Others while
				key = rlutil::getkey();
				if(key == rlutil::KEY_DOWN){  // Move in Gamemode menu
					choose +=1;
				}
				else if(key==rlutil::KEY_UP){  // Move in Gamemode menu
					choose -=1;
				}
				if(key==rlutil::KEY_ENTER){  // Choose the gamemode
					choice_admin==choose;
					rlutil::setColor(7);
					break;
				}  
				if(key==rlutil::KEY_ESCAPE){
					show_menu();
				}

				if(choose==1){ //If user's choose is Yeni Profil
					rlutil::setBackgroundColor(4);
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Kitap Ekle" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Kitap Bul" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Sifre Degistir" << endl;
					rlutil::setBackgroundColor(0);
				} // End of gamemode 1 if

				else if(choose==2){  // If user's choose is Profili Güncelle
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Kitap Ekle" << endl;
					rlutil::setBackgroundColor(4);
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Kitap Bul" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Sifre Degistir" << endl;	 
					rlutil::setBackgroundColor(0);
				} // end of gamemode2 if

				else if(choose==3){  // If user's choose is Kitap Bul
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,10);
					cout << "Kitap Ekle" << endl;
					rlutil::setBackgroundColor(0);
					rlutil::setColor(3);
					rlutil::locate(50,12);
					cout << "Kitap Bul" << endl;
					rlutil::setBackgroundColor(4);
					rlutil::setColor(3);
					rlutil::locate(50,14);
					cout << "Sifre Degistir" << endl;	 
					rlutil::setBackgroundColor(0);
				} // end of gamemode2 if

				if(choose<=0)   // If user try to go down or up in menu set choose 
					choose=1;   
				if(choose>3)     
					choose=3;

				choice_admin=choose;  // Set user's choose to gamemode

			}//End of Gamemode while-loop.
			if (choice_admin == 1) {                                                                                        //Kitap Ekle
				string name,sur,author,author2,year,com;
				rlutil::cls();
				rlutil::locate(50,10);
				cin.ignore();
				cout << "Kitap İsmi: ";
				getline(cin, name);
				rlutil::locate(50,12);
				cout << "Yazar adi: ";
				getline(cin, author);
				rlutil::locate(50,14);
				cout << "Kitap Yili: " ;
				getline(cin, year);
				rlutil::locate(50,16);
				cout << "Basim Firmasi: " ;
				getline(cin, com);

				admin.add_book(name,sur,author,author2,year,com);

			} // End of Gamemode 1


			else if (choice_admin == 2) {                                                                                   // Kitap Bul

				rlutil::cls();
				rlutil::setColor(3);
				rlutil::locate(50,10);
				cout << "Kitap Ismine Gore" << endl;
				rlutil::setColor(3);
				rlutil::locate(50,12);
				cout << "Kitap Yazarina Gore" << endl;
				rlutil::setColor(3);
				rlutil::locate(50,14);
				cout << "Kitap Yilina Gore" << endl;
				rlutil::setColor(3);
				rlutil::locate(50,16);
				cout << "Basim Sirketine Gore" << endl;
				choose=0;
				rlutil::setColor(2);
				rlutil::locate(70,25);
				cout << "Ana Menuye donmek icin ESC basiniz."<<endl;
				rlutil::setColor(7);
				while (true) { // Others while
					key = rlutil::getkey();
					if(key == rlutil::KEY_DOWN){  // Move in Gamemode menu
						choose +=1;
					}
					else if(key==rlutil::KEY_UP){  // Move in Gamemode menu
						choose -=1;
					}
					if(key==rlutil::KEY_ENTER){  // Choose the gamemode
						choice_find==choose;
						rlutil::setColor(7);
						break;
					}  
					if(key==rlutil::KEY_ESCAPE){
						show_menu();
					}

					if(choose==1){ //If user's choose is Kitap ismine Göre
						rlutil::setBackgroundColor(4);
						rlutil::setColor(3);
						rlutil::locate(50,10);
						cout << "Kitap Ismine Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,12);
						cout << "Kitap Yazarina Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,14);
						cout << "Kitap Yilina Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,16);
						cout << "Basim Sirketine Gore" << endl;
						rlutil::setBackgroundColor(0);
					} // End of gamemode 1 if

					else if(choose==2){  // If user's choose is Profili Güncelle
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,10);
						cout << "Kitap Ismine Gore" << endl;
						rlutil::setBackgroundColor(4);
						rlutil::setColor(3);
						rlutil::locate(50,12);
						cout << "Kitap Yazarina Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,14);
						cout << "Kitap Yilina Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,16);
						cout << "Basim Sirketine Gore" << endl;
						rlutil::setBackgroundColor(0);
					} // end of gamemode2 if

					else if(choose==3){  // If user's choose is Kitap Bul
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,10);
						cout << "Kitap Ismine Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,12);
						cout << "Kitap Yazarina Gore" << endl;
						rlutil::setBackgroundColor(4);
						rlutil::setColor(3);
						rlutil::locate(50,14);
						cout << "Kitap Yilina Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,16);
						cout << "Basim Sirketine Gore" << endl;
						rlutil::setBackgroundColor(0);
					} // end of gamemode2 if

					else if(choose==4){  // If user's choose is Kitap Bul
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,10);
						cout << "Kitap Ismine Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,12);
						cout << "Kitap Yazarina Gore" << endl;
						rlutil::setBackgroundColor(0);
						rlutil::setColor(3);
						rlutil::locate(50,14);
						cout << "Kitap Yilina Gore" << endl;
						rlutil::setBackgroundColor(4);
						rlutil::setColor(3);
						rlutil::locate(50,16);
						cout << "Basim Sirketine Gore" << endl;
						rlutil::setBackgroundColor(0);
					} // end of gamemode2 if

					if(choose<=0)   // If user try to go down or up in menu set choose 
						choose=1;   
					if(choose>4)     
						choose=4;

					choice_find=choose;  // Set user's choose to arama kriteri

				}//End of Gamemode while-loop.
				if (choice_find == 1) {                                                                                        //Kitap ismine göre
					string name_of_book,name_of_book2;
					rlutil::cls();
					rlutil::locate(50,10);
					cout << "Kitabin Ismi: ";
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock ON!";
						rlutil::setColor(7);
					}
					else{
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock OFF!";
						rlutil::setColor(7);
					}
					cin.ignore();
					rlutil::locate(65,10);
					getline(cin, name_of_book);
					rlutil::cls();
					admin.search_by_name(name_of_book,name_of_book2);
					rlutil::locate(70,25);
					cout << "Menuye donmek icin bir tusa basin.";
					rlutil::getkey();
				} // End of Kitap İsmine Göre


				else if (choice_find == 2) {                                                                                   // Kitap yazarına göre
					string name_of_author,name_of_author2;
					rlutil::cls();
					rlutil::locate(50,10);
					cout << "Kitabin Yazari: ";
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock ON!";
						rlutil::setColor(7);
					}
					else{
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock OFF!";
						rlutil::setColor(7);
					}
					cin.ignore();
					rlutil::locate(65,10);
					getline(cin, name_of_author);
					rlutil::cls();
					admin.search_by_author(name_of_author,name_of_author2);
					rlutil::locate(70,25);
					cout << "Menuye donmek icin bir tusa basin.";
					rlutil::getkey();


				}// End of Kitap Yazarına Göre

				else if (choice_find == 3) {                                                                                   // Kitap yılına göre

					string year_of_book;
					rlutil::cls();
					rlutil::locate(50,10);
					cout << "Kitabin Yili: ";
					if ((GetKeyState(VK_NUMLOCK) & 0x0001)!=0){
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock ON!";
						rlutil::setColor(7);
					}
					else{
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock OFF!";
						rlutil::setColor(7);
					}
					cin.ignore();
					rlutil::locate(65,10);
					getline(cin, year_of_book);
					rlutil::cls();
					admin.search_by_year(year_of_book);
					rlutil::locate(70,25);
					cout << "Menuye donmek icin bir tusa basin.";
					rlutil::getkey();

				}// End of Kitap Yılına Göre

				else if (choice_find == 4) {                                                                                   // Basım şirketine göre

					string company_of_book;
					rlutil::cls();
					rlutil::locate(50,10);
					cout << "Kitabin Basim Sirketi: ";
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock ON!";
						rlutil::setColor(7);
					}
					else{
						rlutil::setColor(5);
						rlutil::locate(80,25);
						cout << "Caps Lock OFF!";
						rlutil::setColor(7);
					}
					cin.ignore();
					rlutil::locate(65,10);
					getline(cin, company_of_book);
					rlutil::cls();
					admin.search_by_company(company_of_book);
					rlutil::locate(70,25);
					cout << "Menuye donmek icin bir tusa basin.";
					rlutil::getkey();



				}// End of Basım Şirketine Göre


			}                                                                                                              // End of KİTAP BUL



			else if (choice_admin == 3) {                                                                                   // Şifre Değiştir
				string admin_pass;
				rlutil::cls();
				rlutil::locate(50,12);
				cout << "Yeni Sifre: ";
				if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock ON!";
					rlutil::setColor(7);
				}
				else{
					rlutil::setColor(5);
					rlutil::locate(80,25);
					cout << "Caps Lock OFF!";
					rlutil::setColor(7);
				}
				rlutil::locate(65,12);
				cin >> admin_pass;
				admin.update_password(admin_pass);
				rlutil::locate(50,20);
				cout << "Parola Degistirildi!"<<endl;
				rlutil::msleep(3000);
			}                                                                                                              // End of Şifre Değiştir



		}  // End of About


		else if(choice==3){                                                                                                  //Exit
			rlutil::locate(40,15); cout << "Uygulamayi kullandiginiz icin tesekkur ederiz!";
			rlutil::setColor(2);
			rlutil::locate(80,27); cout << "Cikis icin ENTER'a basiniz!";
			rlutil::setColor(7);
			exit(0);
		}   // End of Exit

	}  // End of Menu while


}
