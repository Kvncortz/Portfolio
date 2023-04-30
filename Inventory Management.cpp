#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Date
{
           int month, day, year;
};

struct Item
{
    string ItemDescription;
    
    int quantity;
    
    float wholesale;
    
    float retailCost;
    
    Date dateAdded;
};

Date String_To_MDY (char * date_ptr);

char * Strchcpy (char * target, char * source, int ch);

int Validate_Date (Date date);

Item inputItem();

void outputItem(Item);

void readInventory(string,vector<Item>&);

void writeInventory(string,vector<Item>);

int  displayMenu();

void displayRecords(vector<Item>);


int main( )

{
    vector <Item> inventory;
    
    int menuOption;
           
    string fileName;

    readInventory("inven.txt",inventory);
    
        do
		 {
            menuOption=displayMenu( );
                
            switch(menuOption)
            
				{
                    case 1:
						   {
                             inventory.push_back(inputItem());
                           }
                               
                    break;
                            
                    case 2: 
						    {
                              int menuIndex;
                              
                                do
								   {
                                     displayRecords(inventory);
                                         
                                     cout <<"Enter number of record to view: ";
                                         
                                     cin  >> menuIndex;
                                         
                                     if(menuIndex<0 || menuIndex>=inventory.size())
                                         
                                     cout<<"Invalid Input!"<<endl;
                                    }
                                
							    while(menuIndex<0 || menuIndex>=inventory.size());
								
                                 outputItem(inventory[menuIndex]);
                            }
                                
                    break;
                             
                    case 3:
						    {
                              int menuIndex;
                              
                                do
									{
                                      displayRecords(inventory);
                                                    
                                      cout << "Enter number of record to change: ";
                                                    
                                      cin  >> menuIndex;
                                                    
                                      if(menuIndex<0 || menuIndex>=inventory.size())
                                                    
									  cout << "Invalid Input!" <<endl;
                                    }
                                    
								while(menuIndex<0 || menuIndex>=inventory.size());
												 
                                inventory[menuIndex]=inputItem();
                            }
                    break;
                    
                    case 4:
						    {
                              writeInventory("inventory.txt",inventory);
                            }
                               
                    break;
                    
                }
        }
	      while(menuOption!=4);
	      
          return 0;
}

Date String_To_MDY (char * date_ptr)

{
    Date mdy_date;
    
    char month[4],
    
         day[4],
         
         year[4];
         
    char * ch_ptr;
    
    ch_ptr = date_ptr;
    
    ch_ptr = Strchcpy(month, ch_ptr, '/');
    
    ++ch_ptr;
    
    ch_ptr = Strchcpy(day, ch_ptr, '/');
    
    ++ch_ptr;
    
Strchcpy(year, ch_ptr, '\0');

mdy_date.month = atoi(month);

mdy_date.day   = atoi(day);

mdy_date.year = atoi(year);

return mdy_date;

}
char * Strchcpy(char * target, char * source, int ch)
	{
		while (*source != ch && *source != '\0')
		
    	{
          *target = *source;
          
          ++target;
          
          ++source;
                    
    	}
    	    	
*target = '\0';

return source;
    }
int Validate_Date(Date date)

   {
     int num_days [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

     int last_days [13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    	if (date.month < 1 || date.month > 12)
      	return 0;
      
    	if (date.day < 1)
     	return 0;
     
    	if (date.year % 4 == 0)
      		{
        		if (date.day > last_days[date.month])
        		return 0;
      		}

    	else

      	if (date.day > num_days[date.month])
      	return 0;
      
    	if (date.year > 100)
    	return 0;
    
    	return 1;

   } 
   
void outputItem(Item output)

   {

            cout<< endl << "Item Description :\t" <<output.ItemDescription;

            cout<< endl << "Date             :\t" <<output.dateAdded.month <<"/" <<output.dateAdded.day <<"/"   <<output.dateAdded.year;
                
            cout<< endl << "Quantity on Hand :\t" <<output.quantity;

            cout<< endl << "Wholesale Cost   :\t" <<output.wholesale;

            cout<< endl << "Retail Cost      :\t" <<output.retailCost <<endl<<endl;

   }

Item inputItem()

   {

            Item temp;

            char date[9];

            cout << "Item Description:\t";

            cin  >> temp.ItemDescription;

            do
            
			  {

                cout <<"Date in mm/dd/yy form:\t";

                cin >>date;

                temp.dateAdded=String_To_MDY(date);

                if(!Validate_Date(temp.dateAdded))

                    cout<<"Invalid Entry :: Invalid Date!\n";

              }
			
			while(!Validate_Date(temp.dateAdded));

                do
                
				{

                    cout<<"Quantity:\t";

                    cin>>temp.quantity;

                    if(temp.quantity<0)

                        cout<<"Invalid value\n";

               }
			
			while(temp.quantity<0);

                do
				
				{

                    cout <<"Wholesale Cost:\t";

                    cin  >>temp.wholesale;

                    if(temp.wholesale<0)

                        cout<<"Invalid Value\n";

                }
			
			while(temp.wholesale<0);

                do
                
				 {

                    cout <<"Retail Cost:\t";

                    cin  >>temp.retailCost;

                    if(temp.retailCost<0)

                        cout<<"Invalid value\n";

                }
			
			while(temp.retailCost<0);

                return temp;

   }

void readInventory(string fileName,vector<Item>&inventory)
   {
        cout <<"\nFile name: " <<fileName <<endl;
        
        fstream file(fileName.c_str(),fstream::in);
        
            if(file.good())
			               {
            	

                             cout<<"\t\t :: Success!\n";

                             while(!file.eof())
                             
							   {

                                 Item temp;

                                 int readsize=0;

                                 file>>readsize;

                                if(readsize)
                                
								   {
                                        file.read((char*)&temp.ItemDescription,readsize);
                                        file >>temp.dateAdded.day;
                                        
                                        file >>temp.dateAdded.month;
                                        
                                        file >>temp.dateAdded.year;
                                        
                                        file >>temp.quantity;
                                        
                                        file >>temp.retailCost;
                                        
                                        file >>temp.wholesale;

                                        inventory.push_back(temp);

                                        cout <<"\t\t :: read item: " << temp.ItemDescription << endl;

                                    }

                                }

                            }

            else

                             cout<<"\nFailed,If you Save & Exit then a new file will be created.";

                             file.close();

                             cout<<"\nClosed "<<fileName<<endl;

    }

void writeInventory(string fileName,vector<Item> inventory)

    {

            cout<<"\t :: Opening "<<fileName<<endl;

            fstream file(fileName.c_str(),fstream::out);

            if(file.good())
            
			               {

                             cout<<"\t\t :: Success!\n";

                             for(int x=0;x<inventory.size();x++)
						          
								  {

                                    file<<sizeof(inventory[x].ItemDescription);

                                    file.write((char*)&inventory[x].ItemDescription,sizeof(inventory[x].ItemDescription));

                                    file<<inventory[x].dateAdded.day<<endl;

                                    file<<inventory[x].dateAdded.month<<endl;

                                    file<<inventory[x].dateAdded.year<<endl;

                                    file<<inventory[x].quantity<<endl;

                                    file<<inventory[x].retailCost<<endl;

                                    file<<inventory[x].wholesale<<endl;

                                    cout<<"\t\t :: wrote item: "<<inventory[x].ItemDescription<<endl;

                                 }

                            }

            else

                             cout<<"\t\t :: Failure!\n";

                             file.close();

                             cout<<"\t :: Closed "<<fileName<<endl;

    }

int displayMenu()

   {

            int ch;

            do
			   {

                             cout<<"--------------------------------"<<endl;

                             cout<<"1: Add new records to the file"<<endl;

                             cout<<"2: Display any record in the file"<<endl;

                             cout<<"3: Change any record in the file "<<endl;

                             cout<<"4: Save & Exit"<<endl;

                             cout<<"--------------------------------\n>";

                             cin>>ch;

                             if(ch<1 || ch>4)

                                cout<<"Invalid Input!"<<endl;

               }
               
			while(ch<1 || ch>4);

            return ch;

   }

void displayRecords(vector<Item> inventory)

   {

            cout <<"Records:"<<endl;

            for(int x=0;x<inventory.size();x++)

                        cout<<x<<": "<<inventory[x].ItemDescription<<endl;

   }