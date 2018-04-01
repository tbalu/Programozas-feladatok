#include <iostream>
#include <fstream>
using namespace std;
int main(int argc , char *argv[])
{
	for(int i=1;i<argc;i++)
		{//cout<<"Hello "<<*++argv<<endl;
			string line;
			char *file = *++argv;
			string filename=file;
			//std::fstream file (*++argv, std::ios_base::in);			
			ifstream theFile;
			theFile.open(filename);
		if(theFile.is_open())
 		{
			cout<<filename<<":\n"<<endl;
				while(getline(theFile ,line))
			{
				cout<<line<<endl;
			}
		}
		else cout<<"A "<<filename<<"fajl nem létezik"<<endl;
		theFile.close();
}
}
