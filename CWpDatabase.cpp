
// System include files //
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <map>

// Own include files //
#include "CWpDatabase.h"
#include "CWaypoint.h"

using namespace std;

//Method Implementations

CWpDatabase::CWpDatabase() {
	// TODO Auto-generated constructor stub
}

void CWpDatabase::addWaypoint(CWaypoint const &wp)
{
	//Inserting waypoints in the map//

	mymapWp.insert(pair<string,CWaypoint>(wp.getName(),wp));
	map<string,CWaypoint> :: iterator i;
	cout << "==========" << endl;
	cout<<"WAYPOINTS IN DATABASE"<<endl;
		for(i=mymapWp.begin();i!=mymapWp.end();i++)
		     {

		    	 cout<<"Name of Waypoint is "<<(i->first)<<endl;
		    	 cout<<"Latitude is "<<(i->second).getLatitude()<<"  and Longitude is "<<(i->second).getLongitude()<<endl;

		     }


}


CWaypoint* CWpDatabase::getPointerToWaypoint(string name){

	    CWaypoint* ptrwp;


// Implemeting the STL map container for storing Waypoints //

        //std::map<string, CWaypoint> mymapWp;
		std::map<string,CWaypoint> :: iterator it;
		for (it=mymapWp.begin(); it!=mymapWp.end(); ++it)
		{
		    if (name == (*it).first)
				{

					ptrwp = &(it->second);
					return ptrwp;

				}

			}
			return 0;
		}





void CWpDatabase::print(){

}


CWpDatabase::~CWpDatabase() {
	// TODO Auto-generated destructor stub
}

void CWpDatabase::getMapWp(map<string,CWaypoint> & mapWp)  // To be handled afterwards.
{
	// Getter function(used in CDerived) implementation for accessing the map container of waypoints//
	map<string,CWaypoint> :: iterator it=mymapWp.begin();

		for(;it!=mymapWp.end();++it)
		{
			mapWp.insert(pair<string,CWaypoint>(it->first,it->second));

		}




}

void CWpDatabase::removeDb()
{
   mymapWp.clear();                     // This method will be used in "Replace Mode" of the function read data in CDerived Class. //
}


