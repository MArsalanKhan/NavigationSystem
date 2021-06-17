//System Include Files
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>


//Own Include Files
#include "CPoiDatabase.h"
#include "CPOI.h"

using namespace std;

//Method Implementations

CPoiDatabase::CPoiDatabase() {

	//m_noPoi = 0;

}

void CPoiDatabase::addPoi(CPOI const &poi) {


	//Inserting POIs in the map and checking conditions//
	//mymapPoi.max_size();


	mymapPoi.insert(pair<string,CPOI>(poi.getName(),poi));
	map<string,CPOI> :: iterator i;
	cout << "==========" << endl;
	cout<<"POIs in DATABASE"<<endl;
	     for(i=mymapPoi.begin();i!=mymapPoi.end();i++)
	     {

	    	 cout<<"Name of POI is "<<(i->first)<< endl;
	    	 cout<<"Latitude is "<<(i->second).getLatitude()<< "  and Longitude is "<<(i->second).getLongitude()<<endl;

	     }
	//mymap.Poi

    //if (m_noPoi>=10)
	//{
	//cout << "Values are out of range " << endl;
	//}

}
//CPoiDatabase::std::map<std::string,double> my_map{

//}

//Searching for a POI with the provided name (STEP7)//
CPOI* CPoiDatabase::getPointerToPoi(string name) {

   CPOI* ptrpoi;

// Implemeting the STL map (Associative container) container for storing POIs //

	//std::map<string, CPOI> mymapPoi;
	std::map<string,CPOI> :: iterator it;


for (it=mymapPoi.begin(); it!=mymapPoi.end(); ++it)
{
    if (name == (*it).first)
		{

			ptrpoi = &(it->second);
			return ptrpoi;

		}

	}
	return 0;
}




void CPoiDatabase::getMapPoi(map<string,CPOI> & mapPoi) {

	// Getter function(used in CDerived) implementation for accessing the map container of POIs//
	map<string,CPOI> :: iterator it=mymapPoi.begin();

	for(;it!=mymapPoi.end();++it)
	{
		mapPoi.insert(pair<string,CPOI>(it->first,it->second));

	}



}

void CPoiDatabase::removeDb(){

	mymapPoi.clear();                   // This method will be used in "Replace Mode" of the function read data in CDerived Class. //


}
