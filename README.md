# Magnetic Reverberations
Hardware and software for the Magnetic Reverberations textile project. Created by Elizabeth Meiklejohn (concept, weaving), Laura Devendorf (tech), Irene Posch (concept, tech). The cloth contains 16 individually controllable electromagnets that animate flaps upon its surface. It can be controlled by a web-based controller at [https://flappable-rtd.web.app/](https://flappable-rtd.web.app/)
 

![A .gif of the fabric animating](/documentation/gif-1-perceptual-40-lossy.gif)

![the interface used to control the interaction](/documentation/interface.png)


## Directory Structure

### hw (hardware)
contains Platform IO project for programming the microcontroller. We used a Sparkfun Thing ESP32 Board and code that allows us to write realtime press data to a Fibebase Realtime Database. 

### interface
Contains an Angular project that reads from the realtime database to update a webpage at [https://flappable-rtd.web.app/](https://flappable-rtd.web.app/)


### documentation
contains images used in this README. 


## Installing and Debugging the Hardware

1. pull/clone this directory
2. open the project using the [Platform IO](https://platformio.org/) extension in [VSCode](https://code.visualstudio.com/). 
3. select "open" -> "import arduino project" -> navigate to the /hw directory and select 'SparkFun ESP32 Thing' from the boards list
4. make changes to your code, compile and push to the microcontroller. 
5. if having trouble debugging, you may reference the code we build ours upon at: https://RandomNerdTutorials.com/esp32-firebase-realtime-database/

:old_key:	Note: if you are and event/gallery looking to run our project, you will need to request the "secrets.h" file which includes the firebase key and database id. That file will also include your local wireless network (Username and Password), which is used to connect to the firebase database. 


## Installing Interface Code
1. pull/clone this directory
2. navigate to the /interface directory and run `npm install`
3. run `ng serve` to deploy and test code changes locally
4. when satisified with code run `ng build` then `firebase deploy` to push the contents of the generated dist/ directory to your hosting server. 

:old_key: Note: if you are copy this project on your own, you will need to generate a file that will be placed at interface/src/environments/environments.ts, which will contains all of you secret firebase authentication codes and API keys. 


## Installing The Fabric
1. hand the acryllic plate holding the cloth to the wall using the provided screws. 
2. Plug it into wall power
3. Flip the switch behind the cloth to "ON". Little lights on top of the electornics should turn on when you do this. 
4. A blue light will turn on behind the cloth, indicating that the cloth is looking to connect with the network (which you would have specified to the hardware using the secrets.h file -- see above). When the light turns off, the network is connected and the cloth is ready to be controlled from the interface at  [https://flappable-rtd.web.app/](https://flappable-rtd.web.app/)


## Troubleshooting

### Can't connect to Network (e.g. Blue Light Never Turning Off)
Use the programming cable (included in the shipping materials or sourced locally) to plug the textile's electronics into a computer. You will plug directly into the USB mircro port on the Sparkfun Thing ESP 32 board behind the cloth. Install the hardware files via the method above and then hit upload to get status messages about what the hardware is trying to do. After pushing upload, hold down the two "RESET" buttons on top of the ESP32. If you don't do this, the hardware will not get past the "connecting ...____....___..." phase. Make sure the Wifi information stored in secrets.h is correct and accessible, and then upload again. If it still doesn't work, call Laura :) 

### Electronics are not turning on at All. 
If you turn the switch to on and nothing happens (and no lights turn on at all), then the hardware is not getting power. Make sure all the connections from the wall power to the board are secure. If the barrel jack on the back of the fabric is loose at all, call Laura :) 

### Everything is connected, the Blue Light has Turned off, but the Fabric is Not Resonsive to the Interface
Give it a minute or so, sometimes it just gets a little confused about what's happening. I usually toggle the "all on" and "all off" buttons until I see something happen. 



## Acknowledgements
This has been a collaborative project led by Elizabeth Meiklejohn, Laura Devendorf and Irene Posch. It was created at the [Unstable Design Lab](https://unstable.design)  at the [https://www.colorado.edu/atlas/](ATLAS Institute) at the University of Colorado Boulder. The project emerged from a program called the "Experimental Weaving Residency", which is supported by the National Science Foundation. 

## Exhibition History

- On View at [Textile Intersections](https://www.textile-intersections.com/) as Loughborough University in London, UK Sept 20-23. 2023



## Read More and Demo Video
Coming Soon
