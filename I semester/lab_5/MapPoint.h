#pragma once
struct MapPoint{
    char name[50];
    double longitude;
    double latitude;
};

MapPoint* construct(const char[],double,double);
void movePoint(MapPoint*, double,double);
void print(const MapPoint*);
void clear(MapPoint*);
void clear(MapPoint*, MapPoint*, MapPoint*);
MapPoint& closestPlace(MapPoint*,MapPoint*,MapPoint*);
MapPoint inTheMiddle(MapPoint*, const MapPoint*, const char *);
const char* getName( const MapPoint&);
