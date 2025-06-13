#include <vector>
#include <unordered_map>

// C++ struct definition for Employee.
struct Employee {
  int id;
  int importance;
  std::vector<int> subordinates;
};

/**
 * Calculates the total importance value of an employee and their subordinates.
 * 
 * @param employees - Vector of Employee pointers.
 * @param id - The employee id for which the importance value needs to be calculated.
 * @return The total importance value of the employee and their subordinates.
 */
int getImportance(std::vector<Employee*> employees, int id) {
  // Unordered map to store employee id as key and employee pointer as value for constant time look-ups.
  std::unordered_map<int, Employee*> employee_map;

  // Fill the map with the employees.
  for (Employee* employee : employees) {
    employee_map[employee->id] = employee;
  }

  // Recursive helper function to calculate importance using depth-first search.
  std::function<int(int)> dfs = [&](int employeeId) -> int {
    // Retrieve the current employee from the map using their id.
    auto it = employee_map.find(employeeId);
  
    // If the employee is not found in the map, there is no such employee with the employeeId.
    if (it == employee_map.end()) {
      return 0;
    }
  
    Employee* employee = it->second;
  
    // Start with the importance of the current employee.
    int total_importance = employee->importance;

    // Include the importance of each subordinate using depth-first search.
    for (int subId : employee->subordinates) {
      total_importance += dfs(subId);
    }
  
    return total_importance;
  };

  // Kick off the recursive depth-first search process using the provided id.
  return dfs(id);
}

// Usage of the function remains the same as provided by the user.