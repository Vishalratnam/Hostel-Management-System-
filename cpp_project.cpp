#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include <sstream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
class student
{
	public: string name;
			string reg_no;
			int sem;
			int priority;
			int preference;
			int year;
			void year_s(student *s)
			{
				if(s->sem==1 || s->sem==2)
					s->year=1;
				else if(sem ==3 || s->sem ==4)
					s->year=2;
				else if(s->sem== 4 || s->sem==5)
					s->year=3;
				else
					s->year=4;
			}
			int room_no;
			string block_present;
};

struct room
{
	int no_filled;
	int no_empty;
	int student_sem_exist;
	student *stud;
};
typedef struct room room;

int stoi(string NumberAsString)
{
	int NumberAsInteger;
	stringstream ss;
	ss << NumberAsString;
	ss >> NumberAsInteger;
	return NumberAsInteger;
}
class block_info
{
	public: int student_sem_enter;
			int rooms_empty;
			int rooms_filled;
			int number_of_students;
			block_info()
			{
				rooms_empty=200;
				rooms_filled=0;
				number_of_students=0;
			}
			virtual int create_entry(student* s, block_info* n)
			{
			}
			virtual void remove_entry(student s,int room,block_info *n)
			{
			}
};

class newBlock : public block_info
{
	public: int total_rooms;
			room b[200];
			int seats_empty;
			newBlock()
			{
				for(int i=0; i<200; i++)
				{
					b[i].no_filled=0;
					b[i].no_empty=3;
					b[i].student_sem_exist=0;
					b[i].stud=new student [3];
				}
				total_rooms=200;
				seats_empty=200*3;
			}
			int create_entry(student *s,block_info *n)
			{
				if( n->rooms_filled == 200)
				{
					return 0;
				}				
				for(int i=0; i<200; i++)
				{
					if(b[i].no_filled == 0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						//newBlock_file << b[i].no_filled<<"\t";
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						if(b[i].no_filled == 3)
						{
							n->rooms_filled++;
							n->rooms_empty--;
						}
						
					//	if(b[i].no_filled==3)
					//		newBlock_file << b[i].no_filled<<"\n";
					//	else
							//newBlock_file << b[i].no_filled<<"\t";
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
					}						
				}
			}
			void remove_entry(student s,int room,block_info *n)
			{
				student s1;
				s1.name="Not Assigned";
				s1.reg_no="Nill";
				s1.priority=0;
				s1.sem=0;
				s1.preference=0;
				s1.year=0;
				s1.room_no=0;
				s1.block_present="Not Alloted";
				for(int i=0; i<3;i++)
				{
					if((b[room-1].stud[i].reg_no).compare(s.reg_no) ==0)
					{
						cout<<"\t\t\t\tRecord Deleted!"<<endl;
						b[room-1].stud[i] = s1;
						b[room-1].no_filled--;
						b[room-1].no_empty++;
					}
				}
				n->number_of_students--;
				seats_empty++;
				cout<<"\t\t\t\tNumber of students in room left: "<<b[room-1].no_filled<<endl;
				if(b[room-1].no_filled == 0)
				{
					cout<<"Room Empty!!"<<endl;
					n->rooms_filled--;
					n->rooms_empty++;
				}
			}
};
class itBlock : public block_info
{
	public: int total_rooms;
			int seats_empty;
			room b[100];
			itBlock()
			{
				for(int i=0; i<100; i++)
				{
					b[i].no_filled=0;
					b[i].no_empty=3;
					b[i].student_sem_exist=0;
					b[i].stud=new student [3];
				}
				total_rooms=100;
				seats_empty=100*3;
			}
			int create_entry(student *s,block_info *n)
			{
				if( n->rooms_filled == 100)
				{
					return 0;
				}
				for(int i=0; i<100; i++)
				{
					if(b[i].no_filled == 0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						if(b[i].no_filled == 3)
						{
							n->rooms_filled++;
							n->rooms_empty--;
						}
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
					}						
				}
			}
			void remove_entry(student s,int room,block_info *n)
			{
				student s1;
				s1.name="Not Assigned";
				s1.reg_no="Nill";
				s1.priority=0;
				s1.sem=0;
				s1.preference=0;
				s1.year=0;
				s1.room_no=0;
				s1.block_present="\t\t\t\tNot Alloted";
				for(int i=0; i<3;i++)
				{
					if((b[room-1].stud[i].reg_no).compare(s.reg_no) ==0)
					{
						cout<<"Record Deleted!"<<endl;
						b[room-1].stud[i] = s1;
						b[room-1].no_filled--;
						b[room-1].no_empty++;
					}
				}
				n->number_of_students--;
				seats_empty++;
				cout<<"\t\t\t\tNumber of students in room left: "<<b[room-1].no_filled<<endl;
				if(b[room-1].no_filled == 0)
				{
					cout<<"Room Empty!!"<<endl;
					n->rooms_filled--;
					n->rooms_empty++;
				}
			}
};
class ihBlock : public block_info
{
	public: int total_rooms;
			int seats_empty;
			room b[100];
			ihBlock()
			{
				for(int i=0; i<100; i++)
				{
					b[i].no_filled=0;
					b[i].no_empty=1;
					b[i].student_sem_exist=0;
					b[i].stud=new student [1];
				}
				total_rooms=100;
				seats_empty=100*1;
			}
			int create_entry(student *s,block_info *n)
			{
				if( n->rooms_filled == 100)
				{
					return 0;
				}
				for(int i=0; i<100; i++)
				{
					if(b[i].no_filled == 0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						if(b[i].no_filled == 1)
						{
							n->rooms_filled++;
							n->rooms_empty--;
						}
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
					}						
				}
			}
			void remove_entry(student s,int room,block_info *n)
			{
				student s1;
				s1.name="Not Assigned";
				s1.reg_no="Nill";
				s1.priority=0;
				s1.sem=0;
				s1.preference=0;
				s1.year=0;
				s1.room_no=0;
				s1.block_present="Not Alloted";
				for(int i=0; i<3;i++)
				{
					if((b[room-1].stud[i].reg_no).compare(s.reg_no) ==0)
					{
						cout<<"Record Deleted!"<<endl;
						b[room-1].stud[i] = s1;
						b[room-1].no_filled--;
						b[room-1].no_empty++;
					}
				}
				n->number_of_students--;
				seats_empty++;
				cout<<"\t\t\t\tNumber of students in room left: "<<b[room-1].no_filled<<endl;
				if(b[room-1].no_filled == 0)
				{
					cout<<"\t\t\t\tRoom Empty!!"<<endl;
					n->rooms_filled--;
					n->rooms_empty++;
				}
			}
};
class messBlock : public block_info
{
	public: int total_rooms;
			room b[50];
			int seats_empty;
			messBlock()
			{
				for(int i=0; i<50; i++)
				{
					b[i].no_filled=0;
					b[i].no_empty=2;
					b[i].student_sem_exist=0;
					b[i].stud=new student [2];
				}
				total_rooms=50;
				seats_empty=50*2;
			}
			int create_entry(student *s,block_info *n)
			{
				if( n->rooms_filled == 50)
				{
					return 0;
				}
				for(int i=0; i<50; i++)
				{
					if(b[i].no_filled == 0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
						b[i].stud[b[i].no_filled]=*s;
						b[i].no_filled++;
						b[i].no_empty--;
						b[i].student_sem_exist=n->student_sem_enter;
						n->number_of_students++;
						seats_empty--;
						if(b[i].no_filled == 2)
						{
							n->rooms_filled++;
							n->rooms_empty--;
						}
						return i+1;
					}
					else if((n->student_sem_enter == b[i].student_sem_exist) && b[i].no_empty !=0)
					{
					}						
				}
			}
			void remove_entry(student s,int room,block_info *n)
			{
				student s1;
				s1.name="Not Assigned";
				s1.reg_no="Nill";
				s1.priority=0;
				s1.sem=0;
				s1.preference=0;
				s1.year=0;
				s1.room_no=0;
				s1.block_present="Not Alloted";
				for(int i=0; i<3;i++)
				{
					if((b[room-1].stud[i].reg_no).compare(s.reg_no) ==0)
					{
						cout<<"\t\t\t\tRecord Deleted!"<<endl;
						b[room-1].stud[i] = s1;
						b[room-1].no_filled--;
						b[room-1].no_empty++;
					}
				}
				n->number_of_students--;
				seats_empty++;
				cout<<"\t\t\t\tNumber of students in room left: "<<b[room-1].no_filled<<endl;
				if(b[room-1].no_filled == 0)
				{
					cout<<"Room Empty!!"<<endl;
					n->rooms_filled--;
					n->rooms_empty++;
				}
			}
};

void new_allotment(student *s,block_info *n,int pref)
{
	string block;
	switch(pref)
	{
		case 1: block="New Block";
				break;
		case 2: block="IT Block";
				break;
		case 3: block="Mess Block";
				break;
		case 4: block="IH Block";
				break;
	}
	n->student_sem_enter=s->sem;
	if(n->rooms_empty != 0)
	{
		int room_given = n->create_entry(s,n);
		if(room_given==0)
		{
			cout<<"\t\t\t\tEntry Unsuccessfull\n";
			s->block_present="Not Given";
			s->room_no=-1;
		}
		else
		{
			cout<<"\t\t\t\tEntry Successfull Into Room Number "<<room_given<<" of "<<block<<endl;
			s->block_present=block;
			s->room_no=room_given;
		}
	}
	else
		cout<<"\t\t\t\tBlock Full!"<<endl;
}
void room_info(block_info *req_b, int r_num, int block)
{
	switch(block)
	{
		case 1: cout<<"\n\t\t\t\t\tStudent Information in NewBlock Room: "<<r_num<<endl;
				cout<<"\t\t\t\tNumber Of Students Alloted:"<<static_cast<newBlock*>(req_b)->b[r_num-1].no_filled<<endl;
				cout<<"\t\t\t\tSemester Of Students:"<<static_cast<newBlock*>(req_b)->b[r_num-1].student_sem_exist<<endl;
				cout<<"\t\t\t\tStudent(s) Info:"<<endl;
				for(int i=0;i< static_cast<newBlock*>(req_b)->b[r_num-1].no_filled ;i++)
				{
					cout<<"\t\t\t\tName:"<<static_cast<newBlock*>(req_b)->b[r_num-1].stud[i].name<<endl;
					cout<<"\t\t\t\tRegistration Number:"<<static_cast<newBlock*>(req_b)->b[r_num-1].stud[i].reg_no<<endl;
					cout<<"\t\t\t\tYear:"<<static_cast<newBlock*>(req_b)->b[r_num-1].stud[i].year<<endl;
				}
				break;
		case 2: cout<<"\n\t\t\t\t\tStudent Information in IT Block Room: "<<r_num<<endl;
				cout<<"\t\t\t\tNumber Of Students Alloted:"<<static_cast<itBlock*>(req_b)->b[r_num-1].no_filled<<endl;
				cout<<"\t\t\t\tSemester Of Students:"<<static_cast<itBlock*>(req_b)->b[r_num-1].student_sem_exist<<endl;
				cout<<"\t\t\t\tStudent(s) Info:"<<endl;
				for(int i=0;i< static_cast<itBlock*>(req_b)->b[r_num-1].no_filled ;i++)
				{
					cout<<"\t\t\t\tName:"<<static_cast<itBlock*>(req_b)->b[r_num-1].stud[i].name<<endl;
					cout<<"\t\t\t\tRegistration Number:"<<static_cast<itBlock*>(req_b)->b[r_num-1].stud[i].reg_no<<endl;
					cout<<"\t\t\t\tYear:"<<static_cast<itBlock*>(req_b)->b[r_num-1].stud[i].year<<endl;
				}
				break;
		case 3: cout<<"\n\t\t\t\t\tStudent Information in Mess Block Room: "<<r_num<<endl;
				cout<<"Number Of Students Alloted:"<<static_cast<messBlock*>(req_b)->b[r_num-1].no_filled<<endl;
				cout<<"Semester Of Students:"<<static_cast<messBlock*>(req_b)->b[r_num-1].student_sem_exist<<endl;
				cout<<"Student(s) Info:"<<endl<<endl;
				for(int i=0;i< static_cast<messBlock*>(req_b)->b[r_num-1].no_filled ;i++)
				{
					cout<<"\t\t\t\tName:"<<static_cast<messBlock*>(req_b)->b[r_num-1].stud[i].name<<endl;
					cout<<"\t\t\t\tRegistration Number:"<<static_cast<messBlock*>(req_b)->b[r_num-1].stud[i].reg_no<<endl;
					cout<<"\t\t\t\tYear:"<<static_cast<messBlock*>(req_b)->b[r_num-1].stud[i].year<<endl;
				}
				break;
		case 4: cout<<"\n\t\t\t\t\tStudent Information in IH BlockRoom: "<<r_num<<endl;
				cout<<"\t\t\t\tNumber Of Students Alloted:"<<static_cast<ihBlock*>(req_b)->b[r_num-1].no_filled<<endl;
				cout<<"\t\t\t\tSemester Of Students:"<<static_cast<ihBlock*>(req_b)->b[r_num-1].student_sem_exist<<endl;
				cout<<"\t\t\t\tStudent(s) Info:"<<endl;
				for(int i=0;i< static_cast<ihBlock*>(req_b)->b[r_num-1].no_filled ;i++)
				{
					cout<<"\t\t\t\tName:"<<static_cast<ihBlock*>(req_b)->b[r_num-1].stud[i].name<<endl;
					cout<<"\t\t\t\tRegistration Number:"<<static_cast<ihBlock*>(req_b)->b[r_num-1].stud[i].reg_no<<endl;
					cout<<"\t\t\t\tYear:"<<static_cast<ihBlock*>(req_b)->b[r_num-1].stud[i].year<<endl;
				}
				break;
	}
}

void student_info(student* stud_array, string srn)
{
	for(int i=0;i<500;i++)
	{
		if(srn.compare(stud_array[i].reg_no) == 0)
		{
			cout<<"\n\t\t\t\tStudent Name: "<<stud_array[i].name<<"."<<endl;
			cout<<"\t\t\t\tStudent SRN: "<<stud_array[i].reg_no<<"."<<endl;
			cout<<"\t\t\t\tYear and Semester: "<<stud_array[i].year<<" year, "<<stud_array[i].sem<<" semester. "<<endl;
			cout<<"\t\t\t\tBlock and Room Number: "<<stud_array[i].block_present<<", Room no. "<<stud_array[i].room_no<<"."<<endl;
			return;
		}
	}
	cout<<"\t\t\t\tRecord Not Found!\nPlease Check the SRN"<<endl;
}
void info_block(block_info *req_b, int block)
{
	switch(block)
	{
		case 1: cout<<"\n\t\t\t\t\t\tNew Block\n";
				cout<<"\t\t\t\tTotal Number of Rooms: 200"<<endl;
				cout<<"\t\t\t\tNumber of Rooms Empty: "<<static_cast<newBlock*>(req_b)->rooms_empty<<endl;
				cout<<"\t\t\t\tNumber of Rooms Full: "<<static_cast<newBlock*>(req_b)->rooms_filled<<endl;
				cout<<"\t\t\t\tNumber of Students in the Block: "<<static_cast<newBlock*>(req_b)->number_of_students<<endl;
				cout<<"\t\t\t\tSeats Empty Out Of 600: "<<static_cast<newBlock*>(req_b)->seats_empty<<endl;
				break;
		case 2: cout<<"\n\t\t\t\t\tIT Block\n";
				cout<<"\t\t\t\tTotal Number of Rooms: 100"<<endl;
				cout<<"\t\t\t\tNumber of Rooms Empty: "<<static_cast<itBlock*>(req_b)->rooms_empty<<endl;
				cout<<"\t\t\t\tNumber of Rooms Full: "<<static_cast<itBlock*>(req_b)->rooms_filled<<endl;
				cout<<"\t\t\t\tNumber of Students in the Block: "<<static_cast<itBlock*>(req_b)->number_of_students<<endl;
				cout<<"\t\t\t\t\tSeats Empty Out Of 300: "<<static_cast<itBlock*>(req_b)->seats_empty<<endl;
				break;		
		case 3: cout<<"\n\t\t\t\t\tMess Block\n";
				cout<<"\t\t\t\tTotal Number of Rooms: 50"<<endl;
				cout<<"\t\t\t\tNumber of Rooms Empty: "<<static_cast<messBlock*>(req_b)->rooms_empty<<endl;
				cout<<"\t\t\t\tNumber of Rooms Full: "<<static_cast<messBlock*>(req_b)->rooms_filled<<endl;
				cout<<"\t\t\t\tNumber of Students in the Block: "<<static_cast<messBlock*>(req_b)->number_of_students<<endl;
				cout<<"\t\t\t\t\tSeats Empty Out Of 100: "<<static_cast<messBlock*>(req_b)->seats_empty<<endl;
				break;
		case 4: cout<<"\n\t\t\t\t\tIH Block\n";
				cout<<"\t\t\t\tTotal Number of Rooms: 100"<<endl;
				cout<<"\t\t\t\tNumber of Rooms Empty: "<<static_cast<ihBlock*>(req_b)->rooms_empty<<endl;
				cout<<"\t\t\t\tNumber of Rooms Full: "<<static_cast<ihBlock*>(req_b)->rooms_filled<<endl;
				cout<<"\t\t\t\tNumber of Students in the Block: "<<static_cast<ihBlock*>(req_b)->number_of_students<<endl;
				cout<<"\t\t\t\t\tSeats Empty Out Of 100: "<<static_cast<ihBlock*>(req_b)->seats_empty<<endl;
				break;
	}
}
void leave_hostel(student* stud_array, block_info *n1,string srn)
{
	string block_present;
	int room;
	int i;
	student remove;
	for(i=0;i<200;i++)
	{
		if(srn.compare(stud_array[i].reg_no) == 0)
		{
			remove=stud_array[i];
			cout<<"\t\t\t\tRecord Found"<<endl;
			block_present=stud_array[i].block_present;
			room= stud_array[i].room_no;
			student s1;
				s1.name="Not Assigned";
				s1.reg_no="Nill";
				s1.priority=0;
				s1.sem=0;
				s1.preference=0;
				s1.year=0;
				s1.room_no=0;
				s1.block_present="Not Alloted";
			stud_array[i]=s1;
		}
	}
	if(block_present == "New Block" )
		{	
			cout<<"\t\t\t\tNew Block"<<endl;
			newBlock n;
			n1->remove_entry(remove,room,n1);
		}
	else if(block_present == "IT Block")
		{
			cout<<"\t\t\t\tIT Block"<<endl;
			itBlock it;
			n1->remove_entry(stud_array[i-1],room,n1);
		}
	else if(block_present =="Mess Block")
		{
			cout<<"\t\t\t\tMess Block"<<endl;
			messBlock mess;
			n1->remove_entry(stud_array[i-1],room,n1);
		}
	else if(block_present == "IH Block")
		{
			cout<<"\t\t\t\tIH Block"<<endl;
			ihBlock ih;
			n1->remove_entry(stud_array[i-1],room,n1);
		}
	else
		cout<<"\t\t\t\tRecord Not Found!!"<<endl;
}		

int main()
{
	student stud_array[500];
	
	fstream student_file;
	
	student_file.open("StudentDataBase.dat", ios::out | ios::in | ios::app);
	
	cout<<"Writing to the file"<<endl;
	short index=0;
	string line;
	if (student_file.is_open())
    {
		cout<<"Loading into student array:"<<endl;
		while (!student_file.eof())
        {
            getline (student_file,line);
			while(line.compare("+")!= 0 && !student_file.eof())
			{
				stud_array[index].name = line;
				getline (student_file,line);
				stud_array[index].reg_no=line;
				getline (student_file,line);
				stud_array[index].sem=stoi(line);
				getline (student_file,line);
				stud_array[index].year=stoi(line);
				getline (student_file,line);
				stud_array[index].block_present=line;
				getline (student_file,line);
				stud_array[index].room_no=stoi(line);
				getline (student_file,line);			
			}
			index++;
        }
    }
	student_file.close();
	
	student_file.open("StudentDataBase.dat", ios::out | ios::in | ios::app);
	
	//cout<<"Writing into the hostel file"<<endl;
	int choice;
	cout<<"\t\t\t\t\t\t  ===================\n";
	cout<<"\t\t\t\t\t\tHOSTEL MANAGEMENT SYSTEM\n";
	cout<<"\t\t\t\t\t\t  ===================\n";
	cout<<"\t\t\t\t\t\t      ::Main Menu::\n";
	cout<<"\t\t\t\t\t\t 1: New Allotment\n\t\t\t\t\t\t 2: Get Student Information\n\t\t\t\t\t\t 3: Get Room Information\n\t\t\t\t\t\t 4: Leaving Hostel\n\t\t\t\t\t\t 5: Block Information\n\t\t\t\t\t\t 6: Options\n\t\t\t\t\t\t 7:Exit "<<endl;
	int loop=1;
	
	newBlock n;
	itBlock it;
	messBlock m;
	ihBlock ih;
	
	int i=0;
	while(loop)
	{
		string srn;
		int block;
		cout<<"\n\t\t\t\t\tChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{
					student s;
					cout<<"\t\t\t\tEnter the name of the student:";
					cin>>s.name;
					cout<<"\t\t\t\tEnter the Registration Number:";
					cin>>s.reg_no;
					cout<<"\t\t\t\tEnter the Semester Of Study:";
					cin>>s.sem;
					s.year_s(&s);
					if(s.year==1)
					{
						cout<<"\t\t\t\t\tEnter the preference:- \n\t\t\t\t\t 1: New Block \n\t\t\t\t\t 2: IT Block \n\t\t\t\t\t 3: Mess Block\n\t\t\t\t\tBlock: ";
						cin>>s.preference;	
					}
					else
					{
						cout<<"\t\t\t\t\tEnter the preference:- \n\t\t\t\t\t 1: New Block \n\t\t\t\t\t 4: IH Block\n\t\t\t\t\tBlock: ";
						cin>>s.preference;
					}
					switch(s.preference)
					{
						case 1:{
								new_allotment(&s,&n,s.preference);
								}
								break;
						case 2:new_allotment(&s,&it,s.preference);
								break;
						case 3:new_allotment(&s,&m,s.preference);
								break;
						case 4:new_allotment(&s,&ih,s.preference);
								break;
					}
						stud_array[i++]=s;
						student_file << s.name << endl;
						student_file << s.reg_no << endl;
						student_file << s.sem << endl;
						student_file << s.year <<endl;
						student_file << s.block_present << endl;
						student_file << s.room_no<<endl;
						student_file << "+"<<endl;
				}
					break;
			case 2:	cout<<"\t\t\t\t\tEnter The SRN of Student:";
					cin>>srn;
					student_info(stud_array, srn);
					break;
			case 3: int r_num;
					cout<<"\t\t\t\t\tEnter the Block:";
					cin>>block;
					cout<<"\t\t\t\t\tEnter the room number:";
					cin>>r_num;
					switch(block)
					{
						case 1:room_info(&n,r_num,block);
								break;
						case 2:room_info(&it,r_num,block);
								break;
						case 3:room_info(&m,r_num,block);
								break;
						case 4:room_info(&ih,r_num,block);
								break;
					}
					break;
			case 4: cout<<"\t\t\t\t\tEnter The SRN of the Student leaving the hostel :";
					cin>>srn;
					leave_hostel(stud_array,&n,srn);
					break;
			case 5:	cout<<"\t\t\t\t\tEnter Required Block:";
				 	cin>>block;
					switch(block)
					{
						case 1:info_block(&n,block);
								break;
						case 2:info_block(&it,block);
								break;
						case 3:info_block(&m,block);
								break;
						case 4:info_block(&ih,block);
								break;
					}
					break;
			case 6:cout<<"\t\t\t\t\t\t 1: New Allotment\n\t\t\t\t\t\t 2: Get Student Information\n\t\t\t\t\t\t 3: Get Room Information\n\t\t\t\t\t\t 4: Leaving Hostel\n\t\t\t\t\t\t 5: Block Information\n\t\t\t\t\t\t 6:Options\n\t\t\t\t\t\t 7:Exit "<<endl;
					break;
			case 7: loop=0;
					break;
			default:cout<<"\t\t\t\tPlease Enter a valid request:";
					break;
		}
	}
	//student_file.close();
	return 0;
}
