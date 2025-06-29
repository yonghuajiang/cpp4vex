#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include <string>

enum class CartridgeType {
    RED,    // 100 RPM
    GREEN,  // 200 RPM
    BLUE    // 600 RPM
};

class VexMotor {
private:
    pros::Motor motor;
    int speed; // percentage: -100 to 100
    CartridgeType cartridge;

    int getRPM(CartridgeType cart) {
        switch (cart) {
            case CartridgeType::RED: return 100;
            case CartridgeType::GREEN: return 200;
            case CartridgeType::BLUE: return 600;
        }
        return 200; // default
    }

public:
    // Constructor: takes port number and cartridge type
    VexMotor(int port, CartridgeType cart = CartridgeType::GREEN)
        : motor(port), cartridge(cart), speed(0) {
        motor.set_gearing(static_cast<pros::motor_gearset_e_t>(
            cart == CartridgeType::RED ? pros::E_MOTOR_GEARSET_36 :
            cart == CartridgeType::GREEN ? pros::E_MOTOR_GEARSET_18 :
            pros::E_MOTOR_GEARSET_06
        ));
    }

    void setSpeed(int percent) {
        speed = percent;
        motor.move(percent);
    }

    int getSpeed() const {
        return speed;
    }

    double getTemperature() const {
        return motor.get_temperature();
    }

    void moveForwardDistance(double inches) {
        // Assume 4" wheels; 1 rev = ~12.56 inches
        double revs = inches / (4.0 * 3.1416);
        int ticks = revs * 900; // 900 ticks per revolution for internal encoder
        motor.tare_position();
        motor.move_relative(ticks, speed);
    }

    void moveForwardTime(int ms) {
        motor.move(speed);
        pros::delay(ms);
        motor.brake();
    }

    void stop() {
        motor.brake();
    }
};


VexMotor leftMotor(1, CartridgeType::GREEN); // Port 1 motor, 200 RPM

void opcontrol() {
    leftMotor.setSpeed(50);                 // Set speed to 50%
    leftMotor.moveForwardDistance(24);      // Move forward 24 inches
    pros::delay(2000);                      // Wait
    leftMotor.moveForwardTime(1000);        // Move forward for 1 second
    double temp = leftMotor.getTemperature();
    std::cout << "Motor temp: " << temp << " °C" << std::endl;
}