# Maintainer: Vince Richter <vince@77z.dev>
pkgname=ACElib
pkgver=0.1.0
pkgrel=1
pkgdesc=""
arch=('aarch64')
url="https://77z.dev"
license=('MIT')
groups=()
depends=()
makedepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=()
noextract=()
md5sums=() #autofill using updpkgsums

build() {
	cd ..

	make
}

package() {
	cd ..

	make DESTDIR="$pkgdir" install
}