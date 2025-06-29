// VexMotor.hpp
#pragma once
#include "pros/motors.hpp"

enum class CartridgeType {
    RED,    // 100 RPM
    GREEN,  // 200 RPM
    BLUE    // 600 RPM
};

class VexMotor {
private:
    pros::Motor motor;
    int speed;
    CartridgeType cartridge;

    int getRPM(CartridgeType cart);

public:
    VexMotor(int port, CartridgeType cart = CartridgeType::GREEN);

    void setSpeed(int percent);
    int getSpeed() const;
    double getTemperature() const;
    void moveForwardDistance(double inches);
    void moveForwardTime(int ms);
    void stop();
};
