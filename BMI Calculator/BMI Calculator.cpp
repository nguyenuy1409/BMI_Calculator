#include <iostream>
#include <string>

struct User {
    std::string Full_name;
    int age;
    float height;
    float weight;
    int body_measurements[3]; //bust, waist and hip measurements
};

void Body_mass_index(User user) {
    float bmi = user.weight / (user.height * user.height);
    std::string result;
    if (bmi < 18.5) {
        result = "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 24.9) {
        result = "Normal weight";
    }
    else if (bmi >= 25 && bmi < 29.9) {
        result = "Overweight";
    }
    else {
        result = "Obesity";
    }
    std::cout << "Your BMI is: " << bmi << std::endl;
    std::cout << "You are: " << result << std::endl;
}

int main() {
    User user;
    std::getline(std::cin, user.Full_name);
    std::cin >> user.age;
    std::cin >> user.height;
    std::cin >> user.weight;
    std::cin >> user.body_measurements[0]; //bust
    std::cin >> user.body_measurements[1]; //waist
    std::cin >> user.body_measurements[2]; //hip
    Body_mass_index(user);
    system("pause");
    return 0;
}
