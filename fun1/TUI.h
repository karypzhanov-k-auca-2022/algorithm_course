#ifndef ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_TUI_H
#define ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_TUI_H

#include <iostream>
#include <string>

class TUI {
private:
    double maxDistance;

public:
    TUI(double maxDistance)   {
        this->maxDistance = maxDistance;
    }

    TUI() {}

    void displayMenu() {
        int choice;
        std::cout << "Please, enter the maximum positive distance between a plane can fly (km): ";
        std::cin >> maxDistance;
        std::cout << "Now, tell me what do you want to accomplish?" << std::endl;
        std::cout << "1. Check if a route between two cities exists." << std::endl;
        std::cout << "2. Create a route between two cities." << std::endl;
        std::cout << "3. Create a route map between all the cities." << std::endl;
        std::cout << "4. Browse the flight network." << std::endl;
        std::cout << "5. Play a game." << std::endl;
        std::cout << "6. Exit." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        executeChoice(choice);
    }

    void executeChoice(int choice) {
        try {
            switch (choice) {
                case 1:
                    std::cout << "You chose option 1" << std::endl;
                    break;
                case 2:
                    std::cout << "You chose option 2" << std::endl;
                    break;
                case 3:
                    std::cout << "You chose option 3" << std::endl;
                    break;
                case 4:
                    std::cout << "You chose option 4" << std::endl;
                    break;
                case 5:
                    std::cout << "You chose option 5" << std::endl;
                    break;
                case 6:
                    std::cout << "You chose option 6" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
        }
    }
};

#endif // ALGORITHMS_PERSONAL_REPO_KARYPZHANOV_K_AUCA_2022_TUI_H
