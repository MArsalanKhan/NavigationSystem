

#ifndef CTEMPLATE_H_
#define CTEMPLATE_H_
#include <iostream>
#include <map>
#include <string.h>

#include "CWaypoint.h"
#include "CPOI.h"

using namespace std;

// Template Implementation //

template<class Key, class X>
class CTemplate {

private:
	std::map<Key,X> Templatedmap;

public:
    CTemplate(){};

	void addtoDatabase(X const &object);

	X* getPointerToOperator(string name);


	map<Key,X> getMapDatabase();

    void printDB();

	~CTemplate() {};
};

template<class Key,class X>
void CTemplate<Key,X>::addtoDatabase(X const &object)
{
	string name;

	name=object.getName();
    Templatedmap.insert(pair<Key,X>(name,object));
    //cout<<"The size of container is"<<Templatedmap.size()<<endl;
    //int counter=0;
   //cout<<"The number of object added is"<<counter++<<endl;
    //cout<<"Object added with the name "<<name<<endl;

    //cout<< "Now printing the database"<<endl;
    //printDB();

}

template<class Key,class X>
X* CTemplate<Key,X>::getPointerToOperator(string name)
{
	typename std::map<Key,X> :: iterator it;
	for (it=Templatedmap.begin(); it!=Templatedmap.end(); ++it)
{
        if(name==it->first)
        {
        	return &(it->second);

        }
        else {

        	cout << "Nothing is found " << endl;
        }


}
	return 0;

}
template<class Key,class X>
map<Key,X> CTemplate<Key,X>::getMapDatabase()
{
	return Templatedmap;
}

template<class Key,class X>
void CTemplate<Key,X>::printDB()
{
	typename map<Key,X> :: iterator j;
	cout<<"The size of the container is"<<Templatedmap.size()<<endl;
	for (j=Templatedmap.begin();j!=Templatedmap.end();j++)
	{
		cout << "The name of the printed parameter is " << j->first << endl;
	}
}





#endif /* CTEMPLATE_H_ */
