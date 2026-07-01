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

// Ángulo físico del servo cuando la app manda izquierda completa
constexpr int APP_LEFT_SERVO_ANGLE = 110;

// Ángulo físico del servo cuando la app manda derecha completa
constexpr int APP_RIGHT_SERVO_ANGLE = 65;

#endif