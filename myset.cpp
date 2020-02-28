#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
template<class X>
class myset
{

    private:
    X *arr;
    int size;

    public:
    myset()
    {
        size=0;
        //This is default Constructor
    }

    myset(int a)
    {
        size=a;
        arr=new X[size];
    }

    void getsetelements()
    {
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        duplicate();
        getarray();
    }

    void duplicate()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(arr[i]==arr[j])
                {
                    int temp=j+1;
                    for(int k=j;k<size;k++,temp++)
                    {
                        arr[k]=arr[temp];
                    }
                    size--;
                }
            }
        }
       
    }

    void getarray()
    {
        cout<<"The set is: {";
        if(size == 0)
        	cout<<" }";
        else
        	for(int i=0;i<size;i++)
	        {
	         cout<<arr[i]<<((i==size-1)?'}':',');
	        }
            cout<<endl;
    }

    int getcard()
    {
        return size;
    }

    void showcard()
    {
        cout<<"Cardinality of given set is \n"<<getcard();
    }

    int changecard(int a)
    {
        size=a;
        return size;
    }

    myset operator +(myset obj)
    {
        int n=(size+obj.getcard());
        myset temp(n);
        for(int i=0;i<size;i++)
        {
            temp.arr[i]=arr[i];
        }
        for(int j=size,i=0;j<n;j++,i++)
        {
            temp.arr[j]=obj.arr[i];
        }
        temp.duplicate();
        temp.getarray();
        return temp;
    }

    myset operator *(myset obj)
    {
        int n=(size>obj.getcard())?obj.getcard():size;
        myset temp(n);
        int k=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<obj.getcard();j++)
            {
                if(arr[i]==obj.arr[j])
                {
                    temp.arr[k++]=arr[i];
                }
            }
        }
        temp.changecard(k);
        temp.duplicate();
        temp.getarray();
        return temp;
    }

     myset operator -(myset obj)
    {
        int i=0;
        int j=0;
        int n=(size>obj.getcard())?obj.getcard():size;
        myset temp(n);
        int k=0;
        for(i=0;i<size;i++)
        {
            int flag=0;
            for(j=0;j<obj.getcard();j++)
            {
                if(arr[i]==obj.arr[j])
                {
                    flag=1;
                }
            }
            if(!flag)
            {
                temp.arr[k++]=arr[i];
            }
        }
         temp.duplicate();
         temp.changecard(k);
         temp.getarray();
        return temp;
    }

    myset operator ^(myset obj)
    {
        int n=(size>obj.getcard())?obj.getcard():size;
        myset temp(n);
        myset temp1(size+obj.getcard());
        myset temp2(n);
        cout<<"Union of ";
        temp1=*this +obj;
        cout<<"Intersection of ";
        temp2=*this *obj;
        temp=temp1-temp2;
        temp.duplicate();
        
        return temp;
    }

    bool operator ==(myset obj2)
    {
        if(size==obj2.getcard())
        {
            int flag=0;
            int counter=1;
            for(int i=0;i<size;i++)
            {
                flag=0;
                for(int j=0;j<obj2.getcard();j++)
                {
                    if(arr[i]==obj2.arr[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    counter=0;
                }
            }
            if(counter)
                return true;
            else
                return false;
        }
        else
        {
            cout<<"\nThe size of both the sets is different ";
            return false;
        }
    }

    void powerset(int sze)
	{
		cout<<"Power set is : {";
		for(int i=0;i<pow(2,sze);i++)
		{
			cout<<"{";
			for(int t=i,j=0;j<sze;j++)
			{
				if(t&1)
				{
					cout<<arr[j]<<" ";
				}
				t=t>>1;
			}
			cout<<"}";
			cout<<((i<pow(2,sze)-1)?',':'}');
            	
		}
		cout<<"\n";
		cout<<"The cardianality of power set is: "<<pow(2,sze)<<endl;	
	}

    myset &operator = (const myset &obj)
	{
		int size=obj.size;
        arr=new X[size];
        
		for(int i=0;i<size;i++)
		{
			arr[i]=obj.arr[i];
		}
		duplicate();
		return (*this);
	}

};
template<typename X>
void play(X fun)
{
    int s1,s2;
    cout<<"-----------------Welcome to Program of sets------------------------\n";
    cout<<"Enter the size of first set \n";
    cin>>s1;
    myset<X> obj1(s1);
    cout<<"Enter the elements in first set \n";
    obj1.getsetelements();
    cout<<"Enter the size of second set \n";
    cin>>s2;
    myset<X> obj2(s2);
    cout<<"Enter the elements in set \n";
    obj2.getsetelements();
    myset<X> obj3;
    int choice;
    int choose=0;
    do
    {
        cout<<"Enter 1 for Union of two set \n";
        cout<<"Enter 2 for intersection of two sets \n";
        cout<<"Enter 3 for difference of two sets \n";
        cout<<"Enetr 4 for Symmetric Difference \n";
        cout<<"Enter 5 for Check equality of two sets \n";
        cout<<"Enter 6 for Generation of power set \n";
        cout<<"Enter 7 for find Cardinality of set \n";
        cout<<"Enter your choice ";
        cin>>choice;
    switch(choice)
     {
        case 1:
        {
           obj3=obj1+obj2;
           
           break;
        }
        case 2:
        {
            obj3=obj1*obj2;
            
            break;
        }
        case 3:
        {
            int chose=0;
            int ch;
            do{
                cout<<"Enter 1 for A-B \n";
                cout<<"Enetr 2 for B-A \n";
                cout<<"Enter the choice \n";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    {
                        obj3=obj1-obj2;
                        
                        break;
                    }
                    case 2:
                    {
                        obj3=obj2-obj1;
                    
                        break;
                    }
                }
                 cout<<"Do you want to continue \n";
                 cout<<"Enter 1 for yes \n";
                 cout<<"Enter any key for abort ";
                 cin>>chose;
            }while(chose==1);
        }
        case 4:
        {
           obj3=obj1^obj2;
           
           break;
        }
        case 5:
        {
            if(obj1==obj2)
            {
                cout<<"Two sets are equal \n";
            }
            else
            {
                cout<<"Two sets are unqual \n";
            }
            break;
        }
        case 6:
        {
            system("CLS");
			cout<<"Press 1 to Generate power set of set A \n";
			cout<<"Press 2 to Generate power set of set B \n";
			int subchoice;
			cout<<"Enter your Response: \n";    
			cin>>subchoice;
				
			switch(subchoice)
				{
					case 1:
					{
						int size=obj1.getcard();
						obj1.powerset(size);
						break;
					}
					case 2:
					{
						int size=obj2.getcard();
						obj2.powerset(size);
						break;
					}
					default:
					{
						cout<<"Enter correct choice \n";		
					}
				} 
                break;
        }
        case 7:
        {
            system("CLS");
			cout<<"Press 1 to find Cardinality of set A \n";
			cout<<"Press 2 to find Cardinality of set B \n";
			int subchoice;
			cout<<"Enter your Response: \n";   
			cin>>subchoice;
				
			switch(subchoice)
				{
					case 1:
					{
						obj1.showcard();
						break;
					}
					case 2:
					{
						obj2.showcard();
						break;
					}
					default:
					{
						cout<<"Enter correct choice \n";		
					}
				} 
                break;
        }
        default:
        {
            cout<<"Enter a valid Choice \n";
            break;
        }
     }
     cout<<" Do you want to continue \n";
     cout<<"Enter 1 for yes \n";
     cout<<"Enter any key for abort ";
     cin>>choose;
    }while(choose==1);
}
void newfun()
{
    cout<<"Type of String \n";
    cout<<"1. Character \n";
    cout<<"2. Integer \n";
    cout<<"3. Double \n";
}
int main()
{
   int i;
   char c;
   double d;
   int var;
   newfun();
   cout<<"Enter your choice \n";
   cin>>var;
   switch(var)
   {
       case 1:
       {
           play(c);
           break;
       }
       case 2:
       {
           play(i);
           break;
       }
       case 3:
       {
           play(d);
           break;
       }
       default:
       {
           cout<<"Wrong Input \n";
       }
   }
}
