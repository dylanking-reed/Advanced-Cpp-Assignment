#include "Car.hpp"
#include "MedicalCenter.hpp"

class Ambulance : public Car, public MedicalCenter {
  public:
    Ambulance(MedicalCenter people, Car car,
      size_t patients_capacity_, size_t total_capacity_, double gas_per_passenger_);
    bool move_to(const Point2D& destination);
    
  private:
    const size_t patients_capacity;
    const size_t total_capacity;
    const double gas_per_passenger;
};
