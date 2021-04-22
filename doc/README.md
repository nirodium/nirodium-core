NRDI Core
=============

Setup
---------------------
[NRDI Core](http://nirodium.org/wallet) is the original NRDI client and it builds the backbone of the network. However, it downloads and stores the entire history of NRDI transactions; depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once.

Running
---------------------
The following are some helpful notes on how to run NRDI Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/nirodium-qt` (GUI) or
- `bin/nirodiumd` (headless)

### Windows

Unpack the files into a directory, and then run nirodium-qt.exe.

### macOS

Drag NRDI-Qt to your applications folder, and then run NRDI-Qt.

### Need Help?

* See the documentation at the [NRDI Wiki](https://github.com/NRDI-Project/NRDI/wiki)
for help and more information.
* Ask for help on [BitcoinTalk](https://bitcointalk.org/index.php?topic=1262920.0) or on the [NRDI Forum](http://forum.nirodium.org/).
* Join our Discord server [Discord Server](https://discord.nirodium.org)

Building
---------------------
The following are developer notes on how to build NRDI Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The NRDI repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://www.fuzzbawls.pw/nirodium/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Dnsseed Policy](dnsseed-policy.md)

### Resources
* Discuss on the [BitcoinTalk](https://bitcointalk.org/index.php?topic=1262920.0) or the [NRDI](http://forum.nirodium.org/) forum.
* Join the [NRDI Discord](https://discord.nirodium.org).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
