# Industrial Temperature Alarm System using Arduino UNO

A mini industrial-style temperature monitoring and alarm system built using Arduino UNO, thermistor sensor, LEDs, and passive buzzer.

This project simulates a basic industrial temperature monitoring and alarm mechanism commonly used in automation and control systems.

---

# Project Overview

This system continuously monitors temperature using a thermistor sensor.

When the temperature exceeds a predefined threshold:

- Red LED turns ON
- Passive buzzer activates
- Green LED turns OFF

When the temperature is normal:

- Green LED stays ON
- Red LED and buzzer remain OFF

This project introduces fundamental concepts used in instrumentation and control engineering such as:

- Analog sensor reading
- Voltage divider circuit
- Alarm systems
- Monitoring systems
- Basic control logic

---

# Components Used

| Component | Quantity |
|---|---|
| Arduino UNO R3 | 1 |
| Breadboard | 1 |
| Thermistor | 1 |
| 10K Resistor | 1 |
| Red LED | 1 |
| Green LED | 1 |
| 220Ω Resistor | 2 |
| Passive Buzzer | 1 |
| Jumper Wires | Several |

---

# System Logic

| Condition | Green LED | Red LED | Buzzer |
|---|---|---|---|
| Normal Temperature | ON | OFF | OFF |
| High Temperature | OFF | ON | ON |

---

# Breadboard Layout

## Thermistor Section

| Component | Position |
|---|---|
| Thermistor leg 1 | E10 |
| Thermistor leg 2 | E15 |
| 10K resistor | A15 → rail blue (GND) |

### Connections

| From | To |
|---|---|
| A10 | Red rail (+5V) |
| B15 | Arduino A0 |

---

## Red LED Section

| Component | Position |
|---|---|
| Red LED positive leg | E2 |
| Red LED negative leg | E3 |
| 220Ω resistor | A3 → blue rail |

### Connections

| From | To |
|---|---|
| A2 | Arduino Pin 3 |

---

## Passive Buzzer Section

| Component | Position |
|---|---|
| Buzzer positive (+) | E7 |
| Buzzer negative (-) | Blue rail |

### Connections

| From | To |
|---|---|
| A7 | Arduino Pin 4 |

---

## Green LED Section

| Component | Position |
|---|---|
| Green LED positive leg | E21 |
| Green LED negative leg | E22 |
| 220Ω resistor | A22 → blue rail |

### Connections

| From | To |
|---|---|
| A21 | Arduino Pin 2 |

---

# Power Connections

| Arduino | Breadboard |
|---|---|
| 5V | Red rail |
| GND | Blue rail |

---

# Arduino Code

```cpp
int sensorPin = A0;

int ledHijau = 2;
int ledMerah = 3;
int buzzer = 4;

void setup() {

  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if(sensorValue > 615) {

    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);

    tone(buzzer, 1000);

  }

  else {

    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, HIGH);

    noTone(buzzer);

  }

  delay(500);
}
```

---

# How It Works

The thermistor changes its resistance depending on temperature.

Together with the 10K resistor, it forms a voltage divider circuit that produces varying analog voltage values.

Arduino reads this analog voltage using pin A0.

If the sensor value exceeds the threshold:

- Alarm activates
- Red LED turns ON
- Buzzer produces sound

Otherwise:

- Green LED remains ON
- System stays in safe condition

---

# Features

- Real-time temperature monitoring
- High temperature warning system
- Visual alarm indicators
- Audible alarm system
- Serial monitor monitoring
- Simple industrial control logic

---

# Applications

This project can simulate:

- Industrial overheat alarm systems
- Boiler temperature warning systems
- Motor overheating detection
- Basic industrial monitoring systems
- Introductory instrumentation systems

---

# Serial Monitor

Open:

```text
Tools → Serial Monitor
```

Baud rate:

```text
9600
```

The serial monitor displays real-time sensor values.

---

# Future Improvements

Possible future upgrades:

- LCD display integration
- Fan automation
- IoT monitoring
- Data logging
- PID control
- Relay module integration
- SCADA/HMI simulation

---

# Project Images

## Project Preview

![Project](images/project.jpg)

---

# Author

Aditya Daffa

---

# License

This project is open-source and free to use for educational purposes.
