

#ifndef MYCODE_CWPDATABASE_H_
#define MYCODE_CWPDATABASE_H_

#include <string.h>
#include <iostream>
#include <map>

#include "CWaypoint.h"
#include "CTemplate.h"
using namespace std;


class CWpDatabase:public CTemplate<string,CWaypoint>

{
	//std::map<string,CWaypoint> mymapWp;
private:

//	std::map<string,CWaypoint> mymapWp;

public:
	CWpDatabase();
	void addWaypoint(CWaypoint const &wp);

	CWaypoint* getPointerToWaypoint(string name);
	void getMapWp();
	void printWp();
    void removeDb();

	~CWpDatabase();
};

#endif /* MYCODE_CWPDATABASE_H_ */
