/*
 * CDerived.h
 *
 *  Created on: Dec 8, 2015
 *      Author: Arsalan Khan
 */

#ifndef CDERIVED_H_
#define CDERIVED_H_

#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"

#include <map>
#include <list>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

#include "CPersistentStorage.h"


class CDerived: public CPersistentStorage
{
private:
	string m_medianame;



public:
     	//CDerived();

	    void setMediaName(string name) ;   // Copying functions from abstract class.
		 bool writeData (const CWpDatabase& waypointDb, const CPoiDatabase& poiDb) ;
		//enum MergeMode { MERGE, REPLACE };
		bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode) ;

	   //virtual~CDerived();
};

#endif /* CDERIVED_H_ */
