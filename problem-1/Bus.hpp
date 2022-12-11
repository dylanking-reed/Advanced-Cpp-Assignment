#include "Car.hpp"
#include <list>

class Bus: public Car {
  public:
    Bus(Car car, const std::vector<uint8_t> &passengers_, 
      double gas_per_passenger_, uint8_t max_passengers_);
    std::list<uint8_t> *generate_route(uint8_t start);
    bool move_to(const Point2D& destination);
    const double gas_per_passenger;
    const uint8_t max_passengers;
  private:
    std::vector<uint8_t> passengers;
};
