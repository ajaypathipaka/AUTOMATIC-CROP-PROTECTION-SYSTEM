# AUTOMATIC-CROP-PROTECTION-SYSTEM
🌾 Horizontal Crop Cover System using Arduino

This project is an automatic horizontal crop cover system that protects crops from rain using a rain sensor and a motor driver (L298N). When rain is detected, the system automatically closes a horizontal cover; when no rain is detected, it reopens the cover.

✨ Features

Rain detection using an analog rain sensor.

Automatic motor control via L298N driver module.

Horizontal extension and retraction of cover for crop protection.

Adjustable rain sensitivity using a threshold value.

Simple and efficient Arduino-based design.

🛠 Components Used

Arduino UNO (or compatible board)

L298N Motor Driver

DC Motor

Rain Sensor Module

Power Supply (Motor + Arduino)

Horizontal cover mechanism

⚙ How It Works

The rain sensor continuously reads moisture levels.

If the reading is below the rain threshold, rain is detected:

Motor moves the cover forward to close it.

If the reading is above the threshold, no rain:

Motor moves the cover backward to open it.

The system stops the motor after each action to save energy.

📜 Arduino Code Overview

Reads rain sensor values using analogRead().

Compares values to rainThreshold.

Controls L298N IN1, IN2, and ENA pins for motor direction and speed.

Uses delay() to run the motor for a fixed time to fully open/close the cover.

🚀 How to Run

Connect the components according to the wiring in the code pin definitions.

Upload the Arduino sketch to your board.

Open the Serial Monitor at 9600 baud to view sensor readings and system actions.
