#ifndef SG_CONSTANTS_H
#define SG_CONSTANTS_H

// pin de señal
constexpr int SERVO_PIN = 4;

// frecuencia
constexpr int PERIOD_HERTZ = 50;

constexpr int DEFAULT_uS_LOW_CONST = 500;

constexpr int DEFAULT_uS_HIGH_CONST = 2400;

// dirección

constexpr int SERVO_CENTER = 90;

constexpr int SERVO_LEFT_ANGLE = 20;

constexpr int SERVO_RIGHT_ANGLE = 125;

constexpr int SERVO_MAX_OFFSET = 35;

// Ángulo físico del servo cuando la app manda izquierda completa
constexpr int APP_LEFT_SERVO_ANGLE = 125;

// Ángulo físico del servo cuando la app manda derecha completa
constexpr int APP_RIGHT_SERVO_ANGLE = 40;

constexpr bool INVERT_STEERING = true;

#endif