/*
 * CDerived.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: Arsalan Khan
 */


// Own include files.//
#include "CDerived.h"
#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CWaypoint.h"
#include "CPOI.h"
#include "CRoute.h"
#include "CNavigationSystem.h"

//System include files.//

#include <map>
#include <list>
#include <vector>
#include <string.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;


//CDerived::CDerived()
//{
//	// TODO Auto-generated constructor stub
//
//}

void CDerived::setMediaName(string name) {
// sets the name of the storage(file) media to be used.
//Wpdatabasefile = name+"-wp.txt";
//Poidatabasefile = name+"-poi.txt";
m_medianame = name;
//m_medianame = name+"-poi.txt";


}

bool CDerived::writeData (const CWpDatabase& waypointDb, const CPoiDatabase& poiDb) {
//--------- IMPLEMENTATION OF WRITE METHOD-------------------- //


//------DECLARING THE WRITE DATA METHOD FOR WAYPOINTS------//
		string cwaypoint = m_medianame+"wp.txt";

		ofstream wpfile;


        //string wpfilename;

		//fstream myfile;
		//myfile.open("csv-wp.txt");
		wpfile.open(cwaypoint.c_str());

			//myfile.open((m_medianame + "-wp.txt").c_str());
			  if (wpfile.is_open())
			  {
				  map<string,CWaypoint> mymapWp;
				  CWpDatabase cwaypoint=waypointDb;
				  cwaypoint.getMapWp(mymapWp);  // Getter function called for accessing map of waypoint//

				// Declaring local variables of waypoints.//
				  string wpname;
				  double wplatitude=0;
				  double wplongitude=0;
				//Performing iteration procedure //

				  std::map<string,CWaypoint> :: iterator i;
				  for(i=mymapWp.begin();i!=mymapWp.end();++i)

       {
			wpname=i->second.getName();
			wplatitude=i->second.getLatitude();
			wplongitude=i->second.getLongitude();


// accessing the attributes and operations of waypoints and writing into a file //


			wpfile<<wpname<<";"<<wplatitude<<";"<<wplongitude<<"\n";
			//wpfile<<"Name of Waypoint is "<<(i->second.getName()==wpname)<<endl;
		    //wpfile<<"Latitude is "<<(i->second.getLatitude()==wplatitude) << endl;
		    //wpfile<<"  and Longitude is "<<(i->second.getLongitude()==wplongitude)<<endl;

				//	  wpfile << wpname << wplatitude << wplongitude;
	   }



				  wpfile.close();
				  // return true;
			   }
				  	  else {
				  		  cerr << "Unable to open file" << endl;
				  		  return false;
				  	       }

/////////////////////////////////////////////////////////////////////////////
// SETTING MEDIANAME FOR POI //
			  string cpoi = m_medianame+"poi.txt";

			  		ofstream poifile;
			  		// Declaring local variables of waypoints.//

			          //string wpfilename;

			  		//fstream newfile;
			  		//newfile.open("csv-poi.txt");
			  		poifile.open(cpoi.c_str());


			 //myfile.open((m_medianame + "-wp.txt").c_str());
			  			  if (poifile.is_open())
			  			  {
			  				  map<string,CPOI> mymapPOI;


			  				  CPoiDatabase CPOIobj=poiDb;
			  				  CPOIobj.getMapPoi(mymapPOI);  // Getter function called for accessing map of POI//


             // Declaring local variables for POI //
	// We are using getAllDataByReference function in order to have direct access to POIs and then we will implement write operation.//
			  				string description;
			  				string poiname;
			  				double poilatitude;
			  				double poilongitude;
			  				 t_poi type;

			  				  map<string,CPOI> :: iterator i;
			  				  for(i=mymapPOI.begin();i!=mymapPOI.end();++i)

			         {
			  	(i->second).getAllDataByReference(poiname,poilatitude,poilongitude,type,description);

			  					 switch(type)
			  							{

			  							case RESTAURANT:
			poifile << " RESTAURANT: " << poiname <<";"<< description << ";" << poilatitude << ";" << poilongitude << "\n" ;
			  								    //CWaypoint::print(MMSS);
			  								    break;

			  						    case SIGHTSEEING:
			 poifile << " SIGHTSEEING: " << poiname <<";"<< description << ";" << poilatitude << ";" << poilongitude << "\n" ;
			  						    	//CWaypoint::print(MMSS);
			  						    	break;
			  							}








//			  			(i->second).getAllDataByReference(poiname,poilatitude,poilongitude,poitype,description);
//			  			//poifile << poiname << poilatitude << poilongitude << poitype << description;
//			 poifile<<poitype<<";"<<poiname<<";"<<description<<";"<<poilatitude<<";"<<poilongitude<<"\n" << endl;



			  	   }



			  				  poifile.close();

			  			   }
			  				  	  else {
			  				  		  cerr << "Unable to open file" << endl;
			  				  		  return false;
			  				  	       }




	return true;
}

bool CDerived::readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode) {
	// reading a text file


//	IMPLEMNENTATION OF READ DATA OPERATION OF WAYPOINT TEXT FILE.//


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////If Merge mode is "REPLACE",existing content in the map will be removed before inserting the content from the persistent /////////////////////////

		if (mode == REPLACE)
		{
			//Empty the "CPoiDatabase" & "CWpDatabase" map containers by using remove functions from their respective classes.//////
			waypointDb.removeDb();
			poiDb.removeDb();


			cout << "Replace Mode for reading file is in operation" << endl;
			ifstream filewaypoint, filepoi;
			int line_spacing=0;   // Declaring this for counting lines //

			//int line_spacing2 = 0;
			////////////////-------IMPLEMENTATION OF "WAYPOINT"--------//////////////////////////

			// Setting media name and important attributes for file handling //

			filewaypoint.open((m_medianame + "-wp.txt").c_str());
			if (filewaypoint.is_open())
			{
				string CCSVline;
				while (getline(filewaypoint, CCSVline))
				{
					//Initializing the breaking word with character so that we can check and distinguish  between different fields//
					char checkbreak = ' ';
					//Converting string into stream so we have to take a line from file //
					istringstream CCSVstream(CCSVline);

					//Declaring a vector container for waypoints//
					vector<string> CCSV_waypoint_element;

					//Preliminary Checking of the line. If it has ; and its not empty //
					// Also, we have to check particular string. //
					if (CCSVline.find(';') != string::npos)
					{
						checkbreak = ';';
						cout << " NOTATION: semi-colon found" << endl;
						string CCSVelement;
						while (getline(CCSVstream, CCSVelement, checkbreak))
						{
							CCSV_waypoint_element.push_back(CCSVelement);
						}
						vector<string>::iterator a;
						a = CCSV_waypoint_element.begin();



						line_spacing++;
						if (!(*a).empty())
						{
							if (CCSV_waypoint_element.size() == 3)
							{
								cout << "This element is a WAYPOINT " << endl;
								vector<string>::iterator b;
								b = CCSV_waypoint_element.begin();
//String to stream conversion because we have to read the characters of stream from file.//
// atof is used because we have to convert the latitude and longitude parameter into double //

						istringstream stTost(*(b + 1));
						istringstream stTostt(*(b + 2));
						double de;
						char ce;
						if ((stTost >> de) && (stTostt >> de))
								{
									waypointDb.addWaypoint(
			CWaypoint((*b),atof((*(b + 1)).c_str()),atof((*(b + 2)).c_str())));
								}
								else if ((stTost >> ce) && (stTostt >> ce))
								{
						cerr<< "ERROR! The latitude and longitude values are not in double format " << endl;
								}
							}

						}
						else
						{
		cerr<< "ERROR! The waypoint content declared in vector is empty " << endl;
						}
					}
					else
					{
	cerr << "ERROR! Cannot have access to the respective format of file becuase it is not found ;" << endl;
					}
				}
			}
			else
			{
				cerr << "ERROR: file is not opened" << endl;
				return false;
			}

////////////////-------POI--------/////////////////////////////////////////////////////

			cout << "This element is a POI" << endl;
			filepoi.open((m_medianame + "-poi.txt").c_str());
			if (filepoi.is_open())
			{
				string CCSVline;
				while (getline(filepoi, CCSVline))
				{

		//Initializing the breaking word with character so that we can check and distinguish  between different fields
		// We have use for breaking of characters in empty commas which means no character //
					char checkbreak = ' ';
					//Converting string to stream using stringstream function //
					istringstream CCSVstream(CCSVline);

					//Declaring a vector container for POIs//
					vector<string> CCSV_poi_element;

					//Preliminary Checking of the line. If it has ; and its not empty //
					// Also, we have to check particular string. POIs have total 5 parameters //
					if (CCSVline.find(';') != string::npos)
					{
						checkbreak = ';';
						cout << " NOTATION:semi-colon found" << endl;
						string CCSVelement;
						while (getline(CCSVstream, CCSVelement, checkbreak))
						{
							CCSV_poi_element.push_back(CCSVelement);
						}
						vector<string>::iterator k ;
						int line_figuring = 0;
						k = CCSV_poi_element.begin();
						line_figuring++;
						if (!(*k).empty())
						{
							if (CCSV_poi_element.size() == 5)
							{
								vector<string>::iterator l;

								l = CCSV_poi_element.begin();

				//String to stream conversion because we have to read the characters of stream from file.//
				// atof is used because we have to convert the latitude and longitude parameter into double //
                // We have to check the POI with respect to the "TYPE" we defined //
								istringstream stTost(*(l + 3));
								istringstream stTostt(*(l + 4));
								double dd;
								char cc;

								if ((stTost >> dd) && (stTostt >> dd))
								{

									t_poi TYPE;
									if ((*l) == "RESTAURANT")
										TYPE = RESTAURANT;

									else if ((*l) == "SIGHTSEEING")
										TYPE = SIGHTSEEING;



									poiDb.addPoi(
			CPOI(TYPE, *(l + 1), *(l + 2),atof((*(l + 3)).c_str()),
													atof((*(l + 4)).c_str())));
								}
								else
								{
									if ((stTost >> cc) && (stTostt >> cc))
					cerr << "ERROR! The latitude and longitude values are not in double format " << endl;
								}
							}
						}
						else
						{
					cerr<< "ERROR! The POI element object of string is empty. " << endl;
						}
					}
					else
					{
						cerr << " ERROR! Undefined format of file. Nothing found"
								<< endl;
						return false;
					}
				}
			}
			else
			{
				cerr << "ERROR! Cannot open File " << endl;
				return false;
			}
		}

//////If Merge mode is "MERGE"//////////////////////////////////////////////////////////////////////
else if (mode == MERGE)
   {
	cout << "Merge Mode for reading file is in operation" << endl;
	ifstream filewaypoint, filepoi;
	int linespacing;


			filewaypoint.open((m_medianame + "-wp.txt").c_str());
			if (filewaypoint.is_open())
			{
				string CCSVline;
				while (getline(filewaypoint, CCSVline))
				{
					//Initialize the character breaking word //
					char checkbreak = ' ';

					//converting string to stream using stringstream function //
					istringstream CCSVstream(CCSVline);

					//declaring a temporary vector for storing waypoints //
					vector<string> CCSV_wp_element;

					//checking if the line. if it have ; and its not empty

					//Preliminary Checking of the line. If it has ; and its not empty //
					// Also, we have to check particular string//


					if (CCSVline.find(';') != string::npos)
					{
						checkbreak = ';';
						cout << " semi-colon found" << endl;
						string CCSVelement;

						while (getline(CCSVstream, CCSVelement, checkbreak))
						{
							CCSV_wp_element.push_back(CCSVelement);
						}
						vector<string>::iterator a;
						a = CCSV_wp_element.begin();
						linespacing++;
						if (!(*a).empty())
						{
							if (CCSV_wp_element.size() == 3)
							{
								cout << "This segment is a Waypoint" << endl;
								vector<string>::iterator b;
								b = CCSV_wp_element.begin();

								istringstream stTost(*(b + 1));
								istringstream stTostt(*(b + 2));
								double de;
								char ce;
								if ((stTost >> de) && (stTostt >> de))
								{
									waypointDb.addWaypoint(
											CWaypoint((*b),
													atof((*(b + 1)).c_str()),
													atof((*(b + 2)).c_str())));
								}
								else if ((stTost >> ce) && (stTostt >> ce))
								{
									cerr
						<< "ERROR! The values of Latitude and longitude are not in double format" << endl;
								}
							}

						}
						else
						{
							cerr
				<< "ERROR! The content of first element is empty. Or iterator is not working" << endl;
						}
					}
					else
					{
						cerr << "ERROR! format of file is not correct, not found ;"
								<< endl;
					}
				}
			}
			else
			{
				cerr << "ERROR! file is not opened" << endl;
				return false;
			}

//////////////////////---POI----///////////////////////////////

			cout << "This segment is a POI" << endl;
			filepoi.open((m_medianame + "-poi.txt").c_str());
			int line_figuring=0;
			if (filepoi.is_open())
			{
				string CCSVline;
				while (getline(filepoi, CCSVline))
				{
					//initializing breaking word
					char checkbreak = ' ';
					//converting string to stream
					istringstream CCSVstream(CCSVline);

					//declaring a temporary vector
					vector<string> CCSV_poi_element;

					//checking if the line. if it have ; and its not empty
					if (CCSVline.find(';') != string::npos)
					{
						checkbreak = ';';
						cout << " semi-colun found" << endl;
						string CCSVelement;
						while (getline(CCSVstream, CCSVelement, checkbreak))
						{
						   CCSV_poi_element.push_back(CCSVelement);
						}
						vector<string>::iterator m ;
						m = CCSV_poi_element.begin();
						line_figuring++;
						if (!(*m).empty())
						{
							if (CCSV_poi_element.size() == 5)
							{
								vector<string>::iterator n;

								n = CCSV_poi_element.begin();

								istringstream stTost(*(n + 3));
								istringstream stTostt(*(n + 4));
								double de;
								char ce;

								if ((stTost >> de) && (stTostt >> de))
								{

									t_poi TYPE;
									if ((*n) == "RESTAURANT")
										TYPE = RESTAURANT;

									else if ((*n) == "SIGHTSEEING")
										TYPE = SIGHTSEEING;



									poiDb.addPoi(
											CPOI(TYPE, *(n + 1), *(n + 2),
													atof((*(n + 3)).c_str()),
													atof((*(n + 4)).c_str())));
								}
								else
								{
									if ((stTost >> ce) && (stTostt >> ce))
										cerr
												<< "ERROR! The coordinates are not in double format"
												<< endl;
								}
							}
						}
						else
						{
							cerr
									<< "ERROR! first element of string is empty. or iterator is not working"
									<< endl;
						}
					}
					else
					{
						cerr << "The format of file is not correct. no ; found"
								<< endl;
						return false;
					}
				}
			}
			else
			{
				cerr << "ERROR! File is not opened" << endl;
				return false;
			}
		}
		return true;
	}










