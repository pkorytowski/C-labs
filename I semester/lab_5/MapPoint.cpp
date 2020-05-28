#include "MapPoint.h"
#include "MapDist.h"
#include <cstring>
#include <iostream>

MapPoint* construct(const char *name,double latitude,double longitude){

    MapPoint *newStruct = new MapPoint;
    strcpy(newStruct->name,name);
    newStruct->longitude = longitude;
    newStruct->latitude = latitude;
    return newStruct;

}


void movePoint(MapPoint *point, double latitude,double longitude){
    point->longitude += longitude;
    point->latitude += latitude;
}


void print(const MapPoint *point){
    std::cout << "Współrzędne dla " << point->name <<". Długość: " << point->longitude << " Szerokość: " << point->latitude << std::endl;


}

void clear(MapPoint *point){
    delete point;

}
void clear(MapPoint *point1, MapPoint *point2, MapPoint *point3){
    delete point1;
    delete point2;
    delete point3;

}

MapPoint& closestPlace(MapPoint *point1,MapPoint *point2,MapPoint *point3){

    MapDist dist1 = distance(*point1,*point2);
    MapDist dist2 = distance(*point1,*point3);
    
    double distance1 = angularDistance(dist1);
    double distance2 = angularDistance(dist2);

    if(distance1<distance2){

    return *point2;
    }
    else{

       return *point3;
    }   



}
MapPoint inTheMiddle(MapPoint *point1, const MapPoint *point2, const char *name){
    MapPoint pt = MapPoint();
    pt.longitude = (point1->longitude+point2->longitude)/2;
    pt.latitude = (point1->latitude+point2->latitude)/2;
    strcpy(pt.name,name);
    return pt;


}
const char* getName(const MapPoint& point){
    
    
    return point.name;

}
