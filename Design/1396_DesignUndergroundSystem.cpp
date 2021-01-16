class Passenger {
    
 private:
    
    string startStation;
    int startTime;
    
public:
    
    Passenger() : startStation(""), startTime(0) {}
    
    Passenger(const string& s, const int& t) : startStation(s), startTime(t) {}
    
    string getStartStation() {
        return startStation;
    }
    
    int getStartTime() {
        return startTime;
    }
    
};

class Route {
    
private:
    
    int n;
    int totalTime; 
    
public:
    
    Route() : n(0), totalTime(0) {}
    
    void addTime(const int& time) {
        ++n;
        totalTime += time;
    }
    
    double getAverageTime() {
        return (double)(totalTime) / n;
    }
    
};



class UndergroundSystem {
    
private:
    
    unordered_map<int, Passenger> passengers;
    unordered_map<string, unordered_map<string, Route>> routes;
    
    
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        passengers[id] = Passenger(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        routes[passengers[id].getStartStation()][stationName].addTime(t - passengers[id].getStartTime());
        passengers.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        return routes[startStation][endStation].getAverageTime();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */