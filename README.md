# NORCOW

[![Build Status](https://travis-ci.org/trezor/norcow.svg?branch=master)](https://travis-ci.org/trezor/norcow) [![gitter](https://badges.gitter.im/trezor/community.svg)](https://gitter.im/trezor/community)

Copy-on-Write (COW) Key-Value Storage for NOR Flash devices

See `norcow.h` for the API.

## Record format

```
uint16_t key
uint16_t length
uint8_t value[length]
```
