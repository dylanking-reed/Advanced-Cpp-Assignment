#include "MedicalCenter.hpp"

MedicalCenter::MedicalCenter(std::vector<std::string> providers_, std::vector<std::string> patients_) {
  this->providers = providers_;
  this->patients = patients_;
}
size_t MedicalCenter::amt_providers() const {
  return this->providers.size();
}
size_t MedicalCenter::amt_patients() const {
  return this->patients.size();
}
size_t MedicalCenter::amt_people() const {
  return this->amt_patients() + this->amt_providers();
}
