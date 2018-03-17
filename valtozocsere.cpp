#include <iostream>
int main()
	{
	//using namespace std;
		int a = 0;
		int b = 0;
		std::cin>>a>>b;
		std::cout<<"XOR csere:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;		
		a=a^b;
		b=a^b;
		a=a^b;
		std::cout<<"Csere után:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		a=a^b;
		b=a^b;
		a=a^b;
		std::cout<<"Visszacserélés után:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		std::cout<<"Kivonásos csere:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		a=b-a;
		b=b-a;
		a=b+a;
		std::cout<<"Csere után:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;		
		a=b-a;
		b=b-a;
		a=b+a;
		std::cout<<"Visszacserélés után:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		std::cout<<"Szorzásos csere:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		a=a*b;
		b=a/b;
		a=a/b;
		std::cout<<"Csere után:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		a=a*b;
		b=a/b;
		a=a/b;
		std::cout<<"Visszacserélés után:"<<std::endl;
		std::cout<<"a="<<a<<std::endl<<"b="<<b<<std::endl;
		
	}
