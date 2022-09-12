#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class lang
{	public:	
		string en,az;
};

class dic
{	lang a;

	void dadd();
	void dfind();
	void dlist();
	void dremove();
	void dsort();
	
	void dinput();
	void doutput();
	
	void dmenu();
	
	public:
		void dstart();
};



//**********************
void dic::dadd()
{	char ch;
	do
	{	doutput();
		cout<<"Press \'Y\' to continue: ";
		
		cin>>ch;
		
	}while(ch=='Y'||ch=='y');
}
//**********************
void dic::dfind()
{	char ch;
	do
	{	cout<<"***FIND EN-AZ***\n";
		lang b;
	    cout<<"Enter word\nEN: ";
	    cin>>b.en;
	    
		ifstream fin;
		fin.open("dic.txt",ios::in);
		int k=0;
		while(!fin.eof())
		{
			fin>>a.en>>a.az>>ws;
			if(b.en==a.en)
			{	cout<<"AZ: "<<a.az<<endl;	
				k=1;
				break;
			}
		}
		fin.close();
		if(k==0)
			cout<<"Not Found\n";

		cout<<"Press \'Y\' to continue: ";
		cin>>ch;
		
	}while(ch=='Y'||ch=='y');
	
}
//**********************
void dic::dlist()
{	char ch;
	do
	{	dinput();
		cout<<"Press \'Y\' to continue: ";
		
		cin>>ch;
		
	}while(ch=='Y'||ch=='y');

}
//**********************
void dic::dremove()
{	
	char ch;
	ifstream fin;
	ofstream fout;
	do
	{
		cout<<"***DEL*****\n";
		lang b;
		cout<<"Enter word\nEN: ";
		cin>>b.en;
		
		fin.open("dic.txt",ios::in);
		int k=0;
		while(!fin.eof())
		{
			fin>>a.en>>a.az>>ws;
			if(b.en==a.en)
			{
				cout<<"AZ: "<<a.az<<endl;
				k=1;
				break;
			}
		}
		fin.close();
		if(k==0)
		cout<<"Not Found\n";
		else
		{
			fin.open("dic.txt",ios::in);
			fout.open("dic.txt",ios::out);
			
			while(!fin.eof())
			{
				fin>>a.en>>a.az>>ws;
				if((b.en).compare(a.en)!=0)
				fout<<a.en<<endl<<a.az<<endl;
			}
			fin.close();
			fout.close();
			remove("dic.txt");
			rename("dic.txt","dic.txt");
			dlist();
		}		
	}while(ch=='Y'||ch=='y');
}
//**********************
void dic::dsort()
{	
	char ch;
	do
	{	
	cout<<"***SORT***\n";
	lang b[1000];
	
	ifstream fin;
	ofstream fout;
	fin.open("dic.txt",ios::in);
	int i=0,j,n;
	while(!fin.eof())
	{
		fin>>b[i].en>>b[i].az>>ws;
		i++;
	}
	fin.close();
	n=i;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1;j++)
	if((b[i+1].en).compare(b[i].en)<0)
	swap(b[i+1],b[i]);
	
	fout.open("dic.txt",ios::out);
	for(i=0;i<n;i++)
	fout<<b[i].en<<endl<<b[i].az<<endl;
	fout.close();
	
	dlist();	
		
	}while(ch=='Y'||ch=='y');
}
//**********************
void dic::dinput()
{
	ifstream fin;
	fin.open("dictxt",ios::in);
	while(!fin.eof())
	{
		fin>>a.en>>a.az>>ws;
		cout<<setw(20)<<a.en<<setw(20)<<a.az<<endl;
	}
	fin.close();
	
}
//**********************
void dic::doutput()
{
	cout<<"Enter new words (EN-AZ)\n";
	cout<<"EN: "; cin>>a.en;
	cout<<"AZ: "; cin>>a.az;
	ofstream fout;
	fout.open("dic.txt",ios::app);
	fout<<a.en<<endl;
	fout<<a.az<<endl;
	fout.close();
	
}
//**********************
void dic::dmenu()
{ do
  { system("cls");
   	cout<<"******EN-AZ DICTIONARY*******"<<endl;
	cout<<"1. ADD\n";
	cout<<"2. FIND\n";
	cout<<"3. LIST\n";
	cout<<"4. DEL\n";
	cout<<"5. SORT\n";
	cout<<"6. EXIT\n";
	char ch;
	cin>>ch;
	switch(ch)
	{	case '1': dadd(); break;
		case '2': dfind(); break;
		case '3': dlist(); break;
		case '4': dremove(); break;
		case '5': dsort(); break;
		case '6': exit(1); break;
	}
	
	system("pause");
  }while(1);
}
//**********************
void dic::dstart()
{
	dmenu();
}
//**********************

int main() {
	dic d;
	d.dstart();
	return 0;
}
