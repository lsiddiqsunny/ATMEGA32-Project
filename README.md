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
An automated ticketing system for material in Bangladesh.<br>
### Motivation
-----------------
In Bangladesh, people have to buy ticket queued in a long line. This is just waste of valuable time. Moreover, if you are in hurry, it may be brother you. This project will make the ticket buying system easier.<br>
### Project Idea (In brief)
-----------------

In this project, we are going to build a ticketing system for Metrorail in our country. Every traveler should have an <b>RFID card</b>. This unique id card will determine the balance and information of the owner. He/ She can refill the balance whenever they want (maybe via Bkash or Rocket). <br>

We maintain travelers’ information in a database. Every Metrorail have a microcontroller-based <b>RFID based checking system</b>. When a traveler comes and shows his RFID card, it checks via <b>WIFI module</b> if he has balance or not. If there is enough balance, he can enter the train. If there is not enough balance, he cannot enter the train before refilling. We send massage via <b>GSM module</b> after every action and (optional for now) anyone can know the position of the train by <b>GPS module</b>.<br>

<a href="https://github.com/lsiddiqsunny/ATMEGA32-Project/blob/master/Extra%20Files/Metrorail%20Ticketing.pptx">  Presentation Slide </a><br>
### Required Hardwares
-----------------
1. <a href="https://www.techshopbd.com/product-categories/miscellaneous-98724/41/rfid-tag-125khz-techshop-bangladesh
">RFID Card (125KHz) </a>
2. <a href="https://www.techshopbd.com/product-categories/rf/2402/125khz-rfid-module-uart-low-price-edition-techshop-bangladesh"> 125Khz RFID Module - UART(Low price edition) </a>
3. <a href="https://www.techshopbd.com/product-categories/wifi/2583/esp8266-esp-01-wifi-module-techshop-bangladesh
">ESP8266 ESP-01 Wifi Module </a>
4. <a href="https://www.techshopbd.com/product-categories/modules/2984/uart-gps-neo-6m-techshop-bangladesh
"> UART GPS NEO-6M </a>
5. <a href="https://www.techshopbd.com/product-categories/eval-board/2041/sim900a-kit-techshop-bangladesh"> SIM900A kit </a><br>

### Required Softwares
-----------------
1. Atmel Studio
2. Extreme Burner
3. Arduino IDE<br>

### Project Work Status
-----------------
1. Send Data from ATMEGA32 to Arduino - Done
2. Receive Data from Arduino to ATMEGA32 - Done
3. Send and Receive Data Between Two ATMEGA32 - Done
4. Read RFID data -Done
5. communicate with server by ESP8266 -Done


### Circuit Diagram
-----------------
### Demonstration Video
-----------------
1.<a href="https://gifs.com/gif/communicate-between-two-atmega32-qYkw93"><b>Communication between two ATMEGA32</b></a><br>
2.<a href="https://gifs.com/gif/esp8266-nodemcu-controlling-led-from-server-APLMV7"><b>Controlling Led from server</b></a>
