// VexMotor.cpp
#include "VexMotor.hpp"
#include "pros/rtos.hpp"

VexMotor::VexMotor(int port, CartridgeType cart)
    : motor(port), cartridge(cart), speed(0) {
    motor.set_gearing(static_cast<pros::motor_gearset_e_t>(
        cart == CartridgeType::RED ? pros::E_MOTOR_GEARSET_36 :
        cart == CartridgeType::GREEN ? pros::E_MOTOR_GEARSET_18 :
        pros::E_MOTOR_GEARSET_06
    ));
}

int VexMotor::getRPM(CartridgeType cart) {
    switch (cart) {
        case CartridgeType::RED: return 100;
        case CartridgeType::GREEN: return 200;
        case CartridgeType::BLUE: return 600;
    }
    return 200;
}

void VexMotor::setSpeed(int percent) {
    speed = percent;
    motor.move(percent);
}

int VexMotor::getSpeed() const {
    return speed;
}

double VexMotor::getTemperature() const {
    return motor.get_temperature();
}

void VexMotor::moveForwardDistance(double inches) {
    double revs = inches / (4.0 * 3.1416); // Assuming 4" wheels
    int ticks = revs * 900; // Approximate ticks/rev
    motor.tare_position();
    motor.move_relative(ticks, speed);
}

void VexMotor::moveForwardTime(int ms) {
    motor.move(speed);
    pros::delay(ms);
    motor.brake();
}

void VexMotor::stop() {
    motor.brake();
}
