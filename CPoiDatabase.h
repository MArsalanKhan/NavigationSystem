/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/
#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"
#include <map>
#include <string.h>
#include <iostream>

using namespace std;

class CPoiDatabase {

    //std::map<string,CPOI> mymapPoi;
private:
    /**
     * @link aggregationByValue 
     */
    //CPOI m_POI[10];
    //int m_noPoi;

    std::map<string,CPOI> mymapPoi;

public:

    CPoiDatabase();
    void addPoi(CPOI const &poi);  //For Adding Pois, we need a pointer object for this
    //void addPoi(t_poi type, string name,string description, double latitude, double longitude);
    CPOI* getPointerToPoi(string name);
    void getMapPoi(map<string,CPOI> & mapPoi);
    void removeDb();
};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
