#include <cstdlib>
#include <vector>
#include <string>

class MedicalCenter {
  public:
  MedicalCenter(std::vector<std::string> providers_, std::vector<std::string> patients_);
  size_t amt_providers() const;
  size_t amt_patients() const;
  size_t amt_people() const;
  private:
  std::vector<std::string> providers;
  std::vector<std::string> patients; 
};
