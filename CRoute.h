

#ifndef CROUTE_H_
#define CROUTE_H_
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CPOI.h"
#include <iostream>
#include <string>
#include <list>
/**
 * This Class is used to create a route which consists of Waypoints of different locations and Point Of Interests which are added to the CPOIDatabase class
 */


class CRoute {

private:
    //CWaypoint* m_pWaypoint;   // Solution "a": (CWaypoint* m_pWaypoint; is an aggregation relationship because the whole object uses a pointer to address
    //the "part" object. The memory for the part is provided by somebody else(other function)).
    // while (CPOI** m_pPoi; is an association relationship).The objects use a pointer to address the other object.//

    //container(I have taken list as an STL container)

    std::list<CWaypoint*> mylist;


    list<CWaypoint*>::iterator itr;

    //CPOI** m_pPoi;   // Agreegation

    CPoiDatabase* m_pPoiDatabase;
    CWpDatabase* m_pWpDatabase;
    int m_noWps;
    int m_noPois;

public:


    CRoute();  // Initial values are given to the constructor //

    /**
         * This is a Copy Constructor used to copy the attributes of an object to another object of the CRoute class
         *@param origin  The existing object which is being copied to a new object
         */
    CRoute(CRoute const&origin);

    /**
         * This is a destructor function which gets invoked when a route object gets destroyed
         */

    ~CRoute();

    /**
        * This function is used to connect to the CPOI Database which we have already created
        *@param pPoiDB  The address of the database object passed from the function call
        *@return void  The function does not return any value
        */
    void connectToPoiDatabase(CPoiDatabase* pPoiDB);

    /**
         * This function is used to connect to the CPOI Database which we have already created
         *@param pPoiDB  The address of the database object passed from the function call
         *@return void  The function does not return any value
         */

    void connectToWpDatabase(CWpDatabase* pWpDB);


    /**
         * This function is used to add an existing waypoint using an object of Waypoint class to the Route
         *@param wp  The object of the Waypoint class passed
         *@return void  The function does not return any value
         */
    void addWaypoint(string name);


    /**
         * This function is used to add an existing POI to the route by passing the name of the POI
         *@param namePoi  The name of the POI to be added
         *@return void  The function does not return any value
         */

    void addPoi(string namePoi, string afterWp);

    /**
         * This function is used to get the distance of the next POI from the current location using the Waypoint object and the object of the CPOI class
         *@param wp  The object of Waypoint class for passing the current location
         *@param poi  The object of CPOI class for passing the POIs
         *@return double  The distance between the current location and a POI which is of type double
         */

    double getDistanceNextPoi(CWaypoint const& wp, CPOI& poi);

    /**
         * This function is used to print the route with the entered Waypoints and POIs
         *@return void  The function does not return any value
         */

    void print();

    //Operator Overloading function declaration.


    //friend CRoute& operator +(CRoute &route1,CRoute &route2);
    CRoute& operator =(const CRoute &origin);
    void operator+=(string name);
    CRoute operator+(CRoute const& c1);



};

#endif /* CROUTE_H_ */
