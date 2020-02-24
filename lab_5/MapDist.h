#pragma once
struct MapDist{
    double latitude;
    double longitude;
};

MapDist distance(MapPoint,MapPoint);
double angularDistance(MapDist);
