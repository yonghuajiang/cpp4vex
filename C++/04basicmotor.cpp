class basicmotor {
private:
    int speed; // percentage: -100 to 100

public:
    // Constructor: takes port number and cartridge type
    basicmotor(int port, int cartridgetype) {
    }

    void setSpeed(int percent) {
        speed = percent;
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
        motor.brake();
    }

    void stop() {
        motor.brake();
    }
};
