'' Author: Joseph Greshik
'' this script continuously plays music from dump

scriptdir = CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.ScriptFullName)
Dim oPlayer
	Set oPlayer = CreateObject("WMPlayer.OCX")
Function play(file,ByRef player)
	oPlayer.close
	player.URL = scripdir & "dump\music\" & file 
	player.controls.play
End Function
Dim i, songNames, songNamesArray
songNames="24 - Home.mp3,26 - Love.mp3,22 - Majesty.mp3,20 - Nocturne.mp3,11 - Sync.mp3"
songNamesArray = Split(songNames, ",")
While 1
	For Each i in songNamesArray
		play i, oPlayer
		While oPlayer.playState <> 1 ' 1 = Stopped
  			WScript.Sleep 100
		Wend
	Next
Wend


