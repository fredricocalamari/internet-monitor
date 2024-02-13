## Freedesktop internet-monitor
A simple systemd service written in C that checks every 5 seconds for internet 
connectivity and sends a dbus notification to an active GNOME or KDE desktop
when the internet is unreachable. The initial source was written by ChatGPT 3.5
in python and then modified by me until I got exactly what I wanted. Rewritten
in C to use less resources. Try it out, it works well.

### What it does
It pings google.com and when it can't, it generates a desktop notification in
a GNOME or KDE session. I've tested this on Arch Linux with GNOME 45.

### Build package, install and start the service
#### For Arch Linux
Install dbus if you haven't already:
```bash
sudo pacman -Sy dbus
git clone \
    https://www.github.com/fredricocalamari/internet-monitor \
    internet-monitor && cd $_
```
After dbus is installed: 
```bash
makepkg && pacman -U internet-monitor*.zst
```
#### Enable systemd service as an unprivileged user:
```bash
systemctl --user enable internet-monitor.service && \
systemctl start internet-monitor.service
```
##### Run above commands on user accounts wishing to use internet-monitor

### For other distributions:
Download internet-monitor.c and internet-monitor.service to a folder and
cd into it.
Type this in your shell:
```bash
gcc internet-monitor.c -o internet-monitor
sudo -i
chmod 755 internet-monitor && \
cp internet-monitor /usr/bin/
chmod 644 internet-monitor.service && \
cp internet-monitor.service /usr/lib/systemd/user/
exit
# Do this as an unprivileged user
systemctl --user enable internet-monitor.service && \
systemctl start internet-monitor.service
```
