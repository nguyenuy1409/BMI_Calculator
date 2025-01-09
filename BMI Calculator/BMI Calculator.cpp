#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include "functions.h"

struct User {
    std::string Full_name;
    int age;
    float height;
    float weight;
    int body_measurements[3]; //bust, waist and hip measurements
};

void Body_mass_index(User user);
void top_wall();
void bot_wall();
void right_wall();
void left_wall();
void draw_board();
void showMenu();
void Implement(User user);

void Body_mass_index(User user) {
    float bmi = user.weight / (user.height * user.height);
    std::string result;
    if (bmi < 18.5) {
        result = "Underweight. Consider a protein-rich diet and strength training.";
    }
    else if (bmi >= 18.5 && bmi < 24.9) {
        result = "Normal weight. Maintain a balanced diet and regular exercise.";
    }
    else if (bmi >= 25 && bmi < 29.9) {
        result = "Overweight. Consider a calorie deficit diet and cardio exercises.";
    }
    else {
        result = "Obesity. Consult a doctor and follow a structured exercise and diet plan.";
    }
    std::cout << "Your BMI is: " << bmi << std::endl;
    gotoXY(15, 19);
    std::cout << "You are " << result << std::endl;
}
void top_wall(){ //the top wall
    int x = 10, y = 1;
    while (x < 100) {
        gotoXY(x, y);
        std::cout << '=';
        x++;
    }
}
void bot_wall() { //the bottom wall
    int x = 10, y = 26;
    while (x < 100) {
        gotoXY(x, y);
        std::cout << '=';
        x++;
    }
}
void right_wall() { //the right wall
    int x = 100, y = 1;
    while (y < 27) {
        gotoXY(x, y);
        std::cout << '+';
        y++;
    }
}
void left_wall() { //the left wall
    int x = 10, y = 1;
    while (y < 27) {
        gotoXY(x, y);
        std::cout << '+';
        y++;
    }
}
void draw_board() { //save the 4 sides of the wall
    SetColor(2);
    top_wall();
    bot_wall();
    right_wall();
    left_wall();
}
void showMenu() {
    gotoXY(45, 9);
    std::cout << "      BMI Calculator        \n" << std::endl;
    gotoXY(45, 10);
    std::cout << "============================\n" << std::endl;
    gotoXY(45, 11);
    std::cout << "1. Calculate BMI\n" << std::endl;
    gotoXY(45, 12);
    std::cout << "2. Exit\n" << std::endl;
    gotoXY(45, 13);
    std::cout << "============================\n" << std::endl;
    gotoXY(45, 14);
    std::cout << "Choose an option: " << std::endl;
    gotoXY(63, 14);

}
void Implement(User user) {
    gotoXY(45, 8);
    std::cout << "Enter your full name: " << std::endl;
    gotoXY(48, 9);
    std::cin.ignore();
    std::getline(std::cin, user.Full_name);
    gotoXY(48, 10);
    std::cout << "Enter your age: " << std::endl;
    gotoXY(54, 11);
    std::cin >> user.age;
    gotoXY(44, 12);
    std::cout << "Enter your height (metre): " << std::endl;
    gotoXY(54, 13);
    std::cin >> user.height;
    gotoXY(42, 14);
    std::cout << "Enter your weight (kilogram): " << std::endl;
    gotoXY(54, 15);
    std::cin >> user.weight;
    gotoXY(30, 16);
    std::cout << "Enter your body measurements (bust, waist and hip - Centimetre): " << std::endl;
    gotoXY(51, 17);
    std::cin >> user.body_measurements[0] >> user.body_measurements[1] >> user.body_measurements[2];
    gotoXY(46, 18);
    Body_mass_index(user);
    std::cin.ignore();
    std::cin.get();
    exit(0); //exit the program
}
int main() {
    User user;
    int choice;
    while (true) {
        showMenu(); //display the menu
        std::cin >> choice;
        switch (choice) {
        case 1:
            system("cls"); //clear the screen
            draw_board();
            Implement(user); //switch to BMI calculation screen
            break;
        case 2:
            gotoXY(45, 15);
            std::cout << "Exiting program. Goodbye!\n";
			return 0; //exit the program
        default:
            gotoXY(42, 15);
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    system("pause");
    return 0;
}
