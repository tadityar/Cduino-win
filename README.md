# Cduino-win
Interfacing Arduino through C with Xbee to create an IoT device on Windows. As of writing the C code only works on Windows.

# IDEs
The professor's recommended IDE for this course is Eclipse for C/C++. The instructions and steps of configuring the IDE can be found [here](https://www.dropbox.com/s/ka7zz7cwn7bzikx/SettingsandInstallations.pdf?dl=0).

# Instructions
#### Common Instruction
1. Install everything needed to work with UDOO and eHealth library from [here](https://github.com/sibosutd/sutd-iot/blob/master/doc/software.md).
2. To upload an Arduino sketch to the UDOO please follow the steps [here](https://www.dropbox.com/sh/fr3rnyz7xnamxt4/AAAWNVbShBId1Tdtc_Q0qD3La/IOTlab1%20for%20students.zip?dl=0). (It's 50.001 first lab file)
3. Configure the shield, jumpers, and jumper wires according to [this](http://imgur.com/a/P6Fyq).
4. Everytime you try to upload an Arduino sketch to the UNO please remove the XBee shield first.
5. If when uploading Arduino sketch to the UDOO it says "No device found on COM##", do the steps from number 2 then try uploading again.

#### Remote LED Instruction
1. Attach LED to pin 13 and GND on the UNO XBee shield and put the jumpers exactly at [this](http://imgur.com/a/P6Fyq) position.
2. Upload the Arduino sketches for this lab titled "lab1_b_due.ino" and "lab1_b_uno.ino"(Remember to remove the XBee shield before uploading).
3. Modify write.c to match your settings (COM port number, what to send, and the baud rate).
4. Run write.c with an IDE or gcc.
5. Try running gui.c to see how to make simple gui in C.

#### eHealth Instruction
1. Attach the eHealth shield on top of the XBee shield on the UNO and LED on pin 13 and GND of the eHealth shield.
2. Connect the Pulsioximeter and body location sensor to the eHealth shield.
3. Upload the Arduino sketches for this lab titled "lab2_b_due.ino" and "lab2_b_uno.ino" (Remember to remove the XBee shield before uploading).
4. Modify read.c and write.c to match your settings (COM port number, how many bytes to read, what to send, and the baud rate).
5. Run read.c and write.c with an IDE or gcc.

#### Cloud Upload Instruction
1. Here we're using a library called curl. It's commonly installed on *NIX based OS but on Windows we need to download and install it first. Download [here](http://curl.haxx.se/dlwiz/?type=lib&os=Win32&flav=-).
2. Extract the zip file and copy the "curl" folder inside the "include" folder to the same directory as your C project.
3. Copy the entire content of the "bin" folder to your %windir% (just type that on your windows explorer address).
4. Configure your IDE to include the library in the linker settings, here's the guide to do it on eclipse and here's the guide to do it on code blocks.
5. We're going to test our sending mechanism through a free web applications at dweet.io . Choose a unique name for your project.
6. Modify upload.c to match with your URL. It should be "http://dweet.io/dweet/for/project-name?"
7. Also modify the things you want to send.
8. To check if your send is successful go to "http://dweet.io/get/dweets/for/project-name" and your datas will be converted into a JSON form.