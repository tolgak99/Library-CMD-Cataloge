#include <iostream>
#include "User.h"


void User::set_username(string a){
	name=a;
}

void User::set_password(string b){
	password=b;
}

string User::get_username(){
	return(name);
}

string User::get_password(){
	return(password);
}

bool User::check_profile(string a , string b){                                   // Check user profile username and password
	string control;
	int flag=0;

	ifstream ControlFile  (("c:\\LibraryProject\\Accounts\\" + a ).c_str());
	while(getline (ControlFile , control)){

		if(control == b)
			flag++;
	}

	ControlFile.close();
	if(flag>0)
		return(true);
	else if(flag==0)
		return(false);
}

bool User::check_username(string a){                                            // Check User profile is already exist or not
	string control;
	int flag=0;

	ifstream ControlFile  ("c:\\LibraryProject\\usernames.txt");
	while(getline (ControlFile , control)){

		if(control == a)
			flag++;
	}

	ControlFile.close();
	if(flag>0)
		return(false);
	else if(flag==0)
		return(true);
}

void User::open_file(){                                            // Open username.txt to save usernames

	ofstream UserFile( ("c:\\LibraryProject\\Accounts\\" + name ).c_str() );
	UserFile << name << endl <<  password << endl;
	UserFile.close();

	ofstream UserNames("c:\\LibraryProject\\usernames.txt", ios_base::app);
	UserNames << name << endl;
	UserNames.close();

}

void User::update_profile(string a, string b){                       // Change Username and password
	string control;

	ofstream UpdateFile(("c:\\LibraryProject\\Accounts\\" + a ).c_str());
	UpdateFile << a << endl <<  b << endl;
	UpdateFile.close(); 

	ofstream DeleteLine ("c:\\LibraryProject\\usernames.txt");
	ifstream ControlFile  ("c:\\LibraryProject\\usernames.txt");
	while(getline (ControlFile , control)){

		control.replace(control.find(("c:\\LibraryProject\\Accounts\\" + a )),a.length(),"");
		DeleteLine << control << endl;
	}

	DeleteLine.close();
	ControlFile.close();

	ofstream UserNames("c:\\LibraryProject\\usernames.txt", ios_base::app);
	UserNames << a << endl;
	UserNames.close();


}

void User::search_by_name(string a , string b){                                   // //User search book by book name
	int i;
	string control;

	rlutil::setColor(4);
	rlutil::locate(15,2);
	cout << "Kayitlar"<<endl<<endl ;
	rlutil::setColor(7);

	rlutil::setColor(2);
	cout << setw(8) << "Yazar" << setw(10)<< "Yil"<<setw(15)<<"Basim Yeri"<<endl<<endl<<endl;
	rlutil::setColor(7);

	ifstream NameBook  (("c:\\LibraryProject\\Books\\"  + a ).c_str() );
	while(getline (NameBook , control)){

		cout  << control<<endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -"<<endl;

	}

	NameBook.close();



}

void User::search_by_author(string a, string b){                                //User search book by author name

	string control;

	rlutil::setColor(4);
	rlutil::locate(15,2);
	cout << "Kayitlar"<<endl<<endl ;
	rlutil::setColor(7);

	rlutil::setColor(2);
	cout << setw(8) << "Kitap Ismi" << setw(10)<< "Yil"<<setw(15)<<"Basim Yeri"<<endl<<endl<<endl;
	rlutil::setColor(7);


	ifstream NameAuthor  (("c:\\LibraryProject\\Authors\\"  + a).c_str() );
	while(getline (NameAuthor , control)){

		cout << setw(15) << control <<endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -"<<endl;

	}

	NameAuthor.close();



}

void User::search_by_year(string a){                                                    //User search book by year

	string control;

	rlutil::setColor(4);
	rlutil::locate(15,2);
	cout << "Kayitlar"<<endl<<endl ;
	rlutil::setColor(7);

	rlutil::setColor(2);
	cout << setw(8) << "Kitap Ismi" << setw(10)<< "Yazar"<<setw(15)<<"Basim Yeri"<<endl<<endl<<endl;
	rlutil::setColor(7);


	ifstream YearBook  (("c:\\LibraryProject\\Years\\"  + a ).c_str() );
	while(getline (YearBook , control)){

		cout << setw(15) << control <<endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -"<<endl;

	}

	YearBook.close();


}

void User::search_by_company(string a){                                                //User search book by company name

	string control;

	rlutil::setColor(4);
	rlutil::locate(15,2);
	cout << "Kayitlar"<<endl<<endl ;
	rlutil::setColor(7);

	rlutil::setColor(2);
	cout << setw(8) << "Kitap Ismi" << setw(10)<< "Yazar"<<setw(15)<<"Yil"<<endl<<endl<<endl;
	rlutil::setColor(7);


	ifstream CompBook  (("c:\\LibraryProject\\Companies\\"  + a ).c_str() );
	while(getline (CompBook , control)){

		cout << setw(15) << control <<endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -"<<endl;

	}

	CompBook.close();


}
