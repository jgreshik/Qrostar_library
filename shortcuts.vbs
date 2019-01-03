'' Author: Joseph Greshik
' this script creates shortcuts for the executable programs in dump 

scriptdir = CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.ScriptFullName) & "\"
Dim WSHShell,MyShortcut,DesktopPath,names,namesA
Set WSHShell = CreateObject("WScript.Shell") 
If not WSHShell Is Nothing Then 
names="counterhero\counterhero.exe,jelly1000\jelly.exe"
namesA = Split(names, ",")
Dim i 
For Each i in namesA
	Set MyShortcut = WSHShell.CreateShortCut(scriptdir & Mid(i,InStrRev(i,"\")+1) & ".lnk") 
	MyShortcut.TargetPath = scriptdir & "dump\" & i
	MyShortcut.WorkingDirectory = scriptdir
	MyShortcut.WindowStyle = 1 
	MyShortcut.Arguments = "" 
	MyShortcut.Save 
	Set MyShortcut = Nothing 
Next
end if