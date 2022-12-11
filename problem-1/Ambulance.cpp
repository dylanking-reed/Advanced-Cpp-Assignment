#include "Ambulance.hpp"

Ambulance::Ambulance(
  MedicalCenter people,
  Car car,
  size_t patients_capacity_,
  size_t total_capacity_,
  double gas_per_passenger_
) 
  : Car(car)
  , MedicalCenter(people)
  , patients_capacity(patients_capacity_)
  , total_capacity(total_capacity_)
  , gas_per_passenger(gas_per_passenger_)
{}

bool Ambulance::move_to(const Point2D& destination) {
  double current_mpg = this->miles_per_gallon + (this->gas_per_passenger * this->amt_people());
  double fuel_needed = this->pos.distance(destination) / current_mpg;
  if (this->can_move_to(destination)) {
    this->gas -= fuel_needed;
    this->pos = destination;
    return true;
  } else { return false; }	
}
