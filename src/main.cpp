#include "./Class/Kiosk.cpp"
#include "./Class/Date.cpp"

#include <iostream>

int main(int argc, char** argv) {
    Kiosk myKiosk = Kiosk();
    Date today = Date();
    Date yesterDay = Date("05/19/2021");

    std::cout << "today: " << today.toString() << "\n";
    std::cout << "yesterday: " << yesterDay.toString() << "\n";

    return 0;
}