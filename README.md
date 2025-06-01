# exe.png
this is a exe that is disguised as a png to run things. currently the code does almost no harmful tasks and is not associated to webhook and other things(yet)

## how does this work,what does this exactly do?

This C program quietly gathers some basic diagnostic info about the PC it's running on — like your public IP, user account, OS details, running tasks, and network status — then writes it all to a log file in your %TEMP% directory. Think of it like a mini system snapshot, just in batch form.

But here's the cool part:
It hides the console window, creates a temporary .bat file on the fly, fills it with all those sweet Windows command-line instructions, and then runs that batch script automatically — all from C.(this feature is super bugged and it works sometimes and sometimes it dosent. planning to have a thread run in the background to execute the commands)


- i try to hide ahh code:
First thing it does is hide its own console window (ShowWindow(hWnd, SW_HIDE)), so the user won’t even see it running. Stealthy, right?

- storing the log file in temp in temp:
It grabs the %TEMP% folder path and uses that to create a new batch file there (temp_script.bat).

- fetch local time and start displaying the output one by one to the log in file in temp
It logs the current date and time into a text file named pnglogfile.txt, also in the temp directory. This becomes your logbook.

- get the ip and network and store it in the log file:
It pulls your public IP using OpenDNS (classic trick), and logs info about your current Wi-Fi setup using netsh.

- get theuser info and store it in the log file:
It logs your username (whoami) and checks if you're an admin by looking for a specific group ID (S-1-5-32-544).

- get the systeminfo and store it in the log file:
A quick peek at the OS name and version using systeminfo.

- get the task list and store it in the log file:
It dumps the current running tasks using tasklist.

- no internet or uploading things(yet)

  ## What It’s Useful For

   - You wanna debug someone’s PC without overwhelming them? Boom. Run this.

   - Just wanna flex a log file that says “admin?(nyae?)”? Yeah, that too.

   - Great for prank logs or hidden system audits (harmless ones).

## how do i make the .exe to disguise itself as png

refer [this](https://www.youtube.com/watch?v=cXEkSQl9wmw&list=LL&index=34&t=26s) video, [this](https://www.youtube.com/watch?v=cXEkSQl9wmw&list=LL&index=34&t=26s) video was the one that gave me the [idea](https://www.youtube.com/watch?v=dQw4w9WgXcQ).
the logfile of all the data will be present in your local %temp% env to find yours.


> [!NOTE]  
> THIS PROJECT IS FOR EDUCATIONAL PURPOSES

![image](https://github.com/user-attachments/assets/72cf7802-afba-4387-884e-898123e1f06f)

