#include "Bus.hpp"
#include <algorithm>

Bus::Bus(Car car, const std::vector<uint8_t> &passengers_, 
      double gas_per_passenger_, uint8_t max_passengers_)
  : Car(car)
  , gas_per_passenger(gas_per_passenger_)
  , max_passengers(max_passengers_)
  , passengers(passengers_)
{}

std::list<uint8_t> *Bus::generate_route(uint8_t start) {
  auto out = new std::list<uint8_t>(); 
  std::sort(this->passengers.begin(), this->passengers.end());
  for (auto stop: this->passengers) {
    if (stop == start) {
      if (out->front() != stop) out->insert(out->begin(), stop); 
    }
    if (stop > start) {
      if (out->back() != stop) out->insert(out->end(), stop); 
    }
  }
  for (auto stop: this->passengers) {
    if (stop < start) {
      if (out->back() != stop) out->insert(out->end(), stop); 
    }
  }
  return out;
}

bool Bus::move_to(const Point2D& destination) {
  double current_mpg = this->miles_per_gallon + (this->gas_per_passenger * this->passengers.size());
  double fuel_needed = this->pos.distance(destination) / current_mpg;
  if (this->can_move_to(destination)) {
    this->gas -= fuel_needed;
    this->pos = destination;
    return true;
  } else { return false; }	
}
