//System include files//
#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <list>

//Own include files//
#include "CRoute.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWpDatabase.h"

using namespace std;

CRoute::CRoute() {

	//list<CWaypoint*>mylist=NULL;
	m_pWpDatabase=NULL;
	m_pPoiDatabase=NULL;
}

CRoute::CRoute(const CRoute&origin)          // COPY CONSTRUCTOR //
{
	m_pWpDatabase=origin.m_pWpDatabase;
	m_pPoiDatabase=origin.m_pPoiDatabase;
    mylist= origin.mylist;

}

void CRoute::addWaypoint(string name) {

  // In this function,we have to search waypoint pointer IN DATABASE,
  // For this, we have to check the null condition.
if (m_pWpDatabase->getPointerToWaypoint(name) !=NULL)

{
	CWaypoint* wp = m_pWpDatabase->getPointerToWaypoint(name);
    mylist.push_back(wp);
    cout << "Waypoint added into the route " << endl;
    cout << wp->getName() << endl;


}
else {
		cerr << "ERROR: Cannot add more waypoints in a route " << endl;

}
}

void CRoute::addPoi(string namePoi, string afterWp) {

	 // In this function,we have to search poi and afterwp pointer IN DATABASE,
	  // For this, we have to check the null condition.

	if ((m_pPoiDatabase->getPointerToPoi(namePoi) !=NULL)&&(m_pWpDatabase->getPointerToWaypoint(afterWp)!=NULL))

	{

        list<CWaypoint*>::iterator itr;


     for(itr = mylist.begin(); itr!= mylist.end();++itr)
     {

    	 // Checking the condition where you have to find the afterWaypoint to add Pois//
    	 // itr contains the pointer of CWaypoint//
    	 if((*itr)->getName()==m_pWpDatabase->getPointerToWaypoint(afterWp)->getName())
    	 {
    		 // itr points to afterWp
    		 cout << "POI added into the route " << endl;
    		 mylist.insert(++itr,m_pPoiDatabase->getPointerToPoi(namePoi));

    	 }
    	 else {
    	     		 cerr << "ERROR!!! Could not find POI in the system " << endl;


     }


		//CWaypoint* poi = m_pPoiDatabase->getPointerToPoi(namePoi);
	    //mylist.push_back(poi);

}


	////calling getpointertopoi function //
//
//

}
	else {
	    	   cerr << "ERROR!!!No connection between the Route and Poidatabase  " << endl;

	}
}

void CRoute::print()
{
	    //Implementing and Printing Waypoints and POIs in the Route.
	    //Use RTTI(Dynamic Casting) to detect the type of object
	    std::list<CWaypoint*> mylist;
	    list<CWaypoint*>::iterator itr;



	     for(itr = mylist.begin(); itr != mylist.end(); ++itr)
	     {
	      (*itr)->print(2);
	       cout << (**itr);

	      CPOI* tempPoi = dynamic_cast <CPOI*> (*itr);

		if (tempPoi!=NULL)
		{
	        //cout << (*itr)->getName() << (*itr)->getLatitude() << (*itr)->getLongitude() <<  endl;
	        cout << tempPoi << endl;          // Temp Poi is the POI in our route.//
	        cout << "After Waypoints we have to add POIs " << endl;
		}
		else{
			//cout << (*itr)->getName() << (*itr)->getLatitude() << (*itr)->getLongitude() <<  endl;
	         cout << (**itr) << endl;
		}

	}



}


CRoute::~CRoute() {
//	// Destroying the memory locations  //
//
//	delete[] m_pWaypoint;
//	delete[] m_pPoi;
//#ifdef SHOWADDRESS
//	cout<< "Object is destroyed at " << this << endl;
//#endif
}
//
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {


	m_pPoiDatabase = pPoiDB;

}

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB) {
	m_pWpDatabase = pWpDB;

}

// Method implementation of Operator Overloading //


CRoute& CRoute::operator =(const CRoute&origin)
{
	m_pWpDatabase=origin.m_pWpDatabase;
	m_pPoiDatabase=origin.m_pPoiDatabase;
	mylist= origin.mylist;
    return *this;

}

void  CRoute::operator +=(string name)
{    //call the functions in addpoi, addwaypoint//
	CWaypoint *localwp = m_pWpDatabase->getPointerToWaypoint(name);
	CPOI *localpoi = m_pPoiDatabase->getPointerToPoi(name);

	if (localwp != NULL)
	{
		mylist.push_back(localwp);

//	}
//	else
//	{
//		cout << "Waypoints could not match with waypoints database " << endl;
//	}

	if (localpoi != NULL)
		{
			mylist.push_back(localpoi);

		}
		else
		{
			cout << "POIs could not match with POIs database " << endl;
		}

}
	else {
		cout << "No waypoint found " << endl;
	}
}

CRoute& operator +(CRoute &route1,CRoute &route2) {


CRoute route3;

if((route1.m_pPoiDatabase==route2.m_pPoiDatabase)&&(route1.m_pWpDatabase==route2.m_pWpDatabase))
{
	route3 = route1 + route2;
}
else {
	cerr << "ERROR!!! Not adding the Routes " << endl;
	//return route3;
}
return route3;
}

