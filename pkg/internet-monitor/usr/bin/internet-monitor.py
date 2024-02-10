import subprocess
import time
import dbus

class InternetMonitor:
    def __init__(self):
        self.dbus_session_bus = dbus.SessionBus()
        self.notification_interface = None
        self.connected = False
    
    def check_internet(self):
        try:
            subprocess.check_call(["ping", "-c", "1", "8.8.8.8"], stdout=subprocess.DEVNULL)
            self.connected = True
        except subprocess.CalledProcessError:
            self.connected = False

    def send_notification(self, message):
        self.notification_interface.Notify("InternetMonitor", 0, '', 'Internet Connection Status', message, [], {}, -1, dbus_interface="org.freedesktop.Notifications")
 
    
    def start_monitoring(self):
        self.notification_interface = self.dbus_session_bus.get_object("org.freedesktop.Notifications", "/org/freedesktop/Notifications")
        
        while True:
            self.check_internet()
            if not self.connected:
                self.send_notification("You are no longer connected to the internet.")
            time.sleep(5)

if __name__ == "__main__":
    monitor = InternetMonitor()
    monitor.start_monitoring()
