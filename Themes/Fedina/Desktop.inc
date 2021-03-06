[Variables]
Desktop_x=1095
;Left, Right or Center
Desktop_Anchor=Right
Desktop_Width=(#Font_Size#*4)

[Metadata]
Name=Fedina\\Desktop
Author=reddit.com/u/khanhas
Description=Click to show Desktop.

[DesktopAnchor]
Measure=String
String = #Desktop_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption DesktopShape X "(#Bar_OffsetX#+#*Desktop_X*#-#Desktop_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption DesktopShape X "(#Bar_OffsetX#+#*Desktop_X*#-#Desktop_Width#)"]

[DesktopShape]
Meter=Shape
X=(#Bar_OffsetX#+#Desktop_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#Desktop_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', #Desktop_X#)] 
DynamicVariables=1

[DesktopButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=CenterCenter
X=(#Desktop_Width#/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
SolidColor=0,0,0,1
LeftMouseDownAction=["#@#nircmd.exe" sendkeypress lwin+d]
DynamicVariables=1
