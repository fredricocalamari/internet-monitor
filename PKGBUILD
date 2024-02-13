pkgname=internet-monitor
pkgver=1.0
pkgrel=1
pkgdesc="A simple internet connectivity monitor with systemd integration"
arch=('x86_64')
url="https://github.com/fredricocalamari/internet-monitor"
license=('GPL')
depends=('glibc')
makedepends=('gcc')
source=('internet-monitor.c'
        'internet-monitor.service')
sha256sums=('SKIP' 
            'SKIP')

build() {
  gcc "$srcdir/internet-monitor.c" -o internet-monitor
}

package() {
  install -Dm755 "$srcdir/internet-monitor" "$pkgdir/usr/bin/internet-monitor"
  install -Dm644 "$srcdir/internet-monitor.service" "$pkgdir/usr/lib/systemd/user/internet-monitor.service"
}

