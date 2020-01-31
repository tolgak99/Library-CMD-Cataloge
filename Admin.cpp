#include <iostream>
#include "Admin.h"


void Admin::set_username(string a){
    name=a;
}

void Admin::set_password(string a){
	password=a;
}

string Admin::get_username(){
	return(name);
}

string Admin::get_password(){
	return(password);
}

bool Admin::check_profile(string,string){ 
	return(true);
}

bool Admin::check_username(string){
	return(true);
}

void Admin::update_password(string a){                                    // Change Admin's password
	string control;

	ofstream DeleteLine ("c:\\LibraryProject\\AdminPass.txt");
	ifstream ControlFile  ("c:\\LibraryProject\\AdminPass.txt");
	while(getline (ControlFile , control)){

		control.replace(control.find(a),a.length(),"");
		DeleteLine << control << endl;
	}

	DeleteLine.close();
	ControlFile.close();

	ofstream UserNames("c:\\LibraryProject\\AdminPass.txt", ios_base::app);
	UserNames << a << endl;
	UserNames.close();


}

bool Admin::check_password(string b){                                         // Check Admin password is true or not

	string control,first;
	int flag=0;



	ifstream ControlPass ("c:\\LibraryProject\\AdminPass.txt");
	while(getline (ControlPass , control)){

		if(control == b)
			flag++;
	}

	ControlPass.close();
	if(flag>0)
		return(true);
	else if(flag==0)
		return(false);


}

bool Admin::is_empty(std::ifstream& pFile)                                                    //Check Admin Password exist or not
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void Admin::add_book(string name ,string sur ,string author,string author2,string year,string company){  // Admin add book

	ofstream BookName(("c:\\LibraryProject\\Books\\"  + name+" "+sur).c_str() , ios_base::app);
	BookName <<"  "<< author  <<"     "<< year <<"     "<< company <<" "<<endl;
	BookName.close();

	ofstream AuthorName(("c:\\LibraryProject\\Authors\\"  + author+" "+author2).c_str() , ios_base::app);
	AuthorName <<"  "<< name <<"    " << year <<"    "<< company << " " <<endl;
	AuthorName.close();

	ofstream BookYear(("c:\\LibraryProject\\Years\\"  + year).c_str() , ios_base::app);
	BookYear << name <<"    "<< author <<"    "<< company <<" "<<endl;
	BookYear.close();


	ofstream BookCompany(("c:\\LibraryProject\\Companies\\"  + company).c_str() , ios_base::app);
	BookCompany << name <<" "<< author <<" "<< year <<" "<<endl;
	BookCompany.close();

}

void Admin::search_by_name(string a , string b){                               //Admin search book by book name
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

void Admin::search_by_author(string a, string b){                                          //Admin search book by author name

	string control;

	rlutil::setColor(4);
	rlutil::locate(15,2);
	cout << "Kayitlar"<<endl<<endl ;
	rlutil::setColor(7);

	rlutil::setColor(2);
	cout << setw(8) << "Kitap Ismi" << setw(10)<< "Yil"<<setw(15)<<"Basim Yeri"<<endl<<endl<<endl;
	rlutil::setColor(7);


	ifstream NameAuthor  (("c:\\LibraryProject\\Authors\\"  + a ).c_str() );
	while(getline (NameAuthor , control)){

		cout << setw(15) << control <<endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -"<<endl;

	}

	NameAuthor.close();



}

void Admin::search_by_year(string a){                                                         //Admin search book by year

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

void Admin::search_by_company(string a){                                                                 //Admin search book by company name

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
