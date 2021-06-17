/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"
#include <map>
#include <string.h>
#include <iostream>


#include "CTemplate.h"

using namespace std;

class CPoiDatabase:public CTemplate<string,CPOI>
{


private:
    /**
     * @link aggregationByValue 
     */


//    std::map<string,CPOI> mymapPoi;

public:

    CPoiDatabase();
    void addPoi(CPOI const &poi);  //For Adding Pois, we need a pointer object for this
    //void addPoi(t_poi type, string name,string description, double latitude, double longitude);
    CPOI* getPointerToPoi(string name);
    void getMapPoi();
    void removeDb();
    void printPoi();
};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
