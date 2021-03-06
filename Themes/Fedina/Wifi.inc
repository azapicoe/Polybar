[Variables]
Wifi_X=658
;Left, Right or Center
Wifi_Anchor = Left
Wifi_Width=(#Font_Size#*4)

[Metadata]
Name=Fedina\\Wifi
Author=reddit.com/u/khanhas
Description=Display Wifi SSID.

[WifiAnchor]
Measure=String
String = #Wifi_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption WifiShape X "(#Bar_OffsetX#+#*Wifi_X*#-#Wifi_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption WifiShape X "(#Bar_OffsetX#+#*Wifi_X*#-#Wifi_Width#)"]

[WifiSSID]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=SSID

[WifiQuality]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=Quality

[WifiShape]
Meter=Shape
X=(#Bar_OffsetX#+#Wifi_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#Wifi_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', #Wifi_X#)]
DynamicVariables=1
ToolTipText=SSID: [WifiSSID]#CRLF#Quality: [WifiQuality]%

[WifiIcon]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*15/14)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=CenterCenter
X=([WifiShape:X] + [WifiShape:W]/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
InlineSetting=GradientColor | 90 | #Color_Scheme2# ; 0 | #Color_Scheme2# ; ([WifiQuality]/100) | #Color_Scheme2#50 ; ([WifiQuality]/100)
