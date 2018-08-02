# ATMEGA32-Project
### Project Name
-----------------
<b>Metrorail Tickiting</b><br>
### Contributor
-----------------
Mohammed Latif Siddiq Sunny<br>
Nadia Anjum Antara<br>
### Supervisor
-----------------
### project Idea (In short)
-----------------
An automated ticketing system for metrorail in Bangladesh.<br>
### Motivation
-----------------
In Bangladesh, people have to buy ticket queued in a long line. This is just waste of valuable time. Moreover, if you are in hurry, it may be brother you. This project will make the ticket buying system easier.<br>
### Project Idea (In brief)
-----------------

In this project, we are going to build a ticketing system for Metrorail in our country. Every traveler should have an <b>RFID card</b>. This unique id card will determine the balance and information of the owner. He/ She can refill the balance whenever they want (maybe via Bkash or Rocket). <br>

We maintain travelers’ information in a database. Every Metrorail have a microcontroller-based <b>RFID based checking system</b>. When a traveler comes and shows his RFID card, it checks via <b>WIFI module</b> if he has balance or not. If there is enough balance, he can enter the train. If there is not enough balance, he cannot enter the train before refilling. We send massage via <b> SIM900A kit</b>.<br>

<a href="https://github.com/lsiddiqsunny/ATMEGA32-Project/blob/master/Extra%20Files/Metrorail%20Ticketing.pptx">  Presentation Slide </a><br>
### Required Hardwares
-----------------
1. <a href="https://www.techshopbd.com/product-categories/miscellaneous-98724/41/rfid-tag-125khz-techshop-bangladesh
">RFID Card (125KHz) </a>
2. <a href="https://www.techshopbd.com/product-categories/rf/2402/125khz-rfid-module-uart-low-price-edition-techshop-bangladesh"> 125Khz RFID Module - UART(Low price edition) </a>
3. <a href="https://www.techshopbd.com/product-categories/wifi/2583/esp8266-esp-01-wifi-module-techshop-bangladesh
">ESP8266 ESP-NodeMCU Wifi Module </a>
4. <a href="https://www.techshopbd.com/product-categories/eval-board/2041/sim900a-kit-techshop-bangladesh"> SIM900A kit </a><br>

### Required Softwares
-----------------
1. Atmel Studio
2. Extreme Burner
3. Arduino IDE

### Project Work Status
-----------------
1. Send Data from ATMEGA32 to Arduino - Done
2. Receive Data from Arduino to ATMEGA32 - Done
3. Send and Receive Data Between Two ATMEGA32 - Done
4. Read RFID data -Done
5. Communicate with server by ESP8266 -Done
6. Send RFID data to server -Done
7. Connect to data base , modify  and take acknowledgement -Done
8. Send acknowledgement to ATMEGA32 -Done
9. Show acknowledgement to LCD Display -Done
10. Send AT commands to SIM900A from Arduino -Done
11. Send AT commands to SIM900A from ATMEGA -Pending for power supply

### Circuit Diagram
-----------------
### Demonstration Video
-----------------
<a href="https://www.youtube.com/watch?v=X1Xj-NGnFCQ&feature=youtu.be">Metrorail Ticketing </a>
