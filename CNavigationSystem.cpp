
//System Include Files
#include<iostream>
#include<string>
#include<fstream>
#include <map>
#include <list>
#include <vector>

//Own Include Files (Navigation System's major components, GPS sensor, Route and a Point of Interest Database)//

#include "CNavigationSystem.h"
#include "CRoute.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CGPSSensor.h"
#include "CWaypoint.h"
#include "CDerived.h"
#include "CPersistentStorage.h"

using namespace std;

////Method Implementations
//
//// Member initializer list(Defining number of Waypoints and POIs)  //
//
CNavigationSystem::CNavigationSystem()
{
	//enterRoute();
//m_GPSSensor=CGPSSensor();
//m_route = CRoute(2,3);
//m_PoiDatabase= CPoiDatabase();

}
//
 //Entering POIs and waypoints to the route (STEP4)//

void CNavigationSystem::enterRoute(){
//
/// Implemeting the waypoints and POIS //
	CWaypoint WP_Amsterdam("Amsterdam ",52.3731,4.8922);
	CWaypoint WP_Darmstadt("Darmstadt ", 49.850, 8.6527);
    CWaypoint WP_University("Hochschule Darmsatdt ", 49.864740, 8.643225);

	m_WpDatabase.addWaypoint(WP_Amsterdam);
	m_WpDatabase.addWaypoint(WP_Darmstadt);
	m_WpDatabase.addWaypoint(WP_University);



	m_route.connectToWpDatabase(&m_WpDatabase);
	m_route.addWaypoint("WP_Amsterdam");
	m_route.addWaypoint("WP_Darmstadt");
	m_route.addWaypoint("WP_University");



	/// Creating POIs for our route//

	CPOI Berlin(SIGHTSEEING,"Berlin"," Berlin City Center ",52.51, 13.4);
	CPOI Landesmuseum(SIGHTSEEING,"Landesmuseum"," Best place to discover art ",49.854740, 8.643000);
	CPOI MensaHda(RESTAURANT,"Mensa HDA"," The best Mensa in the world ",49.866934, 8.637911);
	//
	m_PoiDatabase.addPoi(Berlin);
	m_PoiDatabase.addPoi(Landesmuseum);
	m_PoiDatabase.addPoi(MensaHda);
	//
	//
	/*m_route.connectToPoiDatabase(&m_PoiDatabase);
	m_route.addPoi("Berlin","WP_Amsterdam");  // We have to pass the waypoints also so that after waypoints, Pois will be added //
	m_route.addPoi("Landesmuseum","WP_Darmstadt");
	m_route.addPoi("Mensa HDA","WP_University");*/
	//m_route.connectToPoiDatabase(&m_PoiDatabase);

}


//
//// Printing POIs and waypoints to the route (STEP5)//
void CNavigationSystem::printRoute(){

	m_route.print();

}

//Checking the persistence component (setting media name, write data implementation and read data implementation )//
void CNavigationSystem::linkPersistence(string const name,CWpDatabase& wpdb, CPoiDatabase& poidb)
{
	CDerived variable;     // declaring an object in order to access the functions of CDerived Class //
	m_name=name;
	m_waypoint=wpdb;
	m_Poi=poidb;

	variable.setMediaName(m_name);
	variable.writeData(m_waypoint,m_Poi);     // Checking of write operation(we have to "ON" the enter route & print route) //

    variable.readData(m_waypoint,m_Poi,MERGE);   // Checking of read operation //

}


//
//// Getting the current position from the GPS sensor and search for the closest Point of Interest (STEP6)//
//void CNavigationSystem::printDistanceCurPosNextPoi()
//{
//
//CPOI poi;
//double Distance;
//CWaypoint presentlocation;
//
//cout << "Testing of the GPS Sensor and calculating the distance to the next point of interest " << endl;
//presentlocation= m_GPSSensor.getCurrentPosition();
//
//
//Distance = m_route.getDistanceNextPoi(presentlocation,poi);
//
//cout << "Distance to the next point of interset = " << Distance << endl;
////cout << "Point of Interest " << endl;
////cout << "=================="  << endl;
//
////poi.print();
//
//}
//
////IMPLEMENTING THE CHECKING OPERATION OF NAVIGATION SYSTEM //
void CNavigationSystem::run()
{

enterRoute();             // Entering the route details //
printRoute();
linkPersistence("MediaFileName",m_WpDatabase,m_PoiDatabase);

}
//
