#include "MapPoint.h"
#include "MapDist.h"
#include <cmath>

MapDist distance(MapPoint point1,MapPoint point2){

    MapDist dist = MapDist();
    dist.latitude = point1.latitude-point2.latitude;
    dist.longitude = point1.longitude-point2.longitude;
    return dist;

}
double angularDistance(MapDist dist){

        double distance = sqrt(dist.latitude*dist.latitude+dist.longitude*dist.longitude);
    return distance;


}
