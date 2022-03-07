#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <iomanip>

#define R 6372795
#define PI 3.14159265

struct Coords {
    double lat;
    double lon;
};

struct Step {
    Coords pos;
    double dist;
};

class Motion
{
public:
    void calcCoords(int v, double d);
    double calcDist();
    void fillPath(double cur_dist);
    void swapCoords();
    void motionSimulation();
    void printPath();
private:
    Coords start_pos;
    Coords end_pos;
    std::vector <Step> path;
};

void Motion::motionSimulation() {
    srand(time(0));
    unsigned int time;
    std::cout << "Enter time: ";
    std::cin >> time;

    std::cout << "Enter the starting coordinates in the format 'latitude' 'longitude': ";
    std::cin >> start_pos.lat >> start_pos.lon;
    Step temp;
    temp.pos.lat = start_pos.lat;
    temp.pos.lon = start_pos.lon;
    temp.dist = 0;
    path.push_back (temp);

    for (int i = 0; i < time; i++) {
        int v = (rand() % 8) + 3;
        double d = rand() % 360;
        calcCoords(v, d);
        double dist = calcDist();
        fillPath(dist);
        swapCoords();
    }
}

void Motion::calcCoords(int v, double d) {
    end_pos.lat = start_pos.lat + v * cos(d * PI / 180) / (R * PI / 180);
    end_pos.lon = start_pos.lon + v * sin(d * PI / 180) / cos(start_pos.lat * PI / 180) / (R * PI / 180);
}

double Motion::calcDist () {
    Coords start_rad;
    Coords end_rad;
    start_rad.lat = (start_pos.lat * PI) / 180;
    start_rad.lon = (start_pos.lon * PI) / 180;
    end_rad.lat = (end_pos.lat * PI) / 180;
    end_rad.lon = (end_pos.lon * PI) / 180;

    //косинусы и синусы широт и разницы долгот
    double cos_start_lat = cos(start_rad.lat);
    double cos_end_lat = cos(end_rad.lat);
    double sin_start_lat = sin(start_rad.lat);
    double sin_end_lat = sin(end_rad.lat);
    double delta = end_rad.lon - start_rad.lon;
    double cos_delta = cos(delta);
    double sin_delta = sin(delta);

    //вычисление длины большого круга
    double y = sqrt(pow(cos_end_lat * sin_delta, 2) + pow(cos_start_lat * sin_end_lat - sin_start_lat * cos_end_lat * cos_delta, 2));
    double x = sin_start_lat * sin_end_lat + cos_start_lat * cos_end_lat * cos_delta;
    double ad = atan2(y, x);
    double dist = ad * R;

    return dist;
}

void Motion::fillPath (double cur_dist) {
    Step temp;
    temp.dist = cur_dist;
    temp.pos.lat = end_pos.lat;
    temp.pos.lon = end_pos.lon;
    path.push_back (temp);
}

void Motion::swapCoords () {
    start_pos.lat = end_pos.lat;
    start_pos.lon = end_pos.lon;
}

void Motion::printPath () {
    double total_path = 0;

    for (std::vector <Step>::iterator it = path.begin(); it != path.end(); ++it) {
        Step temp = *it;
        total_path += temp.dist;
        std::cout << "[" << std::distance (path.begin(), it) << "] " 
                  << "Coords: " << std::setw(10) << temp.pos.lat 
                  << std::setw(11) << temp.pos.lon 
                  << std::setw(13) << " distance: " 
                  << std::setw(5) << temp.dist << std::endl;
    }
    std::cout << "Distance traveled: " << total_path << std::endl;
}

class Human : public Motion
{
public:
    void editFirstName (std::string first_name) {
        this->first_name = first_name;
    }
    std::string discoverFirstName () {
        return this->first_name;
    }

    void editSecondName (std::string second_name) {
        this->second_name = second_name;
    }
    std::string discoverSecondName () {
        return this->second_name;
    }

    void editMiddleName (std::string middle_name) {
        this->middle_name = middle_name;
    }
    std::string discoverMiddleName () {
        return this->middle_name;
    }

    void editHeight (unsigned int heignt) {
        this->height = height;
    }
    unsigned int discoverHeight () {
        return this->height;
    }

    void editWeight (unsigned int weignt) {
        this->weight = weight;
    }
    unsigned int discoverWeight () {
        return this->weight;
    }
    
private:
    std::string first_name;
    std::string second_name;
    std::string middle_name;
    unsigned int height;
    unsigned int weight;
};

int main () {
    Human Human1;
    Human1.motionSimulation();
    Human1.printPath();
}