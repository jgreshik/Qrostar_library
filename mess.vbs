'' Author: Joseph Greshik
'' This script opens presaved images, creates message boxes with screen priority
''  and has a function for writing long strings on one line and easily adding newlines
''  for message box use
'' This script also kills other running vbsript programs at the end of execution of itself
''  specifically in order to end continuous loop of play.vbs script

scriptdir = CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.ScriptFullName) & "\"
Set oShell = WScript.CreateObject("WSCript.shell")

'' Functions
' img(file), file is a string that is the name of the image saved in images folder
' this opens an image saved in dump
Function img(file)
	sCmd = "rundll32.exe %windir%\system32\shimgvw.dll,ImageView_Fullscreen"
	iName=scriptdir & "dump\images\" & file 
	set oWS = createobject("wscript.shell")
	set oExec = oWS.Exec(sCmd & " " & iName)
End Function
' longString(ls), ls is the string to be edited
' ls is formatted to have "{newline} " delimiter specify where carriage returns and newlines are to be added
' edited string is returned
Function longString(ls)
	Dim stringArray,y,out
	out = Space(0)
	stringArray = Split(ls, "{newline} ")
	For Each y in stringArray
		out = out & y & vbCrLF & vbCrLF
	Next
	longString=out
End Function
' msg(ms,mstitle), ms is message, mstitle is title
' msg creates a message box using ms and mstitle as the message and title of the box, respectively
' also adds vbSystemModal option for message box priority on screen
Function msg(ms,mstitle)
	MsgBox ms,vbSystemModal,mstitle
End Function

'' Script begin
img("CH.png")
msg longString("Qrostar created two fun games which I included in dump\.{newline} Running master will create shortcuts for them each in the current working directory.{newline} Please enjoy these games and support Qrostar at http://qrostar.skr.jp/en/."),"title"
'this command kills all wscript processes 
oShell.Run "taskkill /IM wscript.exe /F"