#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace boost::filesystem;
using namespace std;
path new_path;
int f=0,nf=0;
std::string spath,line;
std::string szamlesz;
char idstring;
int linemeret;
int osszpont=0;;
int toint(std::string s) //The conversion function
{
    return atoi(s.c_str());
}

/*int main()
{
    std::string str = "12345";
    int intx = toint(str); //Convert str to an integer
    std::cout << "The string is now an int: " << intx << std::endl; //output it to the screen
    return 0;
}*/
void selective_search( const path &search_here/*, const std::string &exclude_this_directory*/)
{
	ifstream theFile(spath);
    using namespace boost::filesystem;
    recursive_directory_iterator dir( search_here), end;
    while (dir != end)
    {
        // make sure we don't recurse into certain directories
        // note: maybe check for is_directory() here as well...
       /* if (dir->path().filename() == exclude_this_directory)
       / {
            dir.no_push(); // don't recurse into this directory.
        }*/

        // do other stuff here.  
	new_path=dir->path();
	spath=new_path.generic_string();  
	//std::cout<<spath<<endl;
	ifstream theFile;
	theFile.open(spath);
	//cout<<spath<<endl;
	/*if(theFile.is_open())
		{*/
			++f;
		/*while(getline(theFile,line))
{
	cout<<line<<endl;
}
theFile.close();*/
if(theFile.is_open())
 {

  while(getline(theFile ,line))
{
//cout<<"siker"<<endl;
    cout<<line<<endl;
    linemeret=line.size()-1;
    //cout<<linemeret<<endl;
    idstring=line.at(linemeret);
    //cout<<idstring<<endl;
    while(idstring==' ')
    {
        --linemeret;
        idstring=line.at(linemeret);
    }
    while(idstring!=' ')
    {
        szamlesz.insert(szamlesz.begin(),1,idstring);
        --linemeret;
        idstring=line.at(linemeret);
    }
int sz;
    //std::string::size_type sz;
   // sz=std::stoi(szamlesz/*,&sz*/);
sz=toint(szamlesz);
osszpont+=sz;
    //cout<<szamlesz<<endl;
	cout<<sz<<endl;
    szamlesz.clear();

}
}
		
else nf++;
        ++dir;
    }
 }

int main(int argc, char *argv[])
{
char *file = *++argv;
string filename=file;
path p (filename);
  //path p = current_path();
selective_search(p);
//cout<<f<<endl;
//cout<<nf<<endl;
cout<<"Az osszpont: "<<osszpont;
  /*directory_iterator it{p};
  while (it != directory_iterator{})
    std::cout << *it++ << '\n';
    std::cout << "Vége"<<'\n';*/


	cout<<file<<endl;
}
