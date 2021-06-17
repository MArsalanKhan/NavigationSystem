/*
 * CJsonPersistence.h
 *
 *  Created on: Jan 5, 2016
 *      Author: Arsalan Khan
 */

#ifndef CJSONPERSISTENCE_H_
#define CJSONPERSISTENCE_H_

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




class CJsonPersistence : public CPersistentStorage
{


private:
	string m_medianame;



public:
     	//CDerived();
	CJsonPersistence();
	virtual ~CJsonPersistence();
	void setMediaName(string name) ;   // Copying functions from abstract class.
    bool writeData (const CWpDatabase& waypointDb, const CPoiDatabase& poiDb) ;
		//enum MergeMode { MERGE, REPLACE };
    bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode) ;



};

#endif /* CJSONPERSISTENCE_H_ */
