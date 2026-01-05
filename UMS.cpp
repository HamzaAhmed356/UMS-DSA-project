#include<iostream>
using namespace std;
class Teacher;
Teacher *Thead=NULL;
class Student ;
Student *ad=NULL;//admission application head
int Student_id=0;

class Student{
	int S_id;//assigned by admin 
	int age,c;
	string name;
	unsigned long long int cnic;
	string course,Address;
	bool admission,noticed;//assigned by admin 
	int marks;
	Student *left;
	Student *right;
	public:
	Student(){
		S_id=0;
		admission=false;
		noticed=false;
		left=NULL;
		right=NULL;
 
		}	
		
		void AdmissionForm(){
			 system("cls");
			Student *st=new Student;
			int choice=0;
			system("cls");
			cout<<"\n\t\t Admssion Form \n\n";
			cout<<"Enter your age :";
			cin>>st->age;
			cout<<"Enter name of Student : ";
			cin.ignore();
			getline(cin,st->name);
			
			cout<<"Enter your CNIC :";
			cin>>st->cnic;
			cout<<"Enter your marks in Matric";
			cin>>st->marks;
			cout<<"Enter you Address :";
			cin.ignore();
			getline(cin,st->Address);
			again :
			cout<<"Enter course you want to study "<<endl;
			cout<<"1)For ICS \n2)For FSC \n3)For ICOM"<<endl;
			cout<<"Plz enter your choice here :";
			cin>>choice;
			if(choice==1)
				st->course="ICS";
				else if(choice==2)
				st->course="FSC";
				else if(choice==3)
				st->course="ICOM";
				else{
					cout<<"YOU choose invalid choice Plz Enter Again :";
					system("pause");
					system("cls");
					goto again;
				}
				
				if(ad==NULL){			//tree implementation starts from here
					ad=st;
				}
				else{
					Student *copy=ad;
					while(true){
						if(copy->cnic > st->cnic){
							if(copy->left==NULL){
								copy->left=st;
								cout<<"\nApplied successfully"<<endl;
								system("pause");
								system("cls");
								break;
							}else{
								copy=copy->left;
							}
						}
						else{
							if(copy->right==NULL){
								copy->right=st;
								cout<<"\nApplied successfully"<<endl;
								system("pause");
								system("cls");
								break;
							}else{
								copy=copy->right;
							}
						}
					}
				}
		}
		
		void inorderTraversal(Student* root) {//for displaying all records to admin 
  		if (root != NULL) {
    	inorderTraversal(root->right);
    	
  		cout <<"Name of Student :"<< root->name<<"\nAge : "<<root->age<< " "<<root->cnic<<endl;
  		cout<<"\n==============================================================="<<endl;
    	inorderTraversal(root->left);
  }
}	


		void Search(Student *head,long long int cnic){//for searching or accepting records for admin 
			if(head!=NULL){
				if(cnic >head->cnic){
					Search(head->right,cnic);
				}else if(cnic<head->cnic){
					Search(head->left,cnic);
					
				}else if(cnic==head->cnic){
					cout<<"Record found "<<head->name;
					cout<<"DO you really want to accept this addmission :";
					cout<<"\n1)For yes \2) For no :";
					cin>>c;
					if(c==1){
						head->noticed=true;
						head->admission=true;
						head->S_id=++Student_id;
					}
				}
			}
		}

			void Student_Portal(Student *head,string Sname,long long int Scnic){
				if(head!=NULL){
					if(Scnic >head->cnic){
						Student_Portal(head->right,Sname,Scnic);
					}else if(cnic  >head->cnic){
						Student_Portal(head->left,Sname,cnic);
				}
				if(Scnic==head->cnic){
					if(head->name==Sname){
						 system("cls");
						if(head->noticed==false && head->admission==false){
							cout<<"\n\t NOTE!\nYour Application for admssion is on pending"<<endl;
						}
						else if (head->admission==false && head->noticed==true){
							cout<<"\n\t NOTE!\nYour Application for admission is noticed by admin but not accepted by admin ";
							cout<<"\n Please visit college or try to contact Admin "<<endl;	
						}
						else{
							cout<<"\n\t Student ID : "<<head->S_id;
						}
					cout<<"\n\t Name : "<<head->name;
					cout<<"\n\t Age : "<<head->age;
					cout<<"\n\t Cnic : "<<head->cnic;
					cout<<"\ n\t Course :"<<head->course;
					cout<<"\n\t Address :"<<head->Address;
					system("pause");
					system("cls");
					}
					else{
						cout<<"NOT found the record"<<endl;
						system("pause");
					}
					
				}
			}
		}
			
			
		void Menu(){
			
			//authentication function call here
			while(true){
			
			int choice;
			again:
			system("cls");
			cout<<"\n \n\t\t\t Student MENU "<<endl;
			cout<<"\n1)For Applying For Admission";
			cout<<"\n2)For login to portal.";
			cout<<"\n0)To Exit "<<endl;
			cout<<"Plz Enter Your choice here : ";
			cin>>choice;
			if(choice==1){
				//get admission data from student and add in tree
				AdmissionForm();
			}
			else if(choice==2){
				//login to student portal where student can check their application status
				long long int Scnic;
				string Sname;
				cout<<"Please Enter your CNIC :";
				cin>>Scnic;
				cout<<"Enter your name :";
				cin.ignore();
				getline(cin,Sname);
				Student_Portal(ad,name,Scnic);//search record and show protal 
				
			}
			else if(choice==0){
				break;
			
			}
			else{
				cout<<"Invalid choice PLZ select your choice again "<<endl;
				system("pause");
				system("cls");
				goto again;
				
			}
		}
		}
		
};
class Admin{
	public:
		void Menu(){
			
			//authentication function call here
			while(true){
			Student st;
			int choice;
			again:
			system("cls"); 
			cout<<"\n \n\t\t\t Admin Section"<<endl;
			cout<<"\n1)For Show ALL Records";
			cout<<"\n2)For Accepting Student Admissions And Generate Merit list";
			cout<<"\n3)For Showing Job Application"<<endl;
			cout<<"\n4)For Accepting Teaching JOB Application";
			cout<<"0)To Exit "<<endl;
			cout<<"Plz Enter Your choice here : ";
			cin>>choice;
			if(choice==1){
				if(ad==NULL){//for student admin 
					cout<<"NO records to show"<<endl;
					system("pause");
					system("cls");
				}
				else{
					st.inorderTraversal(ad);	
				}
			
			}
			else if(choice==2){//for admin student
				long long int scnic;
				//show all records
				st.inorderTraversal(ad);	
				cout<<"Enter Cnic of Student to Accept Admission";
				cin>>scnic;
				st.Search(ad,scnic);
			}
			else if(choice==3){//for admin teacher
				//show all records of teacher job
			}
			else if(choice==4){
				
			}
			else if(choice==0){
				break;
			
			}
			else{
				cout<<"Invalid choice PLZ select your choice again "<<endl;
				system("pause");
				system("cls");
				goto again;
				
			}
		}
		}
};




class Teacher{
	int T_id;//assigned by admin 
	int age;
	string name;
	unsigned long long int cnic;
	string Qualifictions,Address;
	bool job,noticed;//assigned by admin 
	Student *next;
	public:
		void JobForm(){
			Teacher *teach=new Teacher;
			int choice=0;
			system("cls");
			cout<<"\n\t\t Teaching JoB Form \n\n";
			cout<<"Enter your age :";
			cin>>teach->age;
			cout<<"Enter name Please : ";
			cin.ignore();
			getline(cin,teach->name);
			
			cout<<"Enter your CNIC :";
			cin>>teach->cnic;
			cout<<"Enter your Address :";
			cin.ignore();
			getline(cin,teach->Address);
			again :
			cout<<"Plz Enter your Qualifications "<<endl;
			cout<<"1)For Bachelors \n2)For Masters \n3)For PHD"<<endl;
			cout<<"Plz enter your choice here :";
			cin>>choice;
			if(choice==1)
				teach->Qualifictions="Bachelors";
				else if(choice==2)
				teach->Qualifictions="Masters";
				else if(choice==3)
				teach->Qualifictions="For PHD";
				else{
					cout<<"YOU choose invalid choice Plz Enter Again :";
					system("pause");
					system("cls");
					goto again;
				}
				if(Thead==NULL){
					Thead=teach;
					
				}
				else{
					//teach->next=Thead;//stack implementation here
					Thead=teach;
				}
				
				
		}
		void Tportal(){
			 system("cls");
			if(Thead==NULL){
				cout<<"No record to Login"<<endl;
						
			}
			else{
				Teacher *t=Thead;
				long long int Tcnic;
				string Tname;
				cout<<"Please Enter your name :";
				cin.ignore();
				getline(cin,Tname);
				cout<<"Plz Enter your CNIC :";
				cin>>Tcnic;
				
				while(t!=NULL){
					if(Tname==t->name && Tcnic==t->cnic){
							if(t->noticed==false && t->job==false){
							cout<<"\n\t NOTE!\nYour Application for admssion is on pending"<<endl;
						}
						else if (t->job==false && t->noticed==true){
							cout<<"\n\t NOTE!\nYour Application for JOB is noticed by admin but not accepted by admin ";
							cout<<"\n Please visit college or try to contact Admin "<<endl;	
						}
						else{
							cout<<"\n\t Teacher ID : "<<t->T_id;
						}
					cout<<"\n\t Name : "<<t->name;
					cout<<"\n\t Age : "<<t->age;
					cout<<"\n\t Cnic : "<<t->cnic;
					cout<<"\ n\t Qualification :"<<t->Qualifictions;
					cout<<"\n\t Address :"<<t->Address;
					system("pause");
					system("cls");
					break;
					}
					//t= t->next;
				}
			}
		
		}
		
		void Menu(){
			
			//authentication function call here
			while(true){
			
			int choice;
			again:
			system("cls");
			cout<<"\n \n\t\t\t Teacher MENU "<<endl;
			cout<<"\n1)For Applying For JOB";
			cout<<"\n2)For login to portal";
			cout<<"0)To Exit "<<endl;
			cout<<"Plz Enter Your choice here : ";
			cin>>choice;
			if(choice==1){
				JobForm();
				
			}
			else if(choice==2){
				//login to teacher portal where student can check their application status
			}
			else if(choice==0){
				break;
			
			}
			else{
				cout<<"Invalid choice PLZ select your choice again "<<endl;
				system("pause");
				system("cls");
				goto again;
				
			}
		}
		}
		
};








int main(){
	int choice;
	Student student;
	Teacher teacher;
	Admin admin;
	//title();
	while(true){
		again:
	system("cls");
	cout<<"\n\n\t )"<<endl;
	cout<<"\t 1)Login As Student"<<endl;
	cout<<"\t 2)Login As Teacher"<<endl;
	cout<<"\t 3)Login As Administrator"<<endl;
	cout<<"\t 0)To exit ."<<endl;
	cout<<"\n Plz Enter your choice here .";
	cin>>choice;
	if(choice==1){
		student.Menu();
	}
	else if(choice==2){
		teacher.Menu();
	}
	else if(choice==3){
		admin.Menu();
	}
	else if(choice==0)
	break;
	else{
		cout<<"Invalid choice PLZ select your choice again "<<endl;
		system("pause");
		system("cls");
		goto again;
	}
}
return 0;
}

