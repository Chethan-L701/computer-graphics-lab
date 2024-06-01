#include <CGLab.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
choiceloop:
    std::println(std::cout, "Enter the OpenGL Program to be executed : \n"
                            "1. Basics\n"
                            "2. Bresenham's line\n"
                            "3. 2D Transformations\n"
                            "4. 3D Transformations\n");
    int choice{};
    std::cin >> choice;
    switch (choice) {
    case 1:
        Basic::execute(argc, argv);
        break;
    case 2:
        BresenhamLine::execute(argc, argv);
        break;
    case 3:
        Transformations2D::execute(argc, argv);
        break;
    case 4:
        Transformations3D::execute(argc, argv);
        break;
    default:
        std::println(std::cout, "Invalid Choice!");
        goto choiceloop;
        break;
    }
    return 0;
}
