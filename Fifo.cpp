//FIFO tároló 31.oldal
#include <iostream>
#include <stdio.h>
using namespace std;

class IntFifo
{
	int* data;
	unsigned int size;
	unsigned int count;
	public:
	

	IntFifo();

	IntFifo(unsigned int size);
	
	IntFifo(const IntFifo& fifo);

	~IntFifo();

	void Put(int item);

	bool Get(int &item);

	void Print();

	int Count(){return count;}

	bool IsEmpty(){return count == 0;}
};

IntFifo::IntFifo()
{
  data = NULL;
  size=0;
  count=0;
}

IntFifo::IntFifo(unsigned int size)
{
  data=NULL;
  this->size;
  count = 0;
  if(size!=0)
    data = new int[size];
}

IntFifo::~IntFifo()
{
  delete[] data;
}

void IntFifo::Put(int item)
{
  if(count>=size)
  {
	int* temp = new int[count+1];
	
	for(unsigned int i=0; i<count; i++)
		temp[i]=data[i];

	temp[count] = item;
	++count;
	delete[] data;
	data = temp;
  }
  else
  {
	data[count]=item;
	++count;
  }
}

bool IntFifo::Get(int& item)
  {
	if(count == 0)
	  {
		fprintf(stderr, "Data request from an empy Fifo.\n");
		//cerr<<"Data request from an empy Fifo.\n";
		return false;	    	
	  }
	item = data[0];
	--count;
	if(size<=count)
	{
	  if(count == 0)
	    {
		delete[] data;
		data = NULL;
		return true;
	    }	
	  int* temp = new int[count];
	  for(unsigned int i=0; i < count; i++)
	    temp[i] = data[i+1];
	
	delete []data;
	data=temp;	
	}
	else
	{
	  for(unsigned int i = 0;i < count; i++)
	    data[i] = data[i+1];
	}
	return true;
  }
/*IntFifo::IntFifo(const IntFifo& fifo)
  {
	size=fifo.size;
	count = fifo.count;
	/*unsigned int actualSize;
	if(size>=count)
	  actualSize=fifo.size;
	else actualSize=fifo.count;
	unsigned int actualSize=(size > count)?size:count;
	if(fifo.data==NULL)
	  {
		data = NULL;
  	  }
	else
	  {
		data = new int[actualSize];
		for(unsigned int i = 0; i < count; ++i)
		  data[i]=fifo.data[i];
	  }
  }*/
void IntFifo::Print()
	{
		for(int j=0;j<count;j++)
			cout<<data[j]<<endl;
	return;
	}
IntFifo::IntFifo(const IntFifo& fifo)
{
  size = fifo.size;
  count = fifo.count;
  unsigned int actualSize=(size > count)?size:count;
  if(fifo.data==NULL)
  {
    data=NULL;
  }
  else
  {
    data = new int[actualSize];
    for (unsigned int i = 0; i < count; ++i)
      data[i] = fifo.data[i];
  }
}

/*int main()
{
	IntFifo fifo(2);
	for(int g=1;g<=10;g++)	
	  fifo.Put(g);
	int i;
	fifo.Get(i);
	fifo.Get(i);
	fifo.Get(i);
	cout<<i<<endl;
	cout<<fifo.Count()<<endl;
	IntFifo ffifo(1);
	ffifo.Put(3);
	IntFifo fifo2(ffifo);
	//fifo.Print();
	//fifo2.Print();
}*/
int main()
{
	IntFifo fifo(0);
	fifo.Put(1); // 1 a FIFO-ban
	int i;
	fifo.Get(i); // 1

	printf("%d\n",i);
	//IntFifo ffifo(fifo);
	for(i=0;i<=9;i++)
	{
		fifo.Put(i);
	}

	while(!fifo.IsEmpty())
	{
		fifo.Get(i);
		printf("%d\n",i);
	}
}



