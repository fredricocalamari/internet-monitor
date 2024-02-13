# Freedesktop Internet Monitor

The Freedesktop Internet Monitor is an efficient systemd service, meticulously crafted in C, designed to monitor internet connectivity. By pinging google.com at 5-second intervals, it promptly alerts users of any connectivity issues with a dbus notification, seamlessly integrating with both GNOME and KDE desktop environments. Originally conceived in Python by ChatGPT 3.5, this tool has been refined and rewritten in C to enhance performance and minimize resource consumption, boasting an impressively low memory footprint of under 1.3M. Tailored for responsiveness and sensitivity to connectivity changes, users can easily customize the ping interval to suit their preferences.

## Features

- **Efficient Connectivity Monitoring:** Checks internet access by pinging google.com every 5 seconds.
- **User-Friendly Notifications:** Generates desktop notifications within GNOME or KDE environments upon detecting connectivity issues.
- **Customizable Frequency:** Allows easy adjustment of the ping interval to accommodate user needs.
- **Optimized Performance:** Rewritten in C to ensure minimal resource usage, ideal for systems where efficiency is paramount.
- **Broad Compatibility:** Tested and confirmed operational on Arch Linux with GNOME 45, with potential for wide Linux distribution support.

## Getting Started

### Arch Linux Installation

1. **Install Dependencies:**

Ensure `dbus` is installed:
```bash
sudo pacman -Sy dbus
```

2. **Clone and Navigate to Repository:**
```bash
git clone https://www.github.com/fredricocalamari/internet-monitor internet-monitor && cd $_
```

3. **Build and Install Package:**
```bash
makepkg && sudo pacman -U internet-monitor*.zst
```

4. **Enable and Start the Systemd Service (User Mode):**
```bash
systemctl --user enable internet-monitor.service && systemctl --user start internet-monitor.service
```
Repeat the above command for each user account that requires the internet monitor service.

### Installation on Other Distributions

1. **Download and Prepare Files:**

Download `internet-monitor.c` and `internet-monitor.service` into a desired folder and navigate into it:
```bash
cd path/to/folder
```

2. **Compile the Source:**
```bash
gcc internet-monitor.c -o internet-monitor
```

3. **Install the Binary and Service File:**

<b>As root</b>, execute the following commands:
```bash
chmod 755 internet-monitor && cp internet-monitor /usr/bin/
chmod 644 internet-monitor.service && cp internet-monitor.service /usr/lib/systemd/user/
exit
```

4. **Enable and Start the Service (User Mode):**

As an unprivileged user, enable and start the service:
```bash
systemctl --user enable internet-monitor.service && systemctl --user start internet-monitor.service
```

## Customization

To modify the ping interval, simply edit the `internet-monitor.c` file, changing the sleep duration to your preferred interval, and recompile the program. This flexibility allows the monitor to be adapted to various user requirements and network conditions.

This text can be directly copied into the GitHub README.md editor or any markdown file.
