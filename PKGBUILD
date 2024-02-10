# PKGBUILD

pkgname=internet-monitor
pkgver=0.1
pkgrel=1
pkgdesc="Daemon that monitors internet connectivity and notifies the user"
arch=('any')
url="https://example.com"
license=('GPL')
depends=('python' 'dbus-python')

package() {
    # Install systemd service
    install -Dm644 internet-monitor.service "${pkgdir}/usr/lib/systemd/user/internet-monitor.service"

    # Install Python script
    install -Dm755 internet-monitor.py "${pkgdir}/usr/bin/internet-monitor.py"

    # Set permissions and ownership
    chmod 644 "${pkgdir}/usr/lib/systemd/user/internet-monitor.service"
    chmod 755 "${pkgdir}/usr/bin/internet-monitor.py"
}

# Add md5sums if needed
#md5sums=('...')

