# MFC-Halcon-Webcam-GUI
simple USB Webcam GUI using Halcon &amp; MFC
## Requirement
```ruby
1. MVTec Halcon >= 18.11
2. Visual Studio >= V.2019
```
## Installation
1. Download and install MVTec Halcon >= 18.11
## Project configuration
To add Halcon library to project, do these following step by step.
1. Go to solution properties -> Configuration properties -> VC++ Directories -> Include directories<br />
,then add "MVTec\HALCON-XX.XX-XXXX\(inlude,include\hdevengine\,include\halconcpp\)".Go to library dierectories which on the same page<br />
and then add "MVTec\HALCON-XX.XX-XXXX\lib\x64-win64"<br />
2.Go to solution properties -> C/C++ -> General -> Additional include directories<br />
,then add "MVTec\HALCON-XX.XX-XXXX\(include\hdevengine\,include\halconcpp\)".<br />
3.Go to solution properties -> Linker -> Input -> Additional dependencies<br />
,then add "MVTec\HALCON-XX.XX-XXXX\lib\x64-win64\halconcpp.lib"<br />
## Application
![Screenshot 2022-11-05 140714](https://user-images.githubusercontent.com/56642026/200107451-8a601cf9-ec30-4154-9ef4-7ade4292c9f4.png)
<br /> More functionable than traditional webcam interface on Window,You can adjust advanced parameter using this application.
## !!! Warning
**Be careful to adjust your webcam properties.An invalid parameter or over specification uses**<br />
**will be cause of broken webcam**<br />
You can see available adjust parameter using Hdeveloper -> Image acquisition.<br />
## License
**MVTec Halcon**
