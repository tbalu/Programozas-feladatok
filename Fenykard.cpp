#include <iostream>
#include <stdlib.h>
//#include<conio.h>
#include <dirent.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <boost/program_options.hpp>
using namespace std;

// A program elkészítéséhez felhasználtam ezt a programot https://github.com/kovacsferencz98/jedik_v2
//********************************************************************************************************************************

const string elsoX="Az első védés hiányzik";
const string masodikX="A másokid védés hiányzik";
const string harmadikX="A harmadik védés hiányzik";
const string elsoV="Az első védés megvan";
const string masodikV="Az második védés megvan";
const string harmadikV="A harmadik védés megvan";


class Jegy
{
	public:
		int t[3];
};
class Tanulo
{
	public:
	Tanulo (string tannev):nev(tannev),atlag(1)
		{
			jegyek[0]=1;
			jegyek[1]=1;
			jegyek[2]=1;
			/*allapot[0]=elsoX;
			allapot[1]=masodikX;
			allapot[2]=harmadikX;*/
			//cout<<u8"Új tanuló: "<<tannev<<endl;
		}
	bool ugyanaz(string tannev)
		{
			if(this->nev==tannev)
				return true;
			else return false;
		}
	
	string nev;
	int jegyek[3];	//Mindenkinek három lehetősége van jegyet szerezni 3 különböző témából.
	double atlag;	
	//string allapot[3];
	void set_nev(string nev)
		{
			this->nev=nev;
		}
	void set_jegy(int jegy, int hanyadik)
		{
			if(jegyek[hanyadik]<=jegy)	//Előfordulhat, hogy valaki javít ugyannabból a témából, így a jobb jegy számít.
				{
					this->jegyek[hanyadik]=jegy;
					this->atlag=this->atlagot_szamol();				
				}
		}
	//-------
	double atlagot_szamol()
		{
			double atl;
			double jegyek_szama=0;
			for(int i=0;i<3;i++)
			{		
				if(jegyek[i]!=1)
			{		
				atl+=jegyek[i];
				++jegyek_szama;
			}
			}
			if(jegyek_szama==0)
				atl=0;
			else
			atl=atl/jegyek_szama;
			return trunc(atl);
		}
	string get_nev()		{ return this->nev; }
	double get_atlag()		{ return this->atlag; }
	int get_jegy1()		{ return this->jegyek[0]; }
	int get_jegy2()		{ return this->jegyek[1]; }
	int get_jegy3()		{ return this->jegyek[2]; }
	void print()
		{
			//this->atlag=this->atlagot_szamol();
			cout<<nev<<" "<<atlag<<endl;//" "<<jegyek[0]<<" "<<jegyek[1]<<" "<<jegyek[2]<<endl;//" "<<this->allapot[0]<<" "<<this->allapot[1]<<" "<<this->allapot[2]<<endl;
		}
	bool operator<(const Tanulo& theOther)
		{
			return atlag<theOther.atlag;
		}
	bool operator>(const Tanulo& theOther)
		{
			return atlag>theOther.atlag;
		}
	Tanulo(const Tanulo& Diak);
	Tanulo & operator= (const Tanulo &);
};
Tanulo& Tanulo::operator= (const Tanulo& Diak)
	{
		nev=Diak.nev;
		jegyek[0]=Diak.jegyek[0];
		jegyek[1]=Diak.jegyek[1];
		jegyek[2]=Diak.jegyek[2];
		atlag=Diak.atlag;
	}
Tanulo::Tanulo(const Tanulo& Diak)
	{
		nev=Diak.nev;
		jegyek[0]=Diak.jegyek[0];
		jegyek[1]=Diak.jegyek[1];
		jegyek[2]=Diak.jegyek[2];
		atlag=Diak.atlag;
	}
vector<Tanulo> Tanulok_vektor;






bool tev_vizsgalat(const string& tevvizsgalo)
	{
		if(tevvizsgalo.find(u8"./City/Debrecen/Oktatás/Informatika/Programozás/DEIK/Prog1/Labor/Védés")!=-1)
			return true;
		else
			return false;	
	}
int melyik_vedes(const string& tevvizsgalo)
	{
		if(tevvizsgalo.find(u8"/Védés/I/")!=-1 )
			
			return 0;
		if(tevvizsgalo.find(u8"/Védés/II/")!=-1 )
			
			return 1;
		if(tevvizsgalo.find(u8"/Védés/III/")!=-1)
			return 2;
		return -1;
	}
int jegyvizsgalat(const string& tevvizsgalo)
	{
		if(tevvizsgalo.find(u8"jeles")!=-1)
			return 5;
		if(tevvizsgalo.find(u8"jó")!=-1)
			return 4;
		if(tevvizsgalo.find(u8"közepes")!=-1)
			return 3;
		if(tevvizsgalo.find(u8"elégséges")!=-1)
			return 2;
		if(tevvizsgalo.find(u8"elégtelen")!=-1)
			return 1;
		return -1;
	}
int vektorban_van_e(const string& tannev)
	{
		for(int i=0;i<Tanulok_vektor.size();i++)
			{
				//cout<<"forban vagyok"<<endl;
				if(Tanulok_vektor[i].nev==tannev)
					{//cout<<"ifben vagyok"<<endl;
				//cout<<"benne van"<<endl; 
				return i;}
				
			}
		return -1;
	}

void BubbleSort(vector<Tanulo>& pItems, unsigned itemCount)
{
 for(unsigned int j = itemCount; j>0; j--)
    {
      for(unsigned int i = 1; i<j; i++)
      {
        if(pItems[i] > pItems[i-1]) // *1
        {
          Tanulo tmp = pItems[i];
          pItems[i] = pItems[i-1]; // *2
          pItems[i-1] = tmp;
        }
      }
    }
}

// Ez a fuggvény vizsgálja a fajlt
void fajl_vizsgalo(string fajl,vector<Tanulo>& Tanulok_vektor)
{	
	ifstream tev(fajl);
	if(tev.is_open())
 {
	int ittartok=0;
 	string nevvizsgalo;
	string tevvizsgalo;
	string datum;
  while(getline(tev,nevvizsgalo,',') && getline(tev,tevvizsgalo,',') && getline(tev,datum,'\n'))
{
	
	// "" jelek között van minden ebbe a csv fájlba ezért letörli a string elejét és végét
	nevvizsgalo.erase(nevvizsgalo.begin());
	nevvizsgalo.pop_back();

	if(tev_vizsgalat(tevvizsgalo)==true)
		{
			//Megkeresi a Tanulok_vektorban a nevet
			//cout<<"jegyszerzes tortent"<<endl;
				int pozicio=vektorban_van_e(nevvizsgalo);
				if(pozicio==-1)
					{
						//Ha a pozició -1 akkor új elemet tesz a vektorba
						Tanulok_vektor.push_back(Tanulo(nevvizsgalo));
						//Beállítja a megfelelő jegyet
							Tanulok_vektor[Tanulok_vektor.size()-1].set_jegy(jegyvizsgalat(tevvizsgalo),melyik_vedes(tevvizsgalo));
							//cout<<"ujelem"<<endl;	
							//Tanulok_vektor[Tanulok_vektor.size()-1].print();
							//cout<<Tanulok_vektor[Tanulok_vektor.size()-1].jegyek[0];				
						}
				else //Amikor benne van akkor meg csak beállítja a megfelelő jegyet.
					{
						Tanulok_vektor[pozicio].set_jegy(jegyvizsgalat(tevvizsgalo),melyik_vedes(tevvizsgalo));
						//Tanulok_vektor[pozicio].print();
					}				
				pozicio=0;
			   // cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
			
		}
	//else cout<<"nem tort jegyszerzes"<<endl;
			nevvizsgalo.clear();
			tevvizsgalo.clear();
			datum.clear();
			
	
}

	}
}


//*********************************************************************************************************************************

//*********************************************************************************************************************
struct bejegyzes
{
    string nev;
    string feladat;
    string datum;
};

struct feladat
{
    string nev;
    int pont;
};

struct diak
{
    string nev;
    int pontszam;
};
struct jegy
{
	string nev;
	int ertek;
	int hanyadik;
};
std::vector<jegy> v_jegyek;
void point_sum(string path, int& points , vector<feladat>& v_feladat);
void beolvas_bejegyzesek(string path, vector<bejegyzes>& v_bejegyzes);
void diak_betolt(vector<bejegyzes>& b_vect, vector<feladat>& f_vect, vector<diak>& d_vect);
void diak_rendez(vector<diak>& d_vect, int also, int felso);
int feloszt(vector<diak>& d_vect, int also, int felso);
void fajl_vizsgalo_v_jegyek(string fajl,vector<Tanulo>& Tanulok_vektor,vector<jegy>& v_jegyek);
using namespace boost::program_options;
int evfolyam_atlag(vector<Tanulo>& Tanulok_vektor)
	{
		int van_vedes=0;
		int evf_atl=0;
		for(int i=0;i<Tanulok_vektor.size();i++)
			{
			if(Tanulok_vektor[i].atlag!=1)
			{	van_vedes++;			
				evf_atl+=Tanulok_vektor[i].atlag;
			}
			}
		return evf_atl/van_vedes;	
	}
int main(int argc, char* argv[])
{
/*std::string defops = "City/Debrecen/Oktatás/Informatika/Programozás/DEIK/Prog1/Példák/Előadás;City/Debrecen/Szórakozás/Könyv/Ismeretterjesztő/Informatika;City/Debrecen/Oktatás/Informatika/Programozás/Tankönyv\ olvasás";*/
boost::program_options::options_description desc("Options");
    desc.add_options()
    ("version", "print version number")
    ("help", "print help message")
    /*("root", boost::program_options::value< std::string > ()->default_value(defops),
     " the name of a subdirectory of the FUTURE activity tree to be processed by this program. The default value is City/Debrecen/Oktatás/Informatika/Programozás/DEIK/Prog1/Példák/Előadás")*/
    ("pontok", "Pontszámok: ./Fenykard --pontok A B              A=annak a mappának az elérési útja amiben a tevékenységek vannak.                  B=Annak a csv fájlnak az elérési útvonala amelyben a tanulók által végzett tevékenységek vannak. ")
("jegyek", "./fenykard --jegyek A B  A=annak a mappának az elérési útja amiben a tevékenységek vannak. B=annak a fájlnak a neve amiben megtalálhatók a tanulól által végzett tevékenységek.");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("version")) {
        std::cout << "Jegyek_pontok 1. verzió" << std::endl;
        return 0;
    }

    if (vm.count("help")) {
        std::cout << "" << std::endl;
        std::cout << desc << std::endl;
        return 0;
}

	 //boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
	/*fstream fajl("jegyek.dif");
   string PrFel=argv[1];*/
	

//Itt számolja ki, hogy ki mennyi pontot szerzett a tevékenységeivel


	//if (PrFel=="Pontok")	
	if(vm.count("pontok"))		
	{
   /* string masodik=argv[2];
    string harmadik=argv[3];*/
    string f_path = argv[2];
    string b_path = argv[3];
    vector<feladat> feladatok;
    vector<bejegyzes> bejegyzesek;
    vector<diak> diakok;
    int osszpont = 0;
    ifstream file;
    file.open(f_path.c_str());
    string temp_path;
    /*while(getline(file, temp_path))
    {
        point_sum(temp_path, osszpont, feladatok);
    }*/
	point_sum(f_path,osszpont,feladatok);
    beolvas_bejegyzesek(b_path, bejegyzesek);
    diak_betolt(bejegyzesek, feladatok, diakok);
    diak_rendez(diakok, 0, diakok.size()-1);
	//cout<<"meret "<<diakok.size()<<endl;
    for (int i=0; i<diakok.size(); i++)
    {
        if(diakok[i].pontszam>0)
        {
            cout<<diakok[i].nev<<"\t"<<diakok[i].pontszam<<endl;
        }
        else
            break;

    }
    cout<<"Maximalis pontok szama= "<<osszpont<<endl;
	cout<<"Feladatok"<<endl;
	for(int i=0;i<feladatok.size();i++)
		cout<<feladatok[i].nev<<feladatok[i].pont<<endl;
	for(int j=0;j<v_jegyek.size();j++)
		cout<<v_jegyek[j].nev<<" "<<v_jegyek[j].hanyadik<<" "<<v_jegyek[j].ertek<<endl;
	}

//Itt kezdi a laborjegyes részt

	//if(PrFel=="Jegyek")
	if(vm.count("jegyek"))
		{
		//string fajl=argv[2];
		  string f_path = argv[2];
    string b_path = argv[3];
			vector<feladat> feladatok;		
		//cout<<fajl<<endl;
			int osszpont = 0;
    ifstream file;
    file.open(f_path.c_str());
    string temp_path;
    /*while(getline(file, temp_path))
    {
        point_sum(temp_path, osszpont, feladatok);
    }*/
			//fajl_vizsgalo(fajl,Tanulok_vektor);
	point_sum(f_path,osszpont,feladatok);
		
	//cout<<Tanulok_vektor.size()<<endl;
	
	//cout<<"beolvastam"<<endl;
	/*for(int i=0;i<v_jegyek.size();i++)
		cout<<v_jegyek[i].nev<<" "<<v_jegyek[i].ertek<<endl;*/
	fajl_vizsgalo_v_jegyek( b_path,Tanulok_vektor, v_jegyek);
	/*for(int i=0;i<Tanulok_vektor.size();i++)
		Tanulok_vektor[i].print();
	cout<<"**********************************************************"<<endl;*/
	//BubbleSort(Tanulok_vektor,  Tanulok_vektor.size());
	std::sort(Tanulok_vektor.begin(),Tanulok_vektor.end());
		for(int i=Tanulok_vektor.size()-1;i>=0;i--)
	{		
		Tanulok_vektor[i].print();
	}
		}
	cout<<"Az evfolyam átlaga "<<evfolyam_atlag(Tanulok_vektor)<<endl;
	int vedesek=std::accumulate(Tanulok_vektor.begin(),Tanulok_vektor.end(),0, [](int i, Tanulo& t){return i+t.atlag;});
	int emberek=std::accumulate(Tanulok_vektor.begin(),Tanulok_vektor.end(),0, [](int i, Tanulo& t){return i+1;});
	cout<<vedesek/emberek<<endl;
}

void point_sum(string path, int& points , vector<feladat>& v_feladat)
{
    DIR *dir;
    dirent *pdir;
    dir = opendir(path.c_str());
    while(pdir=readdir(dir))
    {

        if(strcmp(pdir->d_name, ".")!=0 && strcmp(pdir->d_name, "..")!=0)
        {
            if(strcasestr(pdir->d_name, ".props"))
            {
                string file_path = path+"/"+pdir->d_name;
                ifstream file;
                file.open((file_path.c_str()));
                string temp;
                int actual_points = 0;
		//cout<<"feladatot olvas"<<endl;
                while(getline(file, temp))
                {
				
                    bool found_digit = false;
		
                    int end = 0;
                    int start = 0;
                    for(int i=temp.length()-1; i>=0; i--)
                    {
                        if(isdigit(temp[i]))
                        {
                            found_digit = true;
                            end = i;
                        }
                        if( found_digit && !isdigit(temp[i]))
                        {
                            start = i+1;
                            points += atoi(temp.substr(start, end-start+1).c_str());
                            actual_points += atoi(temp.substr(start, end-start+1).c_str());
                            break;
                        }

                    }
                    temp.clear();
                }
//kumentumok/Programozás/Cpp_programok/Jegyek/tanulok_jegyei/
		if(path.find("/Védés/")!=-1)
			{
				jegy tempjegy;
				
				tempjegy.nev=path.substr(path.find("City"));
				if(path.find("/I/")!=-1)
					tempjegy.hanyadik=0;
				else if(path.find("/II/")!=-1)
					tempjegy.hanyadik=1;
				else if(path.find("/III/")!=-1)
					tempjegy.hanyadik=2;
				if(path.find("/elégséges")!=-1)
					tempjegy.ertek=2;
				else if(path.find("/közepes")!=-1)
					tempjegy.ertek=3;
				else if(path.find("/jó")!=-1)
					tempjegy.ertek=4;
				else if(path.find("/jeles")!=-1)
					tempjegy.ertek=5;
			v_jegyek.push_back(tempjegy);
			}
                feladat tempfeladat;
                tempfeladat.nev = path.substr(73);
                tempfeladat.pont = actual_points;
                v_feladat.push_back(tempfeladat);
                file.close();
            }
            else
            {
                point_sum(path+"/"+pdir->d_name, points, v_feladat);
            }
        }

    }
    closedir(dir);
}

void beolvas_bejegyzesek(string path, vector<bejegyzes>& v_bejegyzes)
{
    ifstream file;
    file.open(path.c_str());

    string temp;
    while(getline(file, temp))
    {
	bejegyzes temp_b;
        int pos1 = temp.find('"');
        int pos2 = temp.find('"', pos1+1);
        temp_b.nev = temp.substr(pos1+1, pos2-pos1-1);
        pos1 = temp.find('"', pos2+1);
        pos2 = temp.find('"', pos1+1);
        temp_b.feladat = temp.substr(pos1+3, pos2-pos1-3);
        pos1 = temp.find('"', pos2+1);
        pos2 = temp.find('"', pos1+1);
        temp_b.datum = temp.substr(pos1+1, pos2-pos1-1);
        v_bejegyzes.push_back(temp_b);
    }
    file.close();
}

void diak_betolt(vector<bejegyzes>& b_vect, vector<feladat>& f_vect, vector<diak>& d_vect)
{
    for(int i = 0; i<b_vect.size(); i++)
    {
        bool benne =false;
        int pos = 0;
        for(int j = 0; j<d_vect.size(); j++)
        {
            if (strcmp(b_vect[i].nev.c_str(), d_vect[j].nev.c_str())==0)
            {
                benne = true;
                break;
                pos = j;
            }
        }
        if(!benne)
        {
            diak diak_temp;
            diak_temp.nev = b_vect[i].nev;
            diak_temp.pontszam = 0;
            d_vect.push_back(diak_temp);
        }
        for(int j = 0; j<f_vect.size(); j++)
        {


            if(b_vect[i].feladat.compare(f_vect[j].nev)==0)
            {
                for(int k = 0; k<d_vect.size(); k++)
                {
                    if (strcmp(b_vect[i].nev.c_str(), d_vect[k].nev.c_str())==0)
                    {

                        d_vect[k].pontszam += f_vect[j].pont;

                    }
                }
            }
        }

    }

}
void fajl_vizsgalo_v_jegyek(string fajl,vector<Tanulo>& Tanulok_vektor,vector<jegy>& v_jegyek)
{	
	ifstream tev(fajl);
	if(tev.is_open())
 {
	int ittartok=0;
 	string nevvizsgalo;
	string tevvizsgalo;
	string datum;
  while(getline(tev,nevvizsgalo,',') && getline(tev,tevvizsgalo,',') && getline(tev,datum,'\n'))
{
	
	// "" jelek között van minden ebbe a csv fájlba ezért letörli a string elejét és végét
	nevvizsgalo.erase(nevvizsgalo.begin());
	nevvizsgalo.pop_back();
	tevvizsgalo.erase(tevvizsgalo.begin());
	tevvizsgalo.erase(tevvizsgalo.begin());
	tevvizsgalo.erase(tevvizsgalo.begin());
	tevvizsgalo.pop_back();
	/*if(tev_vizsgalat(tevvizsgalo)==true)
		{
			//Megkeresi a Tanulok_vektorban a nevet
			//cout<<"jegyszerzes tortent"<<endl;
				int pozicio=vektorban_van_e(nevvizsgalo);
				if(pozicio==-1)
					{
						//Ha a pozició -1 akkor új elemet tesz a vektorba
						Tanulok_vektor.push_back(Tanulo(nevvizsgalo));
						//Beállítja a megfelelő jegyet
							Tanulok_vektor[Tanulok_vektor.size()-1].set_jegy(jegyvizsgalat(tevvizsgalo),melyik_vedes(tevvizsgalo));
							//cout<<"ujelem"<<endl;	
							//Tanulok_vektor[Tanulok_vektor.size()-1].print();
							//cout<<Tanulok_vektor[Tanulok_vektor.size()-1].jegyek[0];				
						}
				else //Amikor benne van akkor meg csak beállítja a megfelelő jegyet.
					{
						Tanulok_vektor[pozicio].set_jegy(jegyvizsgalat(tevvizsgalo),melyik_vedes(tevvizsgalo));
						//Tanulok_vektor[pozicio].print();
					}				
				pozicio=0;
			   // cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
			
		}*/
	//else cout<<"nem tort jegyszerzes"<<endl;
		int pozicio=vektorban_van_e(nevvizsgalo);
				if(pozicio==-1)
					{
						Tanulok_vektor.push_back(Tanulo(nevvizsgalo));
							int meret=v_jegyek.size();
							for(int j=0;j<meret;j++)
								{
									if(tevvizsgalo==v_jegyek[j].nev)
										{
											Tanulok_vektor[Tanulok_vektor.size()-1].set_jegy(v_jegyek[j].ertek,v_jegyek[j].hanyadik);
										}
								}
					}
				else
					{					
						for(int j=0;j<v_jegyek.size();j++)
								{
									if(tevvizsgalo==v_jegyek[j].nev)
										{
											Tanulok_vektor[pozicio].set_jegy(v_jegyek[j].ertek,v_jegyek[j].hanyadik);
										}
								}
					}
			nevvizsgalo.clear();
			tevvizsgalo.clear();
			datum.clear();
			
	
}

	}
}
//rendezes quick-sort segitsegevel
void diak_rendez(vector<diak>& d_vect, int also, int felso)
{
    if (also<felso)
    {
        int hatar = feloszt(d_vect, also, felso);
        diak_rendez(d_vect, also, hatar-1);
        diak_rendez(d_vect, hatar+1, felso);
    }
}

int feloszt(vector<diak>& d_vect, int also, int felso)
{
    int kulcs = d_vect[felso].pontszam;
    int i = also -1;
    for(int j=also; j<=felso-1; j++)
    {
        if (d_vect[j].pontszam>kulcs)
        {
            i++;
            diak temp;
            temp.pontszam = d_vect[i].pontszam;
            temp.nev = d_vect[i].nev;
            d_vect[i].pontszam = d_vect[j].pontszam;
            d_vect[i].nev = d_vect[j].nev;
            d_vect[j].pontszam = temp.pontszam;
            d_vect[j].nev = temp.nev;
        }
    }
    diak temp;
    temp.pontszam = d_vect[i+1].pontszam;
    temp.nev = d_vect[i+1].nev;
    d_vect[i+1].pontszam = d_vect[felso].pontszam;
    d_vect[i+1].nev = d_vect[felso].nev;
    d_vect[felso].pontszam = temp.pontszam;
    d_vect[felso].nev = temp.nev;
    return i+1;
}
