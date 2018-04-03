#include <iostream>
using namespace std;
	class Complex
	  {
		friend Complex operator/(double d,const Complex& z);
		public:
		    double re;
		    double im;
		    static double Re(Complex z){return z.re;};
		    static double Im(Complex z){return z.im;};
		    static Complex Conjugate(Complex z){z.im = -z.im;return z;};
		Complex(double re = 0, double im = 0):re(re),im(im){}
	  	Complex operator*(const Complex& theOther) const;
		Complex operator+(const Complex& theOther) const;
		Complex operator/(const Complex& theOther) const;
		Complex operator-(const Complex& theOther) const;
		Complex operator-() const;
	
		
	  };
	
		//std::ostream& operator<<(std::ostream& os, const Complex& z);
		extern const Complex i;
Complex Complex::operator*(const Complex& theOther) const
  {
	Complex z(theOther.re * re-theOther.im * im,
		   re * theOther.im + im * theOther.re);
	return z;
  }

Complex Complex::operator+(const Complex& theOther) const
  {
	Complex z(theOther.re +re, theOther.im + im);
	return z;
  }

Complex Complex::operator/(const Complex& theOther) const
  {
	double den = 
		theOther.re * theOther.re + theOther.im * theOther.im;
	Complex z = *this * Conjugate(theOther);
	z.re /= den;
	z.im /=den;
	return z;
  }

Complex Complex::operator-() const
  {
	Complex z(-re,-im);
	return z;
  }

Complex Complex::operator-(const Complex& theOther) const
  {
	return *this + -theOther;
  }
const Complex i(0,1);
ostream& operator<<(ostream& os, const Complex& z)
	{
		os << z.re << "+i*" << z.im;
		return os;
	}

istream& operator>>(istream& is, Complex& z)
	{
		double re, im;
		is >> re; // Valós rész
		char c = '\0';
		is >> c; // + jel
		if(c != '+')
			is.clear(ios::failbit);
		is >> c; // i
		if(c != 'i')
			is.clear(ios::failbit);
		is >> c; // * jel
		if(c != '*')
			is.clear(ios::failbit);
		is >> im; // Képzetes rész
		if(is.good()) 
			z = Complex(re,im); // Ha minden jól ment
		return is;
	}
Complex operator*(double d, const Complex& z){return z*d;};
Complex operator+(double d, const Complex& z){return z + d;};
Complex operator-(double d, const Complex& z){return - z + d;};

Complex operator/(double d, const Complex& z)
  {
	double den = z.re * z.re + z.im * z.im;
	Complex zz(z.re * d / den, z.im * d / den);
	return zz;
  };

/*ostream& operator<<(ostream& os, const Complex& z)
  {
	os<< z.re << "+i*" << z.im;
	return os;
  }*/
int main()
{
	Complex z(23,1);
	Complex w(2,1);
	cout<<"z+w= "<<z+w<<endl;
	cout<<"z-w= "<<z-w<<endl;
	cout<<"z*w= "<<z*w<<endl;
	cout<<"z/w= "<<z/w<<endl;
	Complex zz;
	cout<<"Írj be egy komplex számot!"<<endl;
	cin>>zz;
	cout<<"z+w= "<<z+w<<endl;
	cout<<"z-w= "<<z-w<<endl;
	cout<<"z*w= "<<z*w<<endl;
	cout<<"z/w= "<<z/w<<endl;

}

