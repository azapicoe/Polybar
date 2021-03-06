[Variables]
Mail_X=1355
Mail_Storage=
Mail_LoggedIn=false

[Metadata]
Name=Papirus\\Mail
Author=reddit.com/u/khanhas
Description=Gmail only. Show number of unread mails. Click to show most recent mails.

[MailShape]
Meter=Shape
X=#Mail_X#
Y=(#Bar_OffsetY#)
Shape=Rectangle 0,0,(#Bar_Height#),(#Bar_Height#) | StrokeWidth 0 | Fill Color #Color_Scheme1#
DynamicVariables=1
MouseOverAction=[!WriteKeyValue Variables "Curr_X" "(#CURRENTCONFIGX#+[MailIcon:X]+[MailIcon:W]/2)" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!WriteKeyValue Variables "Curr_Y" "[SubSkinYPositionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!WriteKeyValue Variables "Dir" "[SubSkinDirectionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!WriteKeyValue Variables "Mail_LoggedIn" "#Mail_LoggedIn#" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "MailList.ini"][!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=["https://mail.google.com/mail/u/#Mail_Form1#/#inbox/"]

[Mail_Script]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\script_Mail.lua

[Mail_Webparser]
Measure=Plugin
Plugin=WebParser
DynamicVariables=1
DecodeCharacterReference=1
Download=1
DownloadFile=gmailFeed.txt
UpdateRate=2
FinishAction=[!SetVariable Mail_LoggedIn true][!CommandMeasure Mail_Script GetMailFeed('module')]
OnDownloadErrorAction=
Disabled=1

[Mail_Avatar]
Measure=Plugin
PLugin=WebParser
URL=https://picasaweb.google.com/data/feed/api/user/#Mail_Form1#
RegExp=(?siU)<gphoto:thumbnail>(.*)</gphoto:thumbnail>
StringIndex=1
Download=1
DownloadFile=gmailAvatar.png
DynamicVariables=1

[MailIcon]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\Mail.png
ImageTint=#Color_Scheme4#
W=(#Font_Size#*15/9)
X=(#Mail_X#+#Bar_Height#/2-[MailIcon:W]/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[MailIcon:H]/2)
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1

[Mail_UnreadBadgeShape]
Meter=Shape
Shape=Rectangle ([Mail_UnreadCountBadge:X]-#Font_Size#*2/3),([Mail_UnreadCountBadge:Y]-#Font_Size#/3),([Mail_UnreadCountBadge:W]+#Font_Size#*sgn([Mail_UnreadCountBadge:W])),([Mail_UnreadCountBadge:H]+#Font_Size#/3*sgn([Mail_UnreadCountBadge:W])) | StrokeWidth 0 | Fill Color #Color_Scheme4#
DynamicVariables=1

[Mail_UnreadCountBadge]
Meter=String
MeasureName=MailNotice
FontFace=#Font_Face2#
FontSize=(#Font_Size#*12/9)
FontColor=#Color_Scheme2#
X=(#Mail_X#+#Bar_Height#-#Font_Size#/3)
StringAlign=RightBottom
Y=(#Bar_OffsetY#+#Bar_Height#)
AntiAlias=1
DynamicVariables=1

[MailNotice]
Measure=Calc
Formula=0
IfCondition=MailNotice > 0 
IfTrueAction=[!ShowMeter Mail_UnreadCountBadge][!SetOption MailIcon ImageTint "#Color_Scheme2#"]
IfFalseAction=[!HideMeter Mail_UnreadCountBadge][!SetOption MailIcon ImageTint "#Color_Scheme4#"]
