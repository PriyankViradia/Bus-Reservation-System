#include<iostream>
#include<string.h>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;
static int p = 0;
class a
{
	public:
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
  void install();
  void allotment();
  void position(int i);
};
class b : public a
{
	public:
	void empty();
      void show();
}bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::install()
{
    ofstream fout;
    fout.open("details.txt",ios :: app);
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  fout <<bus[p].busn<<"\t";
  cout<<"\nEnter driver's name: ";
  cin>>bus[p].driver;
  fout << bus[p].driver<<"\t";
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  fout <<bus[p].from<<"\t";
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  fout << bus[p].to<<"\t";
  cout<<"\nArrival time:";
  cin>>bus[p].arrival;
  fout << bus[p].arrival<<"\t";
  cout<<"\nDeparture time:";
  cin>>bus[p].depart;
  fout << bus[p].depart<<"\n";
  bus[p].empty();
  p++;
  fout.close();
}
void a::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
		cin>>bus[n].seat[seat/4][(seat%4)-1];
		break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
  }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
       goto top;
    }
  }
void b::empty()
{
  for(int i=0; i<8;i++)
 {
   for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void b::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
	cin>>number;
for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
    char c[1000];
  vline('*');
    ifstream fin;
    fin.open("details.txt");
    while(!fin.eof())
    {
        cout<<"\nBus no Driver  From    To   Arrival   Depart\n";
      fin.getline(c,sizeof(fin));
      if(strcmp(number,c))
       {
           cout<<c<<"\n";
           int i=0;
           while(!fin.eof())
           {
               fin.getline(c,sizeof(fin));
               cout<<c<<"\n";


           }
    }
    }
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
int main()
{
system("cls");
int w;
while(1)
{
  cout<<"\n\n\n";
  cout<<"\t\t\t1.Install\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Show\n\t\t\t"
  <<"4.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].install();
    break;
	case 2:  bus[p].allotment();
	break;
	case 3:  bus[0].show();
	break;
	case 4:  exit(0);
	default:
        cout << "invalid choice";
        break;
}
}
return 0;
}
