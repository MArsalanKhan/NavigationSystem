

#ifndef CROUTE_H_
#define CROUTE_H_
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CPOI.h"
#include <iostream>
#include <string>
#include <list>

class CRoute {

private:
    //CWaypoint* m_pWaypoint;   // Solution "a": (CWaypoint* m_pWaypoint; is an aggregation relationship because the whole object uses a pointer to address
    //the "part" object. The memory for the part is provided by somebody else(other function)).
    // while (CPOI** m_pPoi; is an association relationship).The objects use a pointer to address the other object.//

    //container(I have taken list as an STL container)

    std::list<CWaypoint*> mylist;
	//void printList(string s, list<int> a);
	//void  test_list();



    //CPOI** m_pPoi;   // Agreegation

    CPoiDatabase* m_pPoiDatabase;
    CWpDatabase* m_pWpDatabase;
    int m_noWps;
    int m_noPois;

public:
    CRoute();  // Initial values are given to the constructor //

    CRoute(CRoute const&origin);

    ~CRoute();

    void connectToPoiDatabase(CPoiDatabase* pPoiDB);


    void connectToWpDatabase(CWpDatabase* pWpDB);
    void addWaypoint(string name);

    void addPoi(string namePoi, string afterWp);   //Type 'string' could not be resolved.

    double getDistanceNextPoi(CWaypoint const& wp, CPOI& poi);

    void print();

    //Operator Overloading function declaration.


    CRoute operator+(CRoute const& c1);
    CRoute& operator =(const CRoute &origin);
    void operator +=(string name);




};

#endif /* CROUTE_H_ */
